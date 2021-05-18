/*
  EmbedUI Hardware Library - https://github.com/EmbedUI/EmbedUI-Library

  EmbedUI Application - https://github.com/EmbedUI/EmbedUI-App
  (Download EmbedUI Application from above link)

  Author: Maker Vinod (https://github.com/makervinod)
  Website: www.makervinod.in
  Created:  15/05/2021

  UI Design: Devednya Vyas (https://devednyav.xyz)

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

  Getting Started Demo

  Simply Upload this Code to your favourite board (having SRAM > 4kB) & get ready for exploring things :-)

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

//Variable to store the Current Page index
int currentMenuIndex = 0;

//Activates Animation on page 4
bool enableAnimation = false;

//some more helper variables
unsigned long startPoint = 0;
int animationStep = -1;

EmbedUI display(Serial); //The Serial port to connect (Currently Supporting Hardware Serial Ports) (Do not use Serial further, if used over here)

void setup() {

  display.begin(115200); //initialize the display comunication at 115200 baudrate. Make sure you select the same speed on the application.

  delay(1000); //to settle down things after initialization

  display.clear(); //Clear Screen Contents, if any

  display.setDisplayBackgroundColor(WHITE);//set the background color of the screen

  //Show home page and wait for events to happen
  showHomePage();
}

void loop()
{
  //Required for listening to UI Events
  display.handleEvents();

  //This one is going to handle our animation in Page4
  animateObjects();
}

//Function to change animations (Transitions needed to be applied to objects, in order to animate them - Check PageContent4.ino for more info)
void animateObjects()
{
  if ((currentMenuIndex == 4) & (enableAnimation == true))
  {
    if ((millis() - startPoint) > 2000)
    {
      animationStep += 1;
      switch (animationStep)
      {
        case 0: {
            display.setSize("ar", 30, 30);
          }
          break;
        case 1: {
            display.setRotation("ar", 360);
          }
          break;
        case 2: {
            display.setSize("ar", 15, 15);
          }
          break;
        case 3: {
            display.updatePosition("ar", 363, 562);
          }
          break;
        case 4: {
            display.setSize("ar", 62, 15);
          }
          break;
        case 5: {
            display.setSize("ar", 15, 15);
            display.updatePosition("ar", 386, 562);
          }
          break;
        case 6: {
            display.setRotation("ar", 0);
            display.updatePosition("ar", 376, 554);
            animationStep = -1;
          }
          break;
      }
      startPoint = millis();
    }
  }
  else
  {
    animationStep = -1;
  }
}