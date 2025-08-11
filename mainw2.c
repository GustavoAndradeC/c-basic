#include <stdio.h>

#define INTEREST_RATE 0.05

int main() {

    double initialValue, finallyValue;
    int years;

    int vetor[3] = {10, 20, 30};
    int matriz[2][2] = {{1, 2}, {3, 4}};

    printf("Digite o valor inicial do investimento: ");
    scanf("%lf", &initialValue); 

    printf("Digite o numero de anos do investimento: ");
    scanf("%d", &years);

    finallyValue = initialValue * (1 + INTEREST_RATE * years);

    printf("\nValor final do investimento apos %d anos: R$ %.2f\n", years, finallyValue); // Verificar

    int *pVetor = &vetor[0];
    *pVetor = 50; 

    printf("Valores e enderecos dos elementos do VETOR:\n");
    for (int i = 0; i < 3; i++) {
        printf("vetor[%d]: Valor = %d, Endereco = %p\n", i, vetor[i], &vetor[i]);
    }

    printf("\nValores e enderecos dos elementos da MATRIZ:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("matriz[%d][%d]: Valor = %d, Endereco = %p\n", i, j, matriz[i][j], &matriz[i][j]);
        };
    }

    return 0;
}
