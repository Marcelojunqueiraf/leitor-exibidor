#include "show.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "attributes/attributes.h"
#include "../common/get-utf8.h"
#include <math.h>

int showClassFile(ClassFile classFile)
{
    showInformacoesGerais(classFile);

    showConstantPool(classFile);

    showInterfaces(classFile);

    showFields(classFile);

    showMethods(classFile);

    printf("\n----- Atributos da classe -----\n");
    showAttributes(classFile.constant_pool, classFile.attributes, classFile.attributes_count);

    return 0;
}

void showInformacoesGerais(ClassFile classFile)
{
    printf("----- Informações Gerais -----\n");

    printf("Magic number: 0x%04X\n", classFile.magic_number);
    printf("Versão do java: %d.%d\n", classFile.major_version, classFile.minor_version);
    printf("Pool count: %d\n", classFile.constant_pool_count);
    printf("Access flags: 0x%04X %s\n", classFile.access_flags, getAccessFlag(classFile.access_flags));

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

void showConstantPool(ClassFile classFile)
{
    printf("\n----- Pool de Constantes -----\n");

    cp_info *begin = classFile.constant_pool + 1;
    cp_info *end = classFile.constant_pool_count + classFile.constant_pool;
    int i = 1;
    for (cp_info *constant = begin; constant < end; constant++)
    {
        showConstant(classFile.constant_pool, constant, i++);
    }
}

void showInterfaces(ClassFile classFile)
{
    printf("\n----- Interfaces -----\n");

    u2 *begin = classFile.interfaces;
    u2 *end = classFile.interfaces + classFile.interfaces_count;
    int i = 0;
    for (u2 *interface = begin; interface < end; interface++)
    {
        showInterface(*interface, classFile.constant_pool, i++);
    }
}

void showFields(ClassFile classFile)
{
    printf("\n----- Fields -----\n");

    field_info *begin = classFile.fields;
    field_info *end = classFile.fields_count + classFile.fields;
    int i = 0;
    for (field_info *field = begin; field < end; field++)
    {
        showField(field, classFile.constant_pool, i++);
    }
}

void showMethods(ClassFile classFile)
{
    printf("\n----- Métodos -----\n");
    method_info *begin = classFile.methods;
    method_info *end = classFile.methods_count + classFile.methods;
    int i = 0;
    for (method_info *method = begin; method < end; method++)
    {
        showMethod(method, classFile.constant_pool, i++);
    }
}

void showMethod(method_info *method, cp_info *constant_pool, u2 index)
{
    printf("\n---- Método [%d] ----\n", index);

    printf("Access flags: 0x%04X %s\n", method->access_flags, getAccessFlag(method->access_flags));

    printf("Name index: %d ", method->name_index);
    printf("%s", getUtf8(constant_pool, method->name_index));
    printf("\n");

    printf("Descriptor index: %d ", method->descriptor_index);
    printf("%s", getUtf8(constant_pool, method->descriptor_index));
    printf("\n");

    printf("Attributes count: %d\n", method->attributes_count);

    printf("----- Atributos do método -----\n");
    showAttributes(constant_pool, method->attributes, method->attributes_count);
}

void showConstant(cp_info *constant_pool, cp_info *constant, u2 index)
{
    printf("\n---- Constante [%d] ----\n", index);
    printf("Tag: %d ", constant->tag);
    switch (constant->tag)
    {
    case 7:
    { // class
        printf("Constant class\n");
        printf("- name_index: %d ", constant->CONSTANT_Class.name_index);
        printf("\n");
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_Class.name_index));
        printf("\n");
        break;
    }
    case 9:
    { // fieldRef
        printf("FieldRef\n");
        printf("- class Index: %d ", constant->CONSTANT_Fieldref.class_index);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_Fieldref.class_index));
        printf("\n");

        printf("- name_and_type_index: %d ", constant->CONSTANT_Fieldref.name_and_type_index);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_Fieldref.name_and_type_index));
        printf("\n");
        break;
    }
    case 10:
    { // MethodRef
        printf("MethodRef\n");

        printf("- class_index: %d ", constant->CONSTANT_Methodref.class_index);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_Methodref.class_index));
        printf("\n");

        printf("- name_and_type_index: %d ", constant->CONSTANT_Methodref.name_and_type_index);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_Methodref.name_and_type_index));
        printf("\n");
        break;
    }
    case 11:
    { // InterfaceMethod
        printf("InterfaceMethod ");
        printf("- class_index: %d ", constant->CONSTANT_InterfaceMethodref.class_index);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_InterfaceMethodref.class_index));
        printf("\n");

        printf("- name_and_type_index: %d ", constant->CONSTANT_InterfaceMethodref.name_and_type_index);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_InterfaceMethodref.name_and_type_index));
        printf("\n");
        break;
    }
    case 8:
    { // String
        printf("String\n");
        printf("- string_index: %d ", constant->CONSTANT_String.string_index);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_String.string_index));
        printf("\n");
        break;
    }
    case 3:
    { // Integer
        printf("Integer: %d\n", constant->CONSTANT_Integer.bytes);
        break;
    }
    case 4:
    { // Float
        printf("Float: %f\n", getFloat(constant->CONSTANT_Float.bytes));
        break;
    }
    case 5:
    { // Long
        int64_t longValue = ((int64_t)constant->CONSTANT_Long.high_bytes << 32) | constant->CONSTANT_Long.low_bytes;
        printf("Long: %lld\n", longValue);
        break;
    }
    case 6:
    { // Double
        printf("Double %lf\n", getDouble(constant->CONSTANT_Double.low_bytes, constant->CONSTANT_Double.high_bytes));
        break;
    }
    case 12:
    { // NameAndType
        printf("Name and Type\n");
        printf("- name_index: %d ", constant->CONSTANT_NameAndType.name_index);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_InterfaceMethodref.name_and_type_index));
        printf("\n");

        printf("- descriptor_index: %d ", constant->CONSTANT_NameAndType.descriptor_index);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_NameAndType.descriptor_index));
        printf("\n");
        break;
    }
    case 1:
    { // utf8
        printf("utf8: \n\"%s\"\n", getUtf8(constant_pool, index));
        break;
    }
    case 15:
    { // MethodHandle
        printf("Method Hanlde\n");
        printf("- reference_kind: %d ", constant->CONSTANT_MethodHandle.reference_kind);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_MethodHandle.reference_kind));
        printf("\n");

        printf("- reference_index: %d ", constant->CONSTANT_MethodHandle.reference_index);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_MethodHandle.reference_index));
        printf("\n");
        break;
    }
    case 16:
    { // MethodType
        printf("Method type\n");
        printf("- descriptor_index: %d ", constant->CONSTANT_MethodType.descriptor_index);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_MethodType.descriptor_index));
        printf("\n");
        break;
    }
    case 18:
    { // InvokeDynamic
        printf("Invoke Dynamic\n");
        printf("- bootstrap_method_attr_index: %d ", constant->CONSTANT_InvokeDynamic.bootstrap_method_attr_index);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_InvokeDynamic.bootstrap_method_attr_index));
        printf("\n");

        printf("- name_and_type_index: %d ", constant->CONSTANT_InvokeDynamic.name_and_type_index);
        printf("%s", getUtf8(constant_pool, constant->CONSTANT_InvokeDynamic.name_and_type_index));
        printf("\n");
        break;
    }
    default:
        printf("\n");
    }
}

void showField(field_info *field, cp_info *constant_pool, u2 index)
{
    printf("\n----- Field [%d] -----\n", index);

    printf("- access_flags: %d %s\n", field->access_flags, getAccessFlag(field->access_flags));

    printf("- name index: %d %s\n", field->name_index, getUtf8(constant_pool, field->name_index));

    printf("- descriptor_index: %d %s\n", field->descriptor_index, getUtf8(constant_pool, field->descriptor_index));

    printf("- attributes_count: %d\n", field->attributes_count);

    // TODO: listar attributes
    showAttributes(constant_pool, field->attributes, field->attributes_count);
}

void showInterface(u2 interface, cp_info *constant_pool, u2 index)
{
    printf("\n----- Interface [%d] -----\n", index);

    printf("interface: %d %s\n", interface, getUtf8(constant_pool, interface));
}

char *getAccessFlag(u1 tag)
{
    char *accessFlag = malloc(sizeof(char) * 100);
    strcpy(accessFlag, "");

    if (tag & 0x0001)
        strcat(accessFlag, "PUBLIC ");
    if (tag & 0x0002)
        strcat(accessFlag, "PRIVATE ");
    if (tag & 0x0004)
        strcat(accessFlag, "PROTECTED ");
    if (tag & 0x0008)
        strcat(accessFlag, "STATIC ");
    if (tag & 0x0010)
        strcat(accessFlag, "FINAL ");
    if (tag & 0x0040)
        strcat(accessFlag, "VOLATILE ");
    if (tag & 0x0080)
        strcat(accessFlag, "TRANSIENT ");
    if (tag & 0x1000)
        strcat(accessFlag, "SYNTHETIC ");
    if (tag & 0x4000)
        strcat(accessFlag, "ENUM ");

    return accessFlag;
}

float getFloat(u4 value)
{
    int sinal = ((value >> 31) == 0) ? 1 : -1;
    int expon = ((value >> 23) & 0xff);
    int mant = (expon == 0) ? (value & 0x7fffff) << 1 : (value & 0x7fffff) | 0x800000;
    float retorno = (sinal) * (mant) * (pow(2, expon - 150));
    return retorno;
}

double getDouble(u4 low, u4 high)
{
    uint64_t valor = ((uint64_t)high << 32) | (uint64_t)low;
    int sinal = ((valor >> 63) == 0) ? 1 : -1;
    int expon = ((valor >> 52) & 0x7ffL);
    long mant = (expon == 0) ? ((valor & 0xfffffffffffffL) << 1) : ((valor & 0xfffffffffffffL) | 0x10000000000000L);

    double retorno = sinal * mant * (pow(2, expon - 1075));
    return retorno;
}