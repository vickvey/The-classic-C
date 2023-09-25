
#ifndef TASK_H_
#define TASK_H_

typedef struct Task Task;
typedef struct Node Node;
typedef struct List List;

// structure of task containing task information 
struct Task {
    int taskID;
    char taskName[30];
    char taskDescription[100];
    int isCompleted;
};

// Node of linked list struct Node
struct Node {
    Task task;
    Node* next;
};

struct List {
    Node *head;
    int length;
};

Node* newNode(const Task *task);

int addTask(const Task *task, List *list);
int remTask(int taskID, List *list);
Task* getTask(int taskId, List *list);
int destroyList(List *list);

#endif