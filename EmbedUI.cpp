/*
  EmbedUI Hardware Library - https://github.com/EmbedUI/EmbedUI-Library

  EmbedUI Application - https://github.com/EmbedUI/EmbedUI-App
  (Download EmbedUI Application from above link)

  Author: Maker Vinod (https://github.com/makervinod)
  Website: www.makervinod.in
  Created:  05/05/2021
  Updated:  15/05/2021

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
#include "EmbedUI.h"

Font::Font(String font_link, String font_name, String font_fallback) {
  _font_link = font_link;
  _font_name = font_name;
  _font_fallback = font_fallback;
}

Font::Font( String font_fallback) {
  _font_link = "";
  _font_name = "";
  _font_fallback = font_fallback;
}

String EmbedUI::createText(String text_data, long font_size, long x, long y,
                           uint32_t fg_color , bool hasBackground , uint32_t bg_color , long padding_x ,
                           long padding_y , bool center_align_x , bool center_align_y , String id )
{
  _serial.print(CREATE_TEXT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(text_data);
  _serial.print(SEPARATOR);
  _serial.print(String(font_size));
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.print(SEPARATOR);
  _serial.print(String(fg_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(String(hasBackground));
  _serial.print(SEPARATOR);
  _serial.print(String(bg_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(String(padding_x));
  _serial.print(SEPARATOR);
  _serial.print(String(padding_y));
  _serial.print(SEPARATOR);
  _serial.print(String(center_align_x));
  _serial.print(SEPARATOR);
  _serial.print(String(center_align_y));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

String EmbedUI::createTextBox(String text_data, long font_size, long x, long y, long w, long h, uint32_t text_color, bool hasBackground, uint32_t bg_color , long padding_x , long padding_y, bool center_align_x, bool center_align_y, String id )
{
  _serial.print(CREATE_TEXT_BOX_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(text_data);
  _serial.print(SEPARATOR);
  _serial.print(String(font_size));
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.print(SEPARATOR);
  _serial.print(String(w));
  _serial.print(SEPARATOR);
  _serial.print(String(h));
  _serial.print(SEPARATOR);
  _serial.print(String(text_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(String(hasBackground));
  _serial.print(SEPARATOR);
  _serial.print(String(bg_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(String(padding_x));
  _serial.print(SEPARATOR);
  _serial.print(String(padding_y));
  _serial.print(SEPARATOR);
  _serial.print(String(center_align_x));
  _serial.print(SEPARATOR);
  _serial.print(String(center_align_y));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

void EmbedUI::updateText(String id, String value) {
  _serial.print(UPDATE_TEXT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(value);
  _serial.println(SEPARATOR);
}

void EmbedUI::updateTextColor(String id, uint32_t new_color) {
  _serial.print(UPDATE_COLOR_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(String(new_color, HEX));
  _serial.println(SEPARATOR);
}

void EmbedUI::updateTextFont(String id, Font font)
{
  _serial.print(UPDATE_TEXT_FONT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print("'" + font._font_name + "'," + font._font_fallback);
  _serial.println(SEPARATOR);
}

String EmbedUI::createLine(long x1, long y1, long x2, long y2, long line_thickness, uint32_t fill_color,  String id )
{
  _serial.print(LINE_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(String(x1));
  _serial.print(SEPARATOR);
  _serial.print(String(y1));
  _serial.print(SEPARATOR);
  _serial.print(String(x2));
  _serial.print(SEPARATOR);
  _serial.print(String(y2));
  _serial.print(SEPARATOR);
  _serial.print(String(line_thickness));
  _serial.print(SEPARATOR);
  _serial.print(String(fill_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.println(SEPARATOR);
  return id;
}

String EmbedUI::createRect(long x, long y, long w, long h, long border_thickness, uint32_t b_color , String id )
{
  _serial.print(OUTLINE_RECT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.print(SEPARATOR);
  _serial.print(String(w));
  _serial.print(SEPARATOR);
  _serial.print(String(h));
  _serial.print(SEPARATOR);
  _serial.print(String(border_thickness));
  _serial.print(SEPARATOR);
  _serial.print(String(b_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

String EmbedUI::createRoundRect(long x, long y, long w, long h, long border_thickness, long border_radius, uint32_t b_color , String id) {
  _serial.print(OUTLINE_ROUND_RECT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.print(SEPARATOR);
  _serial.print(String(w));
  _serial.print(SEPARATOR);
  _serial.print(String(h));
  _serial.print(SEPARATOR);
  _serial.print(String(border_thickness));
  _serial.print(SEPARATOR);
  _serial.print(String(border_radius));
  _serial.print(SEPARATOR);
  _serial.print(String(b_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

String EmbedUI::createFilledRect(long x, long y, long w, long h, uint32_t fill_color, String id )
{
  _serial.print(FILLED_RECT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.print(SEPARATOR);
  _serial.print(String(w));
  _serial.print(SEPARATOR);
  _serial.print(String(h));
  _serial.print(SEPARATOR);
  _serial.print(String(fill_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

String EmbedUI::createFilledRoundRect(long x, long y, long w, long h, long border_radius, uint32_t fill_color , String id )
{
  _serial.print(FILLED_ROUND_RECT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.print(SEPARATOR);
  _serial.print(String(w));
  _serial.print(SEPARATOR);
  _serial.print(String(h));
  _serial.print(SEPARATOR);
  _serial.print(String(border_radius));
  _serial.print(SEPARATOR);
  _serial.print(String(fill_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

String EmbedUI::createCircle(long x, long y, long radius, long border_thickness, uint32_t b_color , String id )
{
  _serial.print(OUTLINE_CIRCLE_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.print(SEPARATOR);
  _serial.print(String(radius));
  _serial.print(SEPARATOR);
  _serial.print(String(border_thickness));
  _serial.print(SEPARATOR);
  _serial.print(String(b_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

String EmbedUI::createFilledCircle(long x, long y, long radius, uint32_t fill_color, String id )
{
  _serial.print(FILLED_CIRCLE_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.print(SEPARATOR);
  _serial.print(String(radius));
  _serial.print(SEPARATOR);
  _serial.print(String(fill_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

String EmbedUI::createTriangle(long x1, long y1, long x2, long y2, long x3, long y3,  long border_thickness, uint32_t b_color , String id )
{
  _serial.print(OUTLINE_TRIANGLE_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(String(x1));
  _serial.print(SEPARATOR);
  _serial.print(String(y1));
  _serial.print(SEPARATOR);
  _serial.print(String(x2));
  _serial.print(SEPARATOR);
  _serial.print(String(y2));
  _serial.print(SEPARATOR);
  _serial.print(String(x3));
  _serial.print(SEPARATOR);
  _serial.print(String(y3));
  _serial.print(SEPARATOR);
  _serial.print(String(border_thickness));
  _serial.print(SEPARATOR);
  _serial.print(String(b_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

String EmbedUI::createFilledTriangle(long x1, long y1, long x2, long y2, long x3, long y3, uint32_t fill_color, String id)
{
  _serial.print(FILLED_TRIANGLE_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(String(x1));
  _serial.print(SEPARATOR);
  _serial.print(String(y1));
  _serial.print(SEPARATOR);
  _serial.print(String(x2));
  _serial.print(SEPARATOR);
  _serial.print(String(y2));
  _serial.print(SEPARATOR);
  _serial.print(String(x3));
  _serial.print(SEPARATOR);
  _serial.print(String(y3));
  _serial.print(SEPARATOR);
  _serial.print(String(fill_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

void  EmbedUI::addEvent(String id, int event, void (*callBack_func)())
{
  _serial.print(ADD_EVENT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  if (event == CLICK_EVENT)
  {
    _serial.print("click");
  }
  if (event == HOVER_EVENT)
  {
    _serial.print("hover");
  }
  if (event == MOUSE_IN_EVENT)
  {
    _serial.print("mousein");
  }
  if (event == MOUSE_OUT_EVENT)
  {
    _serial.print("mouseout");
  }
  _serial.print(SEPARATOR);
  _serial.println();

  EventListener Event;
  Event.objectId = id;
  Event.event = event;
  Event.callBack_func = callBack_func;
  allEvents[eventCount++] = Event;
}

void EmbedUI::handleEvents()
{
  if (_serial.available() > 0)
  {
    String DATA = _serial.readString();
    String key = DATA.substring(0, DATA.indexOf('\x01'));
    DATA = DATA.substring(DATA.indexOf('\x01') + 1);
    String object_id = DATA.substring(0, DATA.indexOf('\x01'));
    for (long i = 0; i < eventCount ; i++)
    {

      if (allEvents[i].event == key.toInt())
      {
        if (allEvents[i].objectId == object_id)
        {

          allEvents[i].callBack_func();
          break;
        }
      }
    }
  }
}

String EmbedUI::createButton(String button_text, long font_size, long x, long y, long w, long h, int border_radius, uint32_t text_color, uint32_t bg_color, void (*onclick_callBack)(), String id)
{
  _serial.print(CREATE_BUTTON_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(button_text);
  _serial.print(SEPARATOR);
  _serial.print(String(font_size));
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.print(SEPARATOR);
  _serial.print(String(w));
  _serial.print(SEPARATOR);
  _serial.print(String(h));
  _serial.print(SEPARATOR);
  _serial.print(String(border_radius));
  _serial.print(SEPARATOR);
  _serial.print(String(text_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(String(bg_color, HEX));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  EventListener newEvent;
  newEvent.objectId = id;
  newEvent.event = CLICK_EVENT;
  newEvent.callBack_func = onclick_callBack;
  allEvents[eventCount++] = newEvent;
  return id;
}

void EmbedUI::updateButtonText(String id, String value) {
  _serial.print(UPDATE_BUTTON_TEXT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(value);
  _serial.println(SEPARATOR);
}

String EmbedUI::createImageFromLink(String link, long x, long y, long w, long h,  String id)
{
  _serial.print(CREATE_IMAGE_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(link);
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.print(SEPARATOR);
  _serial.print(String(w));
  _serial.print(SEPARATOR);
  _serial.print(String(h));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

String EmbedUI::createImageFromFile(String file_name, long x, long y, long w, long h,  String id)
{
  _serial.print(CREATE_IMAGE_FROM_FILE_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(file_name);
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.print(SEPARATOR);
  _serial.print(String(w));
  _serial.print(SEPARATOR);
  _serial.print(String(h));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

String EmbedUI::createVideoFromLink(String link, long x, long y, long w, long h, bool enable_controls, bool mute_audio, bool enable_autoplay, bool loop_video, String id)
{
  _serial.print(CREATE_VIDEO_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(link);
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.print(SEPARATOR);
  _serial.print(String(w));
  _serial.print(SEPARATOR);
  _serial.print(String(h));
  _serial.print(SEPARATOR);
  _serial.print(String(enable_controls));
  _serial.print(SEPARATOR);
  _serial.print(String(mute_audio));
  _serial.print(SEPARATOR);
  _serial.print(String(enable_autoplay));
  _serial.print(SEPARATOR);
  _serial.print(String(loop_video));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

String EmbedUI::createVideoFromFile(String file_name, long x, long y, long w, long h, bool enable_controls, bool mute_audio, bool enable_autoplay, bool loop_video, String id)
{
  _serial.print(CREATE_VIDEO_FROM_FILE_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(file_name);
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.print(SEPARATOR);
  _serial.print(String(w));
  _serial.print(SEPARATOR);
  _serial.print(String(h));
  _serial.print(SEPARATOR);
  _serial.print(String(enable_controls));
  _serial.print(SEPARATOR);
  _serial.print(String(mute_audio));
  _serial.print(SEPARATOR);
  _serial.print(String(enable_autoplay));
  _serial.print(SEPARATOR);
  _serial.print(String(loop_video));
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.println();
  return id;
}

EmbedUI::EmbedUI(HardwareSerial & serial): _serial(serial) {
}

void EmbedUI::begin(uint32_t baudrate) {
  _serial.setTimeout(5);
  _serial.begin(baudrate);
  _serial.println();
}

void EmbedUI::clear()
{
  _serial.print(CLEAR_COMMAND);
  _serial.println(SEPARATOR);
  eventCount = 0;
}

void EmbedUI::addFont(Font font)
{
  _serial.print(ADD_FONT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(font._font_link);
  _serial.println(SEPARATOR);
}

void EmbedUI::setGlobalFont(Font font)
{
  _serial.print(GLOBAL_FONT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print("'" + font._font_name + "'," + font._font_fallback);
  _serial.println(SEPARATOR);
}

void EmbedUI::setDisplayBackgroundColor(uint32_t color)
{
  _serial.print(DISPLAY_BG_COLOR_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(String(color, HEX));
  _serial.println(SEPARATOR);
}

void EmbedUI::setForegroundColor(String id, uint32_t new_color) {
  _serial.print(UPDATE_COLOR_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(String(new_color, HEX));
  _serial.println(SEPARATOR);
}

void EmbedUI::setBackgroundColor(String id, uint32_t new_color) {
  _serial.print(UPDATE_BACKGROUND_COLOR_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(String(new_color, HEX));
  _serial.println(SEPARATOR);
}

void EmbedUI::updatePosition(String id, long x, long y) {
  _serial.print(UPDATE_POSITION_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(String(x));
  _serial.print(SEPARATOR);
  _serial.print(String(y));
  _serial.println(SEPARATOR);
}

void EmbedUI::setSize(String id, long w, long h) {
  _serial.print(UPDATE_SIZE_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(String(w));
  _serial.print(SEPARATOR);
  _serial.print(String(h));
  _serial.println(SEPARATOR);
}

void EmbedUI::setVisibility(String id, bool visible) {
  _serial.print(UPDATE_VISIBILTY_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(String(visible));
  _serial.println(SEPARATOR);
}

void EmbedUI::setRotation(String id, float degrees) {
  _serial.print(SET_ROTATION_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(String(degrees));
  _serial.println(SEPARATOR);
}

void EmbedUI::setTransition(String id, int transition_type, unsigned long transition_duration, unsigned long transition_delay)
{
  _serial.print(SET_TRANSITION_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(String(transition_type));
  _serial.print(SEPARATOR);
  _serial.print(String(transition_duration));
  _serial.print(SEPARATOR);
  _serial.print(String(transition_delay));
  _serial.println(SEPARATOR);
}

void EmbedUI::addUnderline(String id, uint32_t color)
{
  _serial.print(ADD_UNDERLINE_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(String(color, HEX));
  _serial.println(SEPARATOR);
}

void EmbedUI::addStrikeThrough(String id, uint32_t color)
{
  _serial.print(ADD_STRIKE_THROUGH_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(String(color, HEX));
  _serial.println(SEPARATOR);
}

void EmbedUI::setFontWeight(String id, int font_weight)
{
  _serial.print(SET_FONT_WEIGHT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(String(font_weight));
  _serial.println(SEPARATOR);
}
void EmbedUI::setTextNormal(String id) {
  _serial.print(SET_TEXT_NORMAL_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.println(SEPARATOR);
}

void EmbedUI::setTextBold(String id) {
  _serial.print(SET_TEXT_BOLD_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.println(SEPARATOR);
}

void EmbedUI::setTextItalic(String id) {
  _serial.print(SET_TEXT_ITALIC_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.println(SEPARATOR);
}

void EmbedUI::setTextAlignment(String id, int alignment)
{
  _serial.print(SET_TEXT_ALIGNMENT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(String(alignment));
  _serial.println(SEPARATOR);
}

void EmbedUI::openExternalLink(String external_link)
{
  _serial.print(OPEN_EXTERNAL_LINK_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(external_link);
  _serial.println(SEPARATOR);
}

void EmbedUI::removeObject(String id) {
  _serial.print(REMOVE_OBJECT_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.println(SEPARATOR);
}

void EmbedUI::setOpacity(String id, int opacity )
{
  _serial.print(UPDATE_OPACITY_COMMAND);
  _serial.print(SEPARATOR);
  _serial.print(id);
  _serial.print(SEPARATOR);
  _serial.print(String(opacity));
  _serial.println(SEPARATOR);
}

uint32_t EmbedUI::color(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}
