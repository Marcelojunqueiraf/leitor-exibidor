#include "../../common/class-file.h"
#include "../../common/int-types.h"
#include "../../common/get-utf8.h"
#include <stdio.h>
#include <string.h>

#ifndef SHOW_ATTRIBUTE_H
#define SHOW_ATTRIBUTE_H

void showAttributes(cp_info * constant_pool, attribute_info * attributes, u2 attributes_count);
void showAttribute(attribute_info * attribute, cp_info * constant_pool);

void showCodeAttribute(code_attribute * codeAttribute, cp_info * constant_pool);
void showLineNumberTableAttribute(LineNumberTable_attribute * lineNumberTableAttribute);
void showSourceFileAttribute(SourceFile_attribute * sourceFileAttribute, cp_info * constant_pool);
void showExceptionsAttribute(Exceptions_attribute * exceptionsAttribute, cp_info * constant_pool);
void showConstantValueAttribute(ConstantValue_attribute * constantValueAttribute, cp_info * constant_pool);
void showInnerClassesAttribute(InnerClasses_attribute * innerClassesAttribute, cp_info * constant_pool);
void showLocalVariableTableAttribute(LocalVariableTable_attribute * localVariableTableAttribute, cp_info * constant_pool);

void showInstructions(u1 * code, u2 length, cp_info * constant_pool);

#endif