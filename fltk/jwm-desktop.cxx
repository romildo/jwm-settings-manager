/*                 Joe's Window Manager Configuration
 *
 * This program configures JWM using pugixml and FLTK
 *
 *         Copyright (C) 2016  Israel <israeldahl@gmail.com>
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
 *
 *
 * You may redistribute this, but you must keep this comment in place
 * Jesus is my Lord, and if you don't like it feel free to ignore it.
 */
// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include <libintl.h>
#include "jwm-desktop.h"

void DesktopUI::cb_Choose_i(Fl_Button*, void*) {
  bg_chooser_cb(background_displayer_thingie,current_bg,color_display1,color_display2);
}
void DesktopUI::cb_Choose(Fl_Button* o, void* v) {
  ((DesktopUI*)(o->parent()->parent()->user_data()))->cb_Choose_i(o,v);
}

void DesktopUI::cb_Choose1_i(Fl_Button*, void*) {
  one_color(color_display1,color_display2,background_displayer_thingie,current_bg);
}
void DesktopUI::cb_Choose1(Fl_Button* o, void* v) {
  ((DesktopUI*)(o->parent()->parent()->user_data()))->cb_Choose1_i(o,v);
}

void DesktopUI::cb_Choose2_i(Fl_Button*, void*) {
  two_color(color_display1,color_display2,background_displayer_thingie,current_bg);
}
void DesktopUI::cb_Choose2(Fl_Button* o, void* v) {
  ((DesktopUI*)(o->parent()->parent()->user_data()))->cb_Choose2_i(o,v);
}

void DesktopUI::cb_icons_check_i(Fl_Check_Button* o, void*) {
  bool useful=use_icons_on_desktop(background_displayer_thingie,thisBG);
o->value(0);
fm_pref->hide();
if(useful){o->value(1);fm_pref->show();};
}
void DesktopUI::cb_icons_check(Fl_Check_Button* o, void* v) {
  ((DesktopUI*)(o->parent()->parent()->user_data()))->cb_icons_check_i(o,v);
}

void DesktopUI::cb_check_desktops_i(Fl_Check_Button*, void*) {
  useMultipleDesktops(num_desktop_w,num_desktop_h);
}
void DesktopUI::cb_check_desktops(Fl_Check_Button* o, void* v) {
  ((DesktopUI*)(o->parent()->parent()->user_data()))->cb_check_desktops_i(o,v);
}

void DesktopUI::cb_num_desktop_w_i(Fl_Value_Input* o, void*) {
  int width = int((o->value()));
num_desktop_wh_cb("width",width,num_desktop_w,num_desktop_h,check_desktops);
}
void DesktopUI::cb_num_desktop_w(Fl_Value_Input* o, void* v) {
  ((DesktopUI*)(o->parent()->parent()->user_data()))->cb_num_desktop_w_i(o,v);
}

void DesktopUI::cb_num_desktop_h_i(Fl_Value_Input* o, void*) {
  int height = int((o->value()));
num_desktop_wh_cb("height",height,num_desktop_w,num_desktop_h,check_desktops);
}
void DesktopUI::cb_num_desktop_h(Fl_Value_Input* o, void* v) {
  ((DesktopUI*)(o->parent()->parent()->user_data()))->cb_num_desktop_h_i(o,v);
}

void DesktopUI::cb_Cancel_i(Fl_Button*, void*) {
  cancel();
}
void DesktopUI::cb_Cancel(Fl_Button* o, void* v) {
  ((DesktopUI*)(o->parent()->parent()->user_data()))->cb_Cancel_i(o,v);
}

void DesktopUI::cb_OK_i(Fl_Button*, void*) {
  saveChanges();
desktop_window->hide();
}
void DesktopUI::cb_OK(Fl_Button* o, void* v) {
  ((DesktopUI*)(o->parent()->parent()->user_data()))->cb_OK_i(o,v);
}

Fl_Double_Window* DesktopUI::make_window() {
  load();
  thisBG=getBackground();
  FILEMANAGER=whichFileManagerRunning();
  { Fl_Double_Window* o = desktop_window = new Fl_Double_Window(360, 420, gettext("Desktop Settings"));
    desktop_window->color((Fl_Color)31);
    desktop_window->user_data((void*)(this));
    { Fl_Scroll* o = new Fl_Scroll(0, 0, 360, 420);
      o->color((Fl_Color)31);
      { Fl_Box* o = background_displayer_thingie = new Fl_Box(8, 5, 345, 270);
        background_displayer_thingie->box(FL_FLAT_BOX);
        background_displayer_thingie->color((Fl_Color)37);
        background_displayer_thingie->when(FL_WHEN_RELEASE_ALWAYS);
        background(o,thisBG);
      } // Fl_Box* background_displayer_thingie
      { Fl_Box* o = color_display1 = new Fl_Box(8, 5, 345, 270);
        color_display1->box(FL_FLAT_BOX);
        color_display1->color((Fl_Color)37);
        color_display1->when(FL_WHEN_RELEASE_ALWAYS);
        background1(o,thisBG);
      } // Fl_Box* color_display1
      { Fl_Box* o = color_display2 = new Fl_Box(8, 135, 345, 140);
        color_display2->box(FL_FLAT_BOX);
        color_display2->color((Fl_Color)37);
        color_display2->when(FL_WHEN_RELEASE_ALWAYS);
        background2(o,thisBG);
      } // Fl_Box* color_display2
      { Fl_Button* o = new Fl_Button(8, 315, 110, 25, gettext("Choose Image"));
        o->box(FL_FLAT_BOX);
        o->color((Fl_Color)23);
        o->callback((Fl_Callback*)cb_Choose);
      } // Fl_Button* o
      { Fl_Button* o = new Fl_Button(123, 315, 100, 25, gettext("Choose Color"));
        o->tooltip(gettext("This will take icons off the desktop"));
        o->box(FL_FLAT_BOX);
        o->color((Fl_Color)23);
        o->callback((Fl_Callback*)cb_Choose1);
      } // Fl_Button* o
      { Fl_Button* o = new Fl_Button(228, 315, 125, 25, gettext("Choose Gradient"));
        o->tooltip(gettext("This will take icons off the desktop"));
        o->box(FL_FLAT_BOX);
        o->color((Fl_Color)23);
        o->callback((Fl_Callback*)cb_Choose2);
      } // Fl_Button* o
      { fm_pref = new Fl_Button(5, 390, 105, 25, gettext("Filemanager"));
        fm_pref->tooltip(gettext("Open the filemanager to change preferences"));
        fm_pref->box(FL_FLAT_BOX);
        fm_pref->color((Fl_Color)23);
        fm_pref->deactivate();
      } // Fl_Button* fm_pref
      { Fl_Check_Button* o = icons_check = new Fl_Check_Button(5, 345, 140, 25, gettext("Icons on Desktop"));
        icons_check->box(FL_FLAT_BOX);
        icons_check->down_box(FL_GTK_DOWN_BOX);
        icons_check->color((Fl_Color)31);
        icons_check->selection_color((Fl_Color)59);
        icons_check->callback((Fl_Callback*)cb_icons_check);
        icons_check->align(Fl_Align(FL_ALIGN_RIGHT|FL_ALIGN_INSIDE));
        icons_check->when(FL_WHEN_CHANGED);
        if(isIconsOnDesktop()){o->value(1);fm_pref->show();}
        else{fm_pref->hide();}
      } // Fl_Check_Button* icons_check
      { Fl_Output* o = current_bg = new Fl_Output(8, 280, 345, 30);
        current_bg->box(FL_FLAT_BOX);
        current_bg->color(FL_LIGHT1);
        current_bg->selection_color(FL_DARK_RED);
        current_bg->labelfont(1);
        current_bg->align(Fl_Align(33));
        bg_name(o,thisBG);
      } // Fl_Output* current_bg
      { Fl_Check_Button* o = check_desktops = new Fl_Check_Button(5, 365, 142, 25, gettext("Multiple Desktops"));
        check_desktops->tooltip(gettext("This allows you to have multiple screens to work on from one Display"));
        check_desktops->box(FL_FLAT_BOX);
        check_desktops->down_box(FL_GTK_DOWN_BOX);
        check_desktops->color((Fl_Color)31);
        check_desktops->selection_color((Fl_Color)59);
        check_desktops->callback((Fl_Callback*)cb_check_desktops);
        check_desktops->align(Fl_Align(FL_ALIGN_RIGHT|FL_ALIGN_INSIDE));
        check_desktops->when(FL_WHEN_CHANGED);
        bool m = multipleDesktops();o->value(0);
        if(m){o->value(1);}
      } // Fl_Check_Button* check_desktops
      { Fl_Value_Input* o = num_desktop_w = new Fl_Value_Input(150, 345, 20, 20, gettext("Workspaces Wide"));
        num_desktop_w->tooltip(gettext("Number of workspaces to the left and right"));
        num_desktop_w->box(FL_FLAT_BOX);
        num_desktop_w->color((Fl_Color)53);
        num_desktop_w->callback((Fl_Callback*)cb_num_desktop_w);
        num_desktop_w->align(Fl_Align(FL_ALIGN_RIGHT));
        int width = getIntAttribute("Desktops","width");
        o->value(width);
      } // Fl_Value_Input* num_desktop_w
      { Fl_Value_Input* o = num_desktop_h = new Fl_Value_Input(150, 370, 20, 20, gettext("Workspaces High "));
        num_desktop_h->tooltip(gettext("Number of workspaces up and down"));
        num_desktop_h->box(FL_FLAT_BOX);
        num_desktop_h->color((Fl_Color)53);
        num_desktop_h->callback((Fl_Callback*)cb_num_desktop_h);
        num_desktop_h->align(Fl_Align(FL_ALIGN_RIGHT));
        int height = getIntAttribute("Desktops","height");
        o->value(height);
      } // Fl_Value_Input* num_desktop_h
      { Fl_Button* o = new Fl_Button(233, 390, 65, 25, gettext("Cancel"));
        o->box(FL_FLAT_BOX);
        o->color((Fl_Color)80);
        o->selection_color((Fl_Color)81);
        o->labelcolor(FL_BACKGROUND2_COLOR);
        o->callback((Fl_Callback*)cb_Cancel);
      } // Fl_Button* o
      { Fl_Button* o = new Fl_Button(308, 390, 45, 25, gettext("OK"));
        o->tooltip(gettext("Write to configuration file"));
        o->box(FL_FLAT_BOX);
        o->color((Fl_Color)61);
        o->selection_color((Fl_Color)59);
        o->labelcolor((Fl_Color)55);
        o->callback((Fl_Callback*)cb_OK);
      } // Fl_Button* o
      { Fl_Button* o = new Fl_Button(300, 355, 55, 25, gettext("Names"));
        o->tooltip(gettext("Name your workspaces"));
        o->box(FL_FLAT_BOX);
        o->color((Fl_Color)23);
        o->hide();
        o->deactivate();
      } // Fl_Button* o
      o->end();
    } // Fl_Scroll* o
    startup(o,jsm_desktop_xpm);
    desktop_window->xclass("jsm-desktop");
    desktop_window->end();
    desktop_window->resizable(desktop_window);
  } // Fl_Double_Window* desktop_window
  return desktop_window;
}
