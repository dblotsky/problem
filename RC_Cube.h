#ifndef _RC_CUBE_
#define _RC_CUBE_

#include "RC_Enums.h"
#include "RC_CubeNode.h"

#define SIDE_LENGTH 3

class RC_Cube {
    public:
        RC_Cube();
        ~RC_Cube();
        
        RC_CubeNode* at(int x, int y, int z);
        void select_nodes(RC_Plane plane, int constant, RC_CubeNode** return_array);
        void select_face(RC_Face face, RC_CubeNode** return_array);
        void print_face(RC_Face face);
        void paint_face(RC_Face face, RC_Color color);
        void spin(RC_Plane plane, int index, bool clockwise);
        void print();
        
    private:
        RC_CubeNode** nodes;
        
        int offset(int x, int y, int z);
        
};

#endif
