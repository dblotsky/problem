#include <cassert>
#include <string>
#include <iostream>
#include "RC_Enums.h"

using std::string;
using std::cerr;
using std::endl;

static bool use_color = false;

void toggle_color() {
    if (use_color) {
        use_color = false;
    } else {
        use_color = true;
    }
}

void on_color() {
    use_color = true;
}

void off_color() {
    use_color = false;
}

bool using_color() {
    return use_color;
}

string str(RC_Face face) {
    string return_value = "";
    
    switch (face) {
        case FRONT:
            return_value = "FRONT";
            break;
            
        case BACK:
            return_value = "BACK";
            break;
            
        case LEFT:
            return_value = "LEFT";
            break;
            
        case RIGHT:
            return_value = "RIGHT";
            break;
            
        case TOP:
            return_value = "TOP";
            break;
            
        case BOTTOM:
            return_value = "BOTTOM";
            break;
            
        default:
            cerr << "unexpected face: " << face << endl;
            assert(false);
    }
    
    return return_value;
}

string str(RC_Color color) {
    
    string return_value = "";
    string display_character = "#";
    
    if (use_color) {
        switch (color) {
            case ORANGE:
                return_value = "\033[31m" + display_character + "\033[m ";
                break;
                
            case BLUE:
                return_value = "\033[32m" + display_character + "\033[m ";
                break;
                
            case WHITE:
                return_value = "\033[33m" + display_character + "\033[m ";
                break;
                
            case GREEN:
                return_value = "\033[34m" + display_character + "\033[m ";
                break;
                
            case RED:
                return_value = "\033[35m" + display_character + "\033[m ";
                break;
                
            case YELLOW:
                return_value = "\033[36m" + display_character + "\033[m ";
                break;
                
            case BLANK:
                return_value = "* ";
                break;
                
            default:
                cerr << "unexpected color: " << color << endl;
                assert(false);
        }
    } else {
        switch (color) {
            case ORANGE:
                return_value = "1";
                break;
                
            case BLUE:
                return_value = "2";
                break;
                
            case WHITE:
                return_value = "3";
                break;
                
            case GREEN:
                return_value = "4";
                break;
                
            case RED:
                return_value = "5";
                break;
                
            case YELLOW:
                return_value = "6";
                break;
                
            case BLANK:
                return_value = "*";
                break;
                
            default:
                cerr << "unexpected color: " << color << endl;
                assert(false);
        }
    }
    
    return return_value;
}
