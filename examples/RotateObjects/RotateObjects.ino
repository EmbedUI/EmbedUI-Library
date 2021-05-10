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

  Multiple Fonts Demo

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

  //Load an Image on the UI in the center of the screen from an external link
  /*
     Create Image.
     Parameters: external_image_link(String), x, y, w, h, id(String)
  */
  display.createImageFromLink("https://embedui.github.io/img/arduino_logo.png", MAX_SCREEN_WIDTH / 2 - MAX_SCREEN_HEIGHT / 4,
                              MAX_SCREEN_HEIGHT / 2 - MAX_SCREEN_HEIGHT / 4, MAX_SCREEN_HEIGHT / 2, MAX_SCREEN_HEIGHT / 2, "ArduinoLogo");

  delay(1000); //Optional. Alter this as per your network speed
}

void loop() {

  //Lets's Rotate it
  rotate_object();

}

//Rotation plan - 2 times > 360 degress & 2 times > 90 to -90
void rotate_object()
{
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 360; j++)
    {
      //Rotate the specified object
      /*
        Rotate Object.
        Parameters: object_id(String), rotation(degrees)
      */
      display.setRotation("ArduinoLogo", j);
      delay(10);
    }
  }
  delay(1000);
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 90; j++)
    {
      display.setRotation("ArduinoLogo", j);
      delay(10);
    }
    for (int j = 90; j >= 0; j--)
    {
      display.setRotation("ArduinoLogo", j);
      delay(10);
    }
    for (int j = 0; j >= -90; j--)
    {
      display.setRotation("ArduinoLogo", j);
      delay(10);
    }
    for (int j = -90; j < 0; j++)
    {
      display.setRotation("ArduinoLogo", j);
      delay(10);
    }
  }
  delay(1000);
}
