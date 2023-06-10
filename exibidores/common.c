#include "common.h"
#include <stdlib.h>
#include <string.h>

char * getUtf8(cp_info * constant_pool, u2 index) {
    cp_info * constant = constant_pool + index;
    
    switch (constant->tag) {
        case 1: ;// UTF8
            char * string = (char *) malloc((constant->CONSTANT_Utf8.length+1)*sizeof(char));
            for(int i=0; i<constant->CONSTANT_Utf8.length; i++) {
                string[i] = constant->CONSTANT_Utf8.bytes[i];
            }
            string[constant->CONSTANT_Utf8.length] = '\0';
            return string;
        case 12: ;// NameAndType
            char * name = getUtf8(constant_pool, constant->CONSTANT_NameAndType.name_index);
            char * descriptor = getUtf8(constant_pool, constant->CONSTANT_NameAndType.descriptor_index);

            int size = strlen(name)+strlen(descriptor)+1;
            char * retorno = malloc(sizeof(char)*(size));

            strcpy(retorno, name);
            strcat(retorno, ":");
            strcat(retorno, descriptor);
            return retorno;
        case 7: // class
            return getUtf8(constant_pool, constant->CONSTANT_Class.name_index);
        case 9: // fieldRef
            return getUtf8(constant_pool, constant->CONSTANT_Fieldref.name_and_type_index);
        case 10: // MethodRef
            return getUtf8(constant_pool, constant->CONSTANT_Methodref.name_and_type_index);
        case 11: // InterfaceMethod
            return getUtf8(constant_pool, constant->CONSTANT_InterfaceMethodref.name_and_type_index);
        case 8: // String
            return getUtf8(constant_pool, constant->CONSTANT_String.string_index);
        case 15: // MethodHandle
            return getUtf8(constant_pool, constant->CONSTANT_MethodHandle.reference_index);
        case 16: // MethodType
            return getUtf8(constant_pool, constant->CONSTANT_MethodType.descriptor_index);
        case 18: // InvokeDynamic
            return getUtf8(constant_pool, constant->CONSTANT_InvokeDynamic.name_and_type_index);
        default:
            return "";
    }
}