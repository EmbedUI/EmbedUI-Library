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

/*
   Create a Font Object - Load font from external weblink (Requires Internet Connection)
   Parameters: Link for font(supports Google Fonts),Font Name, Backup Font
*/
Font Roboto("https://fonts.googleapis.com/css2?family=Roboto&display=swap", "Roboto", "sans-serif");
Font OpenSans("https://fonts.googleapis.com/css2?family=Open+Sans&display=swap", "Open Sans", "sans-serif");
Font BebasNeue("https://fonts.googleapis.com/css2?family=Bebas+Neue&display=swap", "Bebas Neue", "cursive");
Font Pacifico("https://fonts.googleapis.com/css2?family=Pacifico&display=swap", "Pacifico", "cursive");
Font ShadowsIntoLight("https://fonts.googleapis.com/css2?family=Shadows+Into+Light&display=swap", "Shadows Into Light", "cursive");
Font Satisfy("https://fonts.googleapis.com/css2?family=Satisfy&display=swap", "Satisfy", "cursive");
Font PTMono("https://fonts.googleapis.com/css2?family=PT+Mono&display=swap", "PT Mono", "monospace");
void setup() {

  display.begin(115200); //initialize the display comunication at 115200 baudrate. Make sure you select the same speed on the application.

  delay(1000); //to settle down things after initialization


  //You need to add fonts to the UI before using them, only once.
  display.addFont(Roboto);
  display.addFont(OpenSans);
  display.addFont(BebasNeue);
  display.addFont(Pacifico);
  display.addFont(ShadowsIntoLight);
  display.addFont(Satisfy);
  display.addFont(PTMono);

  display.clear(); //Clear Screen Contents, if any

  display.setDisplayBackgroundColor(BLACK);//set the background color of the screen

  /*
    Draw Text.
    Parameters: text_string,font_soze(in px),x,y,foreground_color(unit32_t),background_color_enable(bool),background_color(unit32_t),
               padding_x(in px),padding_y(in px),center_align_x(bool),center_align_y(bool), id (String)
  */
  display.createText("Font Demo", MAX_SCREEN_HEIGHT / 10, 0, 100, WHITE, false, 0, 0, 0, true, false, "Title");
  display.createText("You can load multiple fonts from https://fonts.google.com<br>Currently, only Google Fonts are tested<br>You can change the Font for any Text at any point of time :-)", MAX_SCREEN_HEIGHT / 20, 0, 100, WHITE, false, 0, 0, 0, true, true, "Demo Text");
  display.createText("Numerics & Specials: 1234567890~!@#$%^&*()_+-{}:\"<>?,./;'[]", MAX_SCREEN_HEIGHT / 20, 0, MAX_SCREEN_HEIGHT - 100, WHITE, false, 0, 0, 0, true, false, "Demo Text");
  delay(2000);
}

void loop() {

  //loop through all fonts,
  display.setGlobalFont(Roboto);
  delay(2000);
  display.setGlobalFont(OpenSans);
  delay(2000);
  display.setGlobalFont(BebasNeue);
  delay(2000);
  display.setGlobalFont(Pacifico);
  delay(2000);
  display.setGlobalFont(ShadowsIntoLight);
  delay(2000);
  display.setGlobalFont(Satisfy);
  delay(2000);
  display.setGlobalFont(PTMono);
  delay(2000);
}
