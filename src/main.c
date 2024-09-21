#include <stdio.h>
#include <unistd.h>

#include <dgconst.h>
#include <dgutils.h>

// 当前目录
char CUR_DIR[MAX_BUF];

int main(int argc, char **argv)
{
    /*
    argc表示参数的个数
    参数中argv[0]为自身运行目录路径和程序名
    argv[1]指向第一个参数、argv[2]指向第二个参数……
    */
    getcwd(CUR_DIR, MAX_BUF);
    printf("当前工作目录：%s\n", CUR_DIR);

    get_help(CUR_DIR);
    // 调试输出
    printf("参数个数: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("参数[%d]: %s\n", i, argv[i]);
    }

    dian_git(argc, argv);
}