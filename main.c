#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "leitor.h"

// Futuramente essa será a função readClassFile
int main(int argc, char *argv[]){
  FILE *fp = fopen("Child.class", "rb");
  if(!fp) {
    fprintf(stderr, "Não foi possível abrir o arquivo\n");
    return 1;
  }

  ClassFile classFile;

  classFile.magic_number = readU4(fp);
  if(classFile.magic_number != 0xCAFEBABE) {
    fprintf(stderr, "Magic number não bateu: %x", classFile.magic_number);
    fclose(fp);
    return 1;
  }

  classFile.minor_version = readU2(fp);
  classFile.major_version = readU2(fp);

  printf("Versão do java: %d.%d\n", classFile.major_version, classFile.minor_version);

  classFile.constant_pool_count = readU2(fp);
  printf("pool count: %d\n", classFile.constant_pool_count);

  classFile.constant_pool = malloc((classFile.constant_pool_count+1) * sizeof (cp_info));
  int i = 1;
  for(cp_info * aux=classFile.constant_pool; aux<(classFile.constant_pool+classFile.constant_pool_count-1); aux ++){
    aux->tag = readU1(fp);
    printf("index: %d, tag: %d, ", i, aux->tag);
    i++;
    switch (aux->tag){
      case 7: // class
        printf("Constant class\n");
        aux->CONSTANT_Class.name_index = readU2(fp);
          printf(" name_index: %d\n", aux->CONSTANT_Class.name_index);
        break;
      case 9: // fieldRef
        printf("FieldRef\n");
        aux->CONSTANT_Fieldref.class_index = readU2(fp);
        aux->CONSTANT_Fieldref.name_and_type_index = readU2(fp);
        printf("-  class Index: %d\n", aux->CONSTANT_Fieldref.class_index);
        printf("- name_and_type_index: %d\n", aux->CONSTANT_Fieldref.name_and_type_index);
        break;
      case 10: // MethodRef
        printf("MethodRef\n");
        aux->CONSTANT_Methodref.class_index = readU2(fp);
        aux->CONSTANT_Methodref.name_and_type_index = readU2(fp);
        printf("- class_index: %d\n", aux->CONSTANT_Methodref.class_index);
        printf("- name_and_index_type: %d\n", aux->CONSTANT_Methodref.name_and_type_index);
        break;
      case 11: // InterfaceMethod
        printf("InterfaceMethod\n");
        aux->CONSTANT_InterfaceMethodref.class_index = readU2(fp);
        aux->CONSTANT_InterfaceMethodref.name_and_type_index = readU2(fp);
        printf("- class_index: %d\n", aux->CONSTANT_InterfaceMethodref.class_index);
        printf("- name_and_index_type: %d\n", aux->CONSTANT_InterfaceMethodref.name_and_type_index);
        break;
      case 8: // String
        printf("String\n");
        aux->CONSTANT_String.string_index = readU2(fp);
        printf("- string_index: %d\n", aux->CONSTANT_String.string_index);
        break;
      case 3: // Integer
        aux->CONSTANT_Integer.bytes = readU4(fp);
        printf("Integer: %d\n", aux->CONSTANT_Integer.bytes);
        break;
      case 4: // Float
        aux->CONSTANT_Float.bytes = readU4(fp);
        printf("Float: %f\n", (float) aux->CONSTANT_Float.bytes);
        break;
      case 5: // Long
        printf("Long\n");
        aux->CONSTANT_Long.high_bytes = readU4(fp);
        aux->CONSTANT_Long.low_bytes = readU4(fp);
        printf("- high-bytes: %d\n", aux->CONSTANT_Long.high_bytes);
        printf("- low-bytes: %d\n", aux->CONSTANT_Long.low_bytes);
        break;
      case 6: // Double
        printf("Double\n");
        aux->CONSTANT_Double.high_bytes = readU4(fp);
        aux->CONSTANT_Double.low_bytes = readU4(fp);
        printf("- high-bytes: %d\n", aux->CONSTANT_Double.high_bytes);
        printf("- low-bytes: %d\n", aux->CONSTANT_Double.low_bytes);
        break;
      case 12: // NameAndType
        printf("Name and Type\n");
        aux->CONSTANT_NameAndType.name_index = readU2(fp);
        aux->CONSTANT_NameAndType.descriptor_index = readU2(fp);
        printf("- name_index: %d\n", aux->CONSTANT_NameAndType.name_index);
        printf("- descriptor_index: %d\n", aux->CONSTANT_NameAndType.descriptor_index);
        break;
      case 1: // utf8
        printf("utf8\n\"");
        aux->CONSTANT_Utf8.length = readU2(fp);
        aux->CONSTANT_Utf8.bytes = (u1 * ) malloc(sizeof (u1) * aux->CONSTANT_Utf8.length);
        for(int i=0; i<aux->CONSTANT_Utf8.length; i++){
          aux->CONSTANT_Utf8.bytes[i] = readU1(fp);
          printf("%c", aux->CONSTANT_Utf8.bytes[i]);
        }
        printf("\"\n");
        break;
      case 15: // MethodHandle
        printf("Method Hanlde\n");
        aux->CONSTANT_MethodHandle.reference_kind = readU1(fp);
        aux->CONSTANT_MethodHandle.reference_index = readU2(fp);
        printf("- reference_kind: %d\n", aux->CONSTANT_NameAndType.name_index);
        printf("- reference_index: %d\n", aux->CONSTANT_NameAndType.descriptor_index);
        break;
      case 16: // MethodType
        printf("Method type\n");
        aux->CONSTANT_MethodType.descriptor_index = readU2(fp);
        break;
      case 18: // InvokeDynamic
        printf("Invoke Dynamic\n");
        aux->CONSTANT_InvokeDynamic.bootstrap_method_attr_index = readU2(fp);
        aux->CONSTANT_InvokeDynamic.name_and_type_index = readU2(fp);
        printf("- bootstrap_method_attr_index: %d\n", aux->CONSTANT_InvokeDynamic.bootstrap_method_attr_index);
        printf("- name_and_type_index: %d\n", aux->CONSTANT_InvokeDynamic.name_and_type_index);
        break;
      default:
        printf("\n");
    }
  }

  classFile.access_flags = readU2(fp);
  printf("access_class: %x\n", classFile.access_flags );

  classFile.this_class = readU2(fp);
  printf("this: %d\n", classFile.this_class);
  
  classFile.super_class = readU2(fp);
  printf("super: %d\n", classFile.super_class);
  
  classFile.interfaces_count = readU2(fp);
  printf("interface_count: %d\n", classFile.interfaces_count);

  classFile.interfaces = malloc((classFile.interfaces_count) * sizeof (u2));
  for(u2 * aux=classFile.interfaces; aux<(classFile.interfaces+classFile.interfaces_count); aux ++){
    *aux = readU2(fp);
    printf("%d \n", *aux);
  }

  classFile.fields_count = readU2(fp);
  printf("fields_count: %d\n", classFile.fields_count);

  classFile.fields = malloc((classFile.fields_count) * sizeof (field_info));
  for(field_info * field=classFile.fields; field<(classFile.fields+classFile.fields_count); field ++){
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

    for(attribute_info * attribute = field->attributes; attribute<field->attributes+field->attributes_count; field++) {
      attribute->attribute_name_index = readU2(fp);
      printf("name_index: %d\n", attribute->attribute_name_index);

      attribute->attribute_length = readU4(fp);
      printf("atribute length: %d\n", attribute->attribute_name_index);
      
      attribute->info = malloc((attribute->attribute_length) * sizeof (u1));

      for(u1 * info = attribute->info; info<attribute->info+attribute->attribute_length; info++){
        *info = readU1(fp);
        printf("%d\n", *info);
      }
      printf("---\n");
    }
  }

  classFile.methods_count = readU2(fp);
  printf("methods_count: %d\n", classFile.methods_count);

  classFile.methods = malloc((classFile.methods_count) * sizeof (method_info));
  for(method_info * method=classFile.methods; method<(classFile.methods+classFile.methods_count+1); method ++){
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


    for(attribute_info * attribute = method->attributes; attribute<(method->attributes+method->attributes_count); method++) {
      attribute->attribute_name_index = readU2(fp);
      printf("name_index: %d\n", attribute->attribute_name_index);

      attribute->attribute_length = readU4(fp);
      printf("atribute length: %d\n", attribute->attribute_length);
      
      attribute->info = malloc((attribute->attribute_length) * sizeof (u1));

      for(u1 * info = attribute->info; info<attribute->info+attribute->attribute_length; info++){
        *info = readU1(fp);
        printf("%d ", *info);
      }
      printf("\n---\n");
    }
  }

  classFile.attributes_count = readU2(fp);
  printf("attributes_count: %d\n", classFile.attributes_count);


  classFile.attributes = malloc((classFile.attributes_count) * sizeof (attribute_info));
  for(attribute_info * attribute=classFile.attributes; attribute<(classFile.attributes+classFile.attributes_count); attribute ++){

    printf("attribute\n");
    attribute->attribute_name_index = readU2(fp);
    printf("name_index: %d\n", attribute->attribute_name_index);

    attribute->attribute_length = readU4(fp);
    printf("atribute length: %d\n", attribute->attribute_length);
    
    attribute->info = malloc((attribute->attribute_length) * sizeof (u1));

    for(u1 * info = attribute->info; info<(attribute->info+attribute->attribute_length); info++){
      *info = readU1(fp);
      printf("%d\n", *info);
    }
  }
  
  fclose(fp);

  return 0;
}
