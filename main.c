#include <stdio.h>

// Definição da constante da taxa de juros anual (5%)
#define INTEREST_RATE 0.05

int main() {

    // Declaração das variáveis para o investimento
    double initialValue, finallyValue;
    int years;

    // Declaração e inicialização do vetor e da matriz
    int vetor[3] = {10, 20, 30};
    int matriz[2][2] = {{1,2}, {3,4}};

    printf("Digite o valor inicial do investimento: ");
    scanf("%lf", &initialValue);
    printf("Digite o número de anos do investimento: ");
    scanf("%d", &years);

    finallyValue = initialValue * (1 + INTEREST_RATE * years);

    printf("Valor final do investimento após %d anos: %.2lf\n\n", years, finallyValue); // Revisar

    int *pVetor = vetor;
    *pVetor = 50;
    
    printf("Valores e endereços do vetor:\n");
}