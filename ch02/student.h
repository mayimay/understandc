//
// Created by 李熠 on 2019/11/9.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef DEMOCLION_STUDENT_H
#define DEMOCLION_STUDENT_H
#define NAME_LEN 20
enum Gender {
    MALE, FEMALE
};

typedef enum Gender GENDER;

// 学生属性
// 年龄
// 性别
// 名字
// 学号
typedef struct Student {
    int age;
    GENDER gender;
    char name[NAME_LEN];
    int num;
} Student;

/**
 * 根据传入的参数创建一个学生结构对象
 * @param age
 * @param gender
 * @param name
 * @param num
 * @return
 */
Student *createStudent(int age, GENDER gender, char *name, int num);

void displayStudent(Student *);

/**
 * 根据学号查询学生
 * @param num
 * @return
 */
Student *search(Student *[], int num);

/**
 * 根据学生学号更新学生信息
 * @param student
 */
void updateStudentByNum(Student *[], Student *student);

/**
 * 根据学生学号删除学生，后续元素依次前移
 * @param student
 */
void deleteStudentByNum(Student *[], Student *student);







// 添加学生

// 删除

// 根据学号修改学生

// 查询学生信息

// 打印所有学生信息

#endif //DEMOCLION_STUDENT_H
