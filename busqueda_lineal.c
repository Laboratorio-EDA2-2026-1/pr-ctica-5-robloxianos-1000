#include <stdio.h>




int busquedaLineal(int arreglo[], int tamaño, int objetivo) {
       int encontrado = -1; 
    
    for(int i = 0; i < tamaño; i++) {
       
        if(arreglo[i] == objetivo) {
            encontrado = i;  
            printf("ENCONTRADO, POSICION: %i Sigue buscando\n", i);
        }
    }
    
    return encontrado;
}





int busquedaLienalMejorada(int arreglo[], int tamaño, int objetivo) {
    for(int i = 0; i < tamaño; i++) {
        
        
        if(arreglo[i] == objetivo) {
            printf("encontrado-RETORNA\n");
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
    
    printf("BUSQUEDA LINEAL SIMPLE\n");
    int resultado1 = busquedaLineal(arreglo, tamaño, objetivo);
    printf(" %i\n", resultado1);
    
    printf("BUSQUEDA LINEAL MEJORADO\n");
    int resultado2 = busquedaLienalMejorada(arreglo, tamaño, objetivo);
    printf(" %i\n", resultado2);


       int numeros[] = {5, 3, 8, 6, 2, 9, 8};
    int buscado = 8;

    int posicion = busquedaLinealRecursiva(numeros, tamaño, buscado, 0);

    if (posicion != -1)
        printf("el numero %i se encontro en la posicion %i\n", buscado, posicion);
    else
        printf("el numero %i no se encontro en el arreglo\n", buscado);

    

    int posicion = busquedaLinealCentinela(numeros, tamaño, buscado);

    if (posicion != -1)
        printf("el numero %i se encontro en la posicion %i\n", buscado, posicion);
    else
        printf("el numero %i no se encontro en el arreglo\n", buscado);




       

    return 0;
}

