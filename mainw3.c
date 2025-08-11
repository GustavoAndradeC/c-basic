#include <stdio.h>

int main() {
    float nota, soma = 0, maiorNota = -1, menorNota = 11;
    int totalAlunos = 0, aprovados = 0, reprovados = 0;

    printf("Digite as notas dos alunos (digite -1 para encerrar):\n");

    while (1) {
        printf("Nota do aluno %d: ", totalAlunos + 1);
        scanf("%f", &nota);

        if (nota == -1) {
            break;
        }

        if (nota < 0 || nota > 10) {
            printf("Nota invalida! Digite um valor entre 0 e 10 \n");
            continue;
        }

        soma += nota;
        totalAlunos++;

        if (nota > maiorNota) {
            maiorNota = nota;
        }
        if (nota < menorNota) {
            menorNota = nota;
        }

        if (nota >= 6) {
            aprovados++;
        } else {
            reprovados++;
        }
    }

    if (totalAlunos > 0) {
        float media = soma / totalAlunos;
        printf("\n===== RESULTADOS =====\n");
        printf("Quantidade de alunos: %d\n", totalAlunos);
        printf("Media das notas: %.2f\n", media);
        printf("Maior nota: %.2f\n", maiorNota);
        printf("Menor nota: %.2f\n", menorNota);
        printf("Aprovados: %d\n", aprovados);
        printf("Reprovados: %d\n", reprovados);
    } else {
        printf("\nNenhuma nota válida foi inserida.\n");
    }

    return 0;
}
