#include "common/erros.h"
#include "leitores/read-class-file.h"

int main(int argc, char *argv[]) {
  ClassFile classFile;

  if(argc != 2) {
    printf("Especifique 1 arquivo .class\n");
    return INVALID_ARGUMENTS;
  }

  readClassFile(argv[1], &classFile);

  printf("\n%d\n", classFile.attributes[0].attribute_length);
  
  // Seria bom separar a leitura da impressão, mas dá muito trabalho
  // printClassFile(&classFile); 

  return 0;
}
