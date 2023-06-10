#include "../common/class-file.h"
#include "../common/int-types.h"

#ifndef COMMON_H
#define COMMON_H

char * getUtf8(cp_info * constant_pool, u2 index);

#endif