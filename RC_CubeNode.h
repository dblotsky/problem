#ifndef _RC_CUBE_NODE_
#define _RC_CUBE_NODE_

#include <string>
#include "RC_Enums.h"

using std::string;

class RC_CubeNode {
    public:
        RC_CubeNode(int x, int y, int z);
        ~RC_CubeNode();
        
        void spin(RC_Plane plane, bool clockwise);
        string coords();
        RC_Color get_face(RC_Face face);
        void set_face(RC_Face face, RC_Color color);
        
    private:
        RC_Color left;
        RC_Color right;
        RC_Color front;
        RC_Color back;
        RC_Color top;
        RC_Color bottom;
        
        int x_coord;
        int y_coord;
        int z_coord;
};

#endif
