/*
   Page 6 - Use Cases
*/

//Shows Page 6 Content
void showPage6()
{
  display.clear();
  animationStep = -1;
  currentMenuIndex = 6;
  display.createLine(100, 613, 648, 613, 1, display.color(47, 49, 61) , "L1");

  showMenuBar();

  display.createText(F("06 Use Cases"), 36, 103, 146, display.color(47, 49, 61), false, 0, 0, 0, false, false, F("pageHeading"));
  display.setFontWeight("pageHeading", 500);

  display.createVideoFromLink(F("https://embedui.github.io/img/demo_arduino.mp4"), 103, 235, 238, 150, false, true, true, true, "v3");
  display.createVideoFromLink(F("https://embedui.github.io/img/demo_video.mp4"), 354, 235, 238, 150, false, true, true, true, "v2");
  display.createImageFromLink(F("https://embedui.github.io/img/dashboard.jpeg"), 103, 405, 238, 150,  "i1");

  display.createText(F("Feedback"), 46, 360, 410, display.color(47, 49, 61), false, 0, 0, 0, false, false, "t1");
  display.setFontWeight("t1", 600);
  display.createTextBox(F("Help us with your valuable inputs to improve the system."), 14, 359, 477, 282, 144, display.color(47, 49, 61) , 0, 0 , 0, 0, false, false, "tb1");

  showFooter();

  display.addEvent("t1", CLICK_EVENT, openFeedbackLink);
  display.addEvent("tb1", CLICK_EVENT, openFeedbackLink);
}


void openFeedbackLink()
{
  display.openExternalLink("https://forms.gle/pKnn2WLezbUwzjPB6");
}
