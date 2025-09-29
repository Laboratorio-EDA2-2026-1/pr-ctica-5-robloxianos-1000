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


//ALGORITMO 

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
//EJERCICIO 2
#include <stdio.h>
#include <stdlib.h>

#define ROJO 0
#define BLANCO 1
#define AZUL 2

int Examine(int A[], int i) {
    return A[i];
}

void Swap(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void countingSortColores(int A[], int n) {
    if (n <= 0) return;

    int max = 2;
    int *C = (int *)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        C[Examine(A, i)]++;
    }

    for (int i = 1; i <= max; i++) {
        C[i] += C[i - 1];
    }

    int *B = (int *)malloc(n * sizeof(int));

    for (int i = n - 1; i >= 0; i--) {
        int color = Examine(A, i);
        B[C[color] - 1] = color;
        C[color]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }

    free(C);
    free(B);
}

void mostrarArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == ROJO) printf("ROJO ");
        else if (arr[i] == BLANCO) printf("BLANCO ");
        else if (arr[i] == AZUL) printf("AZUL ");
    }
    printf("\n");
}

int main() {
    int colores[] = {AZUL, BLANCO, ROJO, ROJO, AZUL, BLANCO,AZUL,BLANCO, ROJO, AZUL,BLANCO, ROJO, BLANCO};
    int n = sizeof(colores) / sizeof(colores[0]);

    printf("Arreglo original: ");
    mostrarArreglo(colores, n);

    countingSortColores(colores, n);

    printf("Arreglo ordenado: ");
    mostrarArreglo(colores, n);

    return 0;
}
