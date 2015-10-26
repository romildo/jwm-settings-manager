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

#include <libintl.h>
#include "jwm-icons.h"

void IconsUI::cb_Cancel_i(Fl_Button*, void*) {
  cancel(icons_window);
//icons_window->hide();
UI ux;
ux.showSettings();
}
void IconsUI::cb_Cancel(Fl_Button* o, void* v) {
  ((IconsUI*)(o->parent()->parent()->user_data()))->cb_Cancel_i(o,v);
}

void IconsUI::cb_save_button_i(Fl_Button*, void*) {
  flIcons icons;
bool saver = icons.useTheme(iconsBrowser);
if(saver){saveJWMRC(icons_window);}
else{icons_window->hide();}
UI ux;
ux.showSettings();
}
void IconsUI::cb_save_button(Fl_Button* o, void* v) {
  ((IconsUI*)(o->parent()->parent()->user_data()))->cb_save_button_i(o,v);
}

Fl_Double_Window* IconsUI::make_window() {
  load();
  saveChangesTemp();
  { Fl_Double_Window* o = icons_window = new Fl_Double_Window(330, 280, gettext("Icons"));
    icons_window->color((Fl_Color)31);
    icons_window->user_data((void*)(this));
    { Fl_Scroll* o = new Fl_Scroll(0, 0, 330, 290);
      o->color((Fl_Color)31);
      { Fl_Button* o = new Fl_Button(205, 245, 57, 25, gettext("Cancel"));
        o->box(FL_FLAT_BOX);
        o->color((Fl_Color)80);
        o->selection_color((Fl_Color)81);
        o->labelcolor(FL_BACKGROUND2_COLOR);
        o->callback((Fl_Callback*)cb_Cancel);
      } // Fl_Button* o
      { save_button = new Fl_Button(271, 245, 45, 25, gettext("OK"));
        save_button->tooltip(gettext("Write to configuration file"));
        save_button->box(FL_FLAT_BOX);
        save_button->color((Fl_Color)61);
        save_button->selection_color((Fl_Color)59);
        save_button->labelcolor((Fl_Color)55);
        save_button->callback((Fl_Callback*)cb_save_button);
      } // Fl_Button* save_button
      { Fl_Browser* o = iconsBrowser = new Fl_Browser(10, 15, 310, 220);
        iconsBrowser->type(1);
        iconsBrowser->box(FL_FLAT_BOX);
        iconsBrowser->selection_color((Fl_Color)80);
        iconsBrowser->when(FL_WHEN_ENTER_KEY);
        flIcons icons;
        icons.loadTheme(o);
      } // Fl_Browser* iconsBrowser
      o->end();
    } // Fl_Scroll* o
    startup(o);
    icons_window->xclass("jsm-icons");
    icons_window->end();
    icons_window->resizable(icons_window);
  } // Fl_Double_Window* icons_window
  return icons_window;
}

void IconsUI::startup(Fl_Window *o) {
  Config config; config.under_mouse(o);
  o->icon(config.Get_Fl_Icon(jsm_icons_xpm));
}
