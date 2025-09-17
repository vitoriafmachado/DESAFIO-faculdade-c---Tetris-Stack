#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5  // Tamanho da fila

// Estrutura da peça
typedef struct {
    char tipo; // Tipo da peça: 'I', 'O', 'T', 'L'
    int id;    // Identificador único
} Peca;

// Estrutura da fila circular
typedef struct {
    Peca itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->total == 0;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->total == MAX;
}

// Insere uma nova peça no final da fila (enqueue)
void enqueue(Fila *f, Peca p) {
    if(filaCheia(f)) {
        printf("Fila cheia! Não é possível inserir a peça.\n");
        return;
    }
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX; // Circularidade
    f->total++;
}

// Remove a peça do início da fila (dequeue)
Peca dequeue(Fila *f) {
    Peca p = {'X', -1}; // Peça inválida caso a fila esteja vazia
    if(filaVazia(f)) {
        printf("Fila vazia! Não há peça para jogar.\n");
        return p;
    }
    p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
    return p;
}

// Mostra o estado atual da fila
void mostrarFila(Fila *f) {
    if(filaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("\nFila de peças:\n");
    for(int i = 0; i < f->total; i++) {
        int idx = (f->inicio + i) % MAX;
        printf("[%c %d] ", f->itens[idx].tipo, f->itens[idx].id);
    }
    printf("\n");
}

// Gera uma peça aleatória
Peca gerarPeca(int id) {
    char tipos[4] = {'I', 'O', 'T', 'L'};
    Peca p;
    p.tipo = tipos[rand() % 4];
    p.id = id;
    return p;
}

// Menu principal
int main() {
    Fila fila;
    inicializarFila(&fila);
    int proximoId = 0;
    int opcao;
    srand(time(NULL)); // Inicializa semente para rand()

    // Preenche a fila inicial
    for(int i = 0; i < MAX; i++) {
        enqueue(&fila, gerarPeca(proximoId++));
    }

    do {
        mostrarFila(&fila);
        printf("\nOpções de ação:\n");
        printf("1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                dequeue(&fila);
                break;
            case 2:
                enqueue(&fila, gerarPeca(proximoId++));
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while(opcao != 0);

    return 0;
}
