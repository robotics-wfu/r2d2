# r2d2

Parts and documentation
-
- L298N Motor Driver: 
https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/
- MS18 servo: (datasheet for a slightly different part) https://www.ecs.csun.edu/~smirzaei/docs/ece425/sg90_datasheet.pdf
- ESP32 safe pins: https://randomnerdtutorials.com/esp32-pinout-reference-gpios/
- Level shifter: (datasheet for a slightly different part) https://media.digikey.com/pdf/Data%20Sheets/Sparkfun%20PDFs/Bi-Directional-Logic-Level_HookupGuide.pdf
- CN3903 step down converter / buck converter
- NewPing ultrasonic library for Arduino: https://docs.arduino.cc/libraries/newping/
- Possible RC remote and receiver: https://dronebotworkshop.com/radio-control-arduino-car/

Setting up Arduino IDE and the ESP32 board, running the file downloaded from Github
- 
- Download the arduino ide - it is needed to flash the microcontrollers https://www.arduino.cc/en/software/
- with the ide open, go to the boards manager - it is the second icon down on the panel to the left
- download the "esp32" boards by Espressif Systems - the latest version is good, but this is where you can change the version should you ever need to
- go to the board selection menu - select the white drop down menu from the menu bar at the top of the ide
- use board "ESP32 Dev Module", and select the port you have the ESP32 plugged into
- you can deploy your code using the arrow (upload button) in the top menu bar now!
- you can also use the check mark button (verify button) to compile your code without running it for syntax errors. ESP32 has a stricter compiler than some other boards, like the arduino nano.
- to run the R2D2 project, (for mac) I go to where I downloaded this repo (for me, Documents > GitHub > R2D2) and open the R2D2.ino file using the system default, which is the Arduino ide. Then I can edit and deploy the project.

Installing libraries 
- 
- I included the NewPing library for reading ultrasonic sensors, it doesnt do anything yet but you may get compile errors if you don't have it downloaded
- to download the library, go to the library manager - it is the third icon down in the panel to the left
- search "NewPing"
- install the latest version
- (for me, on mac) Arduino keeps all of its files in a folder in my Documents folder called Arduino - any library you install will show up in Arduino > libraries - which means you can read the source code if you want!

Using the Serial Interface
- 
- once you have uploaded code to your board, you can write and receive serial data (basically writing to/reading from the console)
- make sure ESP32 Dev Module and the correct serial port for your board are selected in the board selection menu - the white drop down menu should have bold text if the ESP32 is plugged in and selected
- open the serial monitor, the rightmost button on the top menu bar
- there should be two drop down menu boxes to the top right of the serial monitor window that just opened
- the first says "No line ending" - this is fine, you shouldn't need to change it
- the next says "9600 baud" - open this and change it to "115200 baud"
- Note: the baud rate on the ESP32 in the Serial.begin(115200) method - it has to be the same on both sides. The baud rate is how fast the serial data is being sent - data won't make sense on either side if both sides are not reading at the same rate. Super fun stuff, more info here: https://docs.arduino.cc/learn/communication/uart/
- on that note, if you are getting a bunch of random symbols on your serial output, check your baud rates. 
- To send a message, type the message into the bar at the top of the serial monitor and hit enter.
