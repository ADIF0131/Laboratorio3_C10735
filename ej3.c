#include <stdio.h>
#include <stdlib.h> // Para la función rand
#include <time.h>   // Para inicializar la semilla de rand

#define MAX_SIZE 10 // Definición global de tamaño máximo de la matriz

int my_fmin(int a, int b);
int findLargestSquare(int matrix[][MAX_SIZE], int size);

int main() {
    int n;
    printf("Ingrese el tamaño de la matriz (entre 1 y 10): ");
    scanf("%d", &n);

    // Validar el tamaño ingresado
    if (n < 1 || n > MAX_SIZE) {
        printf("Tamaño no válido. Se usará el valor por defecto 5.\n");
        n = 5;
    }

    const int SIZE = n;

    // Inicializar la semilla de rand
    srand(time(NULL));

    // Llenar la matriz aleatoriamente con valores binarios
    int matrix[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 2; // Genera valores 0 o 1
        }
    }

    // Imprimir la matriz generada
    printf("Matriz generada:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int largestSquareSize = findLargestSquare(matrix, SIZE);
    printf("El tamaño del cuadrado más grande de unos es: %d\n", largestSquareSize);

    return 0;
}

int my_fmin(int a, int b) {
    return (a < b) ? a : b;
}

int findLargestSquare(int matrix[][MAX_SIZE], int size) {
    int maxSquareSize = 0;
    int dp[size][size];

    // Llenar la primera fila y la primera columna de la matriz dp
    for (int i = 0; i < size; i++) {
        dp[i][0] = matrix[i][0];
        dp[0][i] = matrix[0][i];
        if (matrix[i][0] == 1 || matrix[0][i] == 1) {
            maxSquareSize = 1;
        }
    }

    // Llenar el resto de la matriz dp
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (matrix[i][j] == 1) {
                dp[i][j] = 1 + my_fmin(dp[i - 1][j], my_fmin(dp[i][j - 1], dp[i - 1][j - 1]));
                if (dp[i][j] > maxSquareSize) {
                    maxSquareSize = dp[i][j];
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxSquareSize;
}