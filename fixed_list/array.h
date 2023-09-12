/*
 * array.h
 *
 *  Created on: 07-Aug-2023
 *      Author: Vivek Kumar
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stddef.h>

struct ARRAY_DATA {
	int* array; // array pointer
	int size; // current number of elements stored in the array
	int capacity; // total capacity to store elements
}; typedef struct ARRAY_DATA ARRAY_DATA;

struct ARRAY {
	struct ARRAY_DATA array_data;
	void (*DESTROY)(struct ARRAY*);
	void (*SORT)(struct ARRAY*);
	void (*INSERT)(struct ARRAY*, int, int);
	void (*DELETE)(struct ARRAY*, int);
	int (*SEARCH)(struct ARRAY*, int);
	void (*DISPLAY)(struct ARRAY*);
}; typedef struct ARRAY ARRAY;

void ARRAY_INIT(struct ARRAY *_array, int _capacity);
void DESTROY(struct ARRAY *_array);
void SORT(struct ARRAY *_array);
void INSERT(struct ARRAY *_array, int __pos, int _elem);
void DELETE(struct ARRAY *_array, int __pos);
int SEARCH(struct ARRAY *_array, int _search);
void DISPLAY(struct ARRAY *_array);

#endif /* ARRAY_H_ */
