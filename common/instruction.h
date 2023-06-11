#include "opcodes.h"
#include "int-types.h"


typedef struct {
  u1 opcode;
} loadZero;

// u1 ** code;
// u1 ** begin = code;
// while code < begin+size:
//   for ins in code:
//     switch ins[0]:
//       case 1
//         Bla bla
//         ins[1:4]
//         code += 5

typedef struct {
    int bytesCount;
    u4 value;
} instruction_arg;

typedef struct {
    enum opcodes op;
    int argsCount;
    instruction_arg* instruction_args;
} Instruction;

