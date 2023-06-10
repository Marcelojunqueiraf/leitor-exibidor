#include "attributes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../exibidores/common.h"

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

    if (!strcmp(attributeType, "Code"))
        readCodeAttribute(constant_pool, (code_attribute *) attribute->info, fp, attribute->attribute_length);
    else if (!strcmp(attributeType, "LineNumberTable")) {
            readLineNumberTableAttribute(constant_pool, (LineNumberTable_attribute *) attribute->info, fp, attribute->attribute_length);
    }
    else {
      for(u4 info_index = 0; info_index < attribute->attribute_length; info_index++){
        u1* info = &(attribute->info[info_index]);
        *info = readU1(fp);
      }
    }
}

void readCodeAttribute(cp_info * constant_pool, code_attribute * info, FILE * fp, u2 attribute_length) {
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


void readLineNumberTableAttribute(cp_info * constant_pool, LineNumberTable_attribute * info, FILE* fp, u2 attribute_length) {
    info->line_number_table_length = readU2(fp);
    printf("line_number_table_length: %d\n", info->line_number_table_length);

    info->line_number_table = (line_number_table *) malloc(sizeof(line_number_table) * info->line_number_table_length);
    for (int i = 0; i < info->line_number_table_length; i++) {
        info->line_number_table[i].start_pc = readU2(fp);
        printf("start_pc: %d\n", info->line_number_table[i].start_pc);
        info->line_number_table[i].line_number = readU2(fp);
        printf("line_number: %d\n", info->line_number_table[i].line_number);
    }
}