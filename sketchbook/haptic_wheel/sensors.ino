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

void update_sensors(){
  update_fuel_level();
  update_security_belt();
  update_speed();
  update_direction();
}

void update_security_belt(){
  security_belt_status = digitalRead(PIN_SECURITY_BELT);
  if(security_belt_status == LOW){ 
    security_belt_notify();
    delay(500);
  }
}

void security_belt_notify(){
  if(millis()-security_belt_last_checked > SECURITY_BELT_TIMEOUT){
    security_belt_last_checked = millis();
    imprimir_mensaje(2);
    security_belt_feedback();
    delay(500);
  }
}

void update_fuel_level(){
  fuel_level = analogRead(PIN_FUEL);
  fuel_level = map(fuel_level,0,1023,0,10);
  if(fuel_level <= 3) fuel_level_notify();
}

void fuel_level_notify(){
    if(millis()-fuel_level_last_checked > FUEL_LEVEL_TIMEOUT){
    fuel_level_last_checked = millis();
    imprimir_mensaje(1);
    fuel_level_feedback();
    delay(300);
  }
}

void update_speed(){
  speed_level = analogRead(PIN_SPEED);
  speed_level = map(speed_level,0,1023,0,70);
  if(speed_level > 50) speed_level_notify();
}

void speed_level_notify(){
    if(millis()-speed_level_last_checked > SPEED_LEVEL_TIMEOUT){
    speed_level_last_checked = millis();
    imprimir_mensaje(3);
    speed_level_feedback();
    delay(300);
  }
}

void update_direction(){
  direction_level = get_direction_gyro();
  if(direction_level > 120 || direction_level < 60) direction_level_notify(direction_level);
}

void direction_level_notify(int direction_level){
  if(direction_level > 120){
    imprimir_mensaje(5);
  }
  else{
    imprimir_mensaje(4);
  }
  direction_level_feedback(direction_level);
}


