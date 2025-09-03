#include <stdio.h>
#define max_terms 100
    typedef struct {
        int row;
        int col;
        int value;
    } term;
int main(){

    // ...existing code...

    // Initialize an empty 6x6 sparse matrix
    term empty[max_terms];
    empty[0].row = 6;    // Number of rows
    empty[0].col = 6;    // Number of columns
    empty[0].value = 0;  // Number of non-zero terms

    printf("Empty sparse matrix:\n");
    printf("Row: %d, Col: %d, Value: %d\n\n", empty[0].row, empty[0].col, empty[0].value);

    empty[1].row = 2;
    empty[1].col = 3;
    empty[1].value = 10;
    empty[0].value = 1; // Update the number of non-zero terms

    return 0;
}