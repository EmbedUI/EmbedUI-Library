/*
  EmbedUI Hardware Library - https://github.com/EmbedUI/EmbedUI-Library

  EmbedUI Application - https://github.com/EmbedUI/EmbedUI-App
  (Download EmbedUI Application from above link)

  Author: Maker Vinod (https://github.com/makervinod)
  Website: www.makervinod.in
  Created:  10/05/2021

  This software is licensed under MIT License

  Copyright (c) 2021 EmbedUI

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  Transitions Demo

*/

#include <EmbedUI.h>

#define WHITE display.color(255,255,255)
#define RED display.color(255,0,0)
#define GREEN display.color(0,255,0)
#define BLUE display.color(0,0,255)
#define BLACK display.color(0,0,0)
#define YELLOW display.color(255,255,0)
#define TEAL display.color(0,128,128)
#define NAVY display.color(0,0,128)
#define PURPLE display.color(128,0,128)
#define MAROON display.color(128,0,0)
#define AQUA  display.color(255,255,0)
#define OLIVE  display.color(128,128,0)
#define SILVER display.color(192,192,192)

//Don't forget to set your screen resolution here !!!

#define MAX_SCREEN_WIDTH 1920
#define MAX_SCREEN_HEIGHT 1080

EmbedUI display(Serial); //The Serial port to connect (Currently Supporting Hardware Serial Ports) (Do not use Serial if used over here)

void setup() {

  display.begin(115200); //initialize the display comunication at 115200 baudrate. Make sure you select the same speed on the application.

  delay(1000); //to settle down things after initialization

  display.clear(); //Clear Screen Contents, if any

  display.setDisplayBackgroundColor(BLACK);//set the background color of the screen

  //Load some info text
  display.createText("LINEAR", MAX_SCREEN_HEIGHT / 20, 0, MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16 + MAX_SCREEN_HEIGHT / 40, WHITE, false, 0, 0, 0, true, false, "textLinear");
  display.createText("SOFT", MAX_SCREEN_HEIGHT / 20, 0, 2 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16 + MAX_SCREEN_HEIGHT / 40, WHITE, false, 0, 0, 0, true, false, "textLinear");
  display.createText("SOFT_START", MAX_SCREEN_HEIGHT / 20, 0, 3 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16 + MAX_SCREEN_HEIGHT / 40, WHITE, false, 0, 0, 0, true, false, "textLinear");
  display.createText("SOFT_END", MAX_SCREEN_HEIGHT / 20, 0, 4 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16 + MAX_SCREEN_HEIGHT / 40, WHITE, false, 0, 0, 0, true, false, "textLinear");
  display.createText("SOFT_START_END", MAX_SCREEN_HEIGHT / 20, 0, 5 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16 + MAX_SCREEN_HEIGHT / 40, WHITE, false, 0, 0, 0, true, false, "textLinear");

  //Load some images
  display.createImageFromLink("https://embedui.github.io/img/arduino_logo.png", MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16, MAX_SCREEN_HEIGHT / 8, MAX_SCREEN_HEIGHT / 8, "ArduinoLogo1");
  display.createImageFromLink("https://embedui.github.io/img/arduino_logo.png", MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, 2 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16, MAX_SCREEN_HEIGHT / 8, MAX_SCREEN_HEIGHT / 8, "ArduinoLogo2");
  display.createImageFromLink("https://embedui.github.io/img/arduino_logo.png", MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, 3 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16, MAX_SCREEN_HEIGHT / 8, MAX_SCREEN_HEIGHT / 8, "ArduinoLogo3");
  display.createImageFromLink("https://embedui.github.io/img/arduino_logo.png", MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, 4 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16, MAX_SCREEN_HEIGHT / 8, MAX_SCREEN_HEIGHT / 8, "ArduinoLogo4");
  display.createImageFromLink("https://embedui.github.io/img/arduino_logo.png", MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, 5 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16, MAX_SCREEN_HEIGHT / 8, MAX_SCREEN_HEIGHT / 8, "ArduinoLogo5");

  delay(2000); //Optional. Alter this as per your network speed

  //Load transitions
  /*
    Set Transitions for Movements.
    Parameters: id(String), transition_type, transition_time(milliseconds), transition_delay(milliseconds)
  */
  display.setTransition("ArduinoLogo1", LINEAR, 2000, 0);
  display.setTransition("ArduinoLogo2", SOFT, 2000, 0);
  display.setTransition("ArduinoLogo3", SOFT_START, 2000, 0);
  display.setTransition("ArduinoLogo4", SOFT_END, 2000, 0);
  display.setTransition("ArduinoLogo5", SOFT_START_END, 2000, 0);

}

void loop()
{
  //Move to new positions
  display.updatePosition("ArduinoLogo1", MAX_SCREEN_WIDTH - MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16);
  display.updatePosition("ArduinoLogo2", MAX_SCREEN_WIDTH - MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, 2 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16);
  display.updatePosition("ArduinoLogo3", MAX_SCREEN_WIDTH - MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, 3 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16);
  display.updatePosition("ArduinoLogo4", MAX_SCREEN_WIDTH - MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, 4 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16);
  display.updatePosition("ArduinoLogo5", MAX_SCREEN_WIDTH - MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, 5 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16);
  delay(3000);

  //Return back
  display.updatePosition("ArduinoLogo1",  MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16);
  display.updatePosition("ArduinoLogo2",  MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, 2 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16);
  display.updatePosition("ArduinoLogo3",  MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, 3 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16);
  display.updatePosition("ArduinoLogo4",  MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, 4 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16);
  display.updatePosition("ArduinoLogo5",  MAX_SCREEN_WIDTH / 10 - MAX_SCREEN_HEIGHT / 16, 5 * MAX_SCREEN_HEIGHT / 6 -  MAX_SCREEN_HEIGHT / 16);
  delay(3000);
}
