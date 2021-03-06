// generated by Fast Light User Interface Designer (fluid) version 1.0303

#ifndef desktop_file_editor_h
#define desktop_file_editor_h
#include <FL/Fl.H>
#include <dirent.h>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <algorithm>
#include <float.h>
#include "../include/fltkfunctions.hpp"
#include <sstream>
#include <FL/Fl_Text_Buffer.H>
#include "../include/common.hpp"
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Output.H>

class Desktop : public FLTK_FUNCTIONS {
  std::string LOCALE_STRING, CURRENT_FILE; 
public:
  Fl_Text_Buffer * textBuffer; 
  Fl_Double_Window* make_window(std::string filePassedIn);
  Fl_Input *name;
  Fl_Input *comment;
  Fl_Input *tryexec;
  Fl_Input *exec;
  Fl_Input *icon;
  Fl_Input *type;
  Fl_Input *categories;
  Fl_Input *notshowin;
  Fl_Input *onlyshowin;
  Fl_Input *terminal;
  Fl_Input *nodisplay;
  static unsigned char menu_Type_i18n_done;
  static Fl_Menu_Item menu_Type[];
private:
  inline void cb_Application_i(Fl_Menu_*, void*);
  static void cb_Application(Fl_Menu_*, void*);
  inline void cb_Link_i(Fl_Menu_*, void*);
  static void cb_Link(Fl_Menu_*, void*);
  inline void cb_Directory_i(Fl_Menu_*, void*);
  static void cb_Directory(Fl_Menu_*, void*);
  inline void cb_OTHER_i(Fl_Menu_*, void*);
  static void cb_OTHER(Fl_Menu_*, void*);
public:
  Fl_Menu_Button *cat_Button;
  static unsigned char menu_cat_Button_i18n_done;
  static Fl_Menu_Item menu_cat_Button[];
private:
  inline void cb_AudioVideo_i(Fl_Menu_*, void*);
  static void cb_AudioVideo(Fl_Menu_*, void*);
  inline void cb_Development_i(Fl_Menu_*, void*);
  static void cb_Development(Fl_Menu_*, void*);
  inline void cb_Education_i(Fl_Menu_*, void*);
  static void cb_Education(Fl_Menu_*, void*);
  inline void cb_Game_i(Fl_Menu_*, void*);
  static void cb_Game(Fl_Menu_*, void*);
  inline void cb_Graphics_i(Fl_Menu_*, void*);
  static void cb_Graphics(Fl_Menu_*, void*);
  inline void cb_Network_i(Fl_Menu_*, void*);
  static void cb_Network(Fl_Menu_*, void*);
  inline void cb_Office_i(Fl_Menu_*, void*);
  static void cb_Office(Fl_Menu_*, void*);
  inline void cb_Science_i(Fl_Menu_*, void*);
  static void cb_Science(Fl_Menu_*, void*);
  inline void cb_Settings_i(Fl_Menu_*, void*);
  static void cb_Settings(Fl_Menu_*, void*);
  inline void cb_System_i(Fl_Menu_*, void*);
  static void cb_System(Fl_Menu_*, void*);
  inline void cb_Utility_i(Fl_Menu_*, void*);
  static void cb_Utility(Fl_Menu_*, void*);
public:
  Fl_Menu_Button *nsi_Button;
  static unsigned char menu_nsi_Button_i18n_done;
  static Fl_Menu_Item menu_nsi_Button[];
private:
  inline void cb_ToriOS_i(Fl_Menu_*, void*);
  static void cb_ToriOS(Fl_Menu_*, void*);
  inline void cb_GNOME_i(Fl_Menu_*, void*);
  static void cb_GNOME(Fl_Menu_*, void*);
  inline void cb_KDE_i(Fl_Menu_*, void*);
  static void cb_KDE(Fl_Menu_*, void*);
  inline void cb_LXDE_i(Fl_Menu_*, void*);
  static void cb_LXDE(Fl_Menu_*, void*);
  inline void cb_MATE_i(Fl_Menu_*, void*);
  static void cb_MATE(Fl_Menu_*, void*);
  inline void cb_Razor_i(Fl_Menu_*, void*);
  static void cb_Razor(Fl_Menu_*, void*);
  inline void cb_ROX_i(Fl_Menu_*, void*);
  static void cb_ROX(Fl_Menu_*, void*);
  inline void cb_TDE_i(Fl_Menu_*, void*);
  static void cb_TDE(Fl_Menu_*, void*);
  inline void cb_Unity_i(Fl_Menu_*, void*);
  static void cb_Unity(Fl_Menu_*, void*);
  inline void cb_XFCE_i(Fl_Menu_*, void*);
  static void cb_XFCE(Fl_Menu_*, void*);
  inline void cb_EDE_i(Fl_Menu_*, void*);
  static void cb_EDE(Fl_Menu_*, void*);
  inline void cb_Cinnamon_i(Fl_Menu_*, void*);
  static void cb_Cinnamon(Fl_Menu_*, void*);
  inline void cb_Old_i(Fl_Menu_*, void*);
  static void cb_Old(Fl_Menu_*, void*);
public:
  Fl_Menu_Button *osi_Button;
  static unsigned char menu_osi_Button_i18n_done;
  static Fl_Menu_Item menu_osi_Button[];
private:
  inline void cb_ToriOS1_i(Fl_Menu_*, void*);
  static void cb_ToriOS1(Fl_Menu_*, void*);
  inline void cb_GNOME1_i(Fl_Menu_*, void*);
  static void cb_GNOME1(Fl_Menu_*, void*);
  inline void cb_KDE1_i(Fl_Menu_*, void*);
  static void cb_KDE1(Fl_Menu_*, void*);
  inline void cb_LXDE1_i(Fl_Menu_*, void*);
  static void cb_LXDE1(Fl_Menu_*, void*);
  inline void cb_MATE1_i(Fl_Menu_*, void*);
  static void cb_MATE1(Fl_Menu_*, void*);
  inline void cb_Razor1_i(Fl_Menu_*, void*);
  static void cb_Razor1(Fl_Menu_*, void*);
  inline void cb_ROX1_i(Fl_Menu_*, void*);
  static void cb_ROX1(Fl_Menu_*, void*);
  inline void cb_TDE1_i(Fl_Menu_*, void*);
  static void cb_TDE1(Fl_Menu_*, void*);
  inline void cb_Unity1_i(Fl_Menu_*, void*);
  static void cb_Unity1(Fl_Menu_*, void*);
  inline void cb_XFCE1_i(Fl_Menu_*, void*);
  static void cb_XFCE1(Fl_Menu_*, void*);
  inline void cb_EDE1_i(Fl_Menu_*, void*);
  static void cb_EDE1(Fl_Menu_*, void*);
  inline void cb_Cinnamon1_i(Fl_Menu_*, void*);
  static void cb_Cinnamon1(Fl_Menu_*, void*);
  inline void cb_Old1_i(Fl_Menu_*, void*);
  static void cb_Old1(Fl_Menu_*, void*);
public:
  Fl_Menu_Button *term_Button;
  static unsigned char menu_term_Button_i18n_done;
  static Fl_Menu_Item menu_term_Button[];
private:
  inline void cb_True_i(Fl_Menu_*, void*);
  static void cb_True(Fl_Menu_*, void*);
  inline void cb_False_i(Fl_Menu_*, void*);
  static void cb_False(Fl_Menu_*, void*);
public:
  Fl_Menu_Button *nod_Button;
  static unsigned char menu_nod_Button_i18n_done;
  static Fl_Menu_Item menu_nod_Button[];
private:
  inline void cb_True1_i(Fl_Menu_*, void*);
  static void cb_True1(Fl_Menu_*, void*);
  inline void cb_False1_i(Fl_Menu_*, void*);
  static void cb_False1(Fl_Menu_*, void*);
public:
  Fl_Button *icon_display;
private:
  inline void cb_icon_display_i(Fl_Button*, void*);
  static void cb_icon_display(Fl_Button*, void*);
public:
  Fl_Input *genericname;
  Fl_Input *version;
  Fl_Input *path;
  Fl_Input *mime;
  Fl_Input *implements;
  Fl_Input *keywords;
  Fl_Input *wmclass;
  Fl_Input *url;
  Fl_Input *actions;
  Fl_Input *notify;
  Fl_Input *hidden;
  Fl_Input *dbus;
  Fl_Menu_Button *notify_Button;
  static unsigned char menu_notify_Button_i18n_done;
  static Fl_Menu_Item menu_notify_Button[];
private:
  inline void cb_True2_i(Fl_Menu_*, void*);
  static void cb_True2(Fl_Menu_*, void*);
  inline void cb_False2_i(Fl_Menu_*, void*);
  static void cb_False2(Fl_Menu_*, void*);
  static unsigned char menu_Hidden_i18n_done;
  static Fl_Menu_Item menu_Hidden[];
  inline void cb_True3_i(Fl_Menu_*, void*);
  static void cb_True3(Fl_Menu_*, void*);
  inline void cb_False3_i(Fl_Menu_*, void*);
  static void cb_False3(Fl_Menu_*, void*);
  static unsigned char menu_DBusActivatable_i18n_done;
  static Fl_Menu_Item menu_DBusActivatable[];
  inline void cb_True4_i(Fl_Menu_*, void*);
  static void cb_True4(Fl_Menu_*, void*);
  inline void cb_False4_i(Fl_Menu_*, void*);
  static void cb_False4(Fl_Menu_*, void*);
public:
  Fl_Browser *locales_browser;
private:
  inline void cb_locales_browser_i(Fl_Browser*, void*);
  static void cb_locales_browser(Fl_Browser*, void*);
public:
  Fl_Browser *result_locale;
private:
  inline void cb_result_locale_i(Fl_Browser*, void*);
  static void cb_result_locale(Fl_Browser*, void*);
public:
  Fl_Input *locale_value;
private:
  inline void cb_locale_value_i(Fl_Input*, void*);
  static void cb_locale_value(Fl_Input*, void*);
  inline void cb_OPEN_i(Fl_Button*, void*);
  static void cb_OPEN(Fl_Button*, void*);
public:
  Fl_Button *save_button;
private:
  inline void cb_save_button_i(Fl_Button*, void*);
  static void cb_save_button(Fl_Button*, void*);
public:
  Fl_Input *Filename;
private:
  inline void cb_Filename_i(Fl_Input*, void*);
  static void cb_Filename(Fl_Input*, void*);
  inline void cb_CLEAR_i(Fl_Button*, void*);
  static void cb_CLEAR(Fl_Button*, void*);
  inline void cb_PREVIEW_i(Fl_Button*, void*);
  static void cb_PREVIEW(Fl_Button*, void*);
  inline void cb__i(Fl_Button*, void*);
  static void cb_(Fl_Button*, void*);
public:
  Fl_Double_Window* preview_window(std::string message);
  Fl_Double_Window *preview_win;
  Fl_Text_Editor *file_editor;
private:
  inline void cb_SAVE_i(Fl_Button*, void*);
  static void cb_SAVE(Fl_Button*, void*);
  inline void cb_CLOSE_i(Fl_Button*, void*);
  static void cb_CLOSE(Fl_Button*, void*);
public:
  void activate(Fl_Input* o);
  void activate(Fl_Menu_Button* o);
  void check_type();
  std::string choose_directory();
  void clear_all();
  void clear_input(Fl_Input *o);
  void close(Fl_Double_Window* o);
  void DEactivate(Fl_Input* o);
  void DEactivate(Fl_Menu_Button* o);
  std::string get_line(std::string filename, std::string line);
  bool isEmpty(Fl_Input *o);
  std::string keyWords(std::string filename);
  void load(std::string result);
  void locale_chooser(std::string filename, bool getval);
  void make_red(Fl_Input *o);
  void make_white(Fl_Input *o);
  bool not_showin(std::string filename);
  std::string name_line(std::string filename);
  std::string name_locale_line(std::string filename,Fl_Browser *o);
  std::string no_browser_name_locale(std::string filename, std::string LANG);
  bool no_display(std::string filename);
  void NotShowIn(const char* DE);
  bool only_show(std::string filename);
  void OnlyShowIn(const char* DE);
  void open_file();
  void populate(std::string fileName);
  bool check_file();
  void set_input(Fl_Input *o, std::string val);
  void show_all();
  void show_apps_only();
  void show_dir_only();
  void show_link_only();
  std::string stringfile();
  std::string termie_out(std::string terminal_Command_You_Want_Output_From);
  std::string testValue(std::string TEXT, Fl_Input* o);
  void write_out();
  void save_file();
  Fl_Double_Window* save_error();
  Fl_Double_Window *error_win;
private:
  inline void cb_OK_i(Fl_Button*, void*);
  static void cb_OK(Fl_Button*, void*);
  inline void cb_1_i(Fl_Button*, void*);
  static void cb_1(Fl_Button*, void*);
public:
  Fl_Double_Window* help_window();
  Fl_Double_Window *help_win;
private:
  inline void cb_CLOSE1_i(Fl_Button*, void*);
  static void cb_CLOSE1(Fl_Button*, void*);
public:
  Fl_Browser *help_browser;
  void get_help(Fl_Browser *o);
  void populate_locales(Fl_Browser *o,std::string filename);
  std::string locales_string();
  void preview_text(Fl_Text_Display *o,std::string TEXT);
  void write_out(const char* txt);
  void check_save();
};
int main(int argc, char *argv[]);
#endif
