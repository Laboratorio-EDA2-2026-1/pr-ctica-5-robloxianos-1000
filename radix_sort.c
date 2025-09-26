// Escribe aquí la implementación del ejercicio de Radix Sort.
EJERCICIO 1
  
#include <stdio.h>
#include <stdlib.h>

int maximo(int arreglo[], int n) {
    int mayor = arreglo[0];
    for (int i = 1; i < n; i++) {
        if (arreglo[i] > mayor) {
            mayor = arreglo[i];
        }
    }
    return mayor;
}

void contarOrden(int arreglo[], int n, int exp) {
    int *salida = (int*) malloc(n * sizeof(int));
    int conteo[10] = {0};

    for (int i = 0; i < n; i++) {
        int dig = (arreglo[i] / exp) % 10;
        conteo[dig]++;
    }

    for (int i = 1; i < 10; i++) {
        conteo[i] += conteo[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int dig = (arreglo[i] / exp) % 10;
        salida[conteo[dig] - 1] = arreglo[i];
        conteo[dig]--;
    }

    for (int i = 0; i < n; i++) {
        arreglo[i] = salida[i];
    }

    free(salida);
}

void radixSort(int arreglo[], int n) {
    int mayor = maximo(arreglo, n);
    for (int exp = 1; mayor / exp > 0; exp *= 10) {
        contarOrden(arreglo, n, exp);
    }
}

void mostrar(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("¿Cuántos números quieres ordenar?\n ");
    scanf("%d", &n);

    int *lista = (int*) malloc(n * sizeof(int));

    printf("Ingresa los %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }

    printf("Lista original:\n");
    mostrar(lista, n);

    radixSort(lista, n);

    printf("Lista ordenada con Radix Sort:\n");
    mostrar(lista, n);

    free(lista);
    return 0;
}

