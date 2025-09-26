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
    
    return 0;
}

