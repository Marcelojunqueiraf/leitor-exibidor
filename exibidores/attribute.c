#include "attribute.h"
#include <stdio.h>



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

    printf("Attribute length: %d\n", attribute->attribute_length);
    //printf("Info: %s\n", attribute->info);
    // Aqui vem a baguncinha
}