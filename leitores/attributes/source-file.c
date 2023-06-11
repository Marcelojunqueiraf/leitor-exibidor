#include "attributes.h"

void readSourceFileAttribute(cp_info * constant_pool, SourceFile_attribute * info, FILE* fp, u2 attribute_length) {
    info->sourcefile_index = readU2(fp);
    printf("sourcefile_index: %d\n", info->sourcefile_index);
}