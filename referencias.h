typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;

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