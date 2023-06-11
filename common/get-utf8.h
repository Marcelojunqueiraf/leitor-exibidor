#include "class-file.h"
#include "int-types.h"

#ifndef GET_UTF8_H
#define GET_UTF8_H

char * getUtf8(cp_info * constant_pool, u2 index);
char * composedUtf8(char * s1, char * s2, char * divider);

#endif