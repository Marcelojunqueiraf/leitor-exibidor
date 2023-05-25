#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "leitores/leitores.h"

int main(int argc, char *argv[]) {
  ClassFile classFile;

  readClassFile(argv[1], &classFile);
  // printClassFile(&classFile);

  return 0;
}

