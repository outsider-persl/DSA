// @kmp impl
// @author outsider
// @date 2024-Dec-4
//
// @example:
// i: text     index
// j: pattern index
// text     = A B B A B A B A A B
// pattern  = A B A B A
// next [i] = 0 1 1 2 3
//
// if (success); i++ j++
// if (failed):
//      if  (next[j] = 0);  i++
//      if  (next[j] != 0); j = next[j]-1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compute_next(const char* pattern, int* next) {
    int size = strlen(pattern);
    int len = 0;   // length of the previous prefix
    next[0] = -1;  // 通常初始化为 -1 (or 0)
    int i = 1;

    while (i < size) {
        if (pattern[i] == pattern[len]) {
            len++;
            next[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = next[len - 1];
            } else {
                next[i] = 0;
                i++;
            }
        }
    }
}

int kmp(const char* text, const char* pattern, int* next) {
    int text_size = strlen(text);
    int p_size = strlen(pattern);
    compute_next(pattern, next);
    for (int i = 0; i < p_size; i++) {
        printf("%d  ", next[i]);
    }
    printf("\n");
    int count = 0;
    int i = 0;  // 主串索引
    int j = 0;  // 模式串索引
    while (i < text_size) {
        count++;
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == p_size) {
                printf("count %d\n", count);
                free(next);
                return i - j;  // 返回匹配开始的索引
            }
        } else {
            if (j != 0) {
                //  回退点
                //  模式串从(j-1)处与主串当前位置开始匹配
                printf("back j: %d\n", j);
                j = next[j - 1];
            } else {
                i++;
            }
        }
    }

    free(next);
    return -1;  // 如果没有找到匹配，返回 -1
}

int* build_next(int size) {
    int* next = (int*)malloc(sizeof(int) * size);
    if (!next) {
        exit(-1);
    }
    return next;
}

int main() {
    char text[] = "abababaabab";
    char pattern[] = "ababaabab";
    int str_size = sizeof(text) - 1;  // 不包括 '\0'
    int p_size = sizeof(pattern) - 1;
    int* next = build_next(p_size);

    int result = kmp(text, pattern, next);
    if (result != -1) {
        printf("Pattern found at index: %d\n", result);
    } else {
        printf("Pattern not found\n");
    }
    return 0;
}
