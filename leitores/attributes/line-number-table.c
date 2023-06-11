#include "attributes.h"

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