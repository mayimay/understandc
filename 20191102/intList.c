//
// Created by 李熠 on 2019/11/2.
//

#include "intList.h"

int isIndexValid(const IntList *list, int index);

IntList *intListNew(int initSize) {
    int listSize = 0;
    if (initSize <= 0) {
        listSize = SIZE_STEP;
    } else {
        listSize = initSize;
    }

    IntList *rlt = (IntList *) malloc(sizeof(IntList));
    if (rlt == NULL) {
        printf("内存分配失败！");
        return NULL;
    }

    rlt->length = 0;
    rlt->data = malloc(listSize * sizeof(int));
    rlt->size = listSize;
    return rlt;
}

int intListDestroy(IntList *list) {
    int *p = list->data;
    free(list);
    free(p);
    return 1;
}

void serializeB(IntList *list, FILE *file) {
    if (list == NULL || file == NULL) {
        printf("输入不合法！");
        return;
    }

    fwrite(&list->length, sizeof(int), 1, file);
    fwrite(list->data, sizeof(int), list->length, file);
}

IntList *deserializeB(FILE *file) {
    if (file == NULL) {
        printf("文件不合法!");
        return NULL;
    }
    int length = -1;
    fread(&length, sizeof(int), 1, file);
    if (length <= -1) {
        printf("读取内容不合法！");
        return NULL;
    }
    IntList *list = intListNew(length);

    list->length = length;
    list->size = length;

    fread(list->data, sizeof(int), length, file);
    return list;
}

void serialize(IntList *list, FILE *file) {
    if (list == NULL || file == NULL) {
        printf("输入不合法！");
        return;
    }

    fprintf(file, "%d ", list->length);
    for (int i = 0; i < list->length; ++i) {
        fprintf(file, "%d ", list->data[i]);
    }
}

IntList *deserialize(FILE *file) {
    if (file == NULL) {
        printf("文件不合法!");
        return NULL;
    }
    int length = -1;
    fscanf(file, "%d", &length);
    if (length == -1) {
        printf("读取内容不合法！");
        return NULL;
    }
    IntList *list = intListNew(0);
    int content;
    int readRlt = 0;

    for (int i = 0; i < length; i++) {
        readRlt = fscanf(file, "%d", &content);
        if (readRlt == 0) {
            printf("解析文件内容失败");
            return NULL;
        }
        intListAdd(list, content);
    }

    return list;
}

int intListAdd(IntList *list, int elem) {
    if (list == NULL) {
        //TODO
        return 0;
    }

    if (list->length == list->size) {
        list->data = realloc(list->data, list->size + SIZE_STEP);
        list->size += SIZE_STEP;
    }
    list->data[list->length] = elem;
    list->length++;
    return 1;
}

void intListDisplay(IntList *list) {
    for (int i = 0; i < list->length; ++i) {
        printf("[%d]=%d ", i, list->data[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int intListDelete(IntList *list, int index) {
    if (!isIndexValid(list, index)) {
        return 0;
    }

    for (int i = index; i < list->length - 1; ++i) {
        list->data[i] = list->data[i + 1];
    }

    list->length--;
    return 1;
}

int isIndexValid(const IntList *list, int index) {
    if (list == NULL || index < 0 || index >= list->length) {
        printf("index 不合法\n");
        return 0;
    }
    return 1;
}

int intListUpdate(IntList *list, int index, int elem) {
    if (!isIndexValid(list, index)) {
        return 0;
    }

    list->data[index] = elem;
    return 1;
}

int intListGet(IntList *list, int index) {
    if (!isIndexValid(list, index)) {
        return 0;
    }
    return list->data[index];
}

int intListDeleteByElem(IntList *list, int elem) {
    int index = -1;
    for (int i = 0; i < list->length; ++i) {
        if (list->data[index] == elem) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        return intListDelete(list, index);
    } else {
        return 0;
    }
}