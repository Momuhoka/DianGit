#include <stdio.h>
#include <io.h>

#ifndef MAX_BUF
#define MAX_BUF 200
#endif

void init(char*);

int main(int argc, char **argv){
    /*
    argc表示参数的个数
    参数中argv[0]为自身运行目录路径和程序名
    argv[1]指向第一个参数、argv[2]指向第二个参数……
    */
   char path[MAX_BUF];
   getcwd(path, MAX_BUF);
   printf("%s", path);
}

void init(char *dirName){
    return;
}
