/**********************************************************************
    This file is part of Haptic Wheel
    
    Created by Boba Fett Team for
    Hackathon for a Better Driving Experience
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
   
************************************************************************/

/***********************************************************************/
//DECLARATIONS
/***********************************************************************/
//FEEDBACK
/***********************************************************************/
#define PWM_LEVEL_HIGH 200
#define PWM_LEVEL_MEDIUM 120
#define PWM_LEVEL_NONE 0
#define PIN_LEFT_ENGINE 6
#define PIN_RIGHT_ENGINE 5
/***********************************************************************/
//GYRO
/***********************************************************************/
#include <ADXL345.h>
const float alpha = 0.5;
double fXg = 0;
double fYg = 0;
double fZg = 0;
ADXL345 acc;
int steering_wheel_position_reading=0;
/***********************************************************************/
//SCREEN
/***********************************************************************/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define BACKLIGHT_PIN     3
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, BACKLIGHT_PIN, POSITIVE);  // Set the LCD I2C address
/***********************************************************************/
//SECURITY BELT
/***********************************************************************/
#define PIN_SECURITY_BELT 8
#define SECURITY_BELT_TIMEOUT 5000
int security_belt_status = 0;
long security_belt_last_checked = 0;
/***********************************************************************/
//SENSORS
/***********************************************************************/
#define PIN_FUEL 14
#define FUEL_LEVEL_TIMEOUT 5000
#define FUEL_LEVEL_MIN 50
long fuel_level_last_checked = 0;
int fuel_level = 0;

#define PIN_SPEED 15
#define SPEED_LEVEL_TIMEOUT 5000
int speed_level = 0;
long speed_level_last_checked = 0;

int direction_level = 90;
/****************************************************/

void setup() {

  acc.begin();
  
  pinMode(PIN_LEFT_ENGINE,OUTPUT);
  pinMode(PIN_RIGHT_ENGINE,OUTPUT);
  pinMode(PIN_SECURITY_BELT,INPUT);
  digitalWrite(PIN_SECURITY_BELT,HIGH); //Activate pull-up resistor on PIN_SECURITY_BELT
  
  Serial.begin(9600);
  
  pinMode (BACKLIGHT_PIN, OUTPUT);
  digitalWrite (BACKLIGHT_PIN, HIGH);

  
  lcd.begin(20,4);               
  lcd.home ();                   
  lcd.print("** HELLO HACKERS! **");  
  lcd.setCursor ( 2, 1 );
  lcd.print (" Let's hack!  ");
  delay (1000);
}

void loop() {
  lcd.home();
  update_sensors();
  show_main();
}


 
