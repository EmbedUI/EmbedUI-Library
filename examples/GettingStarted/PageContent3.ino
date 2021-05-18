/*
   Page 3 - Keywords
*/

//Shows Page 3 Content
void showPage3()
{
  display.clear();
  animationStep = -1;
  currentMenuIndex = 3;
  display.createLine(103, 421, 648, 421, 1, display.color(47, 49, 61) , "L1");
  display.createLine(100, 613, 638, 613, 1, display.color(47, 49, 61) , "L2");
  
  showMenuBar();
  
  display.createText(F("03 Keywords"), 36, 103, 146, display.color(47, 49, 61), false, 0, 0, 0, false, false, F("pageHeading"));
  display.setFontWeight("pageHeading", 500);

  display.createText(F("Keywords are special words used in the library"), 14, 103, 219, display.color(47, 49, 61), false, 0, 0, 0, false, false, F("pageSubHeading"));

  showKeywordDetails(103, 253, "create", F("create is the most used catchword in the library. It is used to draw elements on the screen"), F("eg: createText"));
  showKeywordDetails(296, 253, "clear", F("clear is used to clear the display and remove all the components."), F("eg: clear()"));
  showKeywordDetails(490, 253, "add", F("add keyword is related to actions and triggering functions."), F("eg: addEvent"));
  showKeywordDetails(103, 438, "set", F("set is used to set different parameters which are not provided at the initialization."), F("eg: setOpacity"));
  showKeywordDetails(296, 438, "update", F("update is used to update parameters of pre-created elements."), F("eg: updatePosition"));
  showKeywordDetails(490, 438, "others", F("you'll find some more keywords such as: remove, handle, open"), "");
  
  showFooter();
}

void showKeywordDetails(long x, long y, String textHead, String textDesc, String textFoot)
{
  display.createText(textHead, 20, x, y, display.color(47, 49, 61), false, 0, 0, 0, false, false, "K" + textHead);
  display.createTextBox(textDesc, 14, x, y + 30, 171, 72, display.color(47, 49, 61) , 0, 0 , 0, 0, false, false, "KD" + textHead);
  display.createText(textFoot, 20, x, y + 113, display.color(47, 49, 61), false, 0, 0, 0, false, false, "KE" + textHead);
  display.setFontWeight("K" + textHead , 600);
  display.setTextItalic("KE" + textHead );
}
