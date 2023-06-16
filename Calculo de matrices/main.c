#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

// Función para imprimir una matriz
void imprimirMatriz(int matriz[FILAS][COLUMNAS]) {
    int i, j;

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("%d ", matriz[i][j]);  // Imprime el elemento en la posición (i, j)
        }
        printf("\n");  // Imprime una nueva línea después de cada fila
    }
}

// Función para ingresar elementos en una matriz
void ingresarMatriz(int matriz[FILAS][COLUMNAS]) {
    int i, j;

    printf("Ingrese los elementos de la matriz:\n");
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("Elemento [%d][%d]: ", i, j);  // Solicita al usuario el elemento en la posición (i, j)
            scanf("%d", &matriz[i][j]);  // Lee el elemento ingresado por el usuario y lo guarda en la matriz
        }
    }
}

int main() {
    int matriz1[FILAS][COLUMNAS];
    int matriz2[FILAS][COLUMNAS];
    int suma[FILAS][COLUMNAS];
    int resta[FILAS][COLUMNAS];
    int producto[FILAS][COLUMNAS];

    int i, j, k;  // Declarar variables fuera de los bucles

    printf("Ingrese la primera matriz:\n");
    ingresarMatriz(matriz1);  // El usuario ingresa los elementos de la primera matriz

    printf("\nIngrese la segunda matriz:\n");
    ingresarMatriz(matriz2);  // El usuario ingresa los elementos de la segunda matriz

    // Suma de matrices
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            suma[i][j] = matriz1[i][j] + matriz2[i][j];  // Suma los elementos correspondientes de ambas matrices y los guarda en 'suma'
        }
    }

    // Resta de matrices
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            resta[i][j] = matriz1[i][j] - matriz2[i][j];  // Resta los elementos correspondientes de ambas matrices y los guarda en 'resta'
        }
    }

    // Producto de matrices
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            producto[i][j] = 0;
            for (k = 0; k < COLUMNAS; k++) {
                producto[i][j] += matriz1[i][k] * matriz2[k][j];  // Calcula el producto de matrices y lo guarda en 'producto'
            }
        }
    }

    printf("\nMatriz 1:\n");
    imprimirMatriz(matriz1);  // Imprime la primera matriz

    printf("\nMatriz 2:\n");
    imprimirMatriz(matriz2);  // Imprime la segunda matriz

    printf("\nSuma de matrices:\n");
    imprimirMatriz(suma);  // Imprime la matriz resultante de la suma

    printf("\nResta de matrices:\n");
    imprimirMatriz(resta);  // Imprime la matriz resultante de la resta

    printf("\nProducto de matrices:\n");
    imprimirMatriz(producto);  // Imprime la matriz resultante del producto

    return 0;
}

