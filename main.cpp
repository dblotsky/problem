#include <iostream>
#include "RC_Enums.h"
#include "RC_Cube.h"

using std::cin;
using std::endl;

int main(int argc, char* argv[]) {
    
    RC_Cube* cube = new RC_Cube();
    
    cube->print();
    cube->spin(YZ, 1, true);
    cube->print();
    
    // char array and string to store entered command
    char raw_command[256];
    string command = "";
    
    // exit flag
    bool exited = false;
    
    // loop a prompt while cin is good and while the user has not exited
    while (cin.good() && !exited) {
        
        cout << "--> ";
        
        // process input
        cin.getline(command, 256);
        command_string = command;
        
        // act on command
        if (command == "q") {
            
        }
    }
    
    cout << "Goodbye!" << endl;
    
    return 0;
}
