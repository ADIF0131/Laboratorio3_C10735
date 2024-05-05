#include <stdio.h>

int main() {
    int i, triangular;

    printf("Los primeros 100 números triangulares son:\n");

    for (i = 1; i <= 100; i++) {
        triangular = i * (i + 1) / 2;
        printf("%d ", triangular);
    }

    printf("\n");

    return 0; 
}