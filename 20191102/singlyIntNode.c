//
// Created by 李熠 on 2019/10/10.
//
#include "singlyIntNode.h"

SinglyIntNode *singlyIntNodeCreate() {
    SinglyIntNode *node = malloc(sizeof(SinglyIntNode));
    node->value = 0;
    node->next = NULL;
    return node;
}

void singlyIntNodeDisplay(const SinglyIntNode *head) {
    SinglyIntNode *curNode = head->next;
    int count = 0;
    while (curNode != NULL) {
        printf("[%d]=%d ", count++, curNode->value);
        if (count + 1 % 10 == 0) {
            printf("\n");
        }
        curNode = curNode->next;
    }
}

/**
 * 结尾追加元素
 * @param head
 * @param elem
 */
void singlyIntNodeAdd(SinglyIntNode *head, int elem) {

    SinglyIntNode *lastNode = head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    SinglyIntNode *node = singlyIntNodeCreate();
    lastNode->next = node;
    node->value = elem;
}


