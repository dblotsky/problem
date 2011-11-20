#ifndef _RC_ENUMS_
#define _RC_ENUMS_

#include <string>

using std::string;

enum RC_Face {FRONT, BACK, LEFT, RIGHT, TOP, BOTTOM};
enum RC_Color {ORANGE, BLUE, WHITE, GREEN, RED, YELLOW, BLANK};
enum RC_Plane {XY, XZ, YZ};

string str(RC_Face face);
string str(RC_Color color);

#endif
