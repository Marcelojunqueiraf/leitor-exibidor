#include "attributes.h"
#include "../../common/get-utf8.h"
#include <stdio.h>

void showSourceFileAttribute(SourceFile_attribute * sourceFileAttribute, cp_info * constant_pool) {
    printf("sourcefile_index: %d\n", sourceFileAttribute->sourcefile_index);
    printf("sourcefile_name: %s\n", getUtf8(constant_pool, sourceFileAttribute->sourcefile_index));
}