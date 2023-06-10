#include "show.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int showClassFile(ClassFile classFile) {
    showInformacoesGerais(classFile);

    showConstantPool(classFile);
    
    showInterfaces(classFile);

    showFields(classFile);

    showMethods(classFile);

    showAttributes(classFile);

    return 0;
}

void showInformacoesGerais(ClassFile classFile) {
    printf("----- Informações Gerais -----\n");

    printf("Magic number: 0x%X\n", classFile.magic_number);
    printf("Versão do java: %d.%d\n", classFile.major_version, classFile.minor_version);
    printf("Pool count: %d\n", classFile.constant_pool_count);
    printf("Access flags: 0x%X ", classFile.access_flags);
    printAccessFlag(classFile.access_flags);
    printf("\n");

    printf("This class: %d ", classFile.this_class);
    printf("%s", getUtf8(classFile.constant_pool, classFile.this_class));
    printf("\n");

    printf("Super class: %d ", classFile.super_class);
    printf("%s", getUtf8(classFile.constant_pool, classFile.super_class));
    printf("\n");

    printf("Interfaces count: %d\n", classFile.interfaces_count);
    printf("Fields count: %d\n", classFile.fields_count);
    printf("Methods count: %d\n", classFile.methods_count);
    printf("Atributes count: %d\n", classFile.attributes_count);
}

void showConstantPool(ClassFile classFile) {
    printf("\n----- Pool de Constantes-----\n");

    cp_info * begin = classFile.constant_pool +1;
    cp_info * end = classFile.constant_pool_count + classFile.constant_pool;
    int i = 1;
    for(cp_info * constant = begin; constant < end; constant++) {
        showConstant(classFile.constant_pool, constant, i++);
    }
}

void showInterfaces(ClassFile classFile) {
  printf("\n----- Interfaces -----\n");

}

void showFields(ClassFile classFile) {
    printf("\n----- Fields -----\n");

    cp_info * begin = classFile.fields;
    cp_info * end = classFile.fields_count + classFile.fields;
    for (cp_info * field = begin; field < end; field++) {
      showField(classFile.fields, field);
    }
}

void showMethods(ClassFile classFile) {
  printf("\n----- Métodos -----\n");

}

void showAttributes(ClassFile classFile) {
  printf("\n----- Atributos da classe -----\n");

}

void showConstant(cp_info * constant_pool, cp_info * constant, u2 index) {
    printf("\n---- Constante [%d] ----\n", index);
    printf("Tag: %d ", constant->tag);
    switch (constant->tag) {
        case 7: // class
            printf("Constant class\n");
            printf(" name_index: %d ", constant->CONSTANT_Class.name_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_Class.name_index));
            printf("\n");
            break;
        case 9: // fieldRef
            printf("FieldRef\n");
            printf("- class Index: %d ", constant->CONSTANT_Fieldref.class_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_Fieldref.class_index));
            printf("\n");

            printf("- name_and_type_index: %d ", constant->CONSTANT_Fieldref.name_and_type_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_Fieldref.name_and_type_index));
            printf("\n");
            break;
        case 10: // MethodRef
            printf("MethodRef\n");

            printf("- class_index: %d ", constant->CONSTANT_Methodref.class_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_Methodref.class_index));
            printf("\n");

            printf("- name_and_type_index: %d ", constant->CONSTANT_Methodref.name_and_type_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_Methodref.name_and_type_index));
            printf("\n");
            break;
        case 11: // InterfaceMethod
            printf("InterfaceMethod ");
            printf("- class_index: %d ", constant->CONSTANT_InterfaceMethodref.class_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_InterfaceMethodref.class_index));
            printf("\n");

            printf("- name_and_type_index: %d ", constant->CONSTANT_InterfaceMethodref.name_and_type_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_InterfaceMethodref.name_and_type_index));
            printf("\n");
            break;
        case 8: // String
            printf("String\n");
            printf("- string_index: %d ", constant->CONSTANT_String.string_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_String.string_index));
            printf("\n");
            break;
        case 3: // Integer
            printf("Integer: %d\n", constant->CONSTANT_Integer.bytes);
            break;
        case 4: // Float
            printf("Float: %f\n", (float) constant->CONSTANT_Float.bytes);
            // implementar representação de float
            break;
        case 5: // Long
            printf("Long\n");
            printf("- high-bytes: %d\n", constant->CONSTANT_Long.high_bytes);
            printf("- low-bytes: %d\n", constant->CONSTANT_Long.low_bytes);
            // implementar representação de long
            break;
        case 6: // Double
            printf("Double\n");
            printf("- high-bytes: %d\n", constant->CONSTANT_Double.high_bytes);
            printf("- low-bytes: %d\n", constant->CONSTANT_Double.low_bytes);
            // implementar representação de double
            break;
        case 12: // NameAndType
            printf("Name and Type\n");
            printf("- name_index: %d ", constant->CONSTANT_NameAndType.name_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_InterfaceMethodref.name_and_type_index));
            printf("\n");
            
            printf("- descriptor_index: %d ", constant->CONSTANT_NameAndType.descriptor_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_NameAndType.descriptor_index));
            printf("\n");
            break;
        case 1: // utf8
            printf("utf8: \n\"%s\"\n", getUtf8(constant_pool, index));
            break;
        case 15: // MethodHandle
            printf("Method Hanlde\n");
            printf("- reference_kind: %d ", constant->CONSTANT_MethodHandle.reference_kind);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_MethodHandle.reference_kind));
            printf("\n");

            printf("- reference_index: %d ", constant->CONSTANT_MethodHandle.reference_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_MethodHandle.reference_index));
            printf("\n");
            break;
        case 16: // MethodType
            printf("Method type\n");
            printf("- descriptor_index: %d ", constant->CONSTANT_MethodType.descriptor_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_MethodType.descriptor_index));
            printf("\n");
            break;
        case 18: // InvokeDynamic
            printf("Invoke Dynamic\n");
            printf("- bootstrap_method_attr_index: %d ", constant->CONSTANT_InvokeDynamic.bootstrap_method_attr_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_InvokeDynamic.bootstrap_method_attr_index));
            printf("\n");
            
            printf("- name_and_type_index: %d ", constant->CONSTANT_InvokeDynamic.name_and_type_index);
            printf("%s", getUtf8(constant_pool, constant->CONSTANT_InvokeDynamic.name_and_type_index));
            printf("\n");
            break;
        default:
            printf("\n");
    }
}

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

void printUtf8Char(u1 _char) {
    printf("%c", _char);
    // e quando tiver 8 bits?
    // implementar representação de utf8
}

void showField(cp_info * fields, field_info * field) {
    printf("Field\n");

    printf("- access_flags: %d ", field->access_flags);
    printAccessFlag(field->access_flags);
    printf("\n");

    printf("- name index: %d ", field->name_index);
    // getUtf8(fields, field->name_index); // FIXME: não printa nada
    printf("\n");

    printf("- descriptor_index: %d ", field->descriptor_index);
    // getUtf8(fields, field->descriptor_index); // FIXME: não printa nada
    printf("\n");

    printf("- attributes_count: %d\n", field->attributes_count);

    // TODO: listar attributes
}

void printAccessFlag(u1 tag) {
    if (tag & 0x0001) printf("PUBLIC ");
    if (tag & 0x0002) printf("PRIVATE ");
    if (tag & 0x0004) printf("PROTECTED ");
    if (tag & 0x0008) printf("STATIC ");
    if (tag & 0x0010) printf("FINAL ");
    if (tag & 0x0040) printf("VOLATILE ");
    if (tag & 0x0080) printf("TRANSIENT ");
    if (tag & 0x1000) printf("SYNTHETIC ");
    if (tag & 0x4000) printf("ENUM ");
}
