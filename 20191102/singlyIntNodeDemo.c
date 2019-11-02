//
// Created by 李熠 on 2019/11/2.
//
#include "singlyIntNode.h"

int main(void) {

    SinglyIntNode *head = singlyIntNodeCreate();

    singlyIntNodeAdd(head, 1);
    singlyIntNodeAdd(head, 3);
    singlyIntNodeAdd(head, 4);
    singlyIntNodeAdd(head, 5);

    singlyIntNodeDisplay(head);
    return 0;
}

