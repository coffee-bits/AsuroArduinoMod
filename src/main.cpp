#include <Arduino.h>

/****************************************************************************
 *   This code is distributed in the hope that it will be useful,           *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 ****************************************************************************/

/**
 * @file Asuro.ino
 * @author CJ
 * @date March 2023
 * @brief This sketch will use the Arexx Asuro robot platform. 
 * Instead of the original Atmega8L we make use of an Arduino Nano like board  
 * Inspiration https://github.com/Dirk-/Asurino-Library/blob/master/src/Asuro.cpp
 */


constexpr int ASURO_IR_REC_SFH5110_PIN = 2; // Asuro pin 2
// "IR Diode - SFH 415-U" GND                  // Asuro pin 3
constexpr int ASURO_COLOR_LED_RED_PIN = 7; // Asuro pin 4
constexpr int ASURO_SWITCH_INT_PIN = 3; // Asuro pin 5
constexpr int ASURO_MOTOR1_T12_PIN = 9; // Asuro pin 6
// VCC    // Asuro pin 7
// GND    // Asuro pin 8
// quarz  // Asuro pin 9
// quarz  // Asuro pin 10
constexpr int ASURO_MOTOR1_T34_PIN = 12; // Asuro pin 11
constexpr int ASURO_LINE_LED_PIN = 4; // Asuro pin 12
constexpr int ASURO_LED13_14_POS_PIN = A7; //? Asuro pin 13
constexpr int ASURO_LED15_16_NEG_PIN = A7; //? Asuro pin 13
constexpr int ASURO_COLOR_LED_GREEN_PIN = 8; // Asuro pin 14
// #####
constexpr int ASURO_MOTOR1_PWM_PIN = 6; // Asuro pin 15
constexpr int ASURO_MOTOR2_PWM_PIN = 5; // Asuro pin 16
constexpr int ASURO_IR_TRANSMITTER_PIN = 10; // Asuro pin 17
constexpr int ASURO_MOTOR2_T78_PIN = 13; // Asuro pin 18
constexpr int ASURO_MOTOR2_T56_PIN = 9; // Asuro pin 19
// AVCC    // Asuro pin 20
// AREF    // Asuro pin 21
// AGND    // Asuro pin 22
constexpr int ASURO_PHOTO_T12_PIN = A0; // Asuro pin 23
constexpr int ASURO_LED16_POS_PIN = A0; // Asuro pin 23
constexpr int ASURO_PHOTO_T11_PIN = A1; // Asuro pin 24
constexpr int ASURO_LED15_POS_PIN = A1; // Asuro pin 24
constexpr int ASURO_PHOTO_T10_PIN = A2; // Asuro pin 25
constexpr int ASURO_PHOTO_T9_PIN = A3; // Asuro pin 26
constexpr int ASURO_SWITCHES_PIN = A4; // Asuro pin 27
constexpr int ASURO_DIVIDER_PIN = A5; // Asuro pin 28

/**
 * @brief color LED color
 * 
 */
enum class LED_COLOR_EN{
  LED_COLOR_RED = 0,
  LED_COLOR_GREEN = 1,
  LED_COLOR_YELLOW = 2
};

/**
 * @brief digital state, for example LED on or off
 * 
 */
enum class IO_STATE_EN{
  IO_STATE_ON = 0,
  IO_STATE_OFF = 1,
  IO_STATE_UNDEF = 2
};


enum class LINE_SENSOR_EN{
  LINE_SENSOR_LEFT = 0,
  LINE_SENSOR_RIGHT = 1,
  LINE_SENSOR_BOTH = 2,
  LINE_SENSOR_UNDEF = 3,
};

/**
 * @brief main Arduino setup routine
 * It initializes and test the main Asuro funktions
 * 
 */
void setup() {
  int tempReadTestValue = 0;
  // init serial interface  
  Serial.begin(9600);

  // initial self test of color LED
  // ##############################
   Serial.println("Set Color LED red to output");
   pinMode(ASURO_COLOR_LED_RED_PIN, OUTPUT);
   Serial.println("Set Color LED red to high");
   digitalWrite(ASURO_COLOR_LED_RED_PIN, HIGH);
   delay(1000);                       // wait for a second
   Serial.println("Set Color LED red to low");
   digitalWrite(ASURO_COLOR_LED_RED_PIN, LOW);
   delay(1000);                       // wait for a second
   Serial.println("Set Color LED green to output");
   pinMode(ASURO_COLOR_LED_GREEN_PIN, OUTPUT);
   Serial.println("Set Color LED green to high");
   digitalWrite(ASURO_COLOR_LED_GREEN_PIN, HIGH);
   delay(1000);                       // wait for a second
   Serial.println("Set Color LED green to low");
   digitalWrite(ASURO_COLOR_LED_GREEN_PIN, LOW);
   delay(1000);                       // wait for a second
  // initial self test of line LED and line photo read
  // #################################################
   Serial.println("Set line LED to output");
   pinMode(ASURO_LINE_LED_PIN, OUTPUT);
   Serial.println("Set line LED to high");
   digitalWrite(ASURO_LINE_LED_PIN, HIGH);
   Serial.print("Read Line 1: ");
   tempReadTestValue = analogRead(ASURO_PHOTO_T10_PIN);
   Serial.println(tempReadTestValue);
   Serial.print("Read Line 2: ");
   tempReadTestValue = analogRead(ASURO_PHOTO_T9_PIN);
   Serial.println(tempReadTestValue);
   delay(1000);                       // wait for a second
   digitalWrite(ASURO_LINE_LED_PIN, LOW);
   Serial.print("Read Line 1: ");
   tempReadTestValue = analogRead(ASURO_PHOTO_T10_PIN);
   Serial.println(tempReadTestValue);
   Serial.print("Read Line 2: ");
   tempReadTestValue = analogRead(ASURO_PHOTO_T9_PIN);
   Serial.println(tempReadTestValue);
   delay(1000);

}

/**
 * @brief main Arduino loop
 * it schedules the Asuro tasks
 * 
 */
void loop() {
  // put your main code here, to run repeatedly:

}

/**
 * @brief inits the color LED with red and green and sets the output to low
 * 
 */
void Asuro_initColorLed(void){
 Serial.println("Set Color LED red to output");
   pinMode(ASURO_COLOR_LED_RED_PIN, OUTPUT);
   Serial.println("Set Color LED red to low");
   digitalWrite(ASURO_COLOR_LED_RED_PIN, LOW);
   Serial.println("Set Color LED green to output");
   pinMode(ASURO_COLOR_LED_GREEN_PIN, OUTPUT);
   Serial.println("Set Color LED green to low");
   digitalWrite(ASURO_COLOR_LED_GREEN_PIN, LOW);
}

/**
 * @brief set the color and state (on/off) of the color LED
 * 
 * @param paramLedColor LED_COLOR_RED, LED_COLOR_GREEN, LED_COLOR_YELLOW 
 * @param paramIoState IO_STATE_ON, IO_STATE_OFF
 */
void Asuro_setColorLed(enum LED_COLOR_EN paramLedColor, enum IO_STATE_EN paramIoState){

  switch (paramLedColor){
    case LED_COLOR_EN::LED_COLOR_RED:
    if (IO_STATE_EN::IO_STATE_ON == paramIoState){
      digitalWrite(ASURO_COLOR_LED_RED_PIN, HIGH);
    }
    else{
      digitalWrite(ASURO_COLOR_LED_RED_PIN, LOW);
    }
    break;
  case LED_COLOR_EN::LED_COLOR_GREEN:
    if (IO_STATE_EN::IO_STATE_ON == paramIoState){
      digitalWrite(ASURO_COLOR_LED_GREEN_PIN, HIGH);
    }
    else{
      digitalWrite(ASURO_COLOR_LED_GREEN_PIN, LOW);
    }
    break;
  case LED_COLOR_EN::LED_COLOR_YELLOW:
    if (IO_STATE_EN::IO_STATE_ON == paramIoState){
      digitalWrite(ASURO_COLOR_LED_RED_PIN, HIGH);
      digitalWrite(ASURO_COLOR_LED_GREEN_PIN, HIGH);
    }
    else{
      digitalWrite(ASURO_COLOR_LED_RED_PIN, LOW);
      digitalWrite(ASURO_COLOR_LED_GREEN_PIN, LOW);  
    }
    break;
  default:
    break;
  }
}

/**
 * @brief set line LED
 * 
 * @param paramIoState IO_STATE_ON, IO_STATE_OFF
 */
void Asuro_setLineLed(enum IO_STATE_EN paramIoState){

  if (IO_STATE_EN::IO_STATE_ON == paramIoState){
    digitalWrite(ASURO_LINE_LED_PIN, HIGH);
  }
  else{
    digitalWrite(ASURO_LINE_LED_PIN, LOW);
  }
}



/**
 * @brief reads the line sensor data
 * 
 * @param paramLineSensor LINE_SENSOR_LEFT, LINE_SENSOR_RIGHT, LINE_SENSOR_BOTH
 * @return -1 in case of a parameter error, else sensor data
 */
int Asuro_readLineSensor(enum LINE_SENSOR_EN paramLineSensor){
  int tempReadSensorValue = 0;
  switch (paramLineSensor){
    case LINE_SENSOR_EN::LINE_SENSOR_LEFT:
      tempReadSensorValue = analogRead(ASURO_PHOTO_T10_PIN);
    break;

    case LINE_SENSOR_EN::LINE_SENSOR_RIGHT:
      tempReadSensorValue = analogRead(ASURO_PHOTO_T9_PIN);
    break;

    case LINE_SENSOR_EN::LINE_SENSOR_BOTH:
      tempReadSensorValue = analogRead(ASURO_PHOTO_T9_PIN);
      tempReadSensorValue += analogRead(ASURO_PHOTO_T10_PIN);
      tempReadSensorValue = tempReadSensorValue / 2;
    break;

    default:
      tempReadSensorValue = -1;
    break;  
  }
   
   
  return tempReadSensorValue;
}