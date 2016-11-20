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
#include <libintl.h>
#include "../include/fonts.hpp"

/*FUNCTIONS*/
//Integer///////////////////////////////////////////////////////////////
unsigned int getFontColor(std::string whichElement){
	debug_out("unsigned int getFontColor(std::string "+whichElement+")");
	std::string color=getElementText(whichElement,"Foreground");
	return flCOLOR(color);
}
int get_font_size(std::string whichElement){
	debug_out("int get_font_size(std::string "+ whichElement+")");
	int font_size=12;
	std::string font =fontTest(whichElement);
	if (font.compare("")!=0){
        unsigned int fontSizeInt;
        std::string fontSize;
        std::string::size_type position = font.find(':');
        std::string::size_type size = font.find('-');
        if((font.find('-')!=std::string::npos)&&(font.find(':')!=std::string::npos)){
            fontSize = font.substr (size+1,(position-(size+1)));
            fontSizeInt = convert(fontSize.c_str());
            debug_out("FontSize= "+fontSize);
            return fontSizeInt;
        }
    }
    else{
        missingFont(whichElement);
        return get_font_size(whichElement);
    }
	return font_size;
	/*font_size_slider->value(font_size);
	Why does this crash everything??
	chooser_size->value(font_size);
	chooser_size->redraw();
	*/
}
//String////////////////////////////////////////////////////////////////
std::string fontTest(std::string whichElement){
	debug_out("std::string fontTest(std::string "+whichElement+")");
	std::string font=getElementText(whichElement,"Font");
	if(font.compare("")==0){missingFont(whichElement);}
	debug_out("FONT="+font);
	return font;
}
std::string getDefaultFONT(){
	std::vector<std::string> defaults;
	defaults.push_back("sans");
	defaults.push_back("droid");
	defaults.push_back("serif");
	defaults.push_back("arial");
	for( std::vector<std::string>::iterator it = defaults.begin();
		it!=defaults.end();
		++it){
		std::string fonty=*it;
		if(isFONT(fonty))return fonty;
	}
	return "sans";
}
std::string processFont(std::string font){
	debug_out("std::string processFont(std::string "+font+")");
	// make sure we process the font correctly
	std::string result=font;
	unsigned int found=result.find(" bold");
	if(found<result.length()){
		result=result.erase(found,5);
		debug_out("processFont(bold)-> result="+result);
	}
	found=result.find(" italic");
	if(found<result.length()){
		result=result.erase(found,7);
		debug_out("processFont(italic)-> result="+result);
	}
	debug_out("processFont TOTAL-> result="+result);
	return result;
}
std::string processFontOPTS(std::string font,std::string currentOPTS){
	//TODO remove bold/italic if they are not in the current font, and in the OLD options...
	debug_out("std::string processFontOPTS(std::string "+font+",std::string "+currentOPTS+")");
	// make sure we process the font Options correctly
	std::string result=font;
	std::string type;
	unsigned int found=result.find(" bold");
	unsigned int finder=currentOPTS.find(":bold");
	if((finder>currentOPTS.length())&&(found<result.length())){type=":bold";}
	found=result.find(" italic");
	finder=currentOPTS.find(":italic");
	if((finder>currentOPTS.length())&&(found<result.length())){type+=":italic";}
	type=currentOPTS+type;
	debug_out("processFontOPTS-> modified options="+type);
	return type;
}
//Boolean////////////////////////////////////////////////////////////////
bool isFONT(std::string font){
	Fl_Font a;
	a = Fl::set_fonts("-*");
    std::string v;
    Fl_Font i;
    for (i=1;i!=a;++i){
        v = Fl::get_font_name(i,0);
        if(v.compare(font)==0){return true;}
    }
	return false;
}
bool newOne(){
	debug_out("bool newOne()");
	switch (newStyle()){
		case -1:
			return false;
			break;
		case 0:
			return false;
			break;
		case 1:
			return true;
			break;
		default:
			return true;
			break;
	}
}
//Void//////////////////////////////////////////////////////////////////
void missingFont(std::string whichElement){
	debug_out("");
	std::string DEFAULTfont=getDefaultFONT();
    DEFAULTfont=DEFAULTfont+"-12:antialias=true:encoding=utf8";
    if(!setElementText(whichElement,"Font",DEFAULTfont)){debug_out("Missing font FAILED to set: "+DEFAULTfont+" for "+whichElement);}
}
void font_browser_cb(Fl_Browser* font_browser,Fl_Output *font_name,Fl_Slider* font_size_slider){
	const char * item = font_browser->text(font_browser->value());
	if(item==NULL){
		debug_out("NULL item in font_browser->text(font_browser->value()) ");
		return;
	}
	std::string temp=item;
	debug_out("Font in browser is:"+temp);
	font_name->value(item);
	Fl_Font b = font_browser->value();
	//std::cout<< Fl::get_font_name(b,0)<<std::endl;
	unsigned int size_of_font = font_size_slider->value();
	Fl_Fontsize fs = size_of_font;
	font_name->textsize(fs);
	font_name->textfont(b);
	font_name->redraw();
}
void font_chooser_cb(Fl_Output *Widget,Fl_Value_Output *chooser_size,Fl_Output *font_name,std::string currentElement){
	const char* fontFamily = font_name->value();
	if(fontFamily==NULL){return;}
	std::string family = fontFamily;
	if (family.compare("")==0){return;}
	std::transform(family.begin(), family.end(), family.begin(), ::tolower);
	setFontName(family, currentElement);
  	Widget->value(fontFamily);
  	Widget->redraw();
	set_font_size(chooser_size,currentElement);
	saveChanges();
}
void font_color(Fl_Widget *o, std::string active){
	debug_out("void font_color(Fl_Widget *o, std::string "+active+")");
	int c;
	double* colors = choose_a_color(c,o);
	if(active.compare("")==0){
		debug_out("nothing sent in");
		return;
	}
	if(c!=0){ //If color chooser isn't canceled... do stuff
		setFontColor(colors, active);
		unsigned int colorSet = getFontColor(active.c_str());
		o->color(colorSet);
		o->redraw();
	}
}
void font_populate(Fl_Browser *o){
	debug_out("void font_populate(Fl_Browser *o)");
	Fl_Font a;a = Fl::set_fonts("-*");
	std::string v;
	Fl_Font i;
	for (i=1;i!=a;++i){
		v = Fl::get_font_name(i,0);
		o->add(v.c_str());
	}
}
void get_font(std::string element, Fl_Output *o){
	debug_out("void get_font(std::string "+element+", Fl_Output *o)");
	std::string result;
	std::string font=fontTest(element);
	if (font.compare("")!=0){
        std::string::size_type size = font.find_first_of('-');
        if((font.find_last_of('-')!=std::string::npos)){
            result = font.substr(0,size);
        }
    }
    else{debug_out("font is empty string");}
    if(result.compare("")!=0){o->value(result.c_str());}
}
void get_font_color(Fl_Widget *o, std::string whichStyle){
  debug_out("void get_font_color(Fl_Widget *o, std::string "+whichStyle+")");
  unsigned int colour;
  std::string COLOR = getElementText(whichStyle,"Foreground");
  colour=flCOLOR(COLOR);
  o->color(colour);
}
void get_window_font_color(Fl_Widget *o, int Active1_Inactive2){
  debug_out("void get_window_font_color(Fl_Widget *o, int Active1_Inactive2)");
  unsigned int colorSet;
  std::string color;
  if(Active1_Inactive2==1){color=color=getElementText("WindowStyle","Active","Foreground");}
  else{color=getElementText("WindowStyle","Foreground");}
  colorSet=flCOLOR(color);
  o->color(colorSet);
  o->redraw();
}
void set_font_size(Fl_Value_Output *chooser_size,std::string currentElement){
	debug_out("void set_font_size(Fl_Value_Output *chooser_size,std::string "+currentElement+")");
	unsigned int sizer = chooser_size->value();
	std::stringstream converter;
    converter<<sizer;
	std::string SIZE=converter.str();
	std::string font=getElementText(currentElement,"Font");
	if(font.compare("")==0){
		missingFont(currentElement);
		font=getElementText(currentElement,"Font");
	}
	std::string::size_type position = font.find(':');
	std::string::size_type size = font.find('-');
	//create temporary variables and a result variable;
	std::string temp1,temp2,result;
	//get the text AFTER the ':' and save it to temp2
	temp2 = font.substr(position,std::string::npos);
	//get the text BEFORE the '-' and save it to temp1
	temp1 = font.substr(0,size+1);
	//add the stuff together, and...
	result = temp1+SIZE+temp2;
	if(!setElementText(currentElement,"Font",result)){debug_out("FAILED to set the size for the font in "+currentElement);}
}
void setFontName(std::string family, std::string currentElement){
	debug_out("void setFontName(std::string "+family+", std::string "+currentElement+")");
	std::string font=fontTest(currentElement);
	std::string fontName ="";
	std::string fontOptions ="";
	std::string::size_type size = font.find_first_of('-');
	if((font.find('-')!=std::string::npos)){
		fontOptions = font.substr(size,std::string::npos);
		std::string newOPTS=processFontOPTS(family,fontOptions);
		std::string newFAM=processFont(family);
		fontName = newFAM + newOPTS;
		if(!setElementText(currentElement,"Font",fontName)){debug_out("FAILED setting Font name:"+family+" in "+currentElement);}
		else{debug_out(currentElement+" font was successfully set to: "+fontName);}
	}
	else{
		std::string newOPTS=processFontOPTS(family,fontOptions);
		std::string newFAM=processFont(family);
		fontName = newFAM + newOPTS;
		if(!setElementText(currentElement,"Font",fontName)){debug_out("FAILED setting Font name:"+family+" in "+currentElement);}
		else{debug_out(currentElement+" font was successfully set to: "+fontName);}
	}
}
void setSize(unsigned int &fontSize,std::string whichElement){
	debug_out("void setSize(unsigned int &fontSize,std::string "+whichElement+")");
	std::string font=getElementText(whichElement,"Font");
	std::stringstream converter;
    converter<<fontSize;
	std::string fontSizeSTR=converter.str();
	std::string::size_type position = font.find(':');
	std::string::size_type size = font.find('-');
	//create temporary variables and a result variable;
	std::string temp1,temp2,result;
	//get the text AFTER the ':' and save it to temp2
	temp2 = font.substr(position,std::string::npos);
	//get the text BEFORE the '-' and save it to temp1
	temp1 = font.substr(0,size+1);
	//add the stuff together, and...
	result = temp1+fontSizeSTR+temp2;
	if(!setElementText(whichElement,"Font",result)){debug_out("Setting "+whichElement+"->Font to:"+result+" FAILED");}
}
void setFontColor(const double* colors, std::string whichElement){
	debug_out("void setFontColor(const double* colors, std::string "+whichElement+")");
	std::string COLOR=colorToString(colors);
	if(!setElementText(whichElement,"Foreground",COLOR)){debug_out("Could not set: "+whichElement+"->Foreground to: "+COLOR);}
	return;
}
void window_font_color(Fl_Widget *o, int Active1_Inactive2){
	debug_out("void window_font_color(Fl_Widget *o, int Active1_Inactive2)");
	int c;
	double* colors = choose_a_color(c,o);
	unsigned int colorSet;
	std::string colorS;
	if(c!=0){ //If color chooser isn't canceled... do stuff
		if(Active1_Inactive2==1){
			setElementText("WindowStyle",colorToString(colors).c_str());
			colorS = getElementText("WindowStyle",colorToString(colors).c_str());
		}
		else{
			setElementText("WindowStyle","Foreground",colorToString(colors).c_str());
			colorS = getElementText("WindowStyle",colorToString(colors).c_str());
		}
		colorSet=flCOLOR(colorS);
		o->color(colorSet);
		o->redraw();
	}
}