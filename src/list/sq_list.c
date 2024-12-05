#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int *elem;
    int length;
} SqList;

void err() {
    printf("ERROR \n");
    exit(1);
}

SqList create() {
    int *elem = (int *)malloc(sizeof(int) * MAX);
    if (elem == NULL) {
        err();
    }

    // for (int i = 0; i < length; i++) {
    //     *(elem + i) = i;
    // }
    SqList res = {elem, 0};
    return res;
}

int getELem(int index, SqList *list) {
    if (index < 0 || index >= list->length) {
        return -1;
    }
    return *(list->elem + index);
}

int locateELem(int val, SqList *list) {
    for (int i = 0; i < list->length; i++) {
        if (val == list->elem[i]) {
            return i;
        }
    }
    return -1;
}

int getLen(SqList *list) { return list->length; }

int insert(int val, int index, SqList *list) {
    // check
    int len = list->length;
    if (index < 0 || index > (MAX - 2)) {
        return -1;
    }
    if (len == MAX) {
        return -1;
    }

    // move
    for (int i = MAX; i > index; i--) {
        list->elem[i] = list->elem[i - 1];
    }

    // grant
    list->elem[index] = val;
    list->length++;
    return 1;
}

void print_list(SqList *list) {
    for (int i = 0; i < list->length; i++) {
        printf("i: %d\t", list->elem[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    SqList list = create();
    for (int i = 0; i < 9; i++) {
        insert(i, i, &list);
    }
    print_list(&list);

    insert(10, 3, &list);
    print_list(&list);

    return 0;
}
