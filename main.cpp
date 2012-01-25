#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include "RC_Enums.h"
#include "RC_Cube.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

#define CUBE_SIDE_LENGTH 3

int main(int argc, char* argv[]) {
    
    RC_Cube* cube = new RC_Cube();
    
    // char array and string to store entered command
    char raw_command[256];
    string command = "";
    
    // exit flag and invalid command flag
    bool exited = false;
    bool invalid = false;
    
    // print help
    
    cube->help();
    
    // loop a prompt while cin is good and while the user has not exited
    while (cin.good() && !exited) {
        
        cout << "--> ";
        
        // process input
        cin.getline(raw_command, 256);
        command = raw_command;
        
        // act on command
        if (command.size() >= 255) {
            cout << "Command too long." << endl;
        } else if (command == "q" ||
            command == "quit" ||
            command == "exit"
        ) {
            exited = true;
            
        } else if (command.size() == 0) {
            
        } else if (command == "p" || 
                   command == "d" || 
                   command == "print" || 
                   command == "display" 
        ) {   
            cube->print();
            
        } else if (command == "j" || 
                   command == "js" || 
                   command == "json"
        ) {   
            cube->print_json();
            
        } else if (command == "reset" ||
                   command == "clear"
        ) {
            cube->reset();
        
        } else if (command == "c" ||
                   command == "color"
        ) {
            toggle_color();
        
        } else if (command == "f" || 
                   command == "fr" || 
                   command == "front"
        ) {
            cube->print_face(FRONT);
            
        } else if (command == "t" ||
                   command == "to" ||
                   command == "top"
        ) {
            cube->print_face(TOP);
            
        } else if (command == "bo" ||
                   command == "bt" ||
                   command == "bottom"
        ) {
            cube->print_face(BOTTOM);
            
        } else if (command == "ba" ||
                   command == "back"
        ) {
            cube->print_face(BACK);
            
        } else if (command == "b") {
            cube->print_face(BACK);
            cube->print_face(BOTTOM);
            
        } else if (command == "l" ||
                   command == "le" ||
                   command == "left"
        ) {
            cube->print_face(LEFT);
            
        } else if (command == "r" ||
                   command == "ri" ||
                   command == "rg" ||
                   command == "right"
        ) {
            cube->print_face(RIGHT);
            
        } else if (command == "h" ||
                   command == "help" ||
                   command == "?"
        ) {
            cube->help();
           
        } else if (command.size() == 6 || command.size() == 3) {
            
            bool clockwise = true;
            int index = 0;
            RC_Plane plane = XY;
            
            // determine plane
            if (command[0] == 'z' && command[1] == ' ') {
                plane = XY;
            } else if (command[0] == 'y' && command[1] == ' ') { 
                plane = XZ;
            } else if (command[0] == 'x' && command[1] == ' ') {
                plane = YZ;
            } else {
                invalid = true;
            }
            
            // determine index
            if (isdigit(command[2])) {
                index = atoi(&command[2]);
                if (index >= CUBE_SIDE_LENGTH || index < 0) {
                    invalid = true;
                }
            } else {
                invalid = true;
            }
            
            // determine direction
            if (command.size() == 3) {
                clockwise = true;
            } else if (command[3] == ' ' && command[4] == 'c' && command[5] == 'w') {
                clockwise = true;
            } else if (command[3] == ' ' && command[4] == 'c' && command[5] == 'c') {
                clockwise = false; 
            } else {
                invalid = true;
            }
            
            // spin the cube if everything was alright
            if (!invalid) {
                cube->spin(plane, index, clockwise);
                cube->print();
            }
            
        } else {
            invalid = true;
        }
        
        if (invalid) {
            cout << "Unknown command: \"" << command << "\"." << endl;
            invalid = false;
        }
    }
    
    cout << "Goodbye!" << endl;
    
    return 0;
}
