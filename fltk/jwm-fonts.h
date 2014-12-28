/*                 Joe's Window Manager Configuration
 *
 * This program configures JWM using tinyxml2 and FLTK
 *
 *         Copyright (C) 2014  Israel <israel@torios.org>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * This has been developed as a part of the ToriOS Project
 * This has been developed by Israel<israel@torios.org>
 *
 *
 * You may redistribute this, but you must keep this comment in place
 * Jesus is my Lord, and if you don't like it feel free to ignore it.
 */
// generated by Fast Light User Interface Designer (fluid) version 1.0302

#ifndef jwm_fonts_h
#define jwm_fonts_h
#include <FL/Fl.H>
#include "../include/flFont.h"
#include <libintl.h>
#include <FL/Fl_File_Chooser.H>
#include <string>
#include "jwm-desktop.h"
#include <stdlib.h>
#include <iostream>
#include <FL/Fl_Color_Chooser.H>
#include "../include/Config.h"
#include "../include/ui.h"
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Browser.H>

class FontUI {
  const char* currentElement; 
  Fl_Output* Widget; 
public:
  Fl_Double_Window* make_window();
  Fl_Double_Window *font_window;
private:
  inline void cb_Cancel_i(Fl_Button*, void*);
  static void cb_Cancel(Fl_Button*, void*);
  inline void cb_OK_i(Fl_Button*, void*);
  static void cb_OK(Fl_Button*, void*);
public:
  Fl_Box *window_box;
  Fl_Output *window_font;
  Fl_Button *a_window_font_color_button;
private:
  inline void cb_a_window_font_color_button_i(Fl_Button*, void*);
  static void cb_a_window_font_color_button(Fl_Button*, void*);
  inline void cb_Choose_i(Fl_Button*, void*);
  static void cb_Choose(Fl_Button*, void*);
public:
  Fl_Button *window_font_color_button;
private:
  inline void cb_window_font_color_button_i(Fl_Button*, void*);
  static void cb_window_font_color_button(Fl_Button*, void*);
  inline void cb_Size_i(Fl_Value_Input*, void*);
  static void cb_Size(Fl_Value_Input*, void*);
public:
  Fl_Box *menu_box;
  Fl_Output *menu_font;
private:
  inline void cb_Choose1_i(Fl_Button*, void*);
  static void cb_Choose1(Fl_Button*, void*);
public:
  Fl_Button *menu_font_color_button;
private:
  inline void cb_menu_font_color_button_i(Fl_Button*, void*);
  static void cb_menu_font_color_button(Fl_Button*, void*);
  inline void cb_Size1_i(Fl_Value_Input*, void*);
  static void cb_Size1(Fl_Value_Input*, void*);
public:
  Fl_Output *panel_button_font;
private:
  inline void cb_Choose2_i(Fl_Button*, void*);
  static void cb_Choose2(Fl_Button*, void*);
public:
  Fl_Button *traybutton_font_color_button;
private:
  inline void cb_traybutton_font_color_button_i(Fl_Button*, void*);
  static void cb_traybutton_font_color_button(Fl_Button*, void*);
  inline void cb_Size2_i(Fl_Value_Input*, void*);
  static void cb_Size2(Fl_Value_Input*, void*);
public:
  Fl_Box *panel_box;
  Fl_Output *panel_font;
private:
  inline void cb_Choose3_i(Fl_Button*, void*);
  static void cb_Choose3(Fl_Button*, void*);
public:
  Fl_Button *panel_font_color_button;
private:
  inline void cb_panel_font_color_button_i(Fl_Button*, void*);
  static void cb_panel_font_color_button(Fl_Button*, void*);
  inline void cb_Size3_i(Fl_Value_Input*, void*);
  static void cb_Size3(Fl_Value_Input*, void*);
public:
  Fl_Value_Input *task_size;
private:
  inline void cb_task_size_i(Fl_Value_Input*, void*);
  static void cb_task_size(Fl_Value_Input*, void*);
public:
  Fl_Button *task_font_color_button;
private:
  inline void cb_task_font_color_button_i(Fl_Button*, void*);
  static void cb_task_font_color_button(Fl_Button*, void*);
public:
  Fl_Output *task_font;
private:
  inline void cb_Choose4_i(Fl_Button*, void*);
  static void cb_Choose4(Fl_Button*, void*);
  inline void cb_Advanced_i(Fl_Button*, void*);
  static void cb_Advanced(Fl_Button*, void*);
  inline void cb_Main_i(Fl_Button*, void*);
  static void cb_Main(Fl_Button*, void*);
public:
  void f_color(Fl_Widget *o, const char * active);
  void getSize(Fl_Value_Input *o, const char * active);
  void setSize(Fl_Value_Input *o, const char * active);
  void w_color(Fl_Widget *o, const char * active);
  void w_getSize(Fl_Value_Input *o, const char * active);
  void w_setSize(Fl_Value_Input *o, const char * active);
  Fl_Double_Window* font_chooser_window();
  Fl_Double_Window *font_choosing;
private:
  inline void cb_Cancel1_i(Fl_Button*, void*);
  static void cb_Cancel1(Fl_Button*, void*);
  inline void cb_OK1_i(Fl_Button*, void*);
  static void cb_OK1(Fl_Button*, void*);
public:
  Fl_Browser *font_browser;
private:
  inline void cb_font_browser_i(Fl_Browser*, void*);
  static void cb_font_browser(Fl_Browser*, void*);
public:
  Fl_Output *font_name;
private:
  inline void cb_font_name_i(Fl_Output*, void*);
  static void cb_font_name(Fl_Output*, void*);
public:
  void font_populate(Fl_Browser *o);
};
#endif
