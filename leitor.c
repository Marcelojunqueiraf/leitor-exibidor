#include "leitor.h"
/*
ClassFile readFile(char * path){
  FILE *file = fopen(path, "rb");
  if(!file) {
    fprintf(stderr, "Não foi possível abrir o arquivo\n");
    return 1;
  }

  uint32_t magic_number;
  uint16_t minor_version;
  uint16_t major_version;
  fread(&magic_number, sizeof(magic_number), 1, file);
  fread(&minor_version, sizeof(minor_version), 1, file);
  fread(&major_version, sizeof(major_version), 1, file);

  printf("%x\n", magic_number);
  if(magic_number != 0xCAFEBABE) {
    fprintf(stderr, "Magic number não bateu");
    return 1;
  }
  printf("Versão do java: %d.%d\n", major_version, minor_version);

  fclose(file);


}
*/

u1 readU1(FILE * fp){
  u1 target;
  if(fread(&target, sizeof(u1), 1, fp) != 1){
    return -1;
  }
  return target;
}

u2 readU2(FILE * fp){
  u2 target;
  u1 lowByte, highByte;
  highByte = readU1(fp);
  lowByte = readU1(fp);

  if(highByte == MAXU1 | lowByte == MAXU1)
    return MAXU2;

  target = ((highByte)<<8) | ((lowByte));
}

u4 readU4(FILE * fp) {
  u4 target;
  u1 b0, b1, b2, b3;
  b3 = readU1(fp);
  b2 = readU1(fp);
  b1 = readU1(fp);
  b0 = readU1(fp);
  //Tratar erros, todo
  if(b0 == MAXU1 | b1 == MAXU1 | b2 == MAXU1 | b3 == MAXU1) return MAXU4;

  target = (b3<<24) | (b2<<16) | (b1<<8) | (b0);
  return target;
}