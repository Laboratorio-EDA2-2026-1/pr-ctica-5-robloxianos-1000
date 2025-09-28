#include <stdio.h>

int busquedaLineal(int arreglo[], int tamaño, int objetivo) {
    int encontrado = -1; 
    
    for(int i = 0; i < tamaño; i++) {
        if(arreglo[i] == objetivo) {
            encontrado = i;  
            printf("encontrado, posicion: %i Sigue buscando\n", i);
        }
    }
    
    return encontrado;
}




int busquedaLinealMejorada(int arreglo[], int tamaño, int objetivo) {
    for(int i = 0; i < tamaño; i++) {
        if(arreglo[i] == objetivo) {
            printf("encontrado-retorna\n");
            return i;  
        }
    }
    
    return -1;
}




int busquedaLinealRecursiva(int arreglo[], int tamaño, int valor, int indice) {
    if (indice >= tamaño)          
        return -1;
    if (arreglo[indice] == valor)  
        return indice;
    
    return busquedaLinealRecursiva(arreglo, tamaño, valor, indice + 1);
}




int busquedaLinealCentinela(int arreglo[], int tamaño, int valor) {
    int ultimo = arreglo[tamaño - 1]; 
    arreglo[tamaño - 1] = valor;      

    int i = 0;
    while (arreglo[i] != valor) {
        i++;
    }

    arreglo[tamaño - 1] = ultimo;

    if (i < tamaño - 1 || arreglo[tamaño - 1] == valor) {
        return i;  
    } else {
        return -1; 
    }
}




int main() {
    int arreglo[] = {10, 25, 30, 45, 50, 25, 60};
    int tamaño = 7;
    int objetivo = 25;
    
    printf("-Busqueda lineal simple\n");
    int resultado1 = busquedaLineal(arreglo, tamaño, objetivo);
    printf("Resultado: %i\n", resultado1);
    
    printf("-Busqueda lineal mejorada\n");
    int resultado2 = busquedaLinealMejorada(arreglo, tamaño, objetivo);
    printf("Resultado: %i\n", resultado2);

    int numeros[] = {5, 3, 8, 6, 2, 9, 8};
    int tamaño2 = 7;  
    int buscado = 8;

    printf("-Busqueda lineal recursiva\n");
    int posicion1 = busquedaLinealRecursiva(numeros, tamaño2, buscado, 0);

    if (posicion1 != -1)
        printf("El numero %i se encontro en la posicion %i\n", buscado, posicion1);
    else
        printf("El numero %i no se encontro en el arreglo\n", buscado);

    printf("-Busqueda lineal centinela\n");
    int posicion2 = busquedaLinealCentinela(numeros, tamaño2, buscado);

    if (posicion2 != -1)
        printf("El numero %i se encontro en la posicion %i\n", buscado, posicion2);
    else
        printf("El numero %i no se encontro en el arreglo\n", buscado);

    return 0;
}
