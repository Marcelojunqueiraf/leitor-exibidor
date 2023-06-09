#include "show.h"
#include <stdio.h>

int showClassFile(ClassFile classFile) {
    printf("----- Informações Gerais -----\n");

    printf("Magic number: 0x%X\n", classFile.magic_number);
    printf("Versão do java: %d.%d\n", classFile.major_version, classFile.minor_version);
    printf("Pool count: %d\n", classFile.constant_pool_count);
    printf("Access flags: 0x%X\n", classFile.access_flags);
    printf("This class: %d\n", classFile.this_class);
    printf("Super class: %d\n", classFile.super_class);
    printf("Interfaces count: %d\n", classFile.interfaces_count);
    printf("Fields count: %d\n", classFile.fields_count);
    printf("Methods count: %d\n", classFile.methods_count);
    printf("Atributes count: %d\n", classFile.attributes_count);

    printf("----- Pool de Constantes-----\n");

    printf("----- Interfaces -----\n");

    printf("----- Fields -----\n");

    printf("----- Métodos -----\n");

    printf("----- Atributos da classe -----\n");

    return 0;
}
