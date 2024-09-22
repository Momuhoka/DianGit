#include <stdio.h>
#include <string.h>

#include <dgconst.h>
#include <dgtype.h>
#include <dgutils.h>

// 帮助文本
char help_text[MAX_COM_NUM][MAX_BUF];

void get_help(char *work_path) {
    
    // 处理目录结合帮助文件名称获取帮助文件绝对路径
    char help_path[MAX_BUF] = {};
    strcpy(help_path, work_path);
    help_path[strlen(work_path)] = '/';
    strcat(help_path, HELP_FILE_NAME);
    DEPRINT("帮助文件绝对路径: %s\n", help_path);

    // 读取帮助文件
    FILE *fp = NULL;
    char buff[MAX_BUF];
    fp = fopen(help_path, "r");

    // 没有帮助文件则生成
    if (fp == NULL) {
        fp = fopen(help_path, "w");
        DEPRINT("未找到帮助文件信息，已帮你在当前目录下生成 %s 文件。\n", HELP_FILE_NAME);
        return;
    }

    /*
    一次读两行命令类型和帮助信息
    [command]
    desciptions...
    */
    TYPE_T type = NONE;
    while (fgets(buff, MAX_BUF, (FILE *)fp)) {
        // 判断TYPE格式是否正确
        int len = strlen(buff);
        if (buff[0] == '[' && buff[len - 2] == ']') {
            memset(buff + len - 2, '\0', 2 * sizeof(char));
            strcpy(buff, buff + 1);
            type = find_type_enum(buff);
        }
        else {
            // 搜集描述
            strcat(help_text[type], buff);
        }
    }
}