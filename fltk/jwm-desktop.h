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

#ifndef jwm_desktop_h
#define jwm_desktop_h
#include <FL/Fl.H>
#include <libintl.h>
#include <FL/Fl_File_Chooser.H>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "../include/Config.h"
#include "../include/flDesktop.h"
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Color_Chooser.H>
#include <algorithm>
//#include <FL/Fl_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include "../include/ui.h"
//#include <cairo-xlib.h>
//#include <cairo.h>
//#include <cairo-svg.h>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Value_Input.H>

class DesktopUI : public Config {
public:
  Fl_Double_Window* make_window();
  Fl_Double_Window *desktop_window;
  Fl_Box *background_displayer_thingie;
  Fl_Box *color_display1;
  Fl_Box *color_display2;
private:
  inline void cb_Choose_i(Fl_Button*, void*);
  static void cb_Choose(Fl_Button*, void*);
  inline void cb_Choose1_i(Fl_Button*, void*);
  static void cb_Choose1(Fl_Button*, void*);
  inline void cb_Choose2_i(Fl_Button*, void*);
  static void cb_Choose2(Fl_Button*, void*);
public:
  Fl_Check_Button *icons_check;
private:
  inline void cb_icons_check_i(Fl_Check_Button*, void*);
  static void cb_icons_check(Fl_Check_Button*, void*);
public:
  Fl_Output *current_bg;
private:
  inline void cb_Multiple_i(Fl_Check_Button*, void*);
  static void cb_Multiple(Fl_Check_Button*, void*);
public:
  Fl_Value_Input *num_desktop_w;
private:
  inline void cb_num_desktop_w_i(Fl_Value_Input*, void*);
  static void cb_num_desktop_w(Fl_Value_Input*, void*);
public:
  Fl_Value_Input *num_desktop_h;
private:
  inline void cb_num_desktop_h_i(Fl_Value_Input*, void*);
  static void cb_num_desktop_h(Fl_Value_Input*, void*);
  inline void cb_Cancel_i(Fl_Button*, void*);
  static void cb_Cancel(Fl_Button*, void*);
  inline void cb_OK_i(Fl_Button*, void*);
  static void cb_OK(Fl_Button*, void*);
public:
  void background(Fl_Box*o);
  void background1(Fl_Box*o);
  void background2(Fl_Box*o);
  void bg_chooser_cb();
  void bg_name(Fl_Output *o);
  void icons_on_desktop();
  bool multipleDesktops();
  void num_desktop_wh_cb(const char* whichone, int value);
  void one_color();
  void two_color();
  void use_icons_on_desktop();
  void useMultipleDesktops();
};
#endif
