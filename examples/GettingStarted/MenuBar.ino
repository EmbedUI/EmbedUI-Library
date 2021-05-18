/*
   Menu Bar
*/

//We have 6 pages in this UI program
#define MAX_PAGE_INDEX 6

//We will be using this functon to draw the Menu Bar onto the UI, many times.
void showMenuBar()
{
  display.createButton(F("Home"), 16, 110, 91, 66, 41, 0, display.color(16, 162, 174), WHITE, showHomePage, F("HomeButton"));
  display.setFontWeight(F("HomeButton"), 700);
  if (currentMenuIndex < MAX_PAGE_INDEX)
  {
    display.createButton(F("Next >>"), 16, 296, 91, 86, 39, 0, display.color(255, 88, 21),  display.color(250, 236, 196), showNextPage, F("NextButton"));
    display.setFontWeight(F("NextButton"), 700);
  }
  if (currentMenuIndex > 1)
  {
    display.createButton(F("<< Prev"), 16, 210, 91, 86, 39, 0,  display.color(255, 88, 21),  display.color(250, 236, 196), showPrevPage, F("PrevButton"));
    display.setFontWeight(F("PrevButton"), 700);
  }
}

//Function to handle switching to Next page
void showNextPage()
{
  currentMenuIndex++;
  if (currentMenuIndex > MAX_PAGE_INDEX)
  {
    currentMenuIndex = MAX_PAGE_INDEX;
    return;
  }
  switch (currentMenuIndex)
  {
    case 1: {
        showPage1();
      }
      break;
    case 2: {
        showPage2();
      }
      break;
    case 3: {
        showPage3();
      }
      break;
    case 4: {
        showPage4();
      }
      break;
    case 5: {
        showPage5();
      }
      break;
    case 6: {
        showPage6();
      }
      break;
    default: {
      }
  }
}

//Function to handle switching to Prev page
void showPrevPage()
{
  currentMenuIndex--;
  if (currentMenuIndex < 1)
  {
    currentMenuIndex = 1;
    return;
  }
  switch (currentMenuIndex)
  {
    case 1: {
        showPage1();
      }
      break;
    case 2: {
        showPage2();
      }
      break;
    case 3: {
        showPage3();
      }
      break;
    case 4: {
        showPage4();
      }
      break;
    case 5: {
        showPage5();
      }
      break;
    case 6: {
        showPage6();
      }
      break;
    default: {
      }
  }
}
