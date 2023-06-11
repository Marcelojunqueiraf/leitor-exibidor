#include "read-class-file.h"
#include "read-bytes.h"
#include "../common/int-types.h"
#include "../common/erros.h"
#include "../exibidores/common.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "attributes/attributes.h"

int readClassFile(char path[], ClassFile* classFile){
  if (!strstr(path, ".class")){
    fprintf(stderr, "Arquivo não é .class\n");
    return INVALID_ARGUMENTS;
  }

  FILE *fp = fopen(path, "rb");
  if(!fp) {
    fprintf(stderr, "Não foi possível abrir o arquivo\n");
    return WRONG_PATH;
  }

  classFile->magic_number = readU4(fp);
  if(classFile->magic_number != 0xCAFEBABE) {
    fprintf(stderr, "Magic number não bateu: %x", classFile->magic_number);
    fclose(fp);
    return WRONG_MAGIC_NUMBER;
  }

  classFile->minor_version = readU2(fp);
  classFile->major_version = readU2(fp);

  printf("Versão do java: %d.%d\n", classFile->major_version, classFile->minor_version);

  classFile->constant_pool_count = readU2(fp);
  printf("pool count: %d\n", classFile->constant_pool_count);

  classFile->constant_pool = malloc((classFile->constant_pool_count+1) * sizeof (cp_info));
  cp_info * begin = classFile->constant_pool +1;
  cp_info * end = begin + classFile->constant_pool_count -1;
  int cp_index = 1;
  for(cp_info * constant = begin; constant < end; constant++){
    constant->tag = readU1(fp);
    printf("index: %d, tag: %d, ", cp_index, constant->tag);
    cp_index += 1;
    switch (constant->tag){
      case 7: // class
        printf("Constant class\n");
        constant->CONSTANT_Class.name_index = readU2(fp);
          printf(" name_index: %d\n", constant->CONSTANT_Class.name_index);
        break;
      case 9: // fieldRef
        printf("FieldRef\n");
        constant->CONSTANT_Fieldref.class_index = readU2(fp);
        constant->CONSTANT_Fieldref.name_and_type_index = readU2(fp);
        printf("-  class Index: %d\n", constant->CONSTANT_Fieldref.class_index);
        printf("- name_and_type_index: %d\n", constant->CONSTANT_Fieldref.name_and_type_index);
        break;
      case 10: // MethodRef
        printf("MethodRef\n");
        constant->CONSTANT_Methodref.class_index = readU2(fp);
        constant->CONSTANT_Methodref.name_and_type_index = readU2(fp);
        printf("- class_index: %d\n", constant->CONSTANT_Methodref.class_index);
        printf("- name_and_index_type: %d\n", constant->CONSTANT_Methodref.name_and_type_index);
        break;
      case 11: // InterfaceMethod
        printf("InterfaceMethod\n");
        constant->CONSTANT_InterfaceMethodref.class_index = readU2(fp);
        constant->CONSTANT_InterfaceMethodref.name_and_type_index = readU2(fp);
        printf("- class_index: %d\n", constant->CONSTANT_InterfaceMethodref.class_index);
        printf("- name_and_index_type: %d\n", constant->CONSTANT_InterfaceMethodref.name_and_type_index);
        break;
      case 8: // String
        printf("String\n");
        constant->CONSTANT_String.string_index = readU2(fp);
        printf("- string_index: %d\n", constant->CONSTANT_String.string_index);
        break;
      case 3: // Integer
        constant->CONSTANT_Integer.bytes = readU4(fp);
        printf("Integer: %d\n", constant->CONSTANT_Integer.bytes);
        break;
      case 4: // Float
        constant->CONSTANT_Float.bytes = readU4(fp);
        printf("Float: %f\n", (float) constant->CONSTANT_Float.bytes);
        break;
      case 5: // Long
        printf("Long\n");
        constant->CONSTANT_Long.high_bytes = readU4(fp);
        constant->CONSTANT_Long.low_bytes = readU4(fp);
        printf("- high-bytes: %d\n", constant->CONSTANT_Long.high_bytes);
        printf("- low-bytes: %d\n", constant->CONSTANT_Long.low_bytes);
        break;
      case 6: // Double
        printf("Double\n");
        constant->CONSTANT_Double.high_bytes = readU4(fp);
        constant->CONSTANT_Double.low_bytes = readU4(fp);
        printf("- high-bytes: %d\n", constant->CONSTANT_Double.high_bytes);
        printf("- low-bytes: %d\n", constant->CONSTANT_Double.low_bytes);
        break;
      case 12: // NameAndType
        printf("Name and Type\n");
        constant->CONSTANT_NameAndType.name_index = readU2(fp);
        constant->CONSTANT_NameAndType.descriptor_index = readU2(fp);
        printf("- name_index: %d\n", constant->CONSTANT_NameAndType.name_index);
        printf("- descriptor_index: %d\n", constant->CONSTANT_NameAndType.descriptor_index);
        break;
      case 1: // utf8
        printf("utf8\n\"");
        constant->CONSTANT_Utf8.length = readU2(fp);
        constant->CONSTANT_Utf8.bytes = (u1 * ) malloc(sizeof (u1) * constant->CONSTANT_Utf8.length);
        for(int i=0; i<constant->CONSTANT_Utf8.length; i++){
          constant->CONSTANT_Utf8.bytes[i] = readU1(fp);
          printf("%c", constant->CONSTANT_Utf8.bytes[i]);
        }
        printf("\"\n");
        break;
      case 15: // MethodHandle
        printf("Method Hanlde\n");
        constant->CONSTANT_MethodHandle.reference_kind = readU1(fp);
        constant->CONSTANT_MethodHandle.reference_index = readU2(fp);
        printf("- reference_kind: %d\n", constant->CONSTANT_NameAndType.name_index);
        printf("- reference_index: %d\n", constant->CONSTANT_NameAndType.descriptor_index);
        break;
      case 16: // MethodType
        printf("Method type\n");
        constant->CONSTANT_MethodType.descriptor_index = readU2(fp);
        break;
      case 18: // InvokeDynamic
        printf("Invoke Dynamic\n");
        constant->CONSTANT_InvokeDynamic.bootstrap_method_attr_index = readU2(fp);
        constant->CONSTANT_InvokeDynamic.name_and_type_index = readU2(fp);
        printf("- bootstrap_method_attr_index: %d\n", constant->CONSTANT_InvokeDynamic.bootstrap_method_attr_index);
        printf("- name_and_type_index: %d\n", constant->CONSTANT_InvokeDynamic.name_and_type_index);
        break;
      default:
        printf("\n");
    }
  }

  classFile->access_flags = readU2(fp);
  printf("access_class: %x\n", classFile->access_flags );

  classFile->this_class = readU2(fp);
  printf("this: %d\n", classFile->this_class);
  
  classFile->super_class = readU2(fp);
  printf("super: %d\n", classFile->super_class);
  
  classFile->interfaces_count = readU2(fp);
  printf("interface_count: %d\n", classFile->interfaces_count);

  classFile->interfaces = malloc((classFile->interfaces_count) * sizeof (u2));

  for(u2 interface_index = 0; interface_index < classFile->interfaces_count; interface_index++){
    u2 * interface = &(classFile->interfaces[interface_index]);
    *interface = readU2(fp);
    printf("%d \n", *interface);
  }

  classFile->fields_count = readU2(fp);
  printf("fields_count: %d\n", classFile->fields_count);

  classFile->fields = malloc((classFile->fields_count) * sizeof (field_info));
  for(u2 field_index = 0; field_index < classFile->fields_count; field_index++){
    field_info * field= &(classFile->fields[field_index]);

    printf("field\n");
    field->access_flags = readU2(fp);
    printf("access_flags: %x \n", field->access_flags  );
    
    field->name_index = readU2(fp);
    printf("name index: %d \n", field->name_index);
    
    field->descriptor_index = readU2(fp);
    printf("descriptor_index: %d \n", field->descriptor_index);
    
    field->attributes_count = readU2(fp);
    printf("attributes_count: %d \n", field->attributes_count);
    
    field->attributes = malloc((field->attributes_count) * sizeof (attribute_info));

    readAttributes(classFile->constant_pool, field->attributes, fp, field->attributes_count);
  }

  classFile->methods_count = readU2(fp);
  printf("methods_count: %d\n", classFile->methods_count);
  classFile->methods = malloc((classFile->methods_count) * sizeof (method_info));;
  for(u2 i = 0; i < classFile->methods_count; i++){
    method_info* method = &(classFile->methods[i]);

    printf("method\n");
    method->access_flags = readU2(fp);
    printf("access_flags: %x \n", method->access_flags  );
    
    method->name_index = readU2(fp);
    printf("name index: %d \n", method->name_index);
    
    method->descriptor_index = readU2(fp);
    printf("descriptor_index: %d \n", method->descriptor_index);
    // dá pra reutilizar o código de atributos
    method->attributes_count = readU2(fp);
    printf("attributes_count: %d \n", method->attributes_count);
    
    method->attributes = malloc((method->attributes_count) * sizeof (attribute_info));
    readAttributes(classFile->constant_pool, method->attributes, fp, method->attributes_count);
  }

  classFile->attributes_count = readU2(fp);
  printf("attributes_count: %d\n", classFile->attributes_count);

  classFile->attributes = malloc((classFile->attributes_count) * sizeof (attribute_info));

  readAttributes(classFile->constant_pool, classFile->attributes, fp, classFile->attributes_count);
  fclose(fp);

  return 0;
}
