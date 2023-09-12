
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
    
    
}