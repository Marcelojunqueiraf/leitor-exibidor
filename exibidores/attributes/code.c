#include "attributes.h"
#include <stdio.h>
#include "../../common/opcodes.h"
#include <stdlib.h>

void showCodeAttribute(code_attribute *codeAttribute, cp_info *constant_pool)
{
    printf("Max stack: %d\n", codeAttribute->max_stack);
    printf("Max locals: %d\n", codeAttribute->max_locals);
    printf("Code length: %d\n", codeAttribute->code_length);
    printf("Code: \n");

    showInstructions(codeAttribute->code, codeAttribute->code_length, constant_pool);

    printf("\nException table length: %d\n", codeAttribute->exception_table_length);

    for (int i = 0; i < codeAttribute->exception_table_length; i++)
    {
        printf("Start pc: %d\n", codeAttribute->exception_table[i].start_pc);
        printf("End pc: %d\n", codeAttribute->exception_table[i].end_pc);
        printf("Handler pc: %d\n", codeAttribute->exception_table[i].handler_pc);
        printf("Catch type: %d\n", codeAttribute->exception_table[i].catch_type);
    }

    printf("Attributes count: %d\n", codeAttribute->attributes_count);
    showAttributes(constant_pool, codeAttribute->attributes, codeAttribute->attributes_count);
}

