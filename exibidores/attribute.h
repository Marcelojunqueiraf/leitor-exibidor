#include "../common/class-file.h"
#include "../common/int-types.h"

#ifndef SHOW_ATTRIBUTE_H
#define SHOW_ATTRIBUTE_H

void showAttributes(cp_info * constant_pool, attribute_info * attributes, u2 attributes_count);
void showAttribute(attribute_info * attribute, cp_info * constant_pool);

void showCodeAttribute(code_attribute * codeAttribute, cp_info * constant_pool);

#endif