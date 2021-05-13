/*
  EmbedUI Hardware Library - https://github.com/EmbedUI/EmbedUI-Library
  
  EmbedUI Application - https://github.com/EmbedUI/EmbedUI-App
  (Download EmbedUI Application from above link)
  
  Author: Maker Vinod (https://github.com/makervinod)
  Website: www.makervinod.in
  Created:  05/05/2021
  
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
 
 */


#include "Arduino.h"
#ifndef EmbedUI_h
#define EmbedUI_h

#define SEPARATOR char(0x01)
#define CLEAR_COMMAND "CS"
#define GLOBAL_FONT_COMMAND "GF"
#define DISPLAY_BG_COLOR_COMMAND "BC"
#define ADD_FONT_COMMAND "NF"
#define UPDATE_TEXT_COMMAND "UTV"
#define UPDATE_BUTTON_TEXT_COMMAND "UBT"
#define UPDATE_TEXT_POS_COMMAND "UTP"
#define CREATE_TEXT_COMMAND "CT"
#define UPDATE_COLOR_COMMAND "UFC"
#define UPDATE_BACKGROUND_COLOR_COMMAND "UBC"
#define UPDATE_POSITION_COMMAND "UP"
#define UPDATE_SIZE_COMMAND "US"
#define UPDATE_VISIBILTY_COMMAND "UV"
#define SET_ROTATION_COMMAND "SR"
#define SET_TRANSITION_COMMAND "ST"
#define REMOVE_OBJECT_COMMAND "RO"
#define UPDATE_OPACITY_COMMAND "UO"
#define LINE_COMMAND "L"
#define OUTLINE_RECT_COMMAND "R"
#define FILLED_RECT_COMMAND "FR"
#define OUTLINE_ROUND_RECT_COMMAND "RR"
#define FILLED_ROUND_RECT_COMMAND "FRR"
#define OUTLINE_CIRCLE_COMMAND "C"
#define FILLED_CIRCLE_COMMAND "FC"
#define OUTLINE_TRIANGLE_COMMAND "TR"
#define FILLED_TRIANGLE_COMMAND "FTR"
#define CREATE_BUTTON_COMMAND "CB"
#define ADD_EVENT_COMMAND "AE"
#define CREATE_IMAGE_COMMAND "CI"
#define CREATE_IMAGE_FROM_FILE_COMMAND "CIF"
#define CREATE_VIDEO_COMMAND "CV"
#define CREATE_VIDEO_FROM_FILE_COMMAND "CVF"
#define ADD_UNDERLINE_COMMAND "AU"
#define ADD_STRIKE_THROUGH_COMMAND "AST"

#define CLICK_EVENT 1
#define HOVER_EVENT 2
#define MOUSE_IN_EVENT 3
#define MOUSE_OUT_EVENT 4

#define LINEAR 100
#define SOFT 200
#define SOFT_START 300
#define SOFT_END 400
#define SOFT_START_END 500



class Font {
  public:
    Font(String font_link, String font_name, String font_fallback);
    String _font_link = "";
    String _font_name = "";
    String _font_fallback = "";
};

class EmbedUI
{
  private:
    HardwareSerial& _serial;
    long eventCount = 0;
  public:
    struct EventListener {
      int event;
      String objectId;
      void (*callBack_func)();
    } ;
    EventListener allEvents[100];
    EmbedUI(HardwareSerial& serial);
    void begin(uint32_t baudrate);
    void clear();
    void addFont(Font font);
    void setGlobalFont(Font font);
    void setDisplayBackgroundColor(uint32_t _color);
    void setForegroundColor(String id, uint32_t new_color);
    void setBackgroundColor(String id, uint32_t new_color);
    void updatePosition(String id, long x, long y);
    void setSize(String id, long w, long h);
    void setVisibility(String id, bool visible);
    void setOpacity(String id , int opacity);
	void setRotation(String id,float degrees);
	void setTransition(String id, int transition_type, unsigned long  transition_duration, unsigned long  transition_delay);
	void addUnderline(String id, uint32_t color);
	void addStrikeThrough(String id, uint32_t color);
    void removeObject(String id);
	
    void addEvent(String id, int event, void (*callBack_func)());
    void handleEvents();
	
    String createText(String text_data, long font_size, long x, long y, uint32_t fg_color, bool hasBackground, uint32_t bg_color , long padding_x , long padding_y, bool center_align_x, bool center_align_y, String id );
    void updateText(String id, String value);
    void updateTextColor(String id, uint32_t new_color);
	
    String createLine(long x1, long y1, long x2, long y2, long line_thickness, uint32_t fill_color , String id);
    String createRect(long x, long y, long w, long h, long border_thickness, uint32_t b_color, String id );
    String createRoundRect(long x, long y, long w, long h, long border_thickness, long border_radius, uint32_t b_color , String id );
    String createFilledRect(long x, long y, long w, long h, uint32_t fill_color, String id );
    String createFilledRoundRect(long x, long y, long w, long h, long border_radius, uint32_t fill_color , String id );
    String createCircle(long x, long y, long radius, long border_thickness, uint32_t b_color , String id);
    String createFilledCircle(long x, long y, long radius, uint32_t fill_color, String id);
    String createTriangle(long x1, long y1, long x2, long y2, long x3, long y3,  long border_thickness, uint32_t b_color, String id);
    String createFilledTriangle(long x1, long y1, long x2, long y2, long x3, long y3, uint32_t fill_color, String id );
	
    String createButton(String button_text, long font_size, long x, long y, long w, long h, int border_radius, uint32_t text_color, uint32_t bg_color, void (*onclick_callBack)(), String id);
    void updateButtonText(String id, String value);
	
    String createImageFromLink(String link, long x, long y, long w, long h,  String id);
    String createImageFromFile(String file_name, long x, long y, long w, long h,  String id);
	
	String createVideoFromLink(String link, long x, long y, long w, long h, bool enable_controls, bool mute_audio, bool enable_autoplay, bool loop_video, String id);
	String createVideoFromFile(String file_name, long x, long y, long w, long h, bool enable_controls, bool mute_audio, bool enable_autoplay, bool loop_video, String id);
    
    uint32_t color(uint8_t _r, uint8_t _g, uint8_t _b);
};

#endif
