# RC_Car

Building an Arduino powered RC car. Hoping to eventually turn this into more than an RC car at some point (vision? autonomy? camera with gimbal?). Mostly just trying to keep track of files for myself as of now, but feel free to use any of this. CAD is done in Solidworks/Onshape (free option) and most parts are designed to be 3D printed. Code could be a useful reference for PWM control/radio communication.




## Hardware
##### Arduino Uno (2) 
https://store.arduino.cc/usa/arduino-uno-rev3
Note: One Uno used to send the joystick signal, the other is used integrated into the car to receive the signal. A Mini could be used instead to send the signal. 
##### TB6612 H-Bridge Controller (1)
https://learn.adafruit.com/adafruit-tb6612-h-bridge-dc-stepper-motor-driver-breakout?view=all
Note: One channel is set to output a constant ~5.5v for the servos, the other channel is activley controlled to run the driveshaft.
##### NRF24L01 Radio (2)
https://www.amazon.com/MakerFocus-NRF24L01-Transceiver-Antistatic-Compatible/dp/B01IK78PQA/ref=sr_1_4?ie=UTF8&qid=1529520045&sr=8-4&keywords=nrf24l01
##### NRF24L01 5v Adapter Socket (1)
https://www.amazon.com/gp/product/B00NJCB7FS/ref=oh_aui_detailpage_o02_s00?ie=UTF8&psc=1
Note: Only one of these is used on the sender side. The idea is to hopefully imporve the range by working around some power issues associated with using the Uno's 3.3v onboard power. 
##### Joystick (1)
https://www.amazon.com/WGCD-Joystick-Breakout-Controller-Arduino/dp/B01N59MK0U/ref=sr_1_3?s=electronics&ie=UTF8&qid=1529519972&sr=1-3&keywords=arduino+joystick
Note: These joysticks aren't very sensitive. I'll probably look for better ones eventually.
##### 12V 200rpm DC motor (1)
https://www.amazon.com/Greartisan-Electric-Reduction-Eccentric-Diameter/dp/B072R5QSRG/ref=sr_1_cc_3?s=aps&ie=UTF8&qid=1529520089&sr=1-3-catcorr&keywords=12V+dc+motor+200rpm
Note: Could use a higher RPM motor, this is just what I had.
##### 180 deg Servo (2)
https://www.amazon.com/Adafruit-Micro-Servo-Torque-ADA1143/dp/B01BMRDXK8/ref=sr_1_13?s=electronics&ie=UTF8&qid=1529520115&sr=1-13&keywords=adafruit+servo
##### Bevel Gears
https://www.amazon.com/gp/product/B004N62ZGE/ref=oh_aui_detailpage_o05_s00?ie=UTF8&psc=1




