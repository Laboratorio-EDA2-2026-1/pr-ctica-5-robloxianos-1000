// Escribe aquí la implementación de los ejercicios de Counting Sort.
#include <stdio.h>
#include <stdlib.h>

void countingSort(int A[], int n) {
    if (n <= 0) return;

    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    int *C = (int *)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }

    
    for (int i = 1; i <= max; i++) {
        C[i] += C[i - 1];
    }

    int *B = (int *)malloc(n * sizeof(int));

    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }

    free(C);
    free(B);
}



