#include <stdio.h>
#include <string.h>

#include <dgconst.h>
#include <dgtype.h>
#include <dgutils.h>

// 帮助文本
extern char help_text[MAX_COM_NUM][MAX_BUF];

void dian_git(int argc, char **argv) {
    // 缺省命令
    if (argc == 2)
    {
        printf("> 指令缺省\n");
        if (strcmp(argv[1], "help") == 0)
        {
            printf("> 进入帮助指令\n");
            for (TYPE_T t = NONE; t < END; t++)
            {
                if (strlen(help_text[t]) != 0)
                {
                    char type_name[10];
                    get_type_name(t, type_name);
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
            TYPE_T type = find_type_enum(argv[2]);
            if (type != NONE)
            {
                printf("%s: \n", argv[2]);
                printf("%s\n", help_text[type]);
            }
            else
            {
                printf("未找到 [%s] 相关帮助.\n", argv[2]);
            }
        }
        if (strcmp(argv[1], "init") == 0)
        {
            printf("> 进入初始化指令\n");
        }
    }
}