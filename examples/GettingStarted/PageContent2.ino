/*
   Page 2 - Getting Started
*/

//Shows Page 2 Content
void showPage2()
{

  display.clear();
  animationStep = -1;
  currentMenuIndex = 2;
  display.createLine(115, 240, 115, 540, 1, display.color(47, 49, 61) , "L1");
  display.createLine(100, 613, 638, 613, 1, display.color(47, 49, 61) , "L2");

  showMenuBar();

  display.createText(F("02 Getting Started"), 36, 103, 146, display.color(47, 49, 61), false, 0, 0, 0, false, false, F("pageHeading"));
  display.setFontWeight("pageHeading", 500);

  //You can mix & use some HTML tags too >>  &nbsp; adds an extra space to the text
  display.createText(F("01 &nbsp;Set Screen Resolution"), 20, 95, 221, display.color(47, 49, 61), true, display.color(255, 255, 255), 0, 10, false, false, "T1");
  display.createText(F("02  Create an Instance of Main Class"), 20, 95, 284, display.color(47, 49, 61), true, display.color(255, 255, 255), 0, 10, false, false, "T2");
  display.createText(F("03  Begin Serial communication"), 20, 95, 347, display.color(47, 49, 61), true, display.color(255, 255, 255), 0, 10, false, false, "T3");
  display.createText(F("04  Upload code"), 20, 95, 410, display.color(47, 49, 61), true, display.color(255, 255, 255), 0, 10, false, false, "T4");
  display.createText(F("05  Configure App"), 20, 95, 476, display.color(47, 49, 61), true, display.color(255, 255, 255), 0, 10, false, false, "T5");
  display.createText(F("06  View output on the display"), 20, 95, 537, display.color(47, 49, 61), true, display.color(255, 255, 255), 0, 10, false, false, "T6");

  for (int i = 1; i <= 6; i++)
  {
    display.setFontWeight("T" + String(i), 600); //Make them bold. Auto - ID manipulation
  }

  display.createText(F("set max width and max height."), 14, 135, 248, display.color(47, 49, 61), false, display.color(255, 255, 255), 0, 0, false, false, "ST1");

  //You can mix & use some HTML tags too.. <string> - use to make text bold. Use it your way
  display.createText(F("<strong>display</strong> is used as an instance in all examples."), 14, 135, 311, display.color(47, 49, 61), false, display.color(255, 255, 255), 0, 0, false, false, "ST2");
  display.createText(F("choose baud rate as per your choice."), 14, 135, 374, display.color(47, 49, 61), false, display.color(255, 255, 255), 0, 0, false, false, "ST3");
  display.createText(F("wait till it uploads."), 14, 135, 437, display.color(47, 49, 61), false, display.color(255, 255, 255), 0, 0, false, false, "ST4");
  display.createText(F("select com port and baud rate. press connect to start"), 14, 135, 503, display.color(47, 49, 61), false, display.color(255, 255, 255), 0, 0, false, false, "ST5");
  display.createText(F("that's all !! "), 14, 135, 565, display.color(47, 49, 61), false, display.color(255, 255, 255), 0, 0, false, false, "ST6");

  showFooter();
}
