
/*
  EmbedUI Hardware Library - https://github.com/EmbedUI/EmbedUI-Library

  EmbedUI Application - https://github.com/EmbedUI/EmbedUI-App
  (Download EmbedUI Application from above link)

  Author: Maker Vinod (https://github.com/makervinod)
  Website: www.makervinod.in
  Created:  15/05/2021

  UI Design: Devednya Vyas 
  Website: https://devednyav.xyz

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

  Weather Dashboard

  This code works with ESP8266 & ESP32 only.
  This codes uses the ArduinoJson Library. You can get it from here: https://github.com/bblanchon/ArduinoJson
  
*/

#include <EmbedUI.h>
#include <ArduinoJson.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#elif defined(ESP32)
#include <WiFi.h>
#include <HTTPClient.h>
#else
#error "Only ESP32 & ESP8266 are supported"
#endif

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



#define HALF_SCREEN_WIDTH MAX_SCREEN_WIDTH/2
#define HALF_SCREEN_HEIGHT MAX_SCREEN_HEIGHT/2

#define CARD_COLOR_DAY display.color(255, 255, 255)
#define BACKGROUND_COLOR_DAY display.color(157, 157, 157)
#define TEXT_COLOR_DAY BLACK

#define CARD_COLOR_NIGHT display.color(23, 27, 50)
#define BACKGROUND_COLOR_NIGHT display.color(15, 17, 30)
#define TEXT_COLOR_NIGHT WHITE

#define STATUS_LED 2 //this wil show the status //change it according to your board
#define DAY 1
#define NIGHT 2


#define WIFI_SSID "*************"  //your wifi ssid  (Important)
#define WIFI_PASSWORD "**********"     //your password  (Important)

//Specify your loaction (Important)
#define CITY "Mumbai"

// Register & Get your API Key from https://openweathermap.org (Important)
#define API_KEY "********************************"


//Link to get current weather using city name (Checkout: https://openweathermap.org/current for more info)
String API_LINK = "http://api.openweathermap.org/data/2.5/weather?q=" + String(CITY) + "&units=metric&appid=" + String(API_KEY);

String country, city;
String weather, weather_desc, weather_icon;
String temperature, min_temp, max_temp, feels_like, pressure, humidity, wind_speed;

//Specify how fast to pull the data from API (in milliseconds).
//The free plan of API limits this to 60 requests/minute
unsigned long sync_interval = 10000; //every 10 seconds

//some additional variables & flags
unsigned long prev_time_interval = 0;
bool first_boot = true;
bool weather_mode_updated = false;
bool WEATHER_MODE_DAY = true;

//Required for parsing API Data
DynamicJsonDocument doc(1024);

EmbedUI display(Serial); //The Serial port to connect (Currently Supporting Hardware Serial Ports) (Do not use Serial further, if used over here)

void setup()
{
  initialize_display();
  pinMode(STATUS_LED, OUTPUT);
  digitalWrite(STATUS_LED, LOW);
  connectWifi();
  delay(1000);
}

void loop()
{
  if ((millis() - prev_time_interval > sync_interval) || first_boot)
  {
    prev_time_interval = millis();
    requestData();
  }

  //required for listening UI Events
  display.handleEvents();
}

void connectWifi()
{
  display.setDisplayBackgroundColor(BLACK);
  display.createText("Connecting to WiFi...", MAX_SCREEN_HEIGHT / 15, 0, MAX_SCREEN_HEIGHT / 4,
                     WHITE, false, 0, 0, 0, true, false, "connText");

  //disconnect, if we are already connected
  WiFi.disconnect(true);
  delay(2000);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(STATUS_LED, HIGH);
    delay(250);
    digitalWrite(STATUS_LED, LOW);
    delay(250);
  }
  digitalWrite(STATUS_LED, HIGH);

  //Yay ! we are connected now
  display.updateText("connText", "Connected");
  display.createText("Syncing Data", MAX_SCREEN_HEIGHT / 20, 0, MAX_SCREEN_HEIGHT / 2,
                     WHITE, false, 0, 0, 0, true, false, "syncText");
}

void requestData()
{
  //if we are connected to wifi
  if ((WiFi.status() == WL_CONNECTED)) {
    digitalWrite(STATUS_LED, LOW);

    HTTPClient http;

    http.begin(API_LINK);
    int httpCode = http.GET();

    if (httpCode > 0) { //Check for the returning code
      String payload = http.getString();
      //      Serial.println(httpCode);
      //      Serial.println(payload);

      //get it converted to json
      DeserializationError error = deserializeJson(doc, payload);

      if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.c_str());

        delay(10000);
        return;
      }

      city = doc["name"].as<String>();
      country = doc["sys"]["country"].as<String>();
      weather = doc["weather"][0]["main"].as<String>();
      weather_desc = doc["weather"][0]["description"].as<String>();
      weather_icon = doc["weather"][0]["icon"].as<String>();
      temperature = String(doc["main"]["temp"].as<int>());
      min_temp = String(doc["main"]["temp_min"].as<int>());
      max_temp = String(doc["main"]["temp_max"].as<int>());
      pressure = doc["main"]["pressure"].as<String>();
      humidity = doc["main"]["humidity"].as<String>();
      wind_speed = doc["wind"]["speed"].as<String>();

      //Decide between day & night modes
      if ((weather_icon.substring(weather_icon.length() - 1)) == "n")
      {
        if (WEATHER_MODE_DAY)
        {
          WEATHER_MODE_DAY = false;
          first_boot = true;
        }
      }
      else
      {
        if (!WEATHER_MODE_DAY)
        {
          WEATHER_MODE_DAY = true;
          first_boot = true;
        }
      }

      //if we want to update the static elements(that require no-repetitive updates) in the UI
      if (first_boot)
      {
        draw_UI();
        first_boot = false;
      }

      //Refresh dynamic elements with live data
      update_dynamic_objects();

    }
    else {
      Serial.println("Error on HTTP request");
      delay(10000);
    }

    http.end(); //Free the resources
    digitalWrite(STATUS_LED, HIGH);
  }
  else
  {
    digitalWrite(STATUS_LED, LOW);
  }
}

void initialize_display()
{
  display.begin(115200); //initialize the display comunication at 115200 baudrate. Make sure you select the same speed on the application
  delay(500); //to settle down things after initialization
  display.clear(); //Clear Screen Contents, if any
}

void draw_UI()
{
  //these will store the relative color to apply
  uint32_t TEXT_COLOR, CARD_COLOR, BACKGROUND_COLOR;

  if (WEATHER_MODE_DAY)
  {
    TEXT_COLOR = TEXT_COLOR_DAY , CARD_COLOR = CARD_COLOR_DAY; BACKGROUND_COLOR = BACKGROUND_COLOR_DAY;
  }
  else
  {
    TEXT_COLOR = TEXT_COLOR_NIGHT , CARD_COLOR = CARD_COLOR_NIGHT ; BACKGROUND_COLOR = BACKGROUND_COLOR_NIGHT ;
  }

  display.clear();
  display.setDisplayBackgroundColor(BACKGROUND_COLOR);

  display.createFilledRoundRect(HALF_SCREEN_WIDTH - (MAX_SCREEN_WIDTH / 1.4) / 2, MAX_SCREEN_HEIGHT / 6, MAX_SCREEN_WIDTH / 1.4,
                                MAX_SCREEN_HEIGHT / 2.5, 8, CARD_COLOR, "mainCard");

  display.createFilledRoundRect(MAX_SCREEN_WIDTH / 7, MAX_SCREEN_HEIGHT / 1.6, MAX_SCREEN_WIDTH / 4.55,
                                MAX_SCREEN_HEIGHT / 3.8, 8, CARD_COLOR, "humidityCard");

  display.createFilledRoundRect(HALF_SCREEN_WIDTH - (MAX_SCREEN_WIDTH / 4.55) / 2, MAX_SCREEN_HEIGHT / 1.6, MAX_SCREEN_WIDTH / 4.55,
                                MAX_SCREEN_HEIGHT / 3.8, 8, CARD_COLOR, "windCard");

  display.createFilledRoundRect(MAX_SCREEN_WIDTH - (MAX_SCREEN_WIDTH / 7) - MAX_SCREEN_WIDTH / 4.55 , MAX_SCREEN_HEIGHT / 1.6, MAX_SCREEN_WIDTH / 4.55,
                                MAX_SCREEN_HEIGHT / 3.8, 8, CARD_COLOR, "pressureCard");

  display.createLine(MAX_SCREEN_WIDTH / 2.07, MAX_SCREEN_HEIGHT / 2.72, MAX_SCREEN_WIDTH / 2.07 +  MAX_SCREEN_WIDTH / 5, MAX_SCREEN_HEIGHT / 2.72, 1, TEXT_COLOR , "L1");

  display.createText("", MAX_SCREEN_HEIGHT / 32, MAX_SCREEN_WIDTH / 2.07, MAX_SCREEN_HEIGHT / 3.24,
                     TEXT_COLOR, false, 0, 0, 0, false, false, "locText");
  display.createTextBox("", MAX_SCREEN_HEIGHT / 38, MAX_SCREEN_WIDTH / 1.85, MAX_SCREEN_HEIGHT / 2.65, MAX_SCREEN_WIDTH / 6.8, MAX_SCREEN_HEIGHT / 11.3,
                        TEXT_COLOR, false, 0, 0, 0, false, false, "weatherDesc");

  display.setFontWeight("locText", 500);

  display.createTextBox("", MAX_SCREEN_HEIGHT / 6.4,
                        MAX_SCREEN_WIDTH / 1.58, MAX_SCREEN_HEIGHT / 3.7, MAX_SCREEN_WIDTH / 5.7, MAX_SCREEN_HEIGHT / 7.68, TEXT_COLOR , 0, 0 , 0, 0, false, false, "tempVal");
  display.setTextAlignment("tempVal", RIGHT_ALIGN);

  display.setFontWeight("tempVal", 700);

  display.createTextBox("", MAX_SCREEN_HEIGHT / 12, MAX_SCREEN_WIDTH / 3.97, MAX_SCREEN_HEIGHT / 1.43, MAX_SCREEN_WIDTH / 10.5, MAX_SCREEN_HEIGHT / 1.47, TEXT_COLOR, 0, 0 , 0, 0, false, false, "humidity");

  display.createTextBox("", MAX_SCREEN_HEIGHT / 12, MAX_SCREEN_WIDTH / 2, MAX_SCREEN_HEIGHT / 1.43, MAX_SCREEN_WIDTH / 10.5, MAX_SCREEN_HEIGHT / 1.47, TEXT_COLOR, 0, 0 , 0, 0, false, false, "wind");
  display.createTextBox("", MAX_SCREEN_HEIGHT / 12, MAX_SCREEN_WIDTH / 1.37, MAX_SCREEN_HEIGHT / 1.43, MAX_SCREEN_WIDTH / 9.42, MAX_SCREEN_HEIGHT / 8.53, TEXT_COLOR, 0, 0 , 0, 0, false, false, "pressure");

  display.setFontWeight("humidity", 700);
  display.setFontWeight("wind", 700);
  display.setFontWeight("pressure", 700);

  display.setTextAlignment("humidity", RIGHT_ALIGN);
  display.setTextAlignment("wind", RIGHT_ALIGN);
  display.setTextAlignment("pressure", RIGHT_ALIGN);

  display.createTextBox("Min Temp: - °C", MAX_SCREEN_HEIGHT / 39, MAX_SCREEN_WIDTH / 1.41, MAX_SCREEN_HEIGHT / 5.12, MAX_SCREEN_WIDTH / 8, MAX_SCREEN_HEIGHT / 27.43, BACKGROUND_COLOR_DAY, 0, 0 , 0, 0, false, false, "minTemp"  );
  display.createTextBox("Max Temp: - °C", MAX_SCREEN_HEIGHT / 39, MAX_SCREEN_WIDTH / 1.41, MAX_SCREEN_HEIGHT / 1.97, MAX_SCREEN_WIDTH / 8, MAX_SCREEN_HEIGHT / 27.43, BACKGROUND_COLOR_DAY, 0, 0 , 0, 0, false, false, "maxTemp"  );

  display.setTextAlignment("minTemp", RIGHT_ALIGN);
  display.setTextAlignment("maxTemp", RIGHT_ALIGN);

  display.createTextBox(F("EmbedUI Weather Dashboard"), MAX_SCREEN_HEIGHT / 21,
                        MAX_SCREEN_WIDTH / 6, MAX_SCREEN_HEIGHT / 5.1, MAX_SCREEN_WIDTH / 4.1, MAX_SCREEN_HEIGHT / 7.68, TEXT_COLOR , 0, 0 , 0, 0, false, false, "dbTitle");
  display.setFontWeight("dbTitle", 500);

  display.createText(F("embedui.github.io"), MAX_SCREEN_HEIGHT / 32, MAX_SCREEN_WIDTH / 6, MAX_SCREEN_HEIGHT / 2,
                     display.color(47, 128, 237), false, 0, 0, 0, false, false, "link");

  display.createText("°C", MAX_SCREEN_HEIGHT / 25.6, MAX_SCREEN_WIDTH / 1.23, MAX_SCREEN_HEIGHT / 3.35,
                     TEXT_COLOR, false, 0, 0, 0, false, false, "t01");

  display.createImageFromLink(F("http://embedui.github.io/img/humidity_icon.svg"), MAX_SCREEN_WIDTH / 6.6, MAX_SCREEN_HEIGHT / 1.33, MAX_SCREEN_WIDTH / 12.89, MAX_SCREEN_HEIGHT / 8.53,  "humidityIcon");
  display.createImageFromLink(F("http://embedui.github.io/img/wind_icon.svg"), MAX_SCREEN_WIDTH / 2.5, MAX_SCREEN_HEIGHT / 1.33, MAX_SCREEN_WIDTH / 12.89, MAX_SCREEN_HEIGHT / 8.53,  "humidityIcon");
  display.createImageFromLink(F("http://embedui.github.io/img/temp_icon.svg"), MAX_SCREEN_WIDTH / 1.54, MAX_SCREEN_HEIGHT / 1.35, MAX_SCREEN_WIDTH / 14.7, MAX_SCREEN_HEIGHT / 7.68,  "pressureIcon");

  display.createTextBox("Humidity", MAX_SCREEN_HEIGHT / 32, MAX_SCREEN_WIDTH / 3.97, MAX_SCREEN_HEIGHT / 1.57, MAX_SCREEN_WIDTH / 10.5, MAX_SCREEN_HEIGHT / 1.47, TEXT_COLOR, 0, 0 , 0, 0, false, false, "humTitle"  );
  display.createTextBox("Wind", MAX_SCREEN_HEIGHT / 32, MAX_SCREEN_WIDTH / 2, MAX_SCREEN_HEIGHT / 1.57, MAX_SCREEN_WIDTH / 10.5, MAX_SCREEN_HEIGHT / 1.47, TEXT_COLOR, 0, 0 , 0, 0, false, false, "windTitle"  );
  display.createTextBox("Pressure", MAX_SCREEN_HEIGHT / 32, MAX_SCREEN_WIDTH / 1.34, MAX_SCREEN_HEIGHT / 1.57, MAX_SCREEN_WIDTH / 10.5, MAX_SCREEN_HEIGHT / 1.47, TEXT_COLOR, 0, 0 , 0, 0, false, false, "presTitle" );

  display.setFontWeight("humTitle", 500);
  display.setFontWeight("windTitle", 500);
  display.setFontWeight("presTitle", 500);

  display.setTextAlignment("humTitle", RIGHT_ALIGN);
  display.setTextAlignment("windTitle", RIGHT_ALIGN);
  display.setTextAlignment("presTitle", RIGHT_ALIGN);
  display.setTextAlignment("humTitle", RIGHT_ALIGN);

  display.createText("%", MAX_SCREEN_HEIGHT / 25.6, MAX_SCREEN_WIDTH / 3.13, MAX_SCREEN_HEIGHT / 1.24,
                     BACKGROUND_COLOR_DAY, false, 0, 0, 0, false, false, "humidityUnit");
  display.createText("m/s", MAX_SCREEN_HEIGHT / 25.6, MAX_SCREEN_WIDTH / 1.8, MAX_SCREEN_HEIGHT / 1.24,
                     BACKGROUND_COLOR_DAY, false, 0, 0, 0, false, false, "windUnit");
  display.createText("hPa", MAX_SCREEN_HEIGHT / 25.6, MAX_SCREEN_WIDTH / 1.25, MAX_SCREEN_HEIGHT / 1.24,
                     BACKGROUND_COLOR_DAY, false, 0, 0, 0, false, false, "pressureUnit");
  display.addEvent("link", CLICK_EVENT, openLink);
}

//function to trigger an external link to open through UI
void openLink()
{
  display.openExternalLink("https://embedui.github.io");
}

//this handles the updates for the live data
void update_dynamic_objects()
{
  display.updateText("locText", city + " (" + country + ")");
  display.updateText("weatherDesc", weather + "\n" + weather_desc );
  display.updateText("tempVal", temperature);
  display.updateText("humidity", humidity);
  display.updateText("wind", wind_speed);
  display.updateText("pressure", pressure);
  display.updateText("minTemp", "Min Temp: " + min_temp + "°C" );
  display.updateText("maxTemp", "Max Temp: " + max_temp + "°C" );
  display.removeObject("weatherIcon");

  //we get icons with respect to the current weather state, so keeping it dyanmic
  display.createImageFromLink("http://openweathermap.org/img/wn/" + weather_icon + "@2x.png", MAX_SCREEN_WIDTH / 2.07, MAX_SCREEN_HEIGHT / 2.7, MAX_SCREEN_HEIGHT / 12, MAX_SCREEN_HEIGHT / 12,  "weatherIcon");
}
