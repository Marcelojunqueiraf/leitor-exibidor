#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../common/class-file.h"
#include "../common/int-types.h"
#include "../common/erros.h"

/*
#define NAME_INDEX 1
#define NAME_AND_TYPE 2
#define STRING_INDEX 3
#define CLASS_INDEX 4
#define NAME_AND_TYPE_INFO_NAME_INDEX 5
#define NAME_AND_TYPE_INFO_DESCRIPTOR_INDEX 6
#define FIELD_INDEX 7
*/

int readClassFile(char path[], ClassFile *classFileAdress);
