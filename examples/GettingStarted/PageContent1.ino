/*
   Page 1 - How it works
*/

//Shows Page 1 Content
void showPage1()
{
  display.clear();
  animationStep = -1;
  currentMenuIndex = 1;

  //Lines have to be drawn first. If not, they won't allow you to perform click events
  display.createLine(100, 419, 638, 419, 1, display.color(47, 49, 61) , "L1");
  display.createLine(438, 528, 645, 528, 1, display.color(47, 49, 61) , "L2");
  display.createLine(100, 613, 638, 613, 1, display.color(47, 49, 61) , "L3");

  showMenuBar();

  display.createText(F("01 How it works"), 36, 103, 146, display.color(47, 49, 61), false, 0, 0, 0, false, false, F("pageHeading"));
  display.setFontWeight("pageHeading", 500);

  display.createText("Library", 24, 103, 217, display.color(47, 49, 61), false, 0, 0, 0, false, false, "T1");
  display.setFontWeight("T1", 500);

  display.createText(F("Send commands from embedded board via serial data."), 14, 103, 255, display.color(47, 49, 61), false, 0, 0, 0, false, false, "T2");
  display.setFontWeight("T2", 500);

  display.createText(">>", 24, 103, 289, display.color(47, 49, 61), false, 0, 0, 0, false, false, "A1");
  display.setRotation("A1", -90);
  display.createText(">>", 24, 132, 289, display.color(47, 49, 61), false, 0, 0, 0, false, false, "A2");
  display.setRotation("A2", 90);

  display.createText("Serial Communication", 14, 174, 293, display.color(16, 162, 174), false, 0, 0, 0, false, false, "ST");

  display.createText("Application", 24, 103, 331, display.color(47, 49, 61), false, 0, 0, 0, false, false, "T3");
  display.setFontWeight("T3", 500);

  display.createText(F("Decodes commands and draw elements on the display."), 14, 103, 371, display.color(47, 49, 61), false, 0, 0, 0, false, false, "T4");

  display.createText(F("Important**"), 14, 100, 431, display.color(47, 49, 61), false, 0, 0, 0, false, false, "T5");
  display.setFontWeight("T5", 600);

  display.createTextBox(F("This library and Application requires a desktop/PC screen and can not be run on standalone display"), 20, 100, 462, 312, 130, display.color(47, 49, 61) , true, display.color(254, 190, 19) , 10, 10, false, false, "TB4");
  display.setFontWeight("TB4", 600);

  display.createTextBox(F("Boards having atleast 4 kB of SRAM are preferred for error-free operation"), 14, 438, 462, 183, 54, display.color(47, 49, 61) , false, 0 , 0, 0, false, false, "TB5");
  display.setFontWeight("TB5", 600);

  display.createTextBox(F("1024x768 Minimum resolution screens preferred"), 14, 438, 538, 205, 36, display.color(47, 49, 61) , false, 0 , 0, 0, false, false, "TB6");
  display.setFontWeight("TB6", 600);
  
  showFooter();
}
