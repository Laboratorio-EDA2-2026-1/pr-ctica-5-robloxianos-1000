// Escribe aqui la implementación de los ejercicios de búsqueda binaria.
#include <stdio.h>

// busqueda binaria arreglo
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

//del [0,1]
void busquedaBinariaReal(double numero, int pasos) {
    double inicio = 0.0;
    double fin = 1.0;

    printf("Codigo binario de %.6lf: ", numero);
    for (int i = 0; i < pasos; i++) {
        double medio = (inicio + fin) / 2.0;
        if (numero < medio) {
            printf("0");
            fin = medio;
        } else {
            printf("1");
            inicio = medio;
        }
    }
    printf("\n");
}

int main() {
    // busqueda en arreglo 
    int arreglo[] = {0, 345, 890, 234, 621, 7890, 50, 45, 1, 89};
    int tamaño = 10;
    int x = 621;
    int resultado = busquedaBinaria(arreglo, tamaño, x);

    printf("----- BUSQUEDA BINARIA EN ARREGLO -----\n");
    if (resultado != -1) {
        printf("Elemento %d encontrado en la posicion %d\n", x, resultado);
    } else {
        printf("Elemento %d no encontrado\n", x);
    }

    // del [0,1) -----
    double numero;
    int pasos;

    printf("\n----- BUSQUEDA BINARIA EN [0,1) -----\n");
    printf("Ingrese un numero x entre 0 y 1: ");
    scanf("%lf", &numero);
    printf("Ingrese el numero de pasos: ");
    scanf("%i", &pasos);

    busquedaBinariaReal(numero, pasos);

    return 0;
}
