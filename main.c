#include "common/erros.h"
#include <stdio.h>
#include "leitores/read-class-file.h"
#include "exibidores/show.h"

int main(int argc, char *argv[]) {
  ClassFile classFile;

  if(argc != 2) {
    printf("Especifique um arquivo .class\n");
    return INVALID_ARGUMENTS;
  }

  readClassFile(argv[1], &classFile);
  showClassFile(classFile);

  return 0;
}
