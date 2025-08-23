#include <stdio.h>
#include <time.h>

#define REP 1000

int fibonacci_simples(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci_simples(n - 1) + fibonacci_simples(n - 2);
    }
}

int fibonacci_cauda_aux(int n, int a, int b) {
    if (n == 0) {
        return a;
    }
    if (n == 1) {
        return b;
    }
    return fibonacci_cauda_aux(n - 1, b, a + b);
}

int fibonacci_cauda(int n) {
    return fibonacci_cauda_aux(n, 0, 1);
}

int main() {
    int n;
    clock_t inicio, fim;
    double tempo_simples, tempo_cauda;
    int resultado1, resultado2;

    printf("Digite um numero para calcular na sequencia de Fibonacci: ");
    scanf("%d", &n);

    // --- Teste da função recursiva simples ---
    inicio = clock();
    for (int i = 0; i < REP; i++) {
        resultado1 = fibonacci_simples(n);
    }
    fim = clock();
    tempo_simples = (double)(fim - inicio) / CLOCKS_PER_SEC / REP;

    printf("\n--- Funcao Recursiva Simples ---\n");
    printf("Resultado: %d\n", resultado1);
    printf("Tempo medio gasto: %f segundos\n", tempo_simples);

    // --- Teste da função recursiva em cauda ---
    inicio = clock();
    for (int i = 0; i < REP; i++) {
        resultado2 = fibonacci_cauda(n);
    }
    fim = clock();
    tempo_cauda = (double)(fim - inicio) / CLOCKS_PER_SEC / REP;

    printf("\n--- Funcao Recursiva em Cauda ---\n");
    printf("Resultado: %d\n", resultado2);
    printf("Tempo medio gasto: %f segundos\n", tempo_cauda);

    return 0;
}
