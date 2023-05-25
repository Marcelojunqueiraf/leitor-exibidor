#include "../common/int-types.h"
#include <stdio.h>

#define MAXU1 255
#define MAXU2 65535
#define MAXU4 2147483647

u1 readU1(FILE * fp);
u2 readU2(FILE * fp);
u4 readU4(FILE * fp);