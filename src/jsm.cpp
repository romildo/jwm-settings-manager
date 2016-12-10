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

/*Project Includes*/
#include <iostream>
#include <iomanip>
#include <string>
//my common functions
#include "../include/jwmrc.h"
#include "../include/ui.h"
#include "../fltk/jwm-shutdown.h"
int showHelp();
int makeWindow();
int Shutdown();
int showDEBUG();
std::string copyrightFile;
std::string email="israeldahl@gmail.com";
std::string author="Israel Dahl";
std::string year="2014-2016";
std::string WEB="http://torios.top";
std::string TOOLKITS="nanosvg, pugixml and FLTK";
std::string programName = "jwm-settings-manager";
std::string LICENSE="  This program is free software: you can redistribute it and/or modify\n\
  it under the terms of the GNU General Public License as published by\n\
  the Free Software Foundation, either version 3 of the License, or\n\
  (at your option) any later version.\n\
\n\
  This program is distributed in the hope that it will be useful,\n\
  but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n\
  GNU General Public License for more details.\n\
\n\
  You should have received a copy of the GNU General Public License\n\
  along with this program.  If not, see <http://www.gnu.org/licenses/>.\n";
std::string copyright="                 JWM Settings Manager\n\
\n\
  "+programName+" configures JWM using "+TOOLKITS+"\n\
\n\
          Copyright (C) "+year+"  "+author+" <"+email+">\n"+LICENSE+"n\
  This has been developed as a part of the ToriOS Project\n\
  "+WEB+"\n\
\n\
\n\
  You may redistribute this, but you must keep this comment in place\n\
  Jesus is my Lord, and if you don't like it feel free to ignore it.\n\
 ";
unsigned int versionMajor = 2;
unsigned int versionMinor = 0;
unsigned int revNo = 0;
std::string ARGicons= "--icons";
std::string ARGautostart= "--autostart";
std::string ARGdesktop= "--desktop";
std::string ARGshutdown= "--shutdown";
std::string ARGwindow= "--window";
std::string ARGclock= "--clock";
std::string ARGpanel= "--panel";
std::string ARGmouse= "--mouse";
std::string ARGkeyboard= "--keyboard";
std::string ARGfont= "--font";
std::string menu= "--menu";
std::string themes= "--themes";
std::string halt = "--halt";
std::string ARGshortcuts = "--shortcuts";
std::string ARGhelp="--help";
std::string ARGversion="--version";
std::string ARGcopyright="--copyright";
std::string ARGdebug="--debug";
std::string ARGpopup="--popups";
int main(int argc, char *argv[]){

    try{
    //integers for searching the argv
    std::string command;
    if(argc>0){
        for(int i=1;i<argc;++i){
            command=argv[i];
            for(int i=0;i<argc;i++){

                #ifdef DEBUG
                    std::cerr<<"command argument: "<<command<<std::endl;
                #endif // DEBUG

                if((command.compare(ARGhelp)==0)||(command.compare("-h")==0)){
                    return showHelp();
                }
                else if((command.compare(ARGversion)==0)||(command.compare("-v")==0)){
                    std::cout<<programName<<" Version: "<<versionMajor<<"."<<versionMinor<<"."<<revNo<<" by "<<author<<"\n  A tool to easily configure JWM.  Built using nanosvg, pugixml and FLTK,\n is fast, and light, but doesn't sacrifice aesthetics."<<std::endl;
                    return 0;
                }
                else if((command.compare(ARGautostart)==0)||(command.compare("-a")==0)){
                    return showAutostart();
                }
                else if((command.compare(ARGshutdown)==0)||(command.compare(halt)==0)){
                    return Shutdown();
                }
                else if((command.compare(ARGwindow)==0)||(command.compare("-w")==0)){
                    return showWindow();
                }
                else if((command.compare(ARGclock)==0)||(command.compare("-l")==0)){
                    return showClock();
                }
                else if((command.compare(ARGdesktop)==0)||(command.compare("-d")==0)){
                    return showDesktop();
                }
                else if((command.compare(ARGpanel)==0)||(command.compare("-p")==0)){
                    return showPanel();
                }
                else if((command.compare(themes)==0)||(command.compare("-t")==0)){
                    return showThemes();
                }
                else if((command.compare(ARGicons)==0)||(command.compare("-i")==0)){
                    return showIcons();
                }
                else if((command.compare(ARGfont)==0)||(command.compare("-f")==0)){
                    return showFonts();
                }
                else if((command.compare(ARGkeyboard)==0)||(command.compare("-k")==0)){
                    return showKeyboard();
                }
                else if((command.compare(menu)==0)||(command.compare("-u")==0)){
                    return showMenu();
                }
                else if((command.compare(ARGmouse)==0)||(command.compare("-m")==0)){
                    return showMouse();
                }
                else if((command.compare(ARGshortcuts)==0)||(command.compare("-s")==0)){
                    return showShortcuts();
                }
                else if(command.compare(ARGpopup)==0){
                    return showPopus();
                }
                else if((command.compare(ARGcopyright)==0)||(command.compare("-c")==0)){
                    copyrightFile=linuxcommon::find_xdg_data_dir_subdir(programName);
                    copyrightFile+="COPYING";
                    if(linuxcommon::test_file(copyrightFile)){
						linuxcommon::print_file_to_stdout(copyrightFile);
					}
                    else{
						std::cout<<copyright<<std::endl;
					}
                    return 0;
                }
                else if(command.compare(ARGdebug)==0){
                    return showDEBUG();
                }
                else {
                    std::cerr<< "Invalid command"<<std::endl;
                    showHelp();
                    return 1;
                }
            }
        }
    }
    return showSettings();
    }
    catch (const std::exception& e){
        std::cerr << "Unhandled exception:\n" << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (...){
        std::cerr << "Unknown exception!" << std::endl;
        return EXIT_FAILURE;
    }
}
int showHelp(){
    std::cout << "Usage: "<<programName<<" [Option]\n\n"
        <<programName<<" will open the Main settings screen if no options are supplied\nconfigure JWM easily\n\n"
        <<"Options:\n"
        <<" -a "<<ARGautostart<<"   show autostart settings\n"
        <<" -d "<< ARGdesktop<<"     show desktop settings\n"
        <<" -f "<<ARGfont<<"        show font settings\n"
        <<" -h "<<ARGhelp<<"        show this listing\n"
        <<" -i "<<ARGicons<<"       show icon settings\n"
        <<" -k "<<ARGkeyboard<<"    show keyboard settings\n"
        <<" -m "<<ARGmouse<<"       show mouse settings\n"
        <<" -p "<<ARGpanel<<"       show panel settings\n"
        <<" -t "<<themes<<"      show theme settings\n"
        <<" -w "<<ARGwindow<<"      show window settings\n"
        <<" "<<ARGpopup<<"        show popups window\n"
        //<<" -r "<<ARGrecover<<"     recover settings file\n"
        <<" -v "<<ARGversion<<"     show current version\n"
        <<" -c "<<ARGcopyright<<"   show copyright information\n"
        <<" "<<ARGdebug<<"        show debugging output\n"
        <<"\n SHORTCUTS FOR USE IN THE PANELS AND MENUS\n"
        <<" "<<ARGshutdown<<" "<<halt <<"   show shutdown menu\n"
        <<" -u "<<menu<<"        show menu editor\n"
        <<" -l "<<ARGclock<<"        show clock settings\n"
        <<" -s "<<ARGshortcuts <<"         show shortcut editor\n\n"
        <<" Version: "<<versionMajor<<"."<<versionMinor<<"."<<revNo
        << std::endl;
    return 0;
}
int showDEBUG(){
std::cout<<"int showDEBUG()"<<std::endl;
	if(!setJSMItem("debug","true")){std::cerr<<"Could not activate debug settings";}
	else{std::cout<<"I suppose the item was set correctly"<<std::endl;}
	return showSettings();
}
int Shutdown(){
    shutdown ui;
    ui.make_window()->xclass("JSM");
    ui.make_window()->show();
    return Fl::run();
}
