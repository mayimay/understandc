//
// Created by edz on 2019/11/16.
#include "demo.h"

IntList *IntListNew(int initSize) {
    if (initSize <= 0) {
        initSize = SIZE_STEP;
    }
    IntList *rlt = (IntList *) malloc(sizeof(IntList));
    rlt->data = (int *) malloc(initSize * sizeof(int));
    rlt->length = 0;
    rlt->size = initSize;
    return rlt;
}

int IntListDestroy(IntList *list) {
    if (list == NULL) {
        return 1;
    }
    free(list->data);
    free(list);
    return 1;
}

int intListAdd(IntList *list, int elem) {
    if (list->size == list->length) {
        //扩容
        int *newList = realloc(list->data, (list->size + SIZE_STEP) * sizeof(int));
        if (newList != NULL) {
            list->data = newList;
            list->size += SIZE_STEP;
        } else {
            printf("分配内存失败，集合已满");
            return 0;
        }
    }

    list->data[list->length] = elem;
//    *(list->data+list->length)=elem;
    list->length++;
    return 1;
}

void intListDisplay(IntList *list) {
    for (int i = 0; i < list->length; ++i) {
        printf("[%d]=[%d]", i, list->data[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }

}

int intListDelete(IntList *list, int index) {
    if (list == NULL || index < 0 || index >= list->length) {
        return 0;
    }
    for (int i = index; i < list->length - 1; ++i) {
        list->data[i] =list->data[i + 1];
    }
    list->length--;
    return 0;
}
