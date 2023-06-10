#include "int-types.h"


#ifndef	CLASS_FILE_H
#define CLASS_FILE_H


typedef struct {
  u1 tag;
  union {
    struct {
      u2 name_index;
    } CONSTANT_Class;
    struct {
      u2 class_index;
      u2 name_and_type_index;
    } CONSTANT_Fieldref;
    struct {
      u2 class_index;
      u2 name_and_type_index;
    } CONSTANT_Methodref;
    struct {
      u2 class_index;
      u2 name_and_type_index;
    } CONSTANT_InterfaceMethodref;
    struct {
      u2 string_index;
    } CONSTANT_String;
    struct {
      u4 bytes;
    } CONSTANT_Integer;
    struct {
      u4 bytes;
    } CONSTANT_Float;
    struct {
      u4 high_bytes;
      u4 low_bytes;
    } CONSTANT_Long;
    struct {
      u4 high_bytes;
      u4 low_bytes;
    } CONSTANT_Double;
    struct {
      u2 name_index;
      u2 descriptor_index;
    } CONSTANT_NameAndType;
    struct {
      u2 length;
      u1 * bytes;
    } CONSTANT_Utf8;
    struct {
      u1 reference_kind;
      u2 reference_index;
    } CONSTANT_MethodHandle;
    struct {
      u2 descriptor_index;
    } CONSTANT_MethodType;
    struct {
      u2 bootstrap_method_attr_index;
      u2 name_and_type_index;
    } CONSTANT_InvokeDynamic;
  };
} cp_info;

typedef struct {
  u2 attribute_name_index;
  u4 attribute_length;
  u1 * info;
} attribute_info;

typedef struct {
 u2 access_flags;
 u2 name_index;
 u2 descriptor_index;
 u2 attributes_count;
 attribute_info * attributes;
} field_info;

typedef struct {
  u2 access_flags;
  u2 name_index;
  u2 descriptor_index;
  u2 attributes_count;
  attribute_info * attributes;
} method_info;

typedef struct {
  u4 magic_number;
  u2 minor_version;
  u2 major_version;
  u2 constant_pool_count;
  cp_info * constant_pool;
  u2 access_flags;
  u2 this_class;
  u2 super_class;
  u2 interfaces_count;
  u2 * interfaces;
  u2 fields_count;
  field_info * fields;
  u2 methods_count;
  method_info * methods;
  u2 attributes_count;
  attribute_info * attributes;
} ClassFile;

//attributes
typedef struct{
  u2 start_pc;
  u2 end_pc;
  u2 handler_pc;
  u2 catch_type;
} exception_table;

typedef struct  {
  u2 max_stack;
  u2 max_locals;
  u4 code_length;
  u1 * code;
  u2 exception_table_length;
  exception_table * exception_table; // Alocar com exception_table_length
  u2 attributes_count;
	attribute_info * attributes;
} code_attribute;

typedef struct {
  u2 start_pc;
  u2 line_number;
} line_number_table;

typedef struct {
  u2 line_number_table_length;
  line_number_table * line_number_table; // Alocar com line_number_table_length
} LineNumberTable_attribute;

typedef struct {
  u2 sourcefile_index;
} SourceFile_attribute;

typedef struct {
  u2 attribute_name_index;
  u4 attribute_length;
  u2 constantvalue_index;
} ConstantValue_attribute;

// typedef struct {} Top_variable_info;
// typedef struct {} Integer_variable_info;
// typedef struct {} Float_variable_info;
// typedef struct {} Null_variable_info;
// typedef struct {} UninitializedThis_variable_info;
// typedef struct {} Long_variable_info;
// typedef struct {} Double_variable_info;
// typedef struct {
//  u2 cpool_index;
// } Object_variable_info;
// typedef struct {
//  u2 offset;
// } Uninitialized_variable_info;

// typedef struct {
//   u1 tag;
//   union {
//     Top_variable_info;
//     Integer_variable_info;
//     Float_variable_info;
//     Long_variable_info;
//     Double_variable_info;
//     Null_variable_info;
//     UninitializedThis_variable_info;
//     Object_variable_info;
//     Uninitialized_variable_info;
//   };
// } verification_type_info;


// typedef struct {} same_frame;

// typedef struct {
//   verification_type_info * stack; // Alocar com 1
// } same_locals_1_stack_item_frame;

// typedef struct {
//   verification_type_info * stack; // Alocar com 1
// } same_locals_1_stack_item_frame_extended;

// typedef struct {} chop_frame;

// typedef struct {} same_frame_extended;

// typedef struct {
//   verification_type_info * locals; // Alocar com frame_type - 251
// } append_frame;

// typedef struct {
//   u2 number_of_locals;
//   verification_type_info * locals; // Alocar com number_of_locals
//   u2 number_of_stack_items;
//   verification_type_info * stack; // Alocar com number_of_stack_items
// } full_frame;

// typedef struct {
//   u1 frame_type;
//   union {
//     same_frame;
//     same_locals_1_stack_item_frame;
//     struct {
//       u2 offset_delta;
//       union {
//         append_frame;
//         same_frame_extended;
//         same_locals_1_stack_item_frame_extended;
//         chop_frame;
//         full_frame;
//       };
//     };
//   };
// } stack_map_frame;

// typedef struct {
//   u2 attribute_name_index;
//   u4 attribute_length;
//   u2 number_of_entries;
//   stack_map_frame * entries; // Alocar com number_of_entries
// } StackMapTable_attribute;

#endif
