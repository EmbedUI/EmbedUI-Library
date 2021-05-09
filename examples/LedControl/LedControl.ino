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
  EmbedUI
  LED Control using EMbedUI Application
  
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

#define LED_BUILTIN 2  //If IDE gives you a LED_BUILTIN Error, Uncomment this and change it to required pin number

bool LED_STATE = false; //We store the state of LED

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  display.begin(115200); //initialize the display comunication at 115200 baudrate. Make sure you select the same speed on the application.

  delay(1000); //to settle down things after initialization

  display.clear(); //Clear Screen Contents, if any

  display.setDisplayBackgroundColor(BLACK);//set the background color of the screen

  /*
    Draw Filled Circle
    Parameters: x,y,radius(in px),fill_color(unit32_t),id (String)
  */
  display.createFilledCircle(  MAX_SCREEN_WIDTH / 2  , MAX_SCREEN_HEIGHT / 2, MAX_SCREEN_HEIGHT / 6, RED, "LedIndicator");

  /*
    Draw Text.
    Parameters: text_string,font_soze(in px),x,y,foreground_color(unit32_t),background_color_enable(bool),background_color(unit32_t),
               padding_x(in px),padding_y(in px),center_align_x(bool),center_align_y(bool), id (String)
  */
  display.createText("LED Control", MAX_SCREEN_HEIGHT / 8, 0, 100, WHITE, false, 0, 0, 0, true, false, "Title");

  /*
    Create Button
    Parameters: button_text(String),text_size(in px),x,y,width,height,border_radius(in px),text_color(unit32_t),background_color(unit32_t),callback_function_name,id (String)
  */
  display.createButton("OFF", 48, MAX_SCREEN_WIDTH / 2 - 80, MAX_SCREEN_HEIGHT - 150, 160, 64, 8, WHITE, SILVER, handle_led, "Switch");

}

void loop() {
  display.handleEvents(); //Required for listening Events from the UI
}

//Handler Function - executes when button is pressed on the UI
void handle_led()
{
  if (LED_STATE == true)
  {
    LED_STATE = false;
    display.setBackgroundColor("LedIndicator", RED);
    display.updateText("Switch", "OFF");
    digitalWrite(LED_BUILTIN, LOW);
  }
  else
  {
    LED_STATE = true;
    display.setBackgroundColor("LedIndicator", GREEN);
    display.updateText("Switch", "ON");
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
