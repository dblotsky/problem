#include <iostream>
#include <string>
#include <cassert>
#include "RC_Cube.h"
#include "RC_CubeNode.h"
#include "RC_Enums.h"

using std::string;
using std::cout;
using std::cerr;
using std::endl;

int RC_Cube::offset(int x, int y, int z) {
    
    if ((x >= SIDE_LENGTH) || 
        (y >= SIDE_LENGTH) || 
        (z >= SIDE_LENGTH) ||
        (x < 0) ||
        (y < 0) ||
        (z < 0))
    {
        assert(false);
    } // if
    
    return (x + (y * SIDE_LENGTH) + (z * SIDE_LENGTH * SIDE_LENGTH));
}

RC_Cube::RC_Cube() {
    
    // create node array
    nodes = new RC_CubeNode*[SIDE_LENGTH * SIDE_LENGTH * SIDE_LENGTH];
    
    // create nodes
    for (int x = 0; x < SIDE_LENGTH; x++) {
        for (int y = 0; y < SIDE_LENGTH; y++) {
            for (int z = 0; z < SIDE_LENGTH; z++) {
                nodes[offset(x, y, z)] = new RC_CubeNode(x, y, z);
            }
        }
    }
    
    // paint faces
    paint_face(FRONT, ORANGE);
    paint_face(BACK, BLUE);
    paint_face(LEFT, WHITE);
    paint_face(RIGHT, GREEN);
    paint_face(TOP, RED);
    paint_face(BOTTOM, YELLOW);
}

RC_CubeNode* RC_Cube::at(int x, int y, int z) {
    return nodes[offset(x, y, z)];
}

void RC_Cube::spin(RC_Plane plane, int index, bool clockwise) {
    
    // get nodes
    RC_CubeNode** slice = new RC_CubeNode*[SIDE_LENGTH * SIDE_LENGTH];
    select_nodes(plane, index, slice);
    
    RC_CubeNode* temp = new RC_CubeNode(0, 0, 0);
    
    if (clockwise) {
        
        *temp     = *slice[0];
        *slice[0] = *slice[6];
        *slice[6] = *slice[8];
        *slice[8] = *slice[2];
        *slice[2] = *temp;
        
        *temp     = *slice[1];
        *slice[1] = *slice[3];
        *slice[3] = *slice[7];
        *slice[7] = *slice[5];
        *slice[5] = *temp;
        
    } else {
        
        *temp     = *slice[0];
        *slice[0] = *slice[2];
        *slice[2] = *slice[8];
        *slice[8] = *slice[6];
        *slice[6] = *temp;
        
        *temp     = *slice[1];
        *slice[1] = *slice[5];
        *slice[5] = *slice[7];
        *slice[7] = *slice[3];
        *slice[3] = *temp;
        
    }
    
    /*
    0 1 2
    3 4 5
    6 7 8
    */
    
    // spin each node individually
    for (int i = 0; i < SIDE_LENGTH * SIDE_LENGTH; i++) {
        slice[i]->spin(plane, clockwise);
    }
    
    cout << "------- spinning -------" << endl;
    
    delete slice;
    delete temp;
    return;
}

void RC_Cube::print() {
    print_face(FRONT);
    print_face(TOP);
    print_face(BACK);
    print_face(BOTTOM);
    print_face(LEFT);
    print_face(RIGHT);
    return;
}

void RC_Cube::select_nodes(RC_Plane plane, int constant, RC_CubeNode** return_array) {
    
    int index = 0;
    
    // traversal orders are adjusted to get nodes in a specific order:
    // if on the Z-axis: always Z descending
    // if on the X-axis: always X ascending
    // if on the Y-axis: with X, Y descending; with Z, Y ascending
    switch (plane) {
        case XY:
            for (int y = (SIDE_LENGTH - 1); y >= 0; y--) {
                for (int x = 0; x < SIDE_LENGTH; x++) {
                    return_array[index] = at(x, y, constant);
                    index++;
                }
            }
            break;
            
        case XZ:
            for (int z = (SIDE_LENGTH - 1); z >= 0; z--) {
                for (int x = 0; x < SIDE_LENGTH; x++) {
                    return_array[index] = at(x, constant, z);
                    index++;
                }
            }
            break;
            
        case YZ:
            for (int z = (SIDE_LENGTH - 1); z >= 0; z--) {
                for (int y = 0; y < SIDE_LENGTH; y++) {
                    return_array[index] = at(constant, y, z);
                    index++;
                }
            }
            break;
            
        default:
            assert(false);
            
    } // switch (plane)
    
    return;
}

void RC_Cube::select_face(RC_Face face, RC_CubeNode** return_array) {
    
    switch (face) {
        case FRONT:
            select_nodes(XZ, (SIDE_LENGTH - 1), return_array);
            break;
            
        case BACK:
            select_nodes(XZ, 0, return_array);
            break;
            
        case LEFT:
            select_nodes(YZ, 0, return_array);
            break;
            
        case RIGHT:
            select_nodes(YZ, (SIDE_LENGTH - 1), return_array);
            break;
            
        case TOP:
            select_nodes(XY, (SIDE_LENGTH - 1), return_array);
            break;
            
        case BOTTOM:
            select_nodes(XY, 0, return_array);
            break;
            
        default:
            assert(false);
            
    }
    return;
}

void RC_Cube::print_face(RC_Face face) {
    
    // get the face
    RC_CubeNode** face_nodes = new RC_CubeNode*[SIDE_LENGTH * SIDE_LENGTH];
    select_face(face, face_nodes);
    
    cout << str(face) << endl;
        
    // go through all returned nodes
    for (int i = 0; i < SIDE_LENGTH * SIDE_LENGTH; i++) {
        
        // print the proper face
        cout << /*face_nodes[i]->coords() << " " << */str(face_nodes[i]->get_face(face));
        
        // print a newline every SIDE_LENGTH faces
        if (i % SIDE_LENGTH == (SIDE_LENGTH - 1)) {
            cout << endl;
        }
        
    }
    
    cout << endl;
    
    delete face_nodes;
    return;
}

void RC_Cube::paint_face(RC_Face face, RC_Color color) {
    
    // get the face
    RC_CubeNode** face_nodes = new RC_CubeNode*[SIDE_LENGTH * SIDE_LENGTH];
    select_face(face, face_nodes);
        
    // paint every node's face
    for (int i = 0; i < SIDE_LENGTH * SIDE_LENGTH; i++) {
        face_nodes[i]->set_face(face, color);
    }
    
    delete face_nodes;
    return;
}
