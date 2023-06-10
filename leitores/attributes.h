#include "../common/class-file.h"
#include <stdio.h>
#include "read-bytes.h"

#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

void readAttributes(cp_info * constant_pool, attribute_info * attributes, FILE * fp, u2 attributes_count);
void readCodeAttribute(cp_info * constant_pool, code_attribute * info, FILE* fp, u2 attribute_length);
void readAttribute(cp_info * constant_pool, attribute_info * attribute, FILE* fp);
#endif