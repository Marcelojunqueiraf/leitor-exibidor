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
    else
    {
        printf("Attribute info: ");
        for (u4 info_index = 0; info_index < attribute->attribute_length; info_index++)
        {
            u1 *info = &(attribute->info[info_index]);
            printf("0x%x ", *info);
        }
        printf("\n");
    }
}