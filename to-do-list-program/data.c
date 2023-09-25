
#include <stdio.h>
#include "data.h"
#include "error.h"

const char dataFile[] = "data.bin";

/*
saves List data into datafile 
input parameters : address of List and filename of data file
*/
int saveData (List *list, const char *filename) {
    size_t workDone = 0;
    
    if(list == NULL || filename == NULL) {
        return ERROR_POINTER_IS_NULL;
    }
    if(list->head == NULL) {
        return SUCCESS;
    }
    // opening the file where data needs to be saved
    FILE *file = NULL;
    file = fopen(filename, "wb");
    if(file == NULL) {
        return ERROR_FAILED_TO_OPEN_FILE;
    }

    // writing data into the file
    Node *current = list->head;
    while(current != NULL) {
        workDone = fwrite(&current->task, sizeof(current->task), 1, file);
        if(workDone != 1) {
            return ERROR_WRITING_IN_FILE;
        }
        current = current->next;
    }

    // closing file
    return SUCCESS;
}

/* 
loads List data back and stores it in the List
input parameters : address of List and filename of data file
*/
int loadData (List *list, const char *filename) {
    if(list == NULL || filename == NULL) {
        return ERROR_FAILED_TO_ALLOCATE_MEMORY;
    }  
    // opening the file from where data needs to be read from
    FILE *file = fopen(filename, "rb");
    if(file == NULL) {
        return ERROR_FAILED_TO_OPEN_FILE;
    }
    // clear the existing list 
    while(list->head != NULL) {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
    } list->length = 0;

    // reading data from file 
    Task task;
    size_t bytesRead;
    while((bytesRead == fread(&task, sizeof(task), 1, file)) == 1) {
        // create a node and add it to the list
        Node *newnode = newNode(&task);
        if(newnode == NULL) {
            return ERROR_FAILED_TO_ALLOCATE_MEMORY;
        }

        // add the node to list
        if(addTask(&task, list) != TASK_ADDED_SUCCESS) {
            return ERROR_ADDING_TASK_INTO_THE_LIST;
        }
    }
    // closing the file 
    fclose(file);

    // check for errors during reading 
    if(bytesRead != 0) {
        return ERROR_READING_FROM_FILE;
    }
    return SUCCESS;
}