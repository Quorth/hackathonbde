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

int  get_direction_gyro()
{
	double pitch, roll, Xg, Yg, Zg;
	acc.read(&Xg, &Yg, &Zg);

	//Low Pass Filter
	fXg = Xg * alpha + (fXg * (1.0 - alpha));
	fYg = Yg * alpha + (fYg * (1.0 - alpha));
	fZg = Zg * alpha + (fZg * (1.0 - alpha));

	//Roll & Pitch Equations
	roll  = (atan2(-fYg, fZg)*180.0)/M_PI;
	pitch = (atan2(fXg, sqrt(fYg*fYg + fZg*fZg))*180.0)/M_PI;

	//Serial.print(pitch);
	//Serial.print(":");
	//Serial.println(roll);
        if(roll > 21) return map(-1*pitch,80,2,90,180);
        else return map(-1*pitch,80,2,90,0);

}
