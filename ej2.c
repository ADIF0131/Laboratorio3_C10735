#include <stdio.h>

long long int factorial(int n) {
    long long int i = 1;
    while (n > 1) {
        i *= n;
        n--; // Se decrementa n en cada iteración
    }
    return i;
}

int main(int argc, char *argv[]) {
    int num;
    printf("Ingrese el número para calcular su factorial: ");
    scanf("%d", &num);
    long long int fac = factorial(num);
    printf("%d! = %lld\n", num, fac);
    return 0;
}
