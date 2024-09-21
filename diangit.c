#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef MAX_BUF
#define MAX_BUF 255
#endif
#define HELP_FILE_NAME "dghelp"

char CUR_DIR[MAX_BUF];

// 枚举命令类型
typedef enum TYPE
{
    none,
    help,
    init,
    end
} TYPE;

char help_text[10][MAX_BUF];

// 获取帮助
void _get_help(char *);

// 获取类型名称
void _get_type_name(int, char *);

// 寻找命令类型
TYPE _find_type_enum(char *);

// 初始化
void _diangit_init(char *);

int main(int argc, char **argv)
{
    /*
    argc表示参数的个数
    参数中argv[0]为自身运行目录路径和程序名
    argv[1]指向第一个参数、argv[2]指向第二个参数……
    */
    getcwd(CUR_DIR, MAX_BUF);
    printf("当前工作目录：%s\n", CUR_DIR);

    _get_help(CUR_DIR);
    // 调试输出
    printf("参数个数: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("参数[%d]: %s\n", i, argv[i]);
    }

    // 缺省命令
    if (argc == 2)
    {
        printf("> 指令缺省\n");
        if (strcmp(argv[1], "help") == 0)
        {
            printf("> 进入帮助指令\n");
            for (TYPE t = none; t < end; t++)
            {
                if (strlen(help_text[t]) != 0)
                {
                    char type_name[10];
                    _get_type_name(t, type_name);
                    printf("%s: \n", type_name);
                    printf("%s\n", help_text[t]);
                }
            }
        }
        if (strcmp(argv[1], "init") == 0)
        {
            printf("> 进入初始化指令\n");
        }
    }

    // 带参命令
    if (argc == 3)
    {
        printf("> 指令带参\n");
        if (strcmp(argv[1], "help") == 0)
        {
            printf("> 进入帮助指令\n");
            TYPE type = _find_type_enum(argv[2]);
            if (type != none)
            {
                printf("%s: \n", argv[2]);
                printf("%s\n", help_text[type]);
            }
            else
            {
                printf("未找到 [%s] 相关帮助.\n");
            }
        }
        if (strcmp(argv[1], "init") == 0)
        {
            printf("> 进入初始化指令\n");
        }
    }
}

void _get_help(char *work_path)
{

    // 处理目录结合帮助文件名称获取帮助文件绝对路径
    char help_path[MAX_BUF];
    strcpy(help_path, work_path);
    help_path[strlen(work_path)] = '/';
    strcat(help_path, HELP_FILE_NAME);
    printf("帮助文件绝对路径: %s\n", help_path);

    // 读取帮助文件
    FILE *fp = NULL;
    char buff[MAX_BUF];
    fp = fopen(help_path, "r");

    // 没有帮助文件则生成
    if (fp == NULL)
    {
        fp = fopen(help_path, "w");
        printf("未找到帮助文件信息，已帮你在当前目录下生成 %s 文件。\n", HELP_FILE_NAME);
        return;
    }

    /*
    一次读两行命令类型和帮助信息
    [command]
    desciptions...
    */
    TYPE type = none;
    while (fgets(buff, MAX_BUF, (FILE *)fp))
    {
        // 判断TYPE格式是否正确
        int len = strlen(buff);
        if (buff[0] == '[' && buff[len - 2] == ']')
        {
            memset(buff + len - 2, '\0', 2 * sizeof(char));
            strcpy(buff, buff + 1);
            type = _find_type_enum(buff);
        }
        else
        {
            // 搜集描述
            strcat(help_text[type], buff);
        }
    }
}

TYPE _find_type_enum(char *type_name)
{
    if (strcmp(type_name, "help") == 0)
        return help;
    if (strcmp(type_name, "init") == 0)
        return init;
    return none;
}

void _get_type_name(int type, char *type_name)
{
    if (type == help)
        strcpy(type_name, "help");
    if (type == init)
        strcpy(type_name, "init");
}

void _diangit_init(char *dirName)
{
    return;
}
