#ifndef AUDIO_H
#define AUDIO_H

namespace Audio {
   /* 
  Tetris theme - (Korobeiniki) 
  Connect a piezo buzzer or speaker to pin 11 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs                                            
                                              
                                              Robson Couto, 2019
*/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 10

#define FCPU 16000000

#define AUDIO_KOROBEINIKI 0
#define AUDIO_BUTTON_SWITCH 1
#define AUDIO_BUTTON_PRESS 2
#define AUDIO_GAME_OVER 3

// change this to make the song slower or faster
constexpr uint8_t tempo = 144;
// this calculates the duration of a whole note in ms (60s/tempo)*4 beats
constexpr uint16_t wholeNote = (60000 * 4) / tempo;

/**
* @brief Converts a note value to note duration
* @param noteValue Note value that will be converted
* @return Note Duration
*/
static constexpr uint32_t Conv(int8_t noteValue)
{
  return noteValue == -4 ? (wholeNote / 4) * 1.5 : (wholeNote / noteValue);
}
/**
* @brief holds data that is relevant for playing a melody/song/audio
*/
struct Melody
{
  /**
  * @brief Actual arrangment of the melody
  */
  uint32_t* p_melody;
  /**
  * @brief Length of the melody
  */
  uint8_t length;
  /**
  * @brief Which note is currently played
  */
  uint8_t currentNote;
};
// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
/**
* @brief arrangement of the audio korobeiniki (AUDIO_KOROBEINIKI)
* @details First entry is the note, second entry is it's note duration (after converting)
*/
static volatile constexpr uint32_t korobeiniki[] = {

  //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192
  
  NOTE_E5,Conv(4),  NOTE_B4,Conv(8),  NOTE_C5,Conv(8),  NOTE_D5,Conv(4),  NOTE_C5,Conv(8),  NOTE_B4,Conv(8),
  NOTE_A4,Conv(4),  NOTE_A4,Conv(8),  NOTE_C5,Conv(8),  NOTE_E5,Conv(4),  NOTE_D5,Conv(8),  NOTE_C5,Conv(8),
  NOTE_B4,Conv(-4),  NOTE_C5,Conv(8),  NOTE_D5,Conv(4),  NOTE_E5,Conv(4),
  NOTE_C5,Conv(4),  NOTE_A4,Conv(4),  NOTE_A4,Conv(8),  NOTE_A4,Conv(4),  NOTE_B4,Conv(8),  NOTE_C5,Conv(8),

  NOTE_D5,Conv(-4),  NOTE_F5,Conv(8),  NOTE_A5,Conv(4),  NOTE_G5,Conv(8),  NOTE_F5,Conv(8),
  NOTE_E5,Conv(-4),  NOTE_C5,Conv(8),  NOTE_E5,Conv(4),  NOTE_D5,Conv(8),  NOTE_C5,Conv(8),
  NOTE_B4,Conv(4),  NOTE_B4,Conv(8),  NOTE_C5,Conv(8),  NOTE_D5,Conv(4),  NOTE_E5,Conv(4),
  NOTE_C5,Conv(4),  NOTE_A4,Conv(4),  NOTE_A4,Conv(4), REST,Conv(4),

  NOTE_E5,Conv(4),  NOTE_B4,Conv(8),  NOTE_C5,Conv(8),  NOTE_D5,Conv(4),  NOTE_C5,Conv(8),  NOTE_B4,Conv(8),
  NOTE_A4,Conv(4),  NOTE_A4,Conv(8),  NOTE_C5,Conv(8),  NOTE_E5,Conv(4),  NOTE_D5,Conv(8),  NOTE_C5,Conv(8),
  NOTE_B4,Conv(-4),  NOTE_C5,Conv(8),  NOTE_D5,Conv(4),  NOTE_E5,Conv(4),
  NOTE_C5,Conv(4),  NOTE_A4,Conv(4),  NOTE_A4,Conv(8),  NOTE_A4,Conv(4),  NOTE_B4,Conv(8),  NOTE_C5,Conv(8),

  NOTE_D5,Conv(-4),  NOTE_F5,Conv(8),  NOTE_A5,Conv(4),  NOTE_G5,Conv(8),  NOTE_F5,Conv(8),
  NOTE_E5,Conv(-4),  NOTE_C5,Conv(8),  NOTE_E5,Conv(4),  NOTE_D5,Conv(8),  NOTE_C5,Conv(8),
  NOTE_B4,Conv(4),  NOTE_B4,Conv(8),  NOTE_C5,Conv(8),  NOTE_D5,Conv(4),  NOTE_E5,Conv(4),
  NOTE_C5,Conv(4),  NOTE_A4,Conv(4),  NOTE_A4,Conv(4), REST,Conv(4),
  

  NOTE_E5,Conv(2),  NOTE_C5,Conv(2),
  NOTE_D5,Conv(2),   NOTE_B4,Conv(2),
  NOTE_C5,Conv(2),   NOTE_A4,Conv(2),
  NOTE_GS4,Conv(2),  NOTE_B4,Conv(4),  REST,Conv(8), 
  NOTE_E5,Conv(2),   NOTE_C5,Conv(2),
  NOTE_D5,Conv(2),   NOTE_B4,Conv(2),
  NOTE_C5,Conv(4),   NOTE_E5,Conv(4),  NOTE_A5,Conv(2),
  NOTE_GS5,Conv(2),

};
/**
* @brief arrangement of the audio that will be played when a button is switched (AUDIO_BUTTON_SWITCH)
* @details First entry is the note, second entry is it's note duration (after converting)
*/
static volatile constexpr uint32_t buttonSwitch[] = { NOTE_G5, Conv(16) };
/**
* @brief arrangement of the audio that will be played when a button is pressed (AUDIO_BUTTON_PRESS)
* @details First entry is the note, second entry is it's note duration (after converting)
*/
static volatile constexpr uint32_t buttonPress[] = { NOTE_D6, Conv(16) };
/**
* @brief arrangement of the audio that will be played when the player lost (AUDIO_GAME_OVER)
* @details First entry is the note, second entry is it's note duration (after converting)
*/
static volatile constexpr uint32_t gameOver[] = { REST, Conv(4), NOTE_G5, Conv(8), NOTE_DS5, Conv(8), NOTE_A4, Conv(2) };
/**
* @brief Collection of every melody that can be played
*/
Melody melodies[] = {
  {korobeiniki, sizeof(korobeiniki) / sizeof(uint32_t), 0},
  {buttonSwitch, sizeof(buttonSwitch) / sizeof(uint32_t), 0},
  {buttonPress, sizeof(buttonPress) / sizeof(uint32_t), 0},
  {gameOver, sizeof(gameOver) / sizeof(uint32_t), 0},
};

// variables that control the current playing audio
static volatile int noteDuration = 0;
static volatile uint8_t currentAudio = 0;
static volatile int iInterrupt = 0; // counts the ISR executions (gets when a new note will be played)
static volatile uint32_t top = 0; // integer to which the timer will count
static volatile uint32_t holdTime = 0; // how long the note should be played (in terms of timer ticks)
static volatile bool isLooping = false;
/**
* @brief Stops the currently running audio
* @details Resets every related variable, so the next audio can be played.
*/
void StopAudio()
{
  cli();
  TIMSK1 = 0;
  OCR1A = 0;
  holdTime = 0;
  iInterrupt = 0;
  noteDuration = 0;
  top = 0;
  sei();
}
/**
* @brief Plays the given audio
* @details Will first stop if there is already running, an audio
* @param audio Name of the audio that will be played
* @param enableLooping Determines wether the audio shall be looping or not
* @param resume If true the audio will resume where it had stopped
*/
void PlayAudio(const uint8_t audio, const bool enableLooping = false, const bool resume = false)
{
  StopAudio(); // stop any audio which is still playing
  TIMSK1 |= (1 << OCIE1A); // enable ISR
  OCR1A = 1;
  TCNT1 = 0;
  currentAudio = audio;
  isLooping = enableLooping;

  // if not resuming then start from the beginning
  if (!resume)
  {
    melodies[currentAudio].currentNote = 0;
  }
}
/**
* @brief Sets up the timer registers (Timer1) for playing audio
*/
void Setup()
{
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; //initialize counter value to 0
  // pinMode(11, OUTPUT);
  DDRB |= (1 << PB5);

  // initialize the Timer1 in fast PWM-Mode with OCR1A as top
  // and the 256 prescaler
  TCCR1A |= (1 << WGM10) | (1 << WGM11) | (1 << COM1A0);
  TCCR1B |=  (1 << CS12) | (1 << WGM12) | (1 << WGM13) ;
}
/**
* @brief Interrupt service routine that will get triggered when the timer hits TOP
* @detials It will determine which frequency the pwm will be
*/
ISR(TIMER1_COMPA_vect)
{

  if (iInterrupt > holdTime)
  {
    uint8_t& currentNote = melodies[currentAudio].currentNote;
    if (currentNote >= melodies[currentAudio].length)
    {
      currentNote = 0;
      if (!isLooping)
      {
        StopAudio();
        return;
      }
    }

    noteDuration = melodies[currentAudio].p_melody[currentNote + 1];

    holdTime = (uint32_t)melodies[currentAudio].p_melody[currentNote] * (uint32_t)noteDuration / 1000;
    top = FCPU / ((int32_t)melodies[currentAudio].p_melody[currentNote] * 256);

    OCR1A = top;

    currentNote += 2;
    iInterrupt = 0;
  }
  else
  {
    iInterrupt++;
  }
}

}

#endif
