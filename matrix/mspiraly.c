// #include <stdio.h>

// void printSpiral(int matrix[100][100], int m, int n) {
//     int top = 0, bottom = m - 1, left = 0, right = n - 1;

//     while (top <= bottom && left <= right) {
//         // Print top row
//         for (int i = left; i <= right; i++) {
//             printf("%d ", matrix[top][i]);
//         }
//         top++;

//         // Print rightmost column
//         for (int i = top; i <= bottom; i++) {
//             printf("%d ", matrix[i][right]);
//         }
//         right--;

//         // Print bottom row
//         if (top <= bottom) {
//             for (int i = right; i >= left; i--) {
//                 printf("%d ", matrix[bottom][i]);
//             }
//             bottom--;
//         }

//         // Print leftmost column
//         if (left <= right) {
//             for (int i = bottom; i >= top; i--) {
//                 printf("%d ", matrix[i][left]);
//             }
//             left++;
//         }
//     }
// }

// int main() {
//     int matrix[100][100], m, n;

//     printf("Enter the number of rows and columns: ");
//     scanf("%d %d", &m, &n);

//     printf("Enter the elements of the matrix:\n");
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             scanf("%d", &matrix[i][j]);
//         }
//     }

//     printf("Spiral Order Matrix: ");
//     printSpiral(matrix, m, n);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

void printSpiral(int **matrix, int m, int n) {
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Print rightmost column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // Print bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Print leftmost column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
}

int main() {
    int m, n;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    // Dynamically allocate memory for the matrix
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Spiral Order Matrix: ");
    printSpiral(matrix, m, n);

    // Free dynamically allocated memory
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
