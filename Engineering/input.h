// int DATA_CLOCK    = 6;
// int DATA_LATCH    = 7;
// int DATA_CLOCK_2    = 2;
// int DATA_LATCH_2  	= 3;
// int DATA_SERIAL_1  = 12;
// int DATA_SERIAL_2  = 4;

#ifndef INPUT_H
#define INPUT_H

#define CONTROLLER_1 0
#define CONTROLLER_2 1
#define BUTTON_PRESSED 0

#define BUTTON_B 0
#define BUTTON_Y 1
#define BUTTON_SELECT 2
#define BUTTON_START 3
#define BUTTON_UP 4
#define BUTTON_DOWN 5
#define BUTTON_LEFT 6
#define BUTTON_RIGHT 7
#define BUTTON_A 8
#define BUTTON_X 9
#define BUTTON_L 10
#define BUTTON_R 11



// int buttons_1[12];
// int buttons_2[12];

namespace Input 
{ // {left controller port, right controller port}
  static constexpr uint8_t dataLatch[] = { 3, 7 };
  static constexpr uint8_t dataClock[] = { 2, 6 };
  static constexpr uint8_t dataSerial[] = { 4, 12 };
  static bool buttons[2][12] = {1};

    
    void SetupPins()
    {
         // Set DATA_CLOCK normally HIGH
         for (int i = 0; i < 2; i++)
         {
  pinMode(dataClock[i], OUTPUT);
  digitalWrite(dataClock[i], HIGH);

  pinMode(dataLatch[i], OUTPUT);
  digitalWrite(dataLatch[i], LOW);
  pinMode(dataSerial[i], OUTPUT);
  digitalWrite(dataSerial[i], HIGH);
  pinMode(dataSerial[i], INPUT);  
         }

  // pinMode(DATA_CLOCK_2, OUTPUT);
  // digitalWrite(DATA_CLOCK_2, HIGH);
  
  // Set DATA_LATCH normally LOW

  // pinMode(DATA_LATCH_2, OUTPUT);
  // digitalWrite(DATA_LATCH_2, LOW);

  // Set DATA_SERIAL normally HIGH

  // pinMode(DATA_SERIAL_2, OUTPUT);
  // digitalWrite(DATA_SERIAL_2, HIGH);
  // pinMode(DATA_SERIAL_2, INPUT);  
    }


    void ReadControllerInputs()
    {
    // Latch for 12us
    for (uint8_t j = 0; j < 2; j++)
    {

      digitalWrite(dataLatch[j], HIGH);
      delayMicroseconds(12);
      digitalWrite(dataLatch[j], LOW);
      delayMicroseconds(6);
    
      // Retrieve button presses from shift register by pulling the clock high for 6us
      for(uint8_t i = 0; i < 16; i++)
      {
          digitalWrite(dataClock[j], LOW);
          delayMicroseconds(6);
          if(i <= 16)
          {
              buttons[j][i] = digitalRead(dataSerial[j]);
              // Serial.println(buttons[j][i]);
          }
          digitalWrite(dataClock[j], HIGH);
          delayMicroseconds(6);
      }   
    }
    }
    // controller is 0 or 1 depending on which controller is being read; key is the button being checked
    bool GetKey(const uint8_t controller, const uint8_t key)
    {
      return buttons[controller][key] == BUTTON_PRESSED;
    }

    // static Controller m_controllers[2];
    // uint8_t controllerCount = 0;
};


#endif

// void setupPins(void){
 
// }


// Prints which buttons are pressed
// void printButtons_1(void){
//     if(buttons_1[0] == 0){
//         Serial.print("B");
//     }
//     if(buttons_1[1] == 0){
//         Serial.print("Y");
//     }
//     if(buttons_1[2] == 0){
//         Serial.print("SELECT");
//     }
//     if(buttons_1[3] == 0){
//         Serial.print("START");
//     }
//     if(buttons_1[4] == 0){
//         Serial.print("UP");
//     }
//     if(buttons_1[5] == 0){
//         Serial.print("DOWN");
//     }
//     if(buttons_1[6] == 0){
//         Serial.print("LEFT");
//     }
//     if(buttons_1[7] == 0){
//         Serial.print("RIGHT");
//     }
//     if(buttons_1[8] == 0){
//         Serial.print("A");
//     }
//     if(buttons_1[9] == 0){
//         Serial.print("X");
//     }
//     if(buttons_1[10] == 0){
//         Serial.print("LB");
//     }
//     if(buttons_1[11] == 0){
//         Serial.print("RB");
//     }
// }

// void printButtons_2(void){
//     if(buttons_2[0] == 0){
//         Serial.print("B");
//     }
//     if(buttons_2[1] == 0){
//         Serial.print("Y");
//     }
//     if(buttons_2[2] == 0){
//         Serial.print("SELECT");
//     }
//     if(buttons_2[3] == 0){
//         Serial.print("START");
//     }
//     if(buttons_2[4] == 0){
//         Serial.print("UP");
//     }
//     if(buttons_2[5] == 0){
//         Serial.print("DOWN");
//     }
//     if(buttons_2[6] == 0){
//         Serial.print("LEFT");
//     }
//     if(buttons_2[7] == 0){
//         Serial.print("RIGHT");
//     }
//     if(buttons_2[8] == 0){
//         Serial.print("A");
//     }
//     if(buttons_2[9] == 0){
//         Serial.print("X");
//     }
//     if(buttons_2[10] == 0){
//         Serial.print("LB");
//     }
//     if(buttons_2[11] == 0){
//         Serial.print("RB");
//     }
// }

// void getControllerData_1(void){
//     // Latch for 12us
//     digitalWrite(DATA_LATCH, HIGH);
//     delayMicroseconds(12);
//     digitalWrite(DATA_LATCH, LOW);
//     delayMicroseconds(6);
    
//     // Retrieve button presses from shift register by pulling the clock high for 6us
//     for(int i = 0; i < 16; i++){
//         digitalWrite(DATA_CLOCK, LOW);
//         delayMicroseconds(6);
//         if(i <= 16){
//             buttons_1[i] = digitalRead(DATA_SERIAL_1);
//         }
//         digitalWrite(DATA_CLOCK, HIGH);
//             delayMicroseconds(6);

//     }
//   printButtons_1();  
// }

// void getControllerData_2(void){
//     // Latch for 12us
//     digitalWrite(DATA_LATCH_2, HIGH);
//     delayMicroseconds(12);
//     digitalWrite(DATA_LATCH_2, LOW);
//     delayMicroseconds(6);
    
//     // Retrieve button presses from shift register by pulling the clock high for 6us
//     for(int i = 0; i < 16; i++){
//         digitalWrite(DATA_CLOCK_2, LOW);
//         delayMicroseconds(6);
//         if(i <= 11){
//             buttons_2[i] = digitalRead(DATA_SERIAL_2);
//         }
//         digitalWrite(DATA_CLOCK_2, HIGH);
//             delayMicroseconds(6);

//     }
//   printButtons_2();  
// }