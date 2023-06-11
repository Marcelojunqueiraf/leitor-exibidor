#include "attributes.h"
#include <stdio.h>
#include <stdlib.h>

void readCodeAttribute(cp_info * constant_pool, code_attribute * info, FILE * fp) {
    info->max_stack = readU2(fp);
    printf("max_stack: %d\n", info->max_stack);
    info->max_locals = readU2(fp);
    printf("max_locals: %d\n", info->max_locals);
    info->code_length = readU4(fp);
    printf("code_length: %d\n", info->code_length);


    info->code = (u1 *) malloc(sizeof(u1) * info->code_length);
    for (u4 code_index = 0; code_index < info->code_length; code_index++) {
        info->code[code_index] = readU1(fp);
        printf("%02x ", info->code[code_index]);
    }
    printf("\n");

    info->exception_table_length = readU2(fp);
    printf("exception_table_length: %d\n", info->exception_table_length);
    info->exception_table = (exception_table *) malloc(sizeof(exception_table) * info->exception_table_length);
    for (int i = 0; i < info->exception_table_length; i++) {
        info->exception_table[i].start_pc = readU2(fp);
        info->exception_table[i].end_pc = readU2(fp);
        info->exception_table[i].handler_pc = readU2(fp);
        info->exception_table[i].catch_type = readU2(fp);
    }
    info->attributes_count = readU2(fp);
    printf("attributes_count: %d\n", info->attributes_count);
    info->attributes = (attribute_info *) malloc(sizeof(attribute_info) * info->attributes_count);
    readAttributes(constant_pool, info->attributes, fp, info->attributes_count);
}