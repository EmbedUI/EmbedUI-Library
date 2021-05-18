/*
   Footer Content
*/

//We will be using this functon to draw the footer onto the UI, many times.
void showFooter()
{
  //We'll use the 'F()' macro function to save all the string content in the Flash memory. We need some free RAM to do other tasks

  display.createText(F("External Links:"), 14, 100, 631, display.color(47, 49, 61), false, 0, 0, 0, false, false, F("footerText"));
  display.createText(F("Documentation"), 14, 193, 631, display.color(47, 49, 61), false, 0, 0, 0, false, false, F("docsLink"));
  display.createText("|", 14, 297, 631, display.color(47, 49, 61), false, 0, 0, 0, false, false, "SL1");
  display.createText(F("Library"), 14, 305, 631, display.color(47, 49, 61), false, 0, 0, 0, false, false, F("libLink"));
  display.createText("|", 14, 353, 631, display.color(47, 49, 61), false, 0, 0, 0, false, false, "SL1");
  display.createText(F("GitHub"), 14, 360, 631, display.color(47, 49, 61), false, 0, 0, 0, false, false, F("gitLink"));
  display.createText("|", 14, 409, 631, display.color(47, 49, 61), false, 0, 0, 0, false, false, "SL1");
  display.createText(F("Support"), 14, 415, 631, display.color(47, 49, 61), false, 0, 0, 0, false, false, F("supportLink"));

  //Adding some click events to text elements
  display.addEvent(F("docsLink"), CLICK_EVENT, openDocumentation);
  display.addEvent(F("libLink"), CLICK_EVENT, openLibrary);
  display.addEvent(F("gitLink"), CLICK_EVENT, openGithub);
  display.addEvent(F("supportLink"), CLICK_EVENT, openSupport);
}

//Some functions to trigger external links
void openDocumentation()
{
  display.openExternalLink(F("https://embedui.github.io/documentation"));
}

void openLibrary()
{
  display.openExternalLink(F("https://github.com/EmbedUI/EmbedUI-Library"));
}

void openGithub()
{
  display.openExternalLink(F("https://github.com/EmbedUI"));
}

void openSupport()
{
  display.openExternalLink(F("http://buymeacoffee.com/makervinod"));
}
