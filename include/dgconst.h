#ifndef DGCONST_H
#define DGCONST_H

#define MAX_BUF 255 // 最大缓冲容量
#define MAX_COM_NUM 10 // 最大命令数量
#define MAX_COM_LEN 10 // 最大命令长度
#define HELP_FILE_NAME "dghelp" // 帮助文件名称
#define DEBUG_OUT stdout // log调试信息输出位置

// #define DEBUG // 开启调试
// 调试信息输出
#ifdef DEBUG
    #define DEPRINT(fmt, ...) \
    printf("[DEBUG] "fmt, ##__VA_ARGS__)
#else
    #define DEPRINT(...)
#endif //DEBUG

#endif // DGCONTS_H