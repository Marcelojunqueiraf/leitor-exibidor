#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "leitores/leitores.h"

int main(int argc, char *argv[]) {
  ClassFile classFile;

  if(argc != 2) {
    printf("Especifique 1 arquivo .class\n");
    return 1;
  }

  readClassFile(argv[1], &classFile);
  // printClassFile(&classFile);

  return 0;
}

