/*
   Home Page
*/

void showHomePage()
{
  display.clear();
  currentMenuIndex = 0;
  display.createFilledCircle(479, 265, 165, display.color(245, 216, 137), F("BgCircle1"));
  display.setOpacity(F("BgCircle1"), 50);
  display.createFilledCircle(566, 424, 165, display.color(116, 232, 173), F("BgCircle2"));
  display.setOpacity(F("BgCircle2"), 50);

  display.createText(F("Basics"), 64, 90, 121, display.color(0, 0, 0), false, 0, 0, 0, false, false, F("TextBasics"));
  display.setFontWeight(F("TextBasics"), 500);

  //You can use some HTML tags too..
  display.createText(F("01 &nbsp;How it works"), 24, 90, 224, display.color(0, 0, 0), false, 0, 0, 0, false, false, F("pageHeading1"));
  display.createText(F("02 Getting Started"), 24, 90, 265, display.color(0, 0, 0), false, 0, 0, 0, false, false, F("pageHeading2"));
  display.createText(F("03 Keywords"), 24, 90, 306, display.color(0, 0, 0), false, 0, 0, 0, false, false, F("pageHeading3"));
  display.createText(F("04 Design Elements"), 24, 90, 345, display.color(0, 0, 0), false, 0, 0, 0, false, false, F("pageHeading4"));
  display.createText(F("05 Positioning & Sizing"), 24, 90, 384, display.color(0, 0, 0), false, 0, 0, 0, false, false, F("pageHeading5"));
  display.createText(F("06 Use Cases"), 24, 90, 423, display.color(0, 0, 0), false, 0, 0, 0, false, false, F("pageHeading6"));

  for (int i = 1; i < 7; i++)
  {
    display.addUnderline("pageHeading" + String(i), 0);
  }

  display.createButton(F("Enter Now"), 18, 90, 495, 168, 43, 44, WHITE, display.color(47, 49, 61), showPage1, F("EnterButton"));

  display.addEvent(F("pageHeading1"), CLICK_EVENT, showPage1);
  display.addEvent(F("pageHeading2"), CLICK_EVENT, showPage2);
  display.addEvent(F("pageHeading3"), CLICK_EVENT, showPage3);
  display.addEvent(F("pageHeading4"), CLICK_EVENT, showPage4);
  display.addEvent(F("pageHeading5"), CLICK_EVENT, showPage5);
  display.addEvent(F("pageHeading6"), CLICK_EVENT, showPage6);


}
