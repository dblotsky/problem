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
    
    // exit flag
    bool exited = false;
    bool invalid = false;
    
    // print help
    const string HELP =
    "\n"
    "+--------------------------------------------------+\n"
    "|                   Rubik's Cube                   |\n"
    "|                                                  |\n"
    "+---------------------+----------------------------+\n"
    "|       COMMAND       |           ACTION           |\n"
    "+---------------------+----------------------------+\n"
    "| p                   | print the cube             |\n"
    "| f|ba|t|bo|l|r       | print a face               |\n"
    "| z|x|y 0|1|2 [cc/cw] | spin a plane of the cube   |\n"
    "+---------------------+----------------------------+\n";
    
    cout << HELP << endl;
    
    // loop a prompt while cin is good and while the user has not exited
    while (cin.good() && !exited) {
        
        cout << "--> ";
        
        // process input
        cin.getline(raw_command, 256);
        command = raw_command;
        
        // act on command
        if (command == "q") {
            exited = true;
            
        } else if (command.size() == 0) {
            
        } else if (command == "p") {
            cube->print();
            
        } else if (command == "r") {
            cube->reset();
         
        } else if (command == "f") {
            cube->print_face(FRONT);
            
        } else if (command == "t") {
            cube->print_face(TOP);
            
        } else if (command == "bo") {
            cube->print_face(BOTTOM);
            
        } else if (command == "ba") {
            cube->print_face(BACK);
            
        } else if (command == "l") {
            cube->print_face(LEFT);
            
        } else if (command == "r") {
            cube->print_face(RIGHT);
            
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
            cout << "Unknown command." << endl;
            invalid = false;
        }
    }
    
    cout << "Goodbye!" << endl;
    
    return 0;
}
