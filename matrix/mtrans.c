// void main(){
//     int arr[100][100],i,j,m,n;
//     printf("enter the number of rows and columns:");
//     scanf("%d%d",&m,&n);
//     printf("enter the elements of the array:");
//     for(i=0;i<m;i++){
//         for(j=0;j<n;j++){
//             scanf("%d",&arr[i][j]);
//         }
//     }
//     for (i = 0; i < m; i++)
//     {
//         for (j = 0; j < n; j++)
//         {
//             printf("%d", arr[i][j]);
//         }
//         printf("\n");
//     }

//     transpose(arr,m,n);
// }

// void transpose(int arr[100][100],int m,int n){
//     int i,j;
//     for(i=0;i<n;i++){
//         for(j=0;j<m;j++){
//             printf("%d",arr[j][i]);
//         }
//         printf("\n");
//     }
// }

#include <stdio.h>
#include <stdlib.h>

void transpose(int **arr, int m, int n);

int main() {
    int **arr, i, j, m, n;

    // Input for the number of rows and columns
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    // Allocate memory for the array
    arr = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    // Input elements for the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Display the original matrix
    printf("\nOriginal Matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Transpose the matrix
    transpose(arr, m, n);

    // Free allocated memory
    for (i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

void transpose(int **arr, int m, int n) {
    int i, j;

    // Allocate memory for the transposed array
    int **transposedArr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        transposedArr[i] = (int *)malloc(m * sizeof(int));
    }

    // Transpose the array
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            transposedArr[i][j] = arr[j][i];
        }
    }

    // Display the transposed matrix
    printf("\nTransposed Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", transposedArr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory for the transposed array
    for (i = 0; i < n; i++) {
        free(transposedArr[i]);
    }
    free(transposedArr);
}
