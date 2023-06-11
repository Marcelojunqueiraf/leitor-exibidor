#include "../../common/class-file.h"
#include "../read-bytes.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef READ_ATTRIBUTES_H
#define READ_ATTRIBUTES_H

void readAttributes(cp_info * constant_pool, attribute_info * attributes, FILE * fp, u2 attributes_count);
void readAttribute(cp_info * constant_pool, attribute_info * attribute, FILE* fp);
void readCodeAttribute(cp_info * constant_pool, code_attribute * info, FILE* fp, u2 attribute_length);
void readLineNumberTableAttribute(cp_info * constant_pool, LineNumberTable_attribute * info, FILE* fp, u2 attribute_length);
void readSourceFileAttribute(cp_info * constant_pool, SourceFile_attribute * info, FILE* fp, u2 attribute_length);

#endif