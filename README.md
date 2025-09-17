# DESAFIO-faculdade-c---Tetris-Stack
# Tetris Stack - Fila de Peças (Desafio Nível Novato)

## Descrição do Projeto

Este projeto implementa a **fila de peças futuras** do jogo Tetris Stack utilizando **linguagem C**.  
O programa simula o comportamento de uma **fila circular**, permitindo inserir, remover e visualizar peças em ordem FIFO (First In, First Out).  
Cada peça possui um **tipo** (representado por caracteres: 'I', 'O', 'T', 'L') e um **identificador único (id)**.

O objetivo deste desafio é aplicar conceitos de **estruturas de dados, arrays, structs, funções e modularização**, além de criar uma interação simples via **terminal**.

---

## Funcionalidades

- Inicializa a fila com um número fixo de peças (padrão: 5).
- Permite jogar uma peça (remoção da frente da fila – `dequeue`).
- Permite inserir uma nova peça ao final da fila (inserção – `enqueue`), se houver espaço.
- Exibe o estado atual da fila após cada ação.
- Gera automaticamente as peças com tipos e IDs únicos.
- Menu interativo com opções claras e simples.

---

## Estruturas Principais

- **Peca**: struct que armazena `tipo` e `id`.
- **Fila**: struct que armazena o array de peças, índices de início e fim, e o total de elementos.

---

## Conceitos Trabalhados

- **Fila circular**: reaproveitamento eficiente do espaço da fila.
- **Structs e arrays**: representação de peças e fila.
- **Funções e modularização**: cada operação da fila possui sua própria função (`enqueue`, `dequeue`, `mostrarFila`, etc.).
- **Entrada e saída de dados**: interação via terminal.
- **Operadores lógicos e condicionais**: controle de fluxo para inserção e remoção.

---

## Requisitos Técnicos

- Linguagem: **C**
- Compilador recomendado: GCC
- Terminal para execução

---

## Como Executar

1. Clone este repositório:
```bash
git clone <URL_DO_REPOSITORIO>
