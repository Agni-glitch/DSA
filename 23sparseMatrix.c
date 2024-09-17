#include <stdio.h>
#define MAX 100
struct SparseMatrix {
    int row;
    int col;
    int value;
};
void createSparseMatrix(int matrix[MAX][MAX], int rows, int cols, struct SparseMatrix sparse[]) {
    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }
    sparse[0].row = rows;
    sparse[0].col = cols;
    sparse[0].value = k - 1;
}
void transposeSparseMatrix(struct SparseMatrix sparse[], struct SparseMatrix transpose[]) {
    int k = 1;
    int nonZeroElements = sparse[0].value;
    transpose[0].row = sparse[0].col; 
    transpose[0].col = sparse[0].row;
    transpose[0].value = nonZeroElements;
    for (int i = 0; i < sparse[0].col; i++) {
        for (int j = 1; j <= nonZeroElements; j++) {
            if (sparse[j].col == i) {
                transpose[k].row = sparse[j].col;
                transpose[k].col = sparse[j].row;
                transpose[k].value = sparse[j].value;
                k++;
            }
        }
    }
}
void printSparseMatrix(struct SparseMatrix sparse[]) {
    int nonZeroElements = sparse[0].value;
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= nonZeroElements; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}
int main() {
    int matrix[MAX][MAX], rows, cols;
    struct SparseMatrix sparse[MAX], transpose[MAX];
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    createSparseMatrix(matrix, rows, cols, sparse);
    transposeSparseMatrix(sparse, transpose);
    printf("\nOriginal Sparse Matrix:\n");
    printSparseMatrix(sparse);
    printf("\nTransposed Sparse Matrix:\n");
    printSparseMatrix(transpose);
    return 0;
}
