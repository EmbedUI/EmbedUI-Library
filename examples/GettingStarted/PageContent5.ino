/*
   Page 5 - Positioning & Sizing
*/

//You can define a String as a constant to use it later. Remember you cannot edit constant after you initialize them. 
//Use them for Really Longer Strings

//You can mix & use some HTML tags too..
#define longText F("Positioning and sizing are two important aspects for UI. For single screen layout static values work well.<br><br>Considering a bigger system which can supporting multiple screens, text sizes and element positioning values can be given in relation with screen width and height.")

//Shows Page 5 Content
void showPage5()
{
  display.clear();
  animationStep = -1;
  currentMenuIndex = 5;
  display.createLine(170, 0, 170, 450, 1, display.color(47, 49, 61) , "L1");
  display.createLine(0, 450, 170, 450, 1, display.color(47, 49, 61) , "L2");
  display.createLine(270, 0, 270, 520, 1, display.color(255, 0, 0) , "L3");
  display.createLine(0, 520, 270, 520, 1, display.color(255, 0, 0) , "L4");
  display.createLine(100, 613, 648, 613, 1, display.color(47, 49, 61) , "L5");

  showMenuBar();

  display.createText(F("05 Positioning & Sizing"), 36, 103, 146, display.color(47, 49, 61), false, 0, 0, 0, false, false, F("pageHeading"));
  display.setFontWeight("pageHeading", 500);

  display.createFilledRect(170, 450, 34, 34, display.color(47, 49, 61), "r1");
  display.createFilledRect(270, 520, 34, 34, display.color(255, 0, 0), "r2");

  display.createTextBox(F("Static Values"), 14, 103, 405, 44, 36, display.color(47, 49, 61) , 0, 0 , 0, 0, false, false, "t1");
  display.createText(F("X = 170"), 14, 103, 455, display.color(47, 49, 61), false, 0, 0, 0, false, false, "t2");
  display.createText(F("Y = 450"), 14, 165, 362, display.color(47, 49, 61), false, 0, 0, 0, false, false, "t3");
  display.setRotation("t3", -90);

  display.createTextBox(F("Dynamic Values"), 14, 208, 480, 44, 36, display.color(47, 49, 61) , 0, 0 , 0, 0, false, false, "t4");
  display.createText(F("X = MAX_WIDTH / x"), 14, 127, 529, display.color(47, 49, 61), false, 0, 0, 0, false, false, "t5");
  display.createText(F("Y = MAX_HEIGHT / y"), 14, 225, 375, display.color(47, 49, 61), false, 0, 0, 0, false, false, "t6");
  display.setRotation("t6", -90);

  //using our longText variable over here
  display.createTextBox(longText, 14, 326, 358, 282, 144, display.color(47, 49, 61) , 0, 0 , 0, 0, false, false, "tb1");

  display.createText(F("Static value"), 14, 326, 227, display.color(47, 49, 61), false, 0, 0, 0, false, false, "t7");
  display.createText(F("20px Font"), 20, 326, 247, display.color(47, 49, 61), false, 0, 0, 0, false, false, "t8");

  display.createText(F("Dynamic value"), 14, 326, 289, display.color(47, 49, 61), false, 0, 0, 0, false, false, "t9");
  display.createText(F("MAX_WIDTH/x Font"), 20, 326, 309, display.color(47, 49, 61), false, 0, 0, 0, false, false, "t10");

  display.setFontWeight("t8" , 600);
  display.setFontWeight("t10", 600);

  display.createText(F("*This might not work if screen size is not set properly"), 12, 103, 566, display.color(47, 49, 61), true, display.color(254, 190, 19), 10, 10, false, false, "Note");
  
  showFooter();
}
