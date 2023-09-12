/*
 * array.c
 *
 *  Created on: 07-Aug-2023
 *      Author: Vivek Kumar
 */

#include "array.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void swap (int *_a, int *_b) {
	int temp = *_a;
	*_a = *_b;
	*_b = temp;
}

void DESTROY(struct ARRAY *_array) {
	if(_array->array_data.array == NULL) {
		return;
	}
	free(_array->array_data.array);
	_array->array_data.array = NULL;

	_array->array_data.size = 0;
	_array->array_data.capacity = 0;
}

void SORT(struct ARRAY *_array) {
	// bubble sort
	int* arr = _array->array_data.array;
	int size = _array->array_data.size;
	for(int i = 0; i<size-1; i++) {
		for(int j = 0; j<size-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr +j, arr +j +1);
			}
		}
	}
}

void INSERT(struct ARRAY *_array, int __pos, int _elem) {
	if(__pos < 1 && _array->array_data.size != 0) {
		puts("Invalid position!\n");
		return;
	}

	if(_array->array_data.size == 0) {
		_array->array_data.array[0] = _elem;
		_array->array_data.size++;
		printf("\nThe element %d is inserted at position 1.\n", _elem);
		return;
	} 

	if(_array->array_data.size <= __pos - 1) {
		_array->array_data.array[_array->array_data.size] = _elem;
		puts("By Default settings applied!!\n");
		puts("Element will be inserted at last position\n");
		printf("\nElement %d is inserted at position %d.\n", 
			_elem, _array->array_data.size + 1);
		_array->array_data.size++;
		return;
	}

	if(_array->array_data.size >= _array->array_data.capacity) {
		puts("No space is left!\n");
		return;
	}

	int st_idx = _array->array_data.size-1; // last filled index
	int in_idx = __pos-1; // index at which element will be inserted
	for(int i = st_idx; i>=in_idx; i--) {
		_array->array_data.array[i+1] = _array->array_data.array[i];
	} _array->array_data.array[in_idx] = _elem;
	_array->array_data.size++;
	printf("\nElement %d is inserted at position %d.\n\n", _elem, __pos);
}

void DELETE(struct ARRAY *_array, int __pos) {
	if(__pos < 1 || __pos > _array->array_data.capacity) {
		puts("Invalid position!\n");
		return;
	}
	if(_array->array_data.size <= 0) {
		puts("There is no elements to delete!\n");
		return;
	}
	int dl_idx = __pos-1; // index to be deleted
 	int ed_idx = _array->array_data.size-1;
 	for(int i = dl_idx; i<ed_idx; i++) {
 		_array->array_data.array[i] = _array->array_data.array[i+1];
 	} _array->array_data.size--;
	printf("\nElement at position %d was deleted.\n", __pos);
}

int SEARCH(struct ARRAY *_array, int _search) {
	int index = -999;
	for(index = 0; index<_array->array_data.size; index++) {
		if(_array->array_data.array[index] == _search) {
			return index + 1;
		}
	}
	return INT_MAX;
}

void DISPLAY(struct ARRAY *_array) {
	printf("\n\n\n");
	puts("***************************************\n");
	if(_array->array_data.size <= 0) {
		puts("Array is empty.\n");
		puts("***************************************\n");
		return;
	}
	for(int i = 0; i<_array->array_data.size; i++) {
		printf("Element %d is : %d\n\n", i+1, _array->array_data.array[i]);
	}
	puts("***************************************\n");
}

void ARRAY_INIT(struct ARRAY *_array, int _capacity) {
	_array->array_data.capacity = _capacity;
	_array->array_data.size = 0; // initially size of array is zero
	_array->array_data.array = (int*)malloc((size_t)_capacity * sizeof(int));

	// Initializing the function pointers
	_array->DESTROY = &DESTROY;
	_array->INSERT = &INSERT;
	_array->DELETE = &DELETE;
	_array->SORT = &SORT;
	_array->SEARCH = &SEARCH;
	_array->DISPLAY = &DISPLAY;
}
