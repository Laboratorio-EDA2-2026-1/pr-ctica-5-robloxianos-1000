// Escribe aquí la implementación de los ejercicios de Counting Sort.
EJERCICIO 1
    #include <stdio.h>
#include <string.h>

int main() {
    char A[100];             
    int B[100];              
    int C[26];               
    int n, k;

    printf("Escribe una palabra (solo minusculas): ");
    scanf("%s", A);

    n = strlen(A);
    k = 25;

    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }
    for (int j = 0; j < n; j++) {
        C[A[j] - 'a'] = C[A[j] - 'a'] + 1;
    }
    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--) {
        int pos = A[j] - 'a';
        B[C[pos] - 1] = A[j];
        C[pos] = C[pos] - 1;
    }
    printf("Ordenada: ");
    for (int i = 0; i < n; i++) {
        printf("%c", B[i]);
    }
    printf("\n");

    return 0;
}



EJERCICIO 2

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


int main() {
    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(A) / sizeof(A[0]);

    countingSort(A, n);

    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
