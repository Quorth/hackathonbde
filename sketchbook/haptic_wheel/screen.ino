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

void imprimir_mensaje(int msg){
  lcd.clear();
  switch(msg){
    case 1:
        lcd.setCursor(4,2);
        lcd.print("LOW FUEL LEVEL");
        //delay(3000);
        //lcd.clear();
    break;//llamar vibracion
    case 2:
        lcd.setCursor(0,1);
        lcd.print("PLEASE FASTEN");
        lcd.setCursor(0,2);
        lcd.print("YOUR BELT");
        //delay(2000);
        //lcd.clear();
        break;
    case 3:
        lcd.setCursor(0,1);
        lcd.print("PLEASE REDUCE");
        lcd.setCursor(0,2);
        lcd.print("YOUR SPEED");
        break;
    case 4:
        lcd.setCursor(6,1);
        lcd.print("CAUTION!");
        lcd.setCursor(0,2);
        lcd.print("CORRECT YOUR COURSE");
        lcd.setCursor(3,3);
        lcd.print("<== STEER LEFT");
        break;
    case 5:
        lcd.setCursor(6,1);
        lcd.print("CAUTION!");
        lcd.setCursor(0,2);
        lcd.print("CORRECT YOUR COURSE");
        lcd.setCursor(3,3);
        lcd.print("STEER RIGHT ==>");
        break;
    default:
    break;
    
    }
}

void show_main(){
  lcd.clear();
      lcd.setCursor ( 0, 0 );
      lcd.print ("SPEED:");
      lcd.setCursor ( 11, 0 );
      lcd.print ("km/h");
      lcd.setCursor ( 0, 1 );
      lcd.setCursor ( 0, 3 );
      lcd.print ("FUEL:");  
      
      lcd.setCursor ( 0, 2 );
      lcd.print ("L");
      lcd.setCursor ( 19, 2 );
      lcd.print ("R");
      lcd.setCursor ( 7, 3 );
      
      for(int i=0; i< fuel_level; i++) {
        lcd.print ("|"); 
      }
      lcd.setCursor(map(direction_level,60,120,1,18),2);
      lcd.print('*');
      lcd.setCursor ( 7, 0 );
      lcd.print(speed_level);
      lcd.setCursor ( 0, 1 );
      if(security_belt_status==0){
         lcd.print ("BELT: NOT FASTENED");
      }else{
        lcd.print ("BELT: FASTENED");
       }
      
   delay (500);
  
  }
