#include "attribute.h"
#include <stdio.h>
#include <string.h>



void showAttributes(cp_info * constant_pool, attribute_info * attributes, u2 attributes_count) {
    attribute_info * begin = attributes;
    attribute_info * end = attributes_count + attributes;
    for(attribute_info * attribute= begin; attribute < end; attribute++){
        showAttribute(attribute, constant_pool);
    }
}

void showAttribute(attribute_info * attribute, cp_info * constant_pool) {
    printf("Attribute name index: %d ", attribute->attribute_name_index);
    printf("%s", getUtf8(constant_pool, attribute->attribute_name_index));
    printf("\n");

    char * attributeType = getUtf8(constant_pool, attribute->attribute_name_index);

    printf("Attribute length: %d\n", attribute->attribute_length);
    if(strcmp(attributeType, "Code") == 0) {
        showCodeAttribute((code_attribute *) attribute->info, constant_pool);
    }
}

void showCodeAttribute(code_attribute * codeAttribute, cp_info * constant_pool) {
    printf("Max stack: %d\n", codeAttribute->max_stack);
    printf("Max locals: %d\n", codeAttribute->max_locals);
    printf("Code length: %d\n", codeAttribute->code_length);
    printf("Code: \n");
    for(int i = 0; i < 11; i++) {
        printf("%02x ", codeAttribute->code[i]);
        // printar o opcode
    }
    printf("\n");
    printf("Exception table length: %d\n", codeAttribute->exception_table_length);
    // show exception table
    printf("Attributes count: %d\n", codeAttribute->attributes_count);
    showAttributes(constant_pool, codeAttribute->attributes, codeAttribute->attributes_count);
}
