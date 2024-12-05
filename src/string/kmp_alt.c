#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compute_next_alternative(const char* pattern, int* next) {
    int size = strlen(pattern);
    int len = 0;  // 当前的最大前后缀长度
    next[0] = 1;  // 初始化为 1，因为我们存储的是前一位的最大公共前后缀长度 + 1

    int i = 1;

    while (i < size) {
        if (pattern[i] == pattern[len]) {
            len++;
            next[i] = len + 1;  // 存储最大前后缀长度 + 1
            i++;
        } else {
            if (len != 0) {
                len = next[len - 1] - 1;  // 回溯到上一个匹配长度，减去 1 因为存储的是 len + 1
            } else {
                next[i] = 1;  // 无匹配时，存储为 1
                i++;
            }
        }
    }
}

int KMP_search(const char* text, const char* pattern, int* next) {
    int n = strlen(text);
    int m = strlen(pattern);
    compute_next_alternative(pattern, next);  // 计算next数组
    for (int i = 0; i < m; i++) {
        printf("%d  ", next[i]);
    }
    printf("\n");
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];  // 回溯
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return i - m + 1;  // 匹配成功，返回匹配起始位置
        }
    }
    return -1;  // 匹配失败
}

int* malloced(int size) {
    int* next = (int*)malloc(sizeof(int) * size);
    if (!next) {
        exit(-1);
    }
    return next;
}

int main() {
    char strs[] = "abababaabab";
    char pattern[] = "ababaabab";
    int* next = malloced(strlen(pattern));

    int result = KMP_search(strs, pattern, next);
    if (result != -1) {
        printf("Pattern found at index: %d\n", result);
    } else {
        printf("Pattern not found\n");
    }
    return 0;
}
