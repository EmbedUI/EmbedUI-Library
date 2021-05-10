/*
  EmbedUI Hardware Library - https://github.com/EmbedUI/EmbedUI-Library
  
  EmbedUI Application - https://github.com/EmbedUI/EmbedUI-App
  (Download EmbedUI Application from above link)
  
  Author: Maker Vinod (https://github.com/makervinod)
  Website: www.makervinod.in
  Created:  05/05/2021
  
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

  Create Basic Shapes
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

  display.setDisplayBackgroundColor(RED); //set the background color of the screen
  delay(500);
  display.setDisplayBackgroundColor(GREEN);
  delay(500);
  display.setDisplayBackgroundColor(BLUE);
  delay(500);
  display.setDisplayBackgroundColor(WHITE);

  basicShapesTextDemo(); //run the demo once
}

void loop() {

}

void basicShapesTextDemo()
{
  /*
      Draw Line
      Parameters: x1,y1,x2,y2,line_thickness(in px),line_color(unit32_t),id (String)
  */
  display.createLine(20, MAX_SCREEN_HEIGHT / 2, MAX_SCREEN_WIDTH - 20, MAX_SCREEN_HEIGHT / 2, 4 , NAVY, "HorizontalLine");
  display.createLine(MAX_SCREEN_WIDTH / 2, 20, MAX_SCREEN_WIDTH / 2, MAX_SCREEN_HEIGHT - 20 , 4 , NAVY, "VerticalLine");

  /*
      Draw Outlined Rectangle
      Parameters: x,y,w,h,outline_thickness(in px),outline_color(unit32_t),id (String)
  */
  display.createRect(20, 20, MAX_SCREEN_WIDTH / 2 - 40, MAX_SCREEN_HEIGHT / 2 - 40, 4 , BLACK, "Rectangle1");

  /*
      Draw Filled Rectangle
      Parameters: x,y,w,h,fill_color(unit32_t),id (String)
  */
  display.createFilledRect(MAX_SCREEN_WIDTH / 2 + 20, MAX_SCREEN_HEIGHT / 2 + 20,  MAX_SCREEN_WIDTH / 2 - 40, MAX_SCREEN_HEIGHT / 2 - 40,  TEAL, "Rectangle2");

  /*
      Draw Outlined Round Cornered Rectangle
      Parameters: x,y,w,h,outline_thickness(in px),corner_radius(in px),outline_color(unit32_t),id (String)
  */
  display.createRoundRect( MAX_SCREEN_WIDTH / 2  + 20, 20, MAX_SCREEN_WIDTH / 2 - 40, MAX_SCREEN_HEIGHT / 2 - 40, 4 , 32,  RED, "RoundRectangle1");

  /*
      Draw Filled Round Cornered Rectangle
      Parameters: x,y,w,h,corner_radius(in px),fill_color(unit32_t),id (String)
  */
  display.createFilledRoundRect(20, MAX_SCREEN_HEIGHT / 2 + 20,  MAX_SCREEN_WIDTH / 2 - 40, MAX_SCREEN_HEIGHT / 2 - 40, 32,  BLUE, "RoundRectangle2");

  /*
      Draw Outlined Circle
      Parameters: x,y,radius(in px),outline_thickness(in px),outline_color(unit32_t),id (String)
  */
  display.createCircle( MAX_SCREEN_WIDTH / 4  , MAX_SCREEN_HEIGHT / 4, (MAX_SCREEN_HEIGHT / 3) / 2, 5 , SILVER, "Circle1");

  /*
      Draw Filled Circle
      Parameters: x,y,radius(in px),fill_color(unit32_t),id (String)
  */
  display.createFilledCircle( MAX_SCREEN_WIDTH  - MAX_SCREEN_WIDTH / 4  , MAX_SCREEN_HEIGHT - MAX_SCREEN_HEIGHT / 4,
                              (MAX_SCREEN_HEIGHT / 3) / 2, YELLOW, "Circle2");

  /*
      Draw a outline trinagle.
      Parameters: x1,y1,x2,y2,x3,y3,outline_thickness(in px),outline_color(unit32_t),id (String)
  */
  display.createTriangle( MAX_SCREEN_WIDTH / 8, MAX_SCREEN_HEIGHT - MAX_SCREEN_HEIGHT / 8,
                          MAX_SCREEN_WIDTH / 2 - MAX_SCREEN_WIDTH / 8, MAX_SCREEN_HEIGHT - MAX_SCREEN_HEIGHT / 8,
                          MAX_SCREEN_WIDTH / 4, MAX_SCREEN_HEIGHT / 2 + MAX_SCREEN_HEIGHT / 8, 5,
                          WHITE, "FilledTrinagle");

  /*
      Draw a filled tline trinagle.
      Parameters: x1,y1,x2,y2,x3,y3,fill_color(unit32_t),id (String)
  */
  display.createFilledTriangle(MAX_SCREEN_WIDTH / 2 + MAX_SCREEN_WIDTH / 8, MAX_SCREEN_HEIGHT / 8,
                               MAX_SCREEN_WIDTH - MAX_SCREEN_WIDTH / 8, MAX_SCREEN_HEIGHT / 8,
                               MAX_SCREEN_WIDTH / 2 + MAX_SCREEN_WIDTH / 4, MAX_SCREEN_HEIGHT / 2 - MAX_SCREEN_HEIGHT / 8,
                               PURPLE, "OutlineTrinagle");

  delay(2000);
  display.clear();
  display.setDisplayBackgroundColor(display.color(0, 0, 0));

  /*
       Draw Text.
       Parameters: text_string,font_soze(in px),x,y,foreground_color(unit32_t),background_color_enable(bool),background_color(unit32_t),
                   padding_x(in px),padding_y(in px),center_align_x(bool),center_align_y(bool), id (String)
  */
  display.createText("EmbedUI", MAX_SCREEN_HEIGHT / 30, 10, 10, RED, false, 0, 0, 0, true, true, "String1");
  delay(500);
  display.clear();
  display.createText("EmbedUI", MAX_SCREEN_HEIGHT / 25, 10, 10, GREEN, false, 0, 0, 0, true, true, "String2");
  delay(500);
  display.clear();
  display.createText("EmbedUI", MAX_SCREEN_HEIGHT / 22, 10, 10, BLUE, false, 0, 0, 0, true, true, "String3");
  delay(500);
  display.clear();
  display.createText("EmbedUI", MAX_SCREEN_HEIGHT / 16, 10, 10, YELLOW , false, 0, 0, 0, true, true, "String4");
  delay(500);
  display.clear();
  display.createText("EmbedUI", MAX_SCREEN_HEIGHT / 14, 10, 10, TEAL, false, 0, 0, 0, true, true, "String5");
  delay(500);
  display.clear();
  display.createText("EmbedUI", MAX_SCREEN_HEIGHT / 8, 10, 10, PURPLE, false, 0, 0, 0, true, true, "String6");
  delay(500);
  display.clear();
  display.createText("EmbedUI", MAX_SCREEN_HEIGHT / 5, 10, 10, WHITE , false, 0, 0, 0, true, true, "String7");
  delay(2000);

  //Some extra demos
  random_text_demo();
  random_rect_demo();
  random_circles_demo();

  display.clear();
  display.setDisplayBackgroundColor(display.color(255, 255, 255));
  display.createText("EmbedUI", MAX_SCREEN_HEIGHT / 5, 10, 10, NAVY , false, 0, 0, 0, true, true, "String8");

}

void random_text_demo()
{
  display.clear();
  display.setDisplayBackgroundColor(display.color(0, 0, 0));

  for (int i = 0; i < 1000; i++)
  {
    display.createText(String(millis()), 64, random(0, MAX_SCREEN_WIDTH), random(0, MAX_SCREEN_HEIGHT), display.color(random(50, 255), random(50, 255), random(50, 255)), true,
                       display.color(random(50, 255), random(50, 255), random(50, 255)), 16, 32, false, false, "T" + String(millis()));
  }
  delay(2000);
}

void random_rect_demo()
{
  display.clear();
  display.setDisplayBackgroundColor(display.color(0, 0, 0));
  for (int i = 0; i < 1000; i++)
  {
    display.createRect(random(0, MAX_SCREEN_WIDTH), random(0, MAX_SCREEN_HEIGHT) , random(0, MAX_SCREEN_WIDTH / 2), random(0, MAX_SCREEN_HEIGHT / 2), 3,
                       display.color(random(0, 255), random(0, 255), random(0, 255)), "R" + String(millis()));
  }
  delay(2000);
}

void random_circles_demo()
{
  display.clear();
  display.setDisplayBackgroundColor(display.color(0, 0, 0));
  for (int i = 0; i < 1000; i++)
  {
    display.createCircle(random(0, 1920), random(0, 1080) , random(0, 400), 4, display.color(random(50, 255), random(50, 255), random(50, 255)), "C" + String(millis()));
  }
  delay(2000);
}
