#include "attributes.h"
#include <stdio.h>

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