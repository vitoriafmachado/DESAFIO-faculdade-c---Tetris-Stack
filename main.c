#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILA 5   // Tamanho da fila de peças futuras
#define MAX_PILHA 3  // Tamanho da pilha de reserva

// Estrutura da peça
typedef struct {
    char tipo; // Tipo da peça: 'I', 'O', 'T', 'L'
    int id;    // Identificador único
} Peca;

// Estrutura da fila circular
typedef struct {
    Peca itens[MAX_FILA];
    int inicio;
    int fim;
    int total;
} Fila;

// Estrutura da pilha
typedef struct {
    Peca itens[MAX_PILHA];
    int topo;
} Pilha;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

// Inicializa a pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->total == 0;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->total == MAX_FILA;
}

// Verifica se a pilha está cheia
int pilhaCheia(Pilha *p) {
    return p->topo == MAX_PILHA - 1;
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// Insere uma nova peça no final da fila (enqueue)
void enqueue(Fila *f, Peca p) {
    if(filaCheia(f)) return;
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX_FILA;
    f->total++;
}

// Remove a peça do início da fila (dequeue)
Peca dequeue(Fila *f) {
    Peca p = {'X', -1};
    if(filaVazia(f)) return p;
    p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->total--;
    return p;
}

// Insere peça na pilha (push)
void push(Pilha *p, Peca pe) {
    if(!pilhaCheia(p)) p->itens[++p->topo] = pe;
}

// Remove peça do topo da pilha (pop)
Peca pop(Pilha *p) {
    Peca pe = {'X', -1};
    if(!pilhaVazia(p)) pe = p->itens[p->topo--];
    return pe;
}

// Mostra fila e pilha
void mostrar(Fila *f, Pilha *p) {
    printf("\nFila de peças: ");
    for(int i = 0; i < f->total; i++) {
        int idx = (f->inicio + i) % MAX_FILA;
        printf("[%c %d] ", f->itens[idx].tipo, f->itens[idx].id);
    }

    printf("\nPilha de reserva (Topo -> Base): ");
    for(int i = p->topo; i >= 0; i--) {
        printf("[%c %d] ", p->itens[i].tipo, p->itens[i].id);
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

int main() {
    Fila fila;
    Pilha pilha;
    inicializarFila(&fila);
    inicializarPilha(&pilha);
    srand(time(NULL));

    int proximoId = 0;
    int opcao;

    // Inicializa fila
    for(int i = 0; i < MAX_FILA; i++) {
        enqueue(&fila, gerarPeca(proximoId++));
    }

    do {
        mostrar(&fila, &pilha);
        printf("\nOpções de ação:\n");
        printf("1 - Jogar peça\n");
        printf("2 - Reservar peça\n");
        printf("3 - Usar peça reservada\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                Peca jogada = dequeue(&fila);
                printf("Jogou: [%c %d]\n", jogada.tipo, jogada.id);
                enqueue(&fila, gerarPeca(proximoId++)); // Mantém a fila cheia
                break;
            }
            case 2: {
                if(pilhaCheia(&pilha)) {
                    printf("Pilha cheia! Não é possível reservar.\n");
                } else {
                    Peca reservada = dequeue(&fila);
                    push(&pilha, reservada);
                    enqueue(&fila, gerarPeca(proximoId++));
                    printf("Peça [%c %d] reservada.\n", reservada.tipo, reservada.id);
                }
                break;
            }
            case 3: {
                if(pilhaVazia(&pilha)) {
                    printf("Pilha vazia! Nenhuma peça para usar.\n");
                } else {
                    Peca usada = pop(&pilha);
                    printf("Usou peça reservada: [%c %d]\n", usada.tipo, usada.id);
                }
                break;
            }
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while(opcao != 0);

    return 0;
}
