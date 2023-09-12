#include "array.h"
#include "array.c"
#include <stdio.h>
#include <stdlib.h>

void Welcome();
void Basic_config(ARRAY *_array);
void Commands();

int main(){
  // code here

  ARRAY array;
  int temp;
  int position;
  int query, num;

  // program greeting
  Welcome();
  Basic_config(&array);

  while(1) {
    system("clear");
    Commands();
    printf("Enter the query : ");
    scanf("%d", &query);

    switch (query){
      case 1 : 
        system("clear");
        array.DISPLAY(&array);
        break;
      case 2 : 
        system("clear");
        puts("Enter the position at which you want the number to be inserted : ");
        puts("(If you are inserting for first time, enter any number.)\n");
        scanf("%d", &position);
        puts("Enter number you want to get inserted : ");
        scanf("%d", &num);
        array.INSERT(&array, position, num);
        break;
      case 3 :
        system("clear");
        puts("Enter the position of number you want to get removed from array : ");
        scanf("%d", &position);
        array.DELETE(&array, position);
        break;
      case 4 :
        system("clear");
        array.SORT(&array);
        printf("array has been sorted.\n");
        break;
      case 5 :
        system("clear");
        puts("Enter the element value you want to search in the array : ");
        scanf("%d", &num);
        temp = array.SEARCH(&array, num);
        if(temp > array.array_data.size) {
          printf("Element %d is not found.\n", num);
          break;
        } printf("Element %d is found at index %d.\n", num, temp);
        break;
      case 0 :
        system("clear");
        puts("Program exited successfully.\n");
        puts("Have a nice day.\n");
        exit(0);
      default:
        system("clear");
        puts("Invalid query.\n");
        break;
    }

    puts("Press any number to continue or press 0 to exit the program.\n");
    scanf("%d", &num);
    if(num == 0){
      puts("Program exited successfully.\n");
      puts("Have a nice day.\n");
      exit(0);
    }
  }
}

void Welcome() {
  system("clear");
  puts("\t     THE ARRAY PROGRAM");
  puts("\n******************************************\n");
  puts("Hello User!\n");
  puts("Welcome to the array program :) \n");
  puts("Give various queries and see the result:)\n");
  puts("******************************************\n\n");
}

void Basic_config(ARRAY *_array) {
  puts("Enter the capacity of the array: \n");
  puts("(Remember you cannot change the capacity later on.)\n");
  int capacity;
  scanf("%d", &capacity);
  _array->array_data.capacity = capacity;
  ARRAY_INIT(_array, capacity);
}

void Commands() {
  puts("\n\n\nPress 1 : to view the current elements in the array.\n");
  puts("Press 2 : to insert an element in the array.\n");
  puts("Press 3 : to delete an element in the array.\n");
  puts("Press 4 : to sort the array.\n");
  puts("Press 5 : to search for an element in the array.\n");
  puts("Press 0 : to exit the program.\n\n\n");
}