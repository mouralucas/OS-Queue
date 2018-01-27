# OS-Queue
Queue Library to the PingPong-OS

O sistema operacional gerencia muitas filas: de processos prontos, suspensos, dormindo, esperando em semáforos, etc.
A estrutura de dados mais adequada para implementar essas filas é uma lista circular duplamente encadeada.

Este projeto consiste em construir uma pequena biblioteca que ofereça operações básicas de inserção e remoção em
uma lista circular duplamente encadeada totalmente escrita em ANSI C, usando estruturas e ponteiros. A fila é genérica
e pode ser usada para organizar vários tipos de dados.

Interface
A biblioteca a ser construída deverá respeitar rigorosamente a interface definida no arquivo queue.h (que não deve ser
modificado). Ela deverá ser totalmente escrita em C ANSI, em um arquivo único chamado queue.c, e deverá funcionar
corretamente com o programa de teste testafila.c.

Exercício do Livro Sistemas Operacionais: Conceitos e Mecanismos - Professor Carlos Maziero.
