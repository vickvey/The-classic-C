#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dash printf("\n----------------------------------------------------------------------\n")

int FindOrder(char* filename); //finds order of matrix in input
void SetMatrices(char* filename, int order, int a[], int b[]);
void PrintMatrices(int order, int* a, int* b);
void Addition(int order, int* a, int* b);
void Subtraction(int order, int* a, int* b);
void Multiplication(int order, int* a, int* b);
void Commands(const char* filename);
void CountOnes();
void Mean(int order, int* a, int* b);

int main(){
    // code here
    char filename[100]; // filename = "input.txt"
    printf("\tEnter the name of file: ");
    scanf("%s", filename);
    dash;

    int order = FindOrder(filename);
    printf("\tThe order of matrices is: %d i.e. %dx%d\n", order, order, order);
    printf("\tSo! I have processed the input of your file %s", filename);
    int A[order*order], B[order*order];
    SetMatrices(filename, order, A, B);

    int cmd;
    here:
    Commands(filename);
    scanf("%d", &cmd);

    switch(cmd){
        case 1:
            PrintMatrices(order, A, B); goto here;
        case 2:
            dash;
            printf("\tSo! Here is A+B matrix: \n");
            Addition(order, A, B); dash; goto here;
        case 3:
            dash;
            printf("\tSo! Here is A-B matrix: \n");
            Subtraction(order, A, B); dash; goto here;
        case 4:
            dash;
            printf("\tSo! Here is AB matrix: \n");
            Multiplication(order, A, B); dash; goto here;
        case 5:
            dash; CountOnes(); dash; goto here;
        case 6:
            dash; Mean(order, A, B); dash; goto here;
        default:
            if(cmd == 0){
                printf("\tProgram exited successfully.\n");
                printf("\tThanks for Playing! Have a good day:)\n");
                dash;
                return 1;
            } printf("\tINVALID command\n");
            printf("\tYou have entered %d which is invalid command.\n", cmd);
            goto here;
            break;
    }
    return 0;
}

void Commands(const char* filename){
    dash;
    printf("->Here are a list of Operations you can do on A and B: \n");
    printf("->Press 1 to view the matrices that you have given in the file %s\n", filename);
    printf("->Press 2 to Add the two matrices i.e. A+B :\n");
    printf("->Press 3 to Subtract B from A i.e. A-B :\n");
    printf("->Press 4 to Multiply A and B i.e. AB :\n");
    printf("->Press 5 to find the number of 1's and their corresponding position.\n");
    printf("->Press 6 to find the mean of the matrices A and B and overall mean.\n");
    printf("->Press 0 Exit.\n");
    dash;
}

int FindOrder(char* filename){
    // initialising file pointer
    FILE* file;
    file = fopen(filename, "r");

    if(file == NULL){printf("Error!\n"); return -9999;}
    char line[100];
    int elems = 0;
    while(fgets(line, sizeof(line), file) != 0){
        if(strcmp(line, "\n") == 0){
            break;
        } elems++;
    } fclose(file);
    if(elems%3 == 0){
        return 3;
    } else if(elems%5 == 0){
        return 5;
    } return 7;
}

void SetMatrices(char* filename, int order, int a[], int b[]){
    FILE* file;
    file = fopen(filename, "r");
    if(file == NULL){
        printf("Error!\n");
    }

    char line[100];
    int* temp = a;
    int i = 0;
    while(fgets(line, 100, file) != NULL){
        if(strcmp(line, "\n") == 0){
            i = 0;
            temp = b;
            continue;
        } temp[i] = atoi(line);
        i++;
    }
}

void PrintMatrices(int order, int* a, int* b){
    dash;
    printf("\tMatrix A is: \n");
    for(int i = 0; i<order*order; i++){
        if((i+1)%order == 0){
            printf("%d\n", a[i]);
        } else {
            printf("%d\t", a[i]);
        }
    }
    dash;
    printf("\tMatrix B is: \n");
    for(int i = 0; i<order*order; i++){
        if((i+1)%order == 0){
            printf("%d\n", b[i]);
        } else {
            printf("%d\t", b[i]);
        }
    }
    dash;
}

void Addition(int order, int* a, int* b){
    int res[order*order];
    for(int i = 0; i<order*order; i++){
        res[i] = a[i] + b[i];
    }
    // printing the result
    for(int i = 0; i<order*order; i++){
        if((i+1)%order == 0){
            printf("%d\n", res[i]);
        } else {
            printf("%d\t", res[i]);
        }
    }
}

void Subtraction(int order, int* a, int* b){
    int res[order*order];
    for(int i = 0; i<order*order; i++){
        res[i] = a[i] - b[i];
    }
    // printing the result
    for(int i = 0; i<order*order; i++){
        if((i+1)%order == 0){
            printf("%d\n", res[i]);
        } else {
            printf("%d\t", res[i]);
        }
    }
}

void Multiplication(int order, int* a, int* b){
    int arr1[order][order];
    int arr2[order][order];
    int res[order][order];
    for(int p = 0; p<order; p++){
        for(int q = 0; q<order; q++){
            res[p][q] = 0;
        }
    }

    int i = 0; int j = 0;
    int k = 0;
    while(i<order){
        while(j<order){
            arr1[i][j] = a[k];
            arr2[i][j] = b[k];
            j++; k++;
        } j = 0;
        i++;
    }
    for(i = 0; i<order; i++){
        for(j = 0; j<order; j++){
            for(k = 0; k<order; k++){
                res[i][j] += (arr1[i][k])*(arr2[k][j]);
            }
        }
    }
    for(i = 0; i<order; i++){
        for(j = 0; j<order; j++){
           printf("%d\t", res[i][j]); 
        } printf("\n");
    }
}

void CountOnes(){
    int A[10][10] = {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 0, 1, 1},
        {1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0}
    };

    printf("Here is your 1's and their corresponding locations: \n");
    int count = 1;
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            if(A[i][j] == 1){
                printf("  (%d, %d) is the %dth occuring 1.\n", i, j, count);
                count++;
            }
        }
    }
    dash;
    printf("there were a total of %d Ones present.\n", count-1);
}

void Mean(int order, int* a, int* b){
    int arr1[order][order];
    int arr2[order][order];

    int i = 0; int j = 0;
    int k = 0;
    int SumMat1 = 0, SumMat2 = 0;
    while(i<order){
        while(j<order){
            arr1[i][j] = a[k];
            arr2[i][j] = b[k];
            j++; k++;
        } j = 0;
        i++;
    } // matrices are ready
    for(int i = 0; i<order; i++){
        for(int j = 0; j<order; j++){
            SumMat1 += arr1[i][j];
            SumMat2 += arr2[i][j];
        }
    }
    double Avg1 = SumMat1/(double)(order*order);
    double Avg2 = SumMat2/(double)(order*order);
    printf("The Average of Matrix A is : %lf \n", Avg1);
    printf("The Average of Matrix B is : %lf \n", Avg2); 
    printf("The Overall Average is : %lf\n", (Avg1+Avg2)/2.0);
}





