#include "attributes.h"
#include <stdio.h>

void showLineNumberTableAttribute(LineNumberTable_attribute * lineNumberTableAttribute) {
    printf("line_number_table_length: %d\n", lineNumberTableAttribute->line_number_table_length);
    for (int i = 0; i < lineNumberTableAttribute->line_number_table_length; i++) {
        printf("start_pc: %d\n", lineNumberTableAttribute->line_number_table[i].start_pc);
        printf("line_number: %d\n", lineNumberTableAttribute->line_number_table[i].line_number);
    }
}