

#include <stdlib.h>
#include <stdio.h>
#include "student.h"

#define SIZE_STEP 10

typedef struct StudentList {
    // 当前存放内容的长度
    int length;
    // 存放数据的内存的首地址
    Student *data;
    // 总共分配的内存空间
    int size;
} StudentList;

StudentList *studentListNew(int initSize);

int studentListDestroy(StudentList *);

void serializeB(StudentList *list, FILE *file);

StudentList *deserializeB(FILE *file);

void serialize(StudentList *list, FILE *file);

StudentList *deserialize(FILE *file);

/**
 *
 * @param list
 * @param elem
 * @return 1操作成功，0操作失败
 */
Student *studentListAdd(StudentList *list, Student student);

Student studentListDelete(StudentList *list, int index);

/**
 * 根据元素进行删除，删除第一个找到的元素
 * @param list
 * @param elem
 * @return 1操作成功，0操作失败
 */
Student studentListDeleteByElem(StudentList *list, Student *);

void studentListDisplay(StudentList *list);

/**
 *
 * @param list
 * @param index
 * @param elem
 * @return  1操作成功，0操作失败
 */
Student *studentListUpdate(StudentList *list, int index, Student student);


/**
 * 指定位置插入元素
 * @param list
 * @param index
 * @param elem
 * @return  1操作成功，0操作失败
 */
Student *studentListInsert(StudentList *list, int index, Student student);

/**
 * 返回指定位置的元素
 * @param list
 * @param index
 * @return
 */
Student *studentListGet(StudentList *list, int index);

