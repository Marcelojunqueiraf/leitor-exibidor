#include "attributes.h"

void readAttributes(cp_info * constant_pool, attribute_info * attributes, FILE * fp, u2 attributes_count) {
    for (u2 i = 0; i < attributes_count; i++) {
        readAttribute(constant_pool, &attributes[i], fp);
    }
}

void readAttribute(cp_info * constant_pool, attribute_info * attribute, FILE* fp) {
    attribute->attribute_name_index = readU2(fp);
    attribute->attribute_length = readU4(fp);
    attribute->info = malloc(sizeof(u1) * attribute->attribute_length);

    char * attributeType = getUtf8(constant_pool, attribute->attribute_name_index);

    if (strcmp(attributeType, "Code"))
        readCodeAttribute(constant_pool, (code_attribute *) attribute->info, fp, attribute->attribute_length);
    else {
      for(u4 info_index = 0; info_index < attribute->attribute_length; info_index++){
        u1* info = &(attribute->info[info_index]);
        *info = readU1(fp);
      }
    }
}

void readCodeAttribute(cp_info * constant_pool, code_attribute * info, FILE * fp, u2 attribute_length) {
    info->max_stack = readU2(fp);
    info->max_locals = readU2(fp);
    info->code_length = readU4(fp);

    info->code = readBytes(fp, info->code_length); // Fazer o for aqui pra ler os bytecodes

    info->exception_table_length = readU2(fp);
    info->exception_table = (exception_table *) malloc(sizeof(exception_table) * info->exception_table_length);
    for (int i = 0; i < info->exception_table_length; i++) {
        info->exception_table[i].start_pc = readU2(fp);
        info->exception_table[i].end_pc = readU2(fp);
        info->exception_table[i].handler_pc = readU2(fp);
        info->exception_table[i].catch_type = readU2(fp);
    }
    info->attributes_count = readU2(fp);
    info->attributes = (attribute_info *) malloc(sizeof(attribute_info) * info->attributes_count);
}

