// #include <stdio.h>

// void multiplyMatrices(int firstMatrix[10][10], int secondMatrix[10][10], int result[10][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond);

// int main() {
//     int firstMatrix[10][10], secondMatrix[10][10], result[10][10], rowFirst, columnFirst, rowSecond, columnSecond;

//     // Input for the first matrix
//     printf("Enter rows and columns for the first matrix: ");
//     scanf("%d %d", &rowFirst, &columnFirst);

//     // Input for the second matrix
//     printf("Enter rows and columns for the second matrix: ");
//     scanf("%d %d", &rowSecond, &columnSecond);

//     if (columnFirst != rowSecond) {
//         printf("Error! column of the first matrix not equal to row of the second.\n");
//         return 0;
//     }

//     // Input elements for the first matrix
//     printf("Enter elements for the first matrix:\n");
//     for (int i = 0; i < rowFirst; ++i) {
//         for (int j = 0; j < columnFirst; ++j) {
//             printf("Enter element a%d%d: ", i + 1, j + 1);
//             scanf("%d", &firstMatrix[i][j]);
//         }
//     }

//     // Input elements for the second matrix
//     printf("Enter elements for the second matrix:\n");
//     for (int i = 0; i < rowSecond; ++i) {
//         for (int j = 0; j < columnSecond; ++j) {
//             printf("Enter element b%d%d: ", i + 1, j + 1);
//             scanf("%d", &secondMatrix[i][j]);
//         }
//     }

//     // Initialize result matrix to zero
//     for (int i = 0; i < rowFirst; ++i) {
//         for (int j = 0; j < columnSecond; ++j) {
//             result[i][j] = 0;
//         }
//     }

//     // Multiply the two matrices
//     multiplyMatrices(firstMatrix, secondMatrix, result, rowFirst, columnFirst, rowSecond, columnSecond);

//     // Display the multiplication result
//     printf("\nOutput Matrix:\n");
//     for (int i = 0; i < rowFirst; ++i) {
//         for (int j = 0; j < columnSecond; ++j) {
//             printf("%d  ", result[i][j]);
//             if (j == columnSecond - 1)
//                 printf("\n");
//         }
//     }

//     return 0;
// }

// void multiplyMatrices(int firstMatrix[10][10], int secondMatrix[10][10], int result[10][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond) {
//     for (int i = 0; i < rowFirst; ++i) {
//         for (int j = 0; j < columnSecond; ++j) {
//             for (int k = 0; k < columnFirst; ++k) {
//                 result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
//             }
//         }
//     }
// }


#include <stdio.h>
#include <stdlib.h>

void multiplyMatrices(int **firstMatrix, int **secondMatrix, int **result, int rowFirst, int columnFirst, int rowSecond, int columnSecond);

int main() {
    int **firstMatrix, **secondMatrix, **result, rowFirst, columnFirst, rowSecond, columnSecond;

    // Input for the first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowFirst, &columnFirst);

    // Input for the second matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowSecond, &columnSecond);

    if (columnFirst != rowSecond) {
        printf("Error! Column of the first matrix not equal to row of the second.\n");
        return 0;
    }

    // Allocate memory for the first matrix
    firstMatrix = (int **)malloc(rowFirst * sizeof(int *));
    for (int i = 0; i < rowFirst; i++) {
        firstMatrix[i] = (int *)malloc(columnFirst * sizeof(int));
    }

    // Input elements for the first matrix
    printf("Enter elements for the first matrix:\n");
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < columnFirst; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    // Allocate memory for the second matrix
    secondMatrix = (int **)malloc(rowSecond * sizeof(int *));
    for (int i = 0; i < rowSecond; i++) {
        secondMatrix[i] = (int *)malloc(columnSecond * sizeof(int));
    }

    // Input elements for the second matrix
    printf("Enter elements for the second matrix:\n");
    for (int i = 0; i < rowSecond; ++i) {
        for (int j = 0; j < columnSecond; ++j) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    // Allocate memory for the result matrix
    result = (int **)malloc(rowFirst * sizeof(int *));
    for (int i = 0; i < rowFirst; i++) {
        result[i] = (int *)malloc(columnSecond * sizeof(int));
    }

    // Initialize result matrix to zero
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < columnSecond; ++j) {
            result[i][j] = 0;
        }
    }

    // Multiply the two matrices
    multiplyMatrices(firstMatrix, secondMatrix, result, rowFirst, columnFirst, rowSecond, columnSecond);

    // Display the multiplication result
    printf("\nOutput Matrix:\n");
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < columnSecond; ++j) {
            printf("%d  ", result[i][j]);
            if (j == columnSecond - 1)
                printf("\n");
        }
    }

    // Free allocated memory
    for (int i = 0; i < rowFirst; ++i) {
        free(firstMatrix[i]);
    }
    free(firstMatrix);

    for (int i = 0; i < rowSecond; ++i) {
        free(secondMatrix[i]);
    }
    free(secondMatrix);

    for (int i = 0; i < rowFirst; ++i) {
        free(result[i]);
    }
    free(result);

    return 0;
}

void multiplyMatrices(int **firstMatrix, int **secondMatrix, int **result, int rowFirst, int columnFirst, int rowSecond, int columnSecond) {
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < columnSecond; ++j) {
            for (int k = 0; k < columnFirst; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}
