/*
   Page 4 - Design Elements
*/

//Shows Page 4 Content
void showPage4()
{

  display.clear();
  animationStep = -1;
  currentMenuIndex = 4;

  //Lines have to be drawn first. If not, they won't allow you to perform click events
  display.createLine(103, 264, 648, 264, 1, display.color(47, 49, 61) , "L1");
  display.createLine(103, 345, 648, 345, 1, display.color(47, 49, 61) , "L2");
  display.createLine(103, 437, 648, 437, 1, display.color(47, 49, 61) , "L3");
  display.createLine(103, 534, 648, 534, 1, display.color(47, 49, 61) , "L4");
  display.createLine(100, 613, 648, 613, 1, display.color(47, 49, 61) , "L5");
  display.createLine(200, 382, 250, 382, 1, display.color(47, 49, 61) , "L6");
  
  showMenuBar();

  display.createText(F("04 Design Elements"), 36, 103, 146, display.color(47, 49, 61), false, 0, 0, 0, false, false, F("pageHeading"));
  display.setFontWeight("pageHeading", 500);
  
  display.createText(F("Currently, the library supports creation of the following elements"), 14, 103, 219, display.color(47, 49, 61), false, 0, 0, 0, false, false, F("pageSubHeading"));

  display.createText(F("Text"), 20, 103, 291, display.color(47, 49, 61), false, 0, 0, 0, false, false, "H1");
  display.createText(F("Shapes"), 20, 103, 379, display.color(47, 49, 61), false, 0, 0, 0, false, false, "H2");
  display.createText(F("Components"), 20, 103, 468, display.color(47, 49, 61), false, 0, 0, 0, false, false, "H3");
  display.createText(F("Interactions"), 20, 103, 560, display.color(47, 49, 61), false, 0, 0, 0, false, false, "H4");
  
  for (int i = 1; i <= 4; i++)
  {
    display.setFontWeight("H" + String(i), 600);
  }

  display.createText(F("Single line text"), 12, 242, 296, display.color(47, 49, 61), false, 0, 0, 0, false, false, "e1");
  display.createTextBox(F("Multi line text box where you can set the width of the box"), 12, 370, 280, 122, 48, display.color(47, 49, 61) , 0, 0 , 0, 0, false, false, "e2");
  display.createText(F("Line"), 12, 210, 406, display.color(47, 49, 61), false, 0, 0, 0, false, false, "e3");
  display.createText(F("Filled/Outlined Circle"), 12, 264, 406, display.color(47, 49, 61), false, 0, 0, 0, false, false, "e4");
  display.createText(F("Filled/Outlined Rectangle"), 12, 404, 406, display.color(47, 49, 61), false, 0, 0, 0, false, false, "e5");
  display.createText(F("Button"), 12, 308, 502, display.color(47, 49, 61), false, 0, 0, 0, false, false, "e6");
  display.createText(F("Image"), 12, 427, 502, display.color(47, 49, 61), false, 0, 0, 0, false, false, "e7");
  display.createText(F("Video"), 12, 535, 502, display.color(47, 49, 61), false, 0, 0, 0, false, false, "e8");
  display.createText(F("Events"), 12, 260, 593, display.color(47, 49, 61), false, 0, 0, 0, false, false, "e9");
  display.createText(F("Animations"), 12, 360, 593, display.color(47, 49, 61), false, 0, 0, 0, false, false, "e10");
  display.createText(F("External Links"), 12, 475, 593, display.color(47, 49, 61), false, 0, 0, 0, false, false, "e11");

  display.createTextBox(F("CLICK, HOVER, MOUSEIN, MOUSEOUT"), 12, 242, 545, 80, 36, display.color(47, 49, 61) , 0, 0 , 0, 0, false, false, "e12");
  display.createText(F("embedui.github.io"), 12, 463, 565, display.color(47, 128, 237), false, 0, 0, 0, false, false, "e13");

  for (int i = 1; i <= 13; i++)
  {
    display.setFontWeight("e" + String(i), 600);
  }

  display.createFilledCircle(298, 379, 19, 0, "c1");
  display.createCircle(350, 379, 19, 1, 0, "c2");
  display.createFilledRect(410, 360, 54, 40, 0, "r1");
  display.createRoundRect(480, 360, 54, 40, 1, 2, 0, "r2");
  display.createButton(F("Enter Now"), 12, 276, 461, 110, 30, 30, WHITE, display.color(47, 49, 61), doNothing , "b1");
  display.createImageFromLink(F("https://embedui.github.io/img/arduino_logo.png"), 426, 454, 38, 38,  "i1");
  display.createVideoFromLink(F("https://embedui.github.io/img/demo_video.mp4"), 511, 449, 80, 48 , false, true, true, true, "v1");

  display.createFilledRect(376, 554, 15, 15, 0, "ar");
  display.setTransition("ar", SOFT_START_END, 1000, 0);

  display.addEvent("e13", CLICK_EVENT, openLink);
  showFooter();

  enableAnimation = true;
}

//Yes that's an empty function !!!
void doNothing()
{
}

//Open External Link 
void openLink()
{
  display.openExternalLink("https://embedui.github.io");
}
