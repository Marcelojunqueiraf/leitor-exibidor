#include "../common/class-file.h"
#include "../common/int-types.h"

#ifndef SHOW_H
#define SHOW_H

int showClassFile(ClassFile classFile);
char *getAccessFlag(u1 tag);

void showInformacoesGerais(ClassFile classFile);
void showInterfaces(ClassFile classFile);
void showFields(ClassFile classFile);
void showConstantPool(ClassFile classFile);
void showMethods(ClassFile classFile);

void showField(field_info *field, cp_info *constant_pool, u2 index);
void showConstant(cp_info *constant_pool, cp_info *constant, u2 index);
void showMethod(method_info *method, cp_info *constant_pool, u2 index);
void showInterface(u2 interface, cp_info *constant_pool, u2 index);

float getFloat(u4 valor);
double getDouble(u4 low, u4 high);

#endif
