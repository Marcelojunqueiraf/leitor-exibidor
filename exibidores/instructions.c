#include "instructions.h"

void showInstruction(enum opcodes opcode) {
    switch (opcode) {
        case nop:
            printf("nop\n");
            break;
        case aconst_null:
            printf("aconst_null\n");
            break;
        case iconst_m1:
            printf("iconst_m1\n");
            break;
        case iconst_0:
            printf("iconst_0\n");
            break;
        case iconst_1:
            printf("iconst_1\n");
            break;
        case iconst_2:
            printf("iconst_2\n");
            break;
        case iconst_3:
            printf("iconst_3\n");
            break;
        case iconst_4:
            printf("iconst_4\n");
            break;
        case iconst_5:
            printf("iconst_5\n");
            break;
        case lconst_0:
            printf("lconst_0\n");
            break;
        case lconst_1:
            printf("lconst_1\n");
            break;
        case fconst_0:
            printf("fconst_0\n");
            break;
        case fconst_1:
            printf("fconst_1\n");
            break;
        case fconst_2:
            printf("fconst_2\n");
            break;
        case dconst_0:
            printf("dconst_0\n");
            break;
        case dconst_1:
            printf("dconst_1\n");
            break;
        case bipush:
            printf("bipush\n");
            break;
        case sipush:
            printf("sipush\n");
            break;
        case ldc:
            printf("ldc\n");
            break;
        case ldc_w:
            printf("ldc_w\n");
            break;
        case ldc2_w:
            printf("ldc2_w\n");
            break;
        case iload:
            printf("iload\n");
            break;
        case lload:
            printf("lload\n");
            break;
        case fload:
            printf("fload\n");
            break;
        case dload:
            printf("dload\n");
            break;
        case aload:
            printf("aload\n");
            break;
        case iload_0:
            printf("iload_0\n");
            break;
        case iload_1:
            printf("iload_1\n");
            break;
        case iload_2: 
            printf("iload_2\n");
            break;
        case iload_3:
            printf("iload_3\n");
            break;
        case lload_0:
            printf("lload_0\n");
            break;
        case lload_1:
            printf("lload_1\n");
            break;
}