#include "../common/class-file.h"
#include "../common/int-types.h"
#include "attribute.h"
#include "common.h"

#ifndef	SHOW_H
#define SHOW_H

int showClassFile(ClassFile classFile);
char * getUtf8(cp_info * constant_pool, u2 index);
char * getAccessFlag(u1 tag);

void showInformacoesGerais(ClassFile classFile);
void showInterfaces(ClassFile classFile);
void showFields(ClassFile classFile);
void showConstantPool(ClassFile classFile);
void showMethods(ClassFile classFile);


void showField(field_info * field, cp_info * constant_pool);
void showConstant(cp_info * constant_pool, cp_info * constant, u2 index);
#endif
