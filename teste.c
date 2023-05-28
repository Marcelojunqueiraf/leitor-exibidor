#include "common/int-types.h"

u4 readU4() {
  u4 target;
  u1 b0, b1, b2, b3;
  b3 = 0x00;
  b2 = 0x00;
  b1 = 0x00;
  b0 = 0x01;

  //Tratar erros, todo
  //if(b0 == MAXU1 | b1 == MAXU1 | b2 == MAXU1 | b3 == MAXU1) return MAXU4;

  target = (b3<<24) | (b2<<16) | (b1<<8) | (b0);
  return target;
}

int main () {
    printf("%d", readU4());
}