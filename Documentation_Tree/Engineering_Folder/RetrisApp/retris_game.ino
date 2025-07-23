#include "vector.h"
#include "block.h"
#include "constants.h"
#include "renderer.h"
#include "preview_block.h"
#include "retris_os.h"
#include "retris_game.h"

#if !SIMULATION
#include "input.h"
#endif

#if DEBUG
uint8_t DEBUG_BLOCK = I;
#endif

#define BASE_BLOCK_SPEED 40
#define CLEAR_LINES_HURDLE 10

#define VIEW_STYLE_HORIZONTAL 1
#define VIEW_STYLE_VERTICAL 2

#define TICKS_UNTIL_AUTO_MOVE 5

constexpr uint8_t RetrisGame::speedTable[];

RetrisGame::RetrisGame()
{
  static uint8_t instanceCount = 0;
  instanceCount++;
  m_instanceCount = instanceCount;
}

void RetrisGame::Init(Vector startPosition, uint8_t style, bool holdBlockActive)
{
  m_gamePosition = startPosition;
  m_holdBlockActive = holdBlockActive;

  // reset all variables from the sesssion
  ResetGame();

  randomSeed(micros());
  m_blockBag.Init();

#if DEBUG
  uint8_t randomBlock = DEBUG_BLOCK;
  m_nextBlock = DEBUG_BLOCK;
#else
  uint8_t startBlock = m_blockBag.GetNextBlock();
  m_nextBlock = m_blockBag.GetNextBlock();
#endif

  DrawGameField(style);
  m_currentBlock.Create(blockShape[startBlock], startBlock, m_gamePosition + positionTable[startBlock]);

  m_activeInput = true;
}

#if SIMULATION
void RetrisGame::ProcessInput(uint8_t pressedButton)
#else
void RetrisGame::ProcessInput()
#endif
{
  // leave if input is disabled
  if (!m_activeInput)
  {
    return;
  }

#if SIMULATION
  switch(pressedButton)
  {
  case BUTTON_RIGTH:
    MoveRight();
    break;

  case BUTTON_LEFT:
    MoveLeft();
    break;

  case BUTTON_DOWN:
    SetTimeScale(4);
    break;

  case BUTTON_A:
    Rotate();
    break;

  case BUTTON_NONE:
    SetTimeScale(m_baseSpeed);
    break;

  default:
    break;
  }
#else
  if (m_holdBlockActive && Input::GetButtonDown(m_instanceCount - 1, BUTTON_Y))
  {
    HoldBlock();
    return;
  }

  static uint8_t rightCounter = 0;
  static uint8_t leftCounter = 0;

  if (Input::GetButton(m_instanceCount - 1, BUTTON_RIGHT))
  {
    if (rightCounter++ > TICKS_UNTIL_AUTO_MOVE)
    {
      m_rightButtonHeld = true;
    }
  }
  else
  {
    m_rightButtonHeld = false;
    rightCounter = 0;
  }

  if (Input::GetButton(m_instanceCount - 1, BUTTON_LEFT))
  {
    if (leftCounter++ > TICKS_UNTIL_AUTO_MOVE)
    {
      m_leftButtonHeld = true;
    }
  }
  else
  {
    m_leftButtonHeld = false;
    leftCounter = 0;
  }

  if (m_rightButtonHeld || Input::GetButtonDown(m_instanceCount - 1, BUTTON_RIGHT))
  {
    MoveRight();
  }

  if (m_leftButtonHeld || Input::GetButtonDown(m_instanceCount - 1, BUTTON_LEFT))
  {
    MoveLeft();
  }

  if (Input::GetButtonDown(m_instanceCount - 1, BUTTON_X))
  {
    Rotate();
  }

  if (Input::GetButtonDown(m_instanceCount - 1, BUTTON_R))
  {
    QuickDrop();
  }

  // if button is pressed then "fast fall", else normal current speed
  SetTimeScale(Input::GetButton(m_instanceCount - 1, BUTTON_A) ? 4 : m_baseSpeed);
#endif
}

void RetrisGame::Update()
{
#if !SIMULATION
  ProcessInput();
#endif

  m_ticks++;
  switch(m_gameState)
  {
    case GAME_STATE_PLAYING:
    {
      bool gameTick = (m_ticks / m_timeScale) || m_quickDropped;

      DisplayQuickDrop(gameTick);

      if (!gameTick)
      {
        return;
      }
      m_ticks = 0;

      if (ValidateMove(MOVE_BELOW, m_currentBlock))
      {
          m_currentBlock.MoveDown();
          Renderer::IncludeBlock(m_currentBlock.points, m_currentBlock.position, BLOCK_LENGTH);
      }
      else 
      {
        Renderer::IncludeBlock(m_currentBlock.points, m_currentBlock.position, BLOCK_LENGTH);
        if (CheckFullLine())
        {
          // start fade out animation
          m_gameState = GAME_STATE_ANIMATION;
          return;
        }
        SpawnNewBlock();
      }
      break;
    }

  case GAME_STATE_ANIMATION:
      ClearAnimation();
      break;

  case GAME_STATE_LOST:
      DeathAnimation();
      break;

  case GAME_STATE_WAIT:
      if (m_ticks >= m_waitTime)
      {
        m_gameState = GAME_STATE_PLAYING;
        m_waitTime = 0;
        CreateBlock(m_nextBlock, true);
        m_activeInput = true;
      }
      break;

  case GAME_STATE_FINISHED:
      break;

  default:
      break;
  }
}

void RetrisGame::MoveRight()
{
  if (ValidateMove(MOVE_RIGHT, m_currentBlock))
  {
    m_currentBlock.MoveRight();
  }

  Renderer::IncludeBlock(m_currentBlock.points, m_currentBlock.position, BLOCK_LENGTH);
}

void RetrisGame::MoveLeft()
{
  if (ValidateMove(MOVE_LEFT, m_currentBlock))
  {
    m_currentBlock.MoveLeft();
  }

  Renderer::IncludeBlock(m_currentBlock.points, m_currentBlock.position, BLOCK_LENGTH);
}

void RetrisGame::HoldBlock()
{
  if (m_holdedBlock == INVALID_BLOCK)
  {
    m_holdedBlock = m_currentBlock.blockName;
    SpawnNewBlock();
  }
  else
  {
    Renderer::RemoveBlock(m_currentBlock.points, m_currentBlock.position, BLOCK_LENGTH);
    uint8_t currBlock = m_currentBlock.blockName;
    CreateBlock(m_holdedBlock, false);
    m_holdedBlock = currBlock;
  }

  m_holdPreviewBlock.UpdatePreview(m_holdedBlock);
}

void RetrisGame::Rotate()
{
  // rotate a copy of the current block and test if it is colliding with anything
  Block temp = m_currentBlock;
  temp.Rotate(); 
  if (ValidateMove(temp.points))
  {
    memcpy(m_currentBlock.points, temp.points, sizeof(Vector) * BLOCK_LENGTH);
  }

  Renderer::IncludeBlock(m_currentBlock.points, m_currentBlock.position, BLOCK_LENGTH);
}

void RetrisGame::QuickDrop()
{
  Block temp = m_currentBlock;
  Renderer::RemoveBlock(m_currentBlock.points, m_currentBlock.position, BLOCK_LENGTH);
  Renderer::RemoveBlock(m_quickDropBlock.points, m_quickDropBlock.position, BLOCK_LENGTH);

  while (ValidatePosition(temp))
  {
    temp.MoveDown();
  };

  // redo last move down which was not valid anymore
  temp.position.y -= 1;

  m_currentBlock = temp;
  Renderer::IncludeBlock(m_currentBlock.points, m_currentBlock.position, BLOCK_LENGTH);
  m_quickDropped = true;
}

void RetrisGame::DisplayQuickDrop(bool isGameTick)
{
  Renderer::RemoveBlock(m_quickDropBlock.points, m_quickDropBlock.position, BLOCK_LENGTH);

  m_quickDropBlock = m_currentBlock;
  Renderer::RemoveBlock(m_currentBlock.points, m_currentBlock.position, BLOCK_LENGTH);

  while (ValidatePosition(m_quickDropBlock))
  {
    m_quickDropBlock.MoveDown();
  };

  // redo last move down which was not valid anymore
  m_quickDropBlock.position.y -= 1;

  Renderer::IncludeBlock(m_quickDropBlock.points, m_quickDropBlock.position, BLOCK_LENGTH);
  if (!ValidateMove(MOVE_BELOW, m_currentBlock))
  {
    Renderer::RemoveBlock(m_quickDropBlock.points, m_quickDropBlock.position, BLOCK_LENGTH);
  }

  Renderer::IncludeBlock(m_currentBlock.points, m_currentBlock.position, BLOCK_LENGTH);
}

void RetrisGame::SetTimeScale(uint8_t timeScale)
{
  m_timeScale = timeScale; 
}

void RetrisGame::DrawGameField(uint8_t viewStyle)
{
  if (viewStyle == VIEW_STYLE_HORIZONTAL)
  {
    // Horizontal style can only be used in 1P-Mode 
    // move the game field to a more central place 
    m_gamePosition = {4, 6};
    m_previewBlock.borderPosition = {m_gamePosition.x + 14, m_gamePosition.y + 4};
  }
  else if (viewStyle == VIEW_STYLE_VERTICAL)
  {
    m_previewBlock.borderPosition = {m_gamePosition.x, 0};
  }

  m_previewBlock.DrawBorder();
  m_previewBlock.UpdatePreview(m_nextBlock);

  if (m_holdBlockActive)
  {
    m_holdPreviewBlock.borderPosition = {m_gamePosition.x + 14, m_gamePosition.y + 10};
    m_holdPreviewBlock.DrawBorder();
  }

  int32_t horizontalWall = 0x00000FFF;
  uint8_t offset = 32 - m_gamePosition.x - GAME_WIDTH_WB;
  horizontalWall <<= offset;

  screen[m_gamePosition.y] |= horizontalWall;
  screen[m_gamePosition.y + 21] |= horizontalWall;

  m_fullLine = horizontalWall;

  // cut of the border pixel
  m_fullLine = (m_fullLine >> 1) & (m_fullLine << 1);

  int32_t verticalWall = 0x00000801;
  verticalWall <<= offset;
  for (int i = 0; i < 21; i++)
  {
    screen[m_gamePosition.y + i] |= verticalWall;
  }
}

uint8_t RetrisGame::GetGameState()
{
  return m_gameState;
}

uint32_t& RetrisGame::GetCurrentScore()
{
  return m_score;
}

Vector RetrisGame::GetGamePosition()
{
  return m_gamePosition;
}

bool RetrisGame::ValidateMove(uint8_t move, const Block& block)
{
  Renderer::RemoveBlock(block.points, block.position, BLOCK_LENGTH);

  bool moveIsAllowed = false; 
  for (int i = 0; i < BLOCK_LENGTH; i++)
  {
    Vector absPosition = block.points[i] + block.position;
    switch(move)
    {
      case MOVE_RIGHT:
        absPosition.x++;
        break;
      case MOVE_LEFT:
        absPosition.x--;
        break;
      case MOVE_BELOW:
        absPosition.y++;
        break;
      default:
        break;
    }

    // shift the wanted value to the first digit and compare if it is on (1)
    moveIsAllowed = !((screen[absPosition.y] >>  (31 - absPosition.x)) & 1);

    if (!moveIsAllowed)
    {
      break;
    }
  }
  return moveIsAllowed;
}

bool RetrisGame::ValidateMove(Vector points[])
{
  Renderer::RemoveBlock(m_currentBlock.points, m_currentBlock.position, BLOCK_LENGTH);

  bool moveIsAllowed = false;
for (int i = 0; i < BLOCK_LENGTH; i++)
{
  Vector absPosition = points[i] + m_currentBlock.position;

  // shift the wanted value to the first digit and compare if it is on (1)
  moveIsAllowed = !((screen[absPosition.y] >>  (31 - absPosition.x)) & 1);

  if (!moveIsAllowed)
  {
    break;
  }
}
  return moveIsAllowed;
}

bool RetrisGame::ValidatePosition(Block block)
{
  bool moveIsAllowed = false;
  for (int i = 0; i < BLOCK_LENGTH; i++)
  {
    Vector absPosition = block.points[i] + block.position;
    moveIsAllowed = !((screen[absPosition.y] >>  (31 - absPosition.x)) & 1);

    if (!moveIsAllowed)
    {
      break;
    }
  }

  return moveIsAllowed;
}

bool RetrisGame::CheckFullLine()
{
  // 1 or 0 represents if the line is full or not
  // stored in an int32_t -> higher bits = top of the board
  // so the information can be used in the animation state
  // this way is more resource efficient than storing it as an array for example 
  for (int i = 0; i < GAME_HEIGHT; i++)
  {
    uint8_t currentLine = i + m_gamePosition.y + 1; // + 1 to account for the border
    int32_t maskedLine = screen[currentLine] & m_fullLine;
    if (maskedLine == m_fullLine)
    {
      m_fullLineTable |= (int32_t)1 << (31 - currentLine);
      m_clearedLinesCount++;
    }
  }

  return m_fullLineTable != 0;
}

void RetrisGame::ClearAnimation()
{
  for (int i = 0; i < GAME_HEIGHT; i++)
  {
    uint8_t currentLine = i + m_gamePosition.y + 1;
    int32_t deletePixel = 0;
    if ((m_fullLineTable >> (31 - currentLine)) & 1)
    {
      // 5 and 6 are the relativ middle of the board with account to m_ticks being 1 at first
      deletePixel |= (int32_t)1 << (31 - (m_gamePosition.x + 5 + m_ticks));
      deletePixel |= (int32_t)1 << (31 - (m_gamePosition.x + 6 - m_ticks));
      screen[currentLine] &= ~deletePixel; 
    }
  }

  // if animatin is not finished then leave
  if (m_ticks != CLEAR_ANIMATION_LENGTH)
  {
    return;
  }

  // shift every line down
  uint8_t lineCount = 0;
  for (int i = GAME_HEIGHT-1; i >= 0; i--)
  {
    uint8_t currentLine = i + m_gamePosition.y + 1;
    if ((m_fullLineTable >> (31 - currentLine)) & 1)
    {
      lineCount++;
    }
    else
    {
      // get ONLY the current line of the board (masking)
      int32_t maskedLine = screen[currentLine] & m_fullLine;
      // clear the the line below and replace it with the masked line from above 
      screen[currentLine + lineCount] &= ~m_fullLine;
      screen[currentLine + lineCount] |= maskedLine;
    }
  }

  m_ticks = 0;
  m_fullLineTable = 0;

  // every 10 cleared Lines the level is incremented as well as the speed
  m_level = m_clearedLinesCount / CLEAR_LINES_HURDLE;

  if (m_level <= 29) // 29 is the last level where the speed increases
  {
    m_baseSpeed = speedTable[m_level];
  }
  SetTimeScale(m_baseSpeed);

  UpdateScore(lineCount);
  SpawnNewBlock();
}

void RetrisGame::UpdateScore(const uint8_t clearedRows)
{
  const uint16_t baseValues[] = { 40, 100, 300, 1200 };
  m_score += baseValues[clearedRows - 1] * (m_level + 1);

  // update lcd screen
  HW::lcd.setCursor(0, m_instanceCount - 1);
  HW::lcd.print("P" + String(m_instanceCount) + ": " + String(m_score));
  HW::lcd.setCursor(14, m_instanceCount - 1);
  HW::lcd.print(m_level);
}

void RetrisGame::DeathAnimation()
{
  // slow down the animation speed
  if (m_ticks % 20 != 0)
  {
    return;
  }

  uint8_t currentLine = 0;
  for (uint8_t i = 0; i < GAME_HEIGHT; i++)
  {
    currentLine = m_gamePosition.y + 1 + i;
    screen[currentLine] ^= m_fullLine;
  }
  if (m_ticks == DEATH_ANIMATION_LENGTH * 20)
  {
    m_gameState = GAME_STATE_FINISHED;
  }
}

void RetrisGame::ResetGame()
{
  m_level = 0;
  m_score = 0;
  m_clearedLinesCount = 0;
  m_gameState = GAME_STATE_PLAYING;
  m_fullLine = 0;
  m_fullLineTable = 0;
  m_holdedBlock = INVALID_BLOCK;
}

void RetrisGame::Wait(const uint8_t waitTime)
{
  m_waitTime = waitTime;
  m_gameState = GAME_STATE_WAIT;
  m_activeInput = false;
}

void RetrisGame::SpawnNewBlock()
{
  // check if a new block can even be placed -> otherwise game lost
  uint32_t deathZone = (m_fullLine >> 3) & (m_fullLine << 4); 
  if ((screen[m_gamePosition.y + 2] & deathZone) != 0)
  {
    m_gameState = GAME_STATE_LOST;
    m_activeInput = false;
    SetTimeScale(m_baseSpeed);
    return;
  }

  Wait(m_quickDropped ? 0 : 20);
  m_quickDropped = false;
}

void RetrisGame::CreateBlock(uint8_t block, bool updatePreview)
{
  m_currentBlock.Create(blockShape[block], block, m_gamePosition + positionTable[block]);
  m_quickDropBlock = m_currentBlock;

  if (updatePreview)
  {
#if DEBUG
    uint8_t randomBlock = DEBUG_BLOCK;
#else
    m_nextBlock = m_blockBag.GetNextBlock();
#endif

    m_previewBlock.UpdatePreview(m_nextBlock);
  }
}
