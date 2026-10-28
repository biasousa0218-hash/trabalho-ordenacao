#include <stdio.h>

// Função para imprimir o vetor de notas
void imprimirVetor(float v[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%.2f ", v[i]);
    }
    printf("\n");
}

// 1. Implementação do Bubble Sort
// Compara elementos adjacentes e os "borbulha" para a posição correta
void bubbleSort(float v[], int tamanho) {
    int i, j;
    float temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            if (v[j] > v[j + 1]) { // Se o atual for maior que o próximo, troca
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }         
        }
    }
}

// Função auxiliar de particionamento para o Quick Sort
int particionar(float v[], int baixo, int alto) {
    float pivo = v[alto]; // Escolhe o último elemento como pivô
    int i = (baixo - 1);
    int j;
    float temp;

    for (j = baixo; j <= alto - 1; j++) {
        if (v[j] < pivo) { // Se o elemento for menor que o pivô
            i++;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    temp = v[i + 1];
    v[i + 1] = v[alto];
    v[alto] = temp;
    return (i + 1);
}

// 2. Implementação do Quick Sort (Algoritmo recursivo de divisão e conquista)
void quickSort(float v[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(v, baixo, alto);
        quickSort(v, baixo, pi - 1);  // Ordena a parte esquerda
        quickSort(v, pi + 1, alto);   // Ordena a parte direita
    }
}

int main() {
    // Conjunto com 10 registros (Notas de estudantes)
    float notasBubble[10] = {7.5, 4.0, 9.2, 5.5, 8.0, 3.2, 10.0, 6.8, 6.0, 8.5};
    float notasQuick[10] = {7.5, 4.0, 9.2, 5.5, 8.0, 3.2, 10.0, 6.8, 6.0, 8.5};
    int tamanho = 10;

    printf("=== APLICACAO: CLASSIFICACAO DE NOTAS DE ESTUDANTES ===\n\n");

    // Apresentar dados antes da ordenação
    printf("Notas originais (antes da ordenacao):\n");
    imprimirVetor(notasBubble, tamanho);
    printf("\n");

    // Ordenando com Bubble Sort
    bubbleSort(notasBubble, tamanho);
    printf("Notas ordenadas usando BUBBLE SORT (Crescente):\n");
    imprimirVetor(notasBubble, tamanho);
    printf("\n");

    // Ordenando com Quick Sort
    quickSort(notasQuick, 0, tamanho - 1);
    printf("Notas ordenadas usando QUICK SORT (Crescente):\n");
    imprimirVetor(notasQuick, tamanho);

    return 0;
}
