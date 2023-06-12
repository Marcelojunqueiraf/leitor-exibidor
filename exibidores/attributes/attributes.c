#include "attributes.h"

void showAttributes(cp_info *constant_pool, attribute_info *attributes, u2 attributes_count)
{
    attribute_info *begin = attributes;
    attribute_info *end = attributes_count + attributes;
    for (attribute_info *attribute = begin; attribute < end; attribute++)
    {
        showAttribute(attribute, constant_pool);
    }
}

void showAttribute(attribute_info *attribute, cp_info *constant_pool)
{
    printf("Attribute name index: %d ", attribute->attribute_name_index);
    printf("%s", getUtf8(constant_pool, attribute->attribute_name_index));
    printf("\n");

    char *attributeType = getUtf8(constant_pool, attribute->attribute_name_index);

    printf("Attribute length: %d\n", attribute->attribute_length);
    if (!strcmp(attributeType, "Code"))
    {
        showCodeAttribute((code_attribute *)attribute->info, constant_pool);
    }
    else if (!strcmp(attributeType, "LineNumberTable"))
    {
        showLineNumberTableAttribute((LineNumberTable_attribute *)attribute->info);
    }
    else if (!strcmp(attributeType, "SourceFile"))
    {
        showSourceFileAttribute((SourceFile_attribute *)attribute->info, constant_pool);
    } 
    else if (!strcmp(attributeType, "Exceptions")) 
    {
        showExceptionsAttribute((Exceptions_attribute *)attribute->info, constant_pool);
    }
    else if (!strcmp(attributeType, "ConstantValue"))
    {
        showConstantValueAttribute((ConstantValue_attribute *)attribute->info, constant_pool);
    }
    else if (!strcmp(attributeType, "InnerClasses"))
    {
        showInnerClassesAttribute((InnerClasses_attribute *)attribute->info, constant_pool);
    }
    else if (!strcmp(attributeType, "LocalVariableTable"))
    {
        showLocalVariableTableAttribute((LocalVariableTable_attribute *)attribute->info, constant_pool);
    }
    else
    {
        printf("Attribute info: ");
        for (u4 info_index = 0; info_index < attribute->attribute_length; info_index++)
        {
            u1 *info = &(attribute->info[info_index]);
            printf("%02x ", *info);
        }
        printf("\n");
    }
}

void showExceptionsAttribute(Exceptions_attribute * exceptionsAttribute, cp_info * constant_pool) {
    printf("Number of exceptions: %d\n", exceptionsAttribute->number_of_exceptions);
    for (u2 i = 0; i < exceptionsAttribute->number_of_exceptions; i++) {
        printf("Exception index table: %d\n", exceptionsAttribute->exception_index_table[i]);
    }
}

void showConstantValueAttribute(ConstantValue_attribute * constantValueAttribute, cp_info * constant_pool) {
    printf("Constant value index: %d\n", constantValueAttribute->constantvalue_index);
}

void showInnerClassesAttribute(InnerClasses_attribute * innerClassesAttribute, cp_info * constant_pool) {
    printf("Number of classes: %d\n", innerClassesAttribute->number_of_classes);
    for (u2 i = 0; i < innerClassesAttribute->number_of_classes; i++) {
        printf("Inner class info index: %d\n", innerClassesAttribute->classes[i].inner_class_info_index);
        printf("Outer class info index: %d\n", innerClassesAttribute->classes[i].outer_class_info_index);
        printf("Inner name index: %d\n", innerClassesAttribute->classes[i].inner_name_index);
        printf("Inner class access flags: %d\n", innerClassesAttribute->classes[i].inner_class_access_flags);
    }
}

void showLocalVariableTableAttribute(LocalVariableTable_attribute *localVariableTableAttribute, cp_info *constant_pool)
{
    printf("Local variable table length: %d\n", localVariableTableAttribute->local_variable_table_length);
    for (u2 i = 0; i < localVariableTableAttribute->local_variable_table_length; i++)
    {
        printf("Start pc: %d\n", localVariableTableAttribute->local_variable_table[i].start_pc);
        printf("Length: %d\n", localVariableTableAttribute->local_variable_table[i].length);
        printf("Name index: %d\n", localVariableTableAttribute->local_variable_table[i].name_index);
        printf("Descriptor index: %d\n", localVariableTableAttribute->local_variable_table[i].descriptor_index);
        printf("Index: %d\n", localVariableTableAttribute->local_variable_table[i].index);
    }
}
