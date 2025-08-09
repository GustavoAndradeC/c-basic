#include <stdio.h>

// Definir a constante da taxa de juros anual (5%)
#define INTEREST_RATE 0.05

int main() {

    // Declarar as variáveis para o investimento
    double initialValue, finallyValue;
    int years;

    // Declarar um vetor e uma matriz e inicializá-los
    int vetor[3] = {10, 20, 30};
    int matriz[2][2] = {{1, 2}, {3, 4}};

    // Solicitar os dados de investimento ao usuário
    printf("Digite o valor inicial do investimento: ");
    scanf("%lf", &initialValue); 

    printf("Digite o numero de anos do investimento: ");
    scanf("%d", &years);

    // Calcular o valor final com juros simples
    finallyValue = initialValue * (1 + INTEREST_RATE * years);

    // Passo 5: Exibir o resultado do investimento
    printf("\nValor final do investimento apos %d anos: R$ %.2f\n", years, finallyValue); // Verificar

    int *pVetor = &vetor[0];
    *pVetor = 50; 

    // Exibir os valores e endereços de memória do vetor e da matriz
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
