#include "attributes.h"
#include <stdio.h>
#include "../../common/opcodes.h"
#include <stdlib.h>
#include <stdint.h>

void showInstructions(u1 *code, u2 length, cp_info *constant_pool)
{
    u1 *end = code + length;
    while (code < end)
    {
        switch (code[0])
        {
        case nop:
        {
            printf("nop\n");
            code += 1;
            break;
        }
        case aconst_null:
        {
            printf("aconst_null\n");
            code += 1;
            break;
        }
        case iconst_m1:
        {
            printf("iconst_m1\n");
            code += 1;
            break;
        }
        case iconst_0:
        {
            printf("iconst_0\n");
            code += 1;
            break;
        }
        case iconst_1:
        {
            printf("iconst_1\n");
            code += 1;
            break;
        }
        case iconst_2:
        {
            printf("iconst_2\n");
            code += 1;
            break;
        }
        case iconst_3:
        {
            printf("iconst_3\n");
            code += 1;
            break;
        }
        case iconst_4:
        {
            printf("iconst_4\n");
            code += 1;
            break;
        }
        case iconst_5:
        {
            printf("iconst_5\n");
            code += 1;
            break;
        }
        case lconst_0:
        {
            printf("lconst_0\n");
            code += 1;
            break;
        }
        case lconst_1:
        {
            printf("lconst_1\n");
            code += 1;
            break;
        }
        case fconst_0:
        {
            printf("fconst_0\n");
            code += 1;
            break;
        }
        case fconst_1:
        {
            printf("fconst_1\n");
            code += 1;
            break;
        }
        case fconst_2:
        {
            printf("fconst_2\n");
            code += 1;
            break;
        }
        case dconst_0:
        {
            printf("dconst_0\n");
            code += 1;
            break;
        }
        case dconst_1:
        {
            printf("dconst_1\n");
            code += 1;
            break;
        }
        case bipush:
        {
            printf("bipush %d \n", code[1]);
            code += 2;
            break;
        }
        case sipush:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("sipush %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case ldc:
        {
            printf("ldc %d\n", code[1]);
            code += 2;
            break;
        }
        case ldc_w:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("ldc_w %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case ldc2_w:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("ldc2_w %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case iload:
        {
            printf("iload %d\n", code[1]);
            code += 2;
            break;
        }
        case lload:
        {
            printf("lload %d\n", code[1]);
            code += 2;
            break;
        }
        case fload:
        {
            printf("fload %d\n", code[1]);
            code += 2;
            break;
        }
        case dload:
        {
            printf("dload %d\n", code[1]);
            code += 2;
            break;
        }
        case aload:
        {
            printf("aload %d\n", code[1]);
            code += 2;
            break;
        }
        case iload_0:
        {
            printf("iload_0\n");
            code += 1;
            break;
        }
        case iload_1:
        {
            printf("iload_1\n");
            code += 1;
            break;
        }
        case iload_2:
        {
            printf("iload_2\n");
            code += 1;
            break;
        }
        case iload_3:
        {
            printf("iload_3\n");
            code += 1;
            break;
        }
        case lload_0:
        {
            printf("lload_0\n");
            code += 1;
            break;
        }
        case lload_1:
        {
            printf("lload_1\n");
            code += 1;
            break;
        }
        case lload_2:
        {
            printf("lload_2\n");
            code += 1;
            break;
        }
        case lload_3:
        {
            printf("lload_3\n");
            code += 1;
            break;
        }
        case fload_0:
        {
            printf("fload_0\n");
            code += 1;
            break;
        }
        case fload_1:
        {
            printf("fload_1\n");
            code += 1;
            break;
        }
        case fload_2:
        {
            printf("fload_2\n");
            code += 1;
            break;
        }
        case fload_3:
        {
            printf("fload_3\n");
            code += 1;
            break;
        }
        case dload_0:
        {
            printf("dload_0\n");
            code += 1;
            break;
        }
        case dload_1:
        {
            printf("dload_1\n");
            code += 1;
            break;
        }
        case dload_2:
        {
            printf("dload_2\n");
            code += 1;
            break;
        }
        case dload_3:
        {
            printf("dload_3\n");
            code += 1;
            break;
        }
        case aload_0:
        {
            printf("aload_0\n");
            code += 1;
            break;
        }
        case aload_1:
        {
            printf("aload_1\n");
            code += 1;
            break;
        }
        case aload_2:
        {
            printf("aload_2\n");
            code += 1;
            break;
        }
        case aload_3:
        {
            printf("aload_3\n");
            code += 1;
            break;
        }
        case iaload:
        {
            printf("iaload\n");
            code += 1;
            break;
        }
        case laload:
        {
            printf("laload\n");
            code += 1;
            break;
        }
        case faload:
        {
            printf("faload\n");
            code += 1;
            break;
        }
        case daload:
        {
            printf("daload\n");
            code += 1;
            break;
        }
        case aaload:
        {
            printf("aaload\n");
            code += 1;
            break;
        }
        case baload:
        {
            printf("baload\n");
            code += 1;
            break;
        }
        case caload:
        {
            printf("caload\n");
            code += 1;
            break;
        }
        case saload:
        {
            printf("saload\n");
            code += 1;
            break;
        }
        case istore:
        {
            printf("istore\n");
            code += 2;
            break;
        }
        case lstore:
        {
            printf("lstore\n");
            code += 2;
            break;
        }
        case fstore:
        {
            printf("fstore\n");
            code += 2;
            break;
        }
        case dstore:
        {
            printf("dstore\n");
            code += 2;
            break;
        }
        case astore:
        {
            printf("astore\n");
            code += 2;
            break;
        }
        case istore_0:
        {
            printf("istore_0\n");
            code += 1;
            break;
        }
        case istore_1:
        {
            printf("istore_1\n");
            code += 1;
            break;
        }
        case istore_2:
        {
            printf("istore_2\n");
            code += 1;
            break;
        }
        case istore_3:
        {
            printf("istore_3\n");
            code += 1;
            break;
        }
        case lstore_0:
        {
            printf("lstore_0\n");
            code += 1;
            break;
        }
        case lstore_1:
        {
            printf("lstore_1\n");
            code += 1;
            break;
        }
        case lstore_2:
        {
            printf("lstore_2\n");
            code += 1;
            break;
        }
        case lstore_3:
        {
            printf("lstore_3\n");
            code += 1;
            break;
        }
        case fstore_0:
        {
            printf("fstore_0\n");
            code += 1;
            break;
        }
        case fstore_1:
        {
            printf("fstore_1\n");
            code += 1;
            break;
        }
        case fstore_2:
        {
            printf("fstore_2\n");
            code += 1;
            break;
        }
        case fstore_3:
        {
            printf("fstore_3\n");
            code += 1;
            break;
        }
        case dstore_0:
        {
            printf("dstore_0\n");
            code += 1;
            break;
        }
        case dstore_1:
        {
            printf("dstore_1\n");
            code += 1;
            break;
        }
        case dstore_2:
        {
            printf("dstore_2\n");
            code += 1;
            break;
        }
        case dstore_3:
        {
            printf("dstore_3\n");
            code += 1;
            break;
        }
        case astore_0:
        {
            printf("astore_0\n");
            code += 1;
            break;
        }
        case astore_1:
        {
            printf("astore_1\n");
            code += 1;
            break;
        }
        case astore_2:
        {
            printf("astore_2\n");
            code += 1;
            break;
        }
        case astore_3:
        {
            printf("astore_3\n");
            code += 1;
            break;
        }
        case iastore:
        {
            printf("iastore\n");
            code += 1;
            break;
        }
        case lastore:
        {
            printf("lastore\n");
            code += 1;
            break;
        }
        case fastore:
        {
            printf("fastore\n");
            code += 1;
            break;
        }
        case dastore:
        {
            printf("dastore\n");
            code += 1;
            break;
        }
        case aastore:
        {
            printf("aastore\n");
            code += 1;
            break;
        }
        case bastore:
        {
            printf("bastore\n");
            code += 1;
            break;
        }
        case castore:
        {
            printf("castore\n");
            code += 1;
            break;
        }
        case sastore:
        {
            printf("sastore\n");
            code += 1;
            break;
        }
        case pop:
        {
            printf("pop\n");
            code += 1;
            break;
        }
        case pop2:
        {
            printf("pop2\n");
            code += 1;
            break;
        }
        case dup:
        {
            printf("dup\n");
            code += 1;
            break;
        }
        case dup_x1:
        {
            printf("dup_x1\n");
            code += 1;
            break;
        }
        case dup_x2:
        {
            printf("dup_x2\n");
            code += 1;
            break;
        }
        case dup2:
        {
            printf("dup2\n");
            code += 1;
            break;
        }
        case dup2_x1:
        {
            printf("dup2_x1\n");
            code += 1;
            break;
        }
        case dup2_x2:
        {
            printf("dup2_x2\n");
            code += 1;
            break;
        }
        case swap:
        {
            printf("swap\n");
            code += 1;
            break;
        }
        case iadd:
        {
            printf("iadd\n");
            code += 1;
            break;
        }
        case ladd:
        {
            printf("ladd\n");
            code += 1;
            break;
        }
        case fadd:
        {
            printf("fadd\n");
            code += 1;
            break;
        }
        case dadd:
        {
            printf("dadd\n");
            code += 1;
            break;
        }
        case isub:
        {
            printf("isub\n");
            code += 1;
            break;
        }
        case lsub:
        {
            printf("lsub\n");
            code += 1;
            break;
        }
        case fsub:
        {
            printf("fsub\n");
            code += 1;
            break;
        }
        case dsub:
        {
            printf("dsub\n");
            code += 1;
            break;
        }
        case imul:
        {
            printf("imul\n");
            code += 1;
            break;
        }
        case lmul:
        {
            printf("lmul\n");
            code += 1;
            break;
        }
        case fmul:
        {
            printf("fmul\n");
            code += 1;
            break;
        }
        case dmul:
        {
            printf("dmul\n");
            code += 1;
            break;
        }
        case idiv:
        {
            printf("idiv\n");
            code += 1;
            break;
        }
        case inst_ldiv:
        {
            printf("inst_ldiv\n");
            code += 1;
            break;
        }
        case fdiv:
        {
            printf("fdiv\n");
            code += 1;
            break;
        }
        case ddiv:
        {
            printf("ddiv\n");
            code += 1;
            break;
        }
        case irem:
        {
            printf("irem\n");
            code += 1;
            break;
        }
        case lrem:
        {
            printf("lrem\n");
            code += 1;
            break;
        }
        case frem:
        {
            printf("frem\n");
            code += 1;
            break;
        }
        case inst_drem:
        {
            printf("inst_drem\n");
            code += 1;
            break;
        }
        case ineg:
        {
            printf("ineg\n");
            code += 1;
            break;
        }
        case lneg:
        {
            printf("lneg\n");
            code += 1;
            break;
        }
        case fneg:
        {
            printf("fneg\n");
            code += 1;
            break;
        }
        case dneg:
        {
            printf("dneg\n");
            code += 1;
            break;
        }
        case ishl:
        {
            printf("ishl\n");
            code += 1;
            break;
        }
        case lshl:
        {
            printf("lshl\n");
            code += 1;
            break;
        }
        case ishr:
        {
            printf("ishr\n");
            code += 1;
            break;
        }
        case lshr:
        {
            printf("lshr\n");
            code += 1;
            break;
        }
        case iushr:
        {
            printf("iushr\n");
            code += 1;
            break;
        }
        case lushr:
        {
            printf("lushr\n");
            code += 1;
            break;
        }
        case iand:
        {
            printf("iand\n");
            code += 1;
            break;
        }
        case land:
        {
            printf("land\n");
            code += 1;
            break;
        }
        case ior:
        {
            printf("ior\n");
            code += 1;
            break;
        }
        case lor:
        {
            printf("lor\n");
            code += 1;
            break;
        }
        case ixor:
        {
            printf("ixor\n");
            code += 1;
            break;
        }
        case lxor:
        {
            printf("lxor\n");
            code += 1;
            break;
        }
        case iinc:
        {
            u1 index = code[1];
            u1 constant = code[2];

            printf("iinc %d %d\n", index, constant);
            code += 3;
            break;
        }
        case i2l:
        {
            printf("i2l\n");
            code += 1;
            break;
        }
        case i2f:
        {
            printf("i2f\n");
            code += 1;
            break;
        }
        case i2d:
        {
            printf("i2d\n");
            code += 1;
            break;
        }
        case l2i:
        {
            printf("l2i\n");
            code += 1;
            break;
        }
        case l2f:
        {
            printf("l2f\n");
            code += 1;
            break;
        }
        case l2d:
        {
            printf("l2d\n");
            code += 1;
            break;
        }
        case f2i:
        {
            printf("f2i\n");
            code += 1;
            break;
        }
        case f2l:
        {
            printf("f2l\n");
            code += 1;
            break;
        }
        case f2d:
        {
            printf("f2d\n");
            code += 1;
            break;
        }
        case d2i:
        {
            printf("d2i\n");
            code += 1;
            break;
        }
        case d2l:
        {
            printf("d2l\n");
            code += 1;
            break;
        }
        case d2f:
        {
            printf("d2f\n");
            code += 1;
            break;
        }
        case i2b:
        {
            printf("i2b\n");
            code += 1;
            break;
        }
        case i2c:
        {
            printf("i2c\n");
            code += 1;
            break;
        }
        case i2s:
        {
            printf("i2s\n");
            code += 1;
            break;
        }
        case lcmp:
        {
            printf("lcmp\n");
            code += 1;
            break;
        }
        case fcmpl:
        {
            printf("fcmpl\n");
            code += 1;
            break;
        }
        case fcmpg:
        {
            printf("fcmpg\n");
            code += 1;
            break;
        }
        case dcmpl:
        {
            printf("dcmpl\n");
            code += 1;
            break;
        }
        case dcmpg:
        {
            printf("dcmpg\n");
            code += 1;
            break;
        }
        case ifeq:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("ifeq %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case ifne:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("ifne %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case iflt:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("iflt %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case ifge:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("ifge %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case ifgt:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("ifgt %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case ifle:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("ifle %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case if_icmpeq:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("if_icmpeq %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case if_icmpne:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("if_icmpne %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case if_icmplt:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("if_icmplt %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case if_icmpge:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("if_icmpge %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case if_icmpgt:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("if_icmpgt %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case if_icmple:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("if_icmple %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case if_acmpeg:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("if_acmpeg %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case if_acmpne:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("if_acmpne %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case inst_goto:
        { 
            int16_t index = (int16_t)((code[1] << 8) | code[2]);
            printf("goto %d\n", index);
            code += 3;
            break;
        }
        case jsr:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("jsr %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case ret:
        {
            printf("ret\n");
            code += 2;
            break;
        }
        case tableswitch:
        {
            // TODO: implementar
            printf("tableswitch\n");
            printf("instrucao nao suportada\n");
            exit(1);
            code += 17; // pode ser 16+ args
            break;
        }
        case lookupswitch:
        {
            // TODO: implementar
            printf("lookupswitch\n");
            printf("instrucao nao suportada\n");
            exit(1);
            code += 9; // pode ser 8+ args
            break;
        }
        case ireturn:
        {
            printf("ireturn\n");
            code += 1;
            break;
        }
        case lreturn:
        {
            printf("lreturn\n");
            code += 1;
            break;
        }
        case freturn:
        {
            printf("freturn\n");
            code += 1;
            break;
        }
        case dreturn:
        {
            printf("dreturn\n");
            code += 1;
            break;
        }
        case areturn:
        {
            printf("areturn\n");
            code += 1;
            break;
        }
        case inst_return:
        {
            printf("return\n");
            code += 1;
            break;
        }
        case getstatic:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("getstatic %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case putstatic:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("putstatic %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case getfield:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("getfield %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case putfield:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("putfield %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case invokevirtual:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("invokevirtual %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case invokespecial:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("invokespecial %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case invokestatic:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("invokestatic %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case invokeinterface:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("invokeinterface %d %s count 0\n", index, getUtf8(constant_pool, index));
            code += 5;
            break;
        }
        case invokedynamic:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("invokedDynamic %d %s 0 0\n", index, getUtf8(constant_pool, index));
            code += 5;
            break;
        }
        case inst_new:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("inst_new %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case newarray:
        {
            printf("newarray\n");
            code += 2;
            break;
        }
        case anewarray:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("anewarray %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case arraylength:
        {
            printf("arraylength\n");
            code += 1;
            break;
        }
        case athrow:
        {
            printf("athrow\n");
            code += 1;
            break;
        }
        case checkcast:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("checkcast %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case instanceof:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("instanceof %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case monitorenter:
        {
            printf("monitorenter\n");
            code += 1;
            break;
        }
        case monitorexit:
        {
            printf("monitorexit\n");
            code += 1;
            break;
        }
        case wide:
        {
            printf("wide\n");
            printf("instrução não suportada\n");
            exit(1);
            break;
        }
        case multianewarray:
        {
            // O que cargas dágua é isso?
            printf("multianewarray\n");
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("\t-index: %d %s\n", index, getUtf8(constant_pool, index));
            printf("\t-dimension: %d\n", code[3]);
            code += 4;
            break;
        }
        case ifnull:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("ifnull %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case ifnonnull:
        {
            u2 index = (u2)((code[1] << 8) | code[2]);
            printf("ifnonnull %d %s\n", index, getUtf8(constant_pool, index));
            code += 3;
            break;
        }
        case goto_w:
        {
            u4 index = (u4)((code[1] << 24) | (code[2] << 16) | (code[3] << 8) | code[4]);
            printf("goto_w %d\n", index);
            code += 5;
            break;
        }
        case jsr_w:
        {
            u4 index = (u4)((code[1] << 24) | (code[2] << 16) | (code[3] << 8) | code[4]);
            printf("jsr_w %d\n", index);
            code += 5;
            break;
        }
        default:
            break;
        }
    }
    printf("\n");
}
