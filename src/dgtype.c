#include <string.h>
#include <dgconst.h>
#include <dgtype.h>

// 枚举字符串对应
const char enum_type[MAX_COM_NUM][MAX_COM_LEN] = {
    [HELP]  "help",
    [INIT]  "init",
};

TYPE_T find_type_enum(char *type_name) {
    if (strcmp(type_name, "help") == 0)
        return HELP;
    if (strcmp(type_name, "init") == 0)
        return INIT;
    return NONE;
}

void get_type_name(int type, char *type_name) {
    strcpy(type_name, enum_type[type]);
    // if (type == help)
    //     strcpy(type_name, "help");
    // else if (type == init)
    //     strcpy(type_name, "init");
}