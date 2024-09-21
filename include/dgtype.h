#ifndef DGTYPE_H
#define DGTYPE_H

// 枚举命令类型
typedef enum TYPE_ENUM {
    NONE, // 0，用于错误命令
    HELP,
    INIT,
    END // 遍历用，无意义
} TYPE_T;


// 获取类型名称
void get_type_name(int, char *);

// 寻找命令类型
TYPE_T find_type_enum(char *);

#endif