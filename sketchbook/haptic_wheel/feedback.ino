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

void fuel_level_feedback(){
   for(int i=0; i<2; i++){
     analogWrite(PIN_LEFT_ENGINE,PWM_LEVEL_HIGH);
     analogWrite(PIN_RIGHT_ENGINE,PWM_LEVEL_HIGH);
     delay(300);
     analogWrite(PIN_LEFT_ENGINE,0);
     analogWrite(PIN_RIGHT_ENGINE,0);
     delay(300);
   }
   
 }
 void security_belt_feedback(){
     analogWrite(PIN_LEFT_ENGINE,PWM_LEVEL_HIGH);
     analogWrite(PIN_RIGHT_ENGINE,PWM_LEVEL_HIGH);
     delay(300);
     analogWrite(PIN_LEFT_ENGINE,0);
     analogWrite(PIN_RIGHT_ENGINE,0);
   
 }
 
 void speed_level_feedback(){
   for(int i=0; i< PWM_LEVEL_HIGH; i++){
     analogWrite(PIN_LEFT_ENGINE,i);
     analogWrite(PIN_RIGHT_ENGINE,i);
     delay(5);
   }
     delay(400);
     analogWrite(PIN_LEFT_ENGINE,0);
     analogWrite(PIN_RIGHT_ENGINE,0);
   
 }
 
  void direction_level_feedback(int direction_level){
   int power;
   if(direction_level > 120){
     power = map(direction_level,120,180,150,PWM_LEVEL_HIGH);
     analogWrite(PIN_RIGHT_ENGINE,power);
     delay(2000);
     analogWrite(PIN_RIGHT_ENGINE,0);
   }
   else{
     power = map(direction_level,60,0,150,PWM_LEVEL_HIGH);
     analogWrite(PIN_LEFT_ENGINE,power);
     delay(2000);
     analogWrite(PIN_LEFT_ENGINE,0);
   }
   
 }
