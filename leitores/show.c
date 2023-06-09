#include "show.h"
#include <stdio.h>

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
    printf("Access flags: 0x%X\n", classFile.access_flags);
    printf("This class: %d\n", classFile.this_class);
    printf("Super class: %d\n", classFile.super_class);
    printf("Interfaces count: %d\n", classFile.interfaces_count);
    printf("Fields count: %d\n", classFile.fields_count);
    printf("Methods count: %d\n", classFile.methods_count);
    printf("Atributes count: %d\n", classFile.attributes_count);
}

void showConstantPool(ClassFile classFile) {
    printf("\n----- Pool de Constantes-----\n");

    cp_info * begin = classFile.constant_pool;
    cp_info * end = classFile.constant_pool_count + classFile.constant_pool;
    for(cp_info * constant = begin; constant < end; constant++) {
        showConstant(classFile.constant_pool, constant);
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

void showConstant(cp_info * constant_pool, cp_info * constant) {
    switch (constant->tag) {
        case 7: // class
            printf("Constant class\n");
            printf(" name_index: %d ", constant->CONSTANT_Class.name_index);
            printUtf8(constant_pool, constant->CONSTANT_Class.name_index);
            printf("\n");
            break;
        case 9: // fieldRef
            printf("FieldRef\n");
            printf("- class Index: %d ", constant->CONSTANT_Fieldref.class_index);
            printUtf8(constant_pool, constant->CONSTANT_Fieldref.class_index);
            printf("\n");

            printf("- name_and_type_index: %d ", constant->CONSTANT_Fieldref.name_and_type_index);
            printUtf8(constant_pool, constant->CONSTANT_Fieldref.name_and_type_index);
            printf("\n");
            break;
        case 10: // MethodRef
            printf("MethodRef\n");

            printf("- class_index: %d ", constant->CONSTANT_Methodref.class_index);
            printUtf8(constant_pool, constant->CONSTANT_Methodref.class_index);
            printf("\n");

            printf("- name_and_type_index: %d ", constant->CONSTANT_Methodref.name_and_type_index);
            printUtf8(constant_pool, constant->CONSTANT_Methodref.name_and_type_index);
            printf("\n");
            break;
        case 11: // InterfaceMethod
            printf("InterfaceMethod ");
            printf("- class_index: %d ", constant->CONSTANT_InterfaceMethodref.class_index);
            printUtf8(constant_pool, constant->CONSTANT_InterfaceMethodref.class_index);
            printf("\n");

            printf("- name_and_type_index: %d ", constant->CONSTANT_InterfaceMethodref.name_and_type_index);
            printUtf8(constant_pool, constant->CONSTANT_InterfaceMethodref.name_and_type_index);
            printf("\n");
            break;
        case 8: // String
            printf("String\n");
            printf("- string_index: %d ", constant->CONSTANT_String.string_index);
            printUtf8(constant_pool, constant->CONSTANT_String.string_index);
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
            printUtf8(constant_pool, constant->CONSTANT_InterfaceMethodref.name_and_type_index);
            printf("\n");
            
            printf("- descriptor_index: %d ", constant->CONSTANT_NameAndType.descriptor_index);
            printUtf8(constant_pool, constant->CONSTANT_NameAndType.descriptor_index);
            printf("\n");
            break;
        case 1: // utf8
            printf("utf8\n\"");
            for(int i=0; i<constant->CONSTANT_Utf8.length; i++) {
                printUtf8Char(constant->CONSTANT_Utf8.bytes[i]);
            }
            printf("\"\n");
            break;
        case 15: // MethodHandle
            printf("Method Hanlde\n");
            printf("- reference_kind: %d ", constant->CONSTANT_MethodHandle.reference_kind);
            printUtf8(constant_pool, constant->CONSTANT_MethodHandle.reference_kind);
            printf("\n");

            printf("- reference_index: %d ", constant->CONSTANT_MethodHandle.reference_index);
            printUtf8(constant_pool, constant->CONSTANT_MethodHandle.reference_index);
            printf("\n");
            break;
        case 16: // MethodType
            printf("Method type\n");
            printf("- descriptor_index: %d ", constant->CONSTANT_MethodType.descriptor_index);
            printUtf8(constant_pool, constant->CONSTANT_MethodType.descriptor_index);
            printf("\n");
            break;
        case 18: // InvokeDynamic
            printf("Invoke Dynamic\n");
            printf("- bootstrap_method_attr_index: %d ", constant->CONSTANT_InvokeDynamic.bootstrap_method_attr_index);
            printUtf8(constant_pool, constant->CONSTANT_InvokeDynamic.bootstrap_method_attr_index);
            printf("\n");
            
            printf("- name_and_type_index: %d ", constant->CONSTANT_InvokeDynamic.name_and_type_index);
            printUtf8(constant_pool, constant->CONSTANT_InvokeDynamic.name_and_type_index);
            printf("\n");
            break;
        default:
            printf("\n");
    }
}

void printUtf8(cp_info * constant_pool, int index) {
    cp_info * constant = constant_pool + index;
    switch (constant->tag) {
        case 7: // class
            printUtf8(constant_pool, constant->CONSTANT_Class.name_index);
            break;
        case 9: // fieldRef
            printUtf8(constant_pool, constant->CONSTANT_Fieldref.name_and_type_index);
            break;
        case 10: // MethodRef
            printUtf8(constant_pool, constant->CONSTANT_Methodref.name_and_type_index);
            break;
        case 11: // InterfaceMethod
            printUtf8(constant_pool, constant->CONSTANT_InterfaceMethodref.name_and_type_index);
            break;
        case 8: // String
            printUtf8(constant_pool, constant->CONSTANT_String.string_index);
            break;
        case 12: // NameAndType
            printUtf8(constant_pool, constant->CONSTANT_NameAndType.name_index);
            break;
        case 15: // MethodHandle
            printUtf8(constant_pool, constant->CONSTANT_MethodHandle.reference_index);
            break;
        case 16: // MethodType
            printUtf8(constant_pool, constant->CONSTANT_MethodType.descriptor_index);
            break;
        case 18: // InvokeDynamic
            printUtf8(constant_pool, constant->CONSTANT_InvokeDynamic.name_and_type_index);
            break;
        case 1: // utf8
            printf("\"");
            for(int i=0; i<constant->CONSTANT_Utf8.length; i++) {
                printUtf8Char(constant->CONSTANT_Utf8.bytes[i]);
            }
            printf("\"");
            break;
        default:
            break;
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
    printUtf8(fields, field->name_index); // FIXME: não printa nada
    printf("\n");

    printf("- descriptor_index: %d ", field->descriptor_index);
    printUtf8(fields, field->descriptor_index); // FIXME: não printa nada
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
