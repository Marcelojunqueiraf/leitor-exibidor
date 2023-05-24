#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;

#define MAXU1 255
#define MAXU2 65535
#define MAXU4 2147483647
#define NAME_INDEX 1
#define NAME_AND_TYPE 2
#define STRING_INDEX 3
#define CLASS_INDEX 4
#define NAME_AND_TYPE_INFO_NAME_INDEX 5
#define NAME_AND_TYPE_INFO_DESCRIPTOR_INDEX 6
#define FIELD_INDEX 7


u1 readU1(FILE * fp);
u2 readU2(FILE * fp);
u4 readU4(FILE * fp);

struct classFile{

	u4 magic;										// Assinatura de um arquivo .class
	u2 minor_version;						// Versao mínima do arquivo - Relação com a versão do Java
	u2 major_version;						// Versao máxima do arquivo - Relação com a versão do Java
	u2 constant_pool_count;			// Numero de entradas na estrutura Constant Pool
	u2 access_flags;						// Mascara de bits que especifica permissão de acesso da classe
	u2 this_class;							// Representa a classe definida
	u2 super_class;							// Representa a super classe direta da classe definida
	u2 interfaces_count;				// Numero de entradas na estrutura Interfaces
	u2 *interfaces;							// Interfaces que são superinterfaces diretas da classe
	u2 fields_count;						// Numero de variáveis de classe ou de instâncias declaradas na classe presentes na estrutura Field
	u2 methods_count;						// Numero de estruturas method_info na tabela de Methods

};
typedef struct classFile ClassFile;

ClassFile readFile(char *);
