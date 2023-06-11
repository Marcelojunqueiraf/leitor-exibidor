#include "attributes.h"
#include "../../common/get-utf8.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void readAttributes(cp_info * constant_pool, attribute_info * attributes, FILE * fp, u2 attributes_count) {
    for (u2 i = 0; i < attributes_count; i++) {
        readAttribute(constant_pool, &attributes[i], fp);
    }
}

void readAttribute(cp_info * constant_pool, attribute_info * attribute, FILE* fp) {
    attribute->attribute_name_index = readU2(fp);
    printf("attribute_name_index: %d\n", attribute->attribute_name_index);
    attribute->attribute_length = readU4(fp);
    printf("attribute_length: %d\n", attribute->attribute_length);

    attribute->info = malloc(sizeof(u1) * attribute->attribute_length);

    char * attributeType = getUtf8(constant_pool, attribute->attribute_name_index);

    printf("attribute_type: %s\n", attributeType);

    if (!strcmp(attributeType, "Code")) {
        readCodeAttribute(constant_pool, (code_attribute *) attribute->info, fp, attribute->attribute_length);
    } else if (!strcmp(attributeType, "LineNumberTable")) {
        readLineNumberTableAttribute(constant_pool, (LineNumberTable_attribute *) attribute->info, fp, attribute->attribute_length);
    } else if (!strcmp(attributeType, "SourceFile")) {
        readSourceFileAttribute(constant_pool, (SourceFile_attribute *) attribute->info, fp, attribute->attribute_length);
    } else {
      for(u4 info_index = 0; info_index < attribute->attribute_length; info_index++){
        u1* info = &(attribute->info[info_index]);
        *info = readU1(fp);
      }
    }
}