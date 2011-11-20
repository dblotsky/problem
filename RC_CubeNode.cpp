#include <cassert>
#include <string>
#include <sstream>
#include "RC_CubeNode.h"
#include "RC_Enums.h"

using std::string;
using std::stringstream;

RC_CubeNode::RC_CubeNode(int x, int y, int z) {
    this->left    = BLANK;
    this->right   = BLANK;
    this->front   = BLANK;
    this->back    = BLANK;
    this->top     = BLANK;
    this->bottom  = BLANK;
    
    this->x_coord = x;
    this->y_coord = y;
    this->z_coord = z;
}

RC_CubeNode::~RC_CubeNode() {
    
}

RC_Color RC_CubeNode::get_face(RC_Face face) {

    switch (face) {
        case FRONT:
            return this->front;
            
        case BACK:
            return this->back;
            
        case LEFT:
            return this->left;
            
        case RIGHT:
            return this->right;
            
        case TOP:
            return this->top;
            
        case BOTTOM:
            return this->bottom;
            
        default:
            assert(false);
            return BLANK;
    }
}

void RC_CubeNode::set_face(RC_Face face, RC_Color color) {

    switch (face) {
        case FRONT:
            this->front = color;
            break;
            
        case BACK:
            this->back = color;
            break;
            
        case LEFT:
            this->left = color;
            break;
            
        case RIGHT:
            this->right = color;
            break;
            
        case TOP:
            this->top = color;
            break;
            
        case BOTTOM:
            this->bottom = color;
            break;
            
        default:
            assert(false);
    }
    return;
}

void RC_CubeNode::spin(RC_Plane plane, bool clockwise){
    
    RC_Color temp = BLANK;
    
    switch (plane) {
        case XY:
            if (clockwise) {
                temp    = front;
                front   = left;
                left    = back;
                back    = right;
                right   = temp;
            } else {
                temp    = front;
                front   = right;
                right   = back;
                back    = left;
                left    = temp;
            }
            break;
            
        case XZ:
            if (clockwise) {
                temp    = top;
                top     = left;
                left    = bottom;
                bottom  = right;
                right   = temp;
            } else {
                temp    = top;
                top     = right;
                right   = bottom;
                bottom  = left;
                left    = temp;
            }
            break;
            
        case YZ:
            if (clockwise) {
                temp    = top;
                top     = back;
                back    = bottom;
                bottom  = front;
                front   = temp;
            } else {
                temp    = top;
                top     = front;
                front   = bottom;
                bottom  = back;
                back    = temp;
            }
            break;
            
        default:
            assert(false);
            
    } // switch (plane)
    
    return;
}

string RC_CubeNode::coords() {
    stringstream return_stream;
    return_stream << "(" << x_coord << ", " << y_coord << ", " << z_coord << ")";
    return return_stream.str();
}
