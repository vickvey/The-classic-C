
#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "task.h"

Node* newNode(const Task *task) {
    if(task == NULL) {
        return NULL;
    }

    Node *temp = (Node*) malloc(sizeof(Node));
    if(temp == NULL) {
        return NULL;
    }
    temp->task = *task;
    temp->next = NULL;
    return temp;
}

int addTask(const Task *task, List *list) {
    if(task == NULL || list == NULL) {
        return ERROR_POINTER_IS_NULL;
    }
    // creating a new Node
    Node *newnode = newNode(task);
    if(newnode == NULL) {
        return ERROR_FAILED_TO_ALLOCATE_MEMORY;
    }

    // If the list is empty, set the new node as the head
    if (list->head == NULL) {
        list->head = newnode;
    } else {
        // Traverse the list to find the last node
        Node *curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        // Add the new node to the end of the list
        curr->next = newnode;
    }

    // update the length of list
    list->length++;
    return TASK_ADDED_SUCCESS;
}

int remTask(int taskID, List *list) {
    if(list == NULL) {
        return ERROR_POINTER_IS_NULL;
    }

    Node *curr = newNode()
    
}

Task* getTask(int tastID, List *list);