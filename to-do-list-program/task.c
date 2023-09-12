
#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "task.h"

Node* newNode(Task *task) {
    if(task == NULL) {
        return ERROR_POINTER_IS_NULL;
    }

    Node *temp = (Node*) malloc(sizeof(Node));
    temp->task = *task;
    temp->next = NULL;
    return temp;
}

int addTask(Task *task, List *list) {
    if()
}

int remTask(int taskID, List *list);
Task* getTask(List *list);