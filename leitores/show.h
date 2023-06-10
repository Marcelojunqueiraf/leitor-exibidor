#include "../common/class-file.h"
#include "../common/int-types.h"

#ifndef	SHOW_H
#define SHOW_H

int showClassFile(ClassFile classFile);
char * getUtf8(cp_info * constant_pool, u2 index);
void printUtf8Char(u1 _char);
void printAccessFlag(u1 tag);
void showField(cp_info * fields, field_info * field);
void showConstant(cp_info * constant_pool, cp_info * constant, u2 index);
void showInterfaces(ClassFile classFile);
void showFields(ClassFile classFile);
#endif
