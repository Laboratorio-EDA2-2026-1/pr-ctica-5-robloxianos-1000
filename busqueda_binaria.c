// Escribe aqui la implementación de los ejercicios de búsqueda binaria.
#include <stdio.h>


int busquedaBR(int A[], int izquierdo, int derecho, int x) { 
    int medio = izquierdo + (derecho - izquierdo) / 2;
    if (A[medio] == x) {
        return medio;
    }
    if (izquierdo >= derecho) {
        return -1;
    }
    if (A[medio] > x) {
        return busquedaBR(A, izquierdo, medio - 1, x);
    } else {
        return busquedaBR(A, medio + 1, derecho, x);
    }
}
int busquedaBinaria(int A[], int tamaño, int x) {
    return busquedaBR(A, 0, tamaño - 1, x);
}

int main() {
    int arreglo[] = {0, 345, 890, 234, 621, 7890, 50, 45, 1, 89};
    int tamaño = 10;
    int x = 621;
    int resultado = busquedaBinaria(arreglo, tamaño, x);
    if (resultado != -1) {
        printf("Elemento %d encontrado en la posición %d\n", x, resultado);
    } else {
        printf("Elemento %d no encontrado\n", x);
    }
   
    return 0;
}
