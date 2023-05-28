#include "read-class-file.h"

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
  int i = 1;
  cp_info *finalCPAdress = classFile->constant_pool+classFile->constant_pool_count-1;
  for(cp_info * currentCPAdress = classFile->constant_pool; currentCPAdress < finalCPAdress; currentCPAdress++){
    currentCPAdress->tag = readU1(fp);
    printf("index: %d, tag: %d, ", i, currentCPAdress->tag);
    i++;
    switch (currentCPAdress->tag){
      case 7: // class
        printf("Constant class\n");
        currentCPAdress->CONSTANT_Class.name_index = readU2(fp);
          printf(" name_index: %d\n", currentCPAdress->CONSTANT_Class.name_index);
        break;
      case 9: // fieldRef
        printf("FieldRef\n");
        currentCPAdress->CONSTANT_Fieldref.class_index = readU2(fp);
        currentCPAdress->CONSTANT_Fieldref.name_and_type_index = readU2(fp);
        printf("-  class Index: %d\n", currentCPAdress->CONSTANT_Fieldref.class_index);
        printf("- name_and_type_index: %d\n", currentCPAdress->CONSTANT_Fieldref.name_and_type_index);
        break;
      case 10: // MethodRef
        printf("MethodRef\n");
        currentCPAdress->CONSTANT_Methodref.class_index = readU2(fp);
        currentCPAdress->CONSTANT_Methodref.name_and_type_index = readU2(fp);
        printf("- class_index: %d\n", currentCPAdress->CONSTANT_Methodref.class_index);
        printf("- name_and_index_type: %d\n", currentCPAdress->CONSTANT_Methodref.name_and_type_index);
        break;
      case 11: // InterfaceMethod
        printf("InterfaceMethod\n");
        currentCPAdress->CONSTANT_InterfaceMethodref.class_index = readU2(fp);
        currentCPAdress->CONSTANT_InterfaceMethodref.name_and_type_index = readU2(fp);
        printf("- class_index: %d\n", currentCPAdress->CONSTANT_InterfaceMethodref.class_index);
        printf("- name_and_index_type: %d\n", currentCPAdress->CONSTANT_InterfaceMethodref.name_and_type_index);
        break;
      case 8: // String
        printf("String\n");
        currentCPAdress->CONSTANT_String.string_index = readU2(fp);
        printf("- string_index: %d\n", currentCPAdress->CONSTANT_String.string_index);
        break;
      case 3: // Integer
        currentCPAdress->CONSTANT_Integer.bytes = readU4(fp);
        printf("Integer: %d\n", currentCPAdress->CONSTANT_Integer.bytes);
        break;
      case 4: // Float
        currentCPAdress->CONSTANT_Float.bytes = readU4(fp);
        printf("Float: %f\n", (float) currentCPAdress->CONSTANT_Float.bytes);
        break;
      case 5: // Long
        printf("Long\n");
        currentCPAdress->CONSTANT_Long.high_bytes = readU4(fp);
        currentCPAdress->CONSTANT_Long.low_bytes = readU4(fp);
        printf("- high-bytes: %d\n", currentCPAdress->CONSTANT_Long.high_bytes);
        printf("- low-bytes: %d\n", currentCPAdress->CONSTANT_Long.low_bytes);
        break;
      case 6: // Double
        printf("Double\n");
        currentCPAdress->CONSTANT_Double.high_bytes = readU4(fp);
        currentCPAdress->CONSTANT_Double.low_bytes = readU4(fp);
        printf("- high-bytes: %d\n", currentCPAdress->CONSTANT_Double.high_bytes);
        printf("- low-bytes: %d\n", currentCPAdress->CONSTANT_Double.low_bytes);
        break;
      case 12: // NameAndType
        printf("Name and Type\n");
        currentCPAdress->CONSTANT_NameAndType.name_index = readU2(fp);
        currentCPAdress->CONSTANT_NameAndType.descriptor_index = readU2(fp);
        printf("- name_index: %d\n", currentCPAdress->CONSTANT_NameAndType.name_index);
        printf("- descriptor_index: %d\n", currentCPAdress->CONSTANT_NameAndType.descriptor_index);
        break;
      case 1: // utf8
        printf("utf8\n\"");
        currentCPAdress->CONSTANT_Utf8.length = readU2(fp);
        currentCPAdress->CONSTANT_Utf8.bytes = (u1 * ) malloc(sizeof (u1) * currentCPAdress->CONSTANT_Utf8.length);
        for(int i=0; i<currentCPAdress->CONSTANT_Utf8.length; i++){
          currentCPAdress->CONSTANT_Utf8.bytes[i] = readU1(fp);
          printf("%c", currentCPAdress->CONSTANT_Utf8.bytes[i]);
        }
        printf("\"\n");
        break;
      case 15: // MethodHandle
        printf("Method Hanlde\n");
        currentCPAdress->CONSTANT_MethodHandle.reference_kind = readU1(fp);
        currentCPAdress->CONSTANT_MethodHandle.reference_index = readU2(fp);
        printf("- reference_kind: %d\n", currentCPAdress->CONSTANT_NameAndType.name_index);
        printf("- reference_index: %d\n", currentCPAdress->CONSTANT_NameAndType.descriptor_index);
        break;
      case 16: // MethodType
        printf("Method type\n");
        currentCPAdress->CONSTANT_MethodType.descriptor_index = readU2(fp);
        break;
      case 18: // InvokeDynamic
        printf("Invoke Dynamic\n");
        currentCPAdress->CONSTANT_InvokeDynamic.bootstrap_method_attr_index = readU2(fp);
        currentCPAdress->CONSTANT_InvokeDynamic.name_and_type_index = readU2(fp);
        printf("- bootstrap_method_attr_index: %d\n", currentCPAdress->CONSTANT_InvokeDynamic.bootstrap_method_attr_index);
        printf("- name_and_type_index: %d\n", currentCPAdress->CONSTANT_InvokeDynamic.name_and_type_index);
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
  u2 *finalInterface = classFile->interfaces + classFile->interfaces_count;
  for(u2 * currentInterface = classFile->interfaces; currentInterface < finalInterface; currentInterface ++){
    *currentInterface = readU2(fp);
    printf("%d \n", *currentInterface);
  }

  classFile->fields_count = readU2(fp);
  printf("fields_count: %d\n", classFile->fields_count);

  classFile->fields = malloc((classFile->fields_count) * sizeof (field_info));
  for(field_info * field=classFile->fields; field<(classFile->fields+classFile->fields_count); field ++){
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

  classFile->methods_count = readU2(fp);
  printf("methods_count: %d\n", classFile->methods_count);
  classFile->methods = malloc((classFile->methods_count) * sizeof (method_info));;
  for(int i = 0; i < classFile->methods_count; i++){
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


    attribute_info * attributes = method->attributes;
    for(int attribute_index = 0;  attribute_index < method->attributes_count; attribute_index++) {
      attribute_info * attribute = &attributes[attribute_index];

      attribute->attribute_name_index = readU2(fp);
      printf("name_index: %d\n", attribute->attribute_name_index);

      attribute->attribute_length = readU4(fp);
      printf("atribute length: %d\n", attribute->attribute_length);
      
      attribute->info = malloc((attribute->attribute_length) * sizeof (u1));

      for(int info_index = 0; info_index < attribute->attribute_length; info_index++){
        u1* info = &(attribute->info[info_index]);
        *info = readU1(fp);
        printf("%02x ", *info);
      }
      printf("\n---\n");
    }
  }

  classFile->attributes_count = readU2(fp);
  printf("attributes_count: %d\n", classFile->attributes_count);


  classFile->attributes = malloc((classFile->attributes_count) * sizeof (attribute_info));
  for(attribute_info * attribute=classFile->attributes; attribute<(classFile->attributes+classFile->attributes_count); attribute ++){

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
