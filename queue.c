//P0 Biblioteca de Filas


//Lucas Penha de Moura		1208977
//Jociane franzoni de Lima	1195409

#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void queue_append(queue_t **queue, queue_t *elem){

// *queue deve apontar para o primeiro elemento da fila, se houver, ou NULL

	if (elem == NULL)
	{
		//erro caso o elemento não exista
		printf("Este elemento não existe.\n");
		return;
	}
	
	if (elem->prev != NULL || elem->next != NULL)
	{
		//erro quando o elemento esta em outra lista
		printf("Este elemento ja esta em outra fila.\n");
		return;
	}
	
	if (queue == NULL)
	{
		//erro caso fila não exista
		printf("Esta fila nao existe.\n");
		return;

	}
	
	if (*queue == NULL){ 	//se a fila for vazia adiciona o primeiro elemento
		
		(*queue) = elem; 	//adicionando elemento na lista.
		elem->next = elem; 	// definindo o proximo elemento como sendo próprio elemento.
		elem->prev = elem;  // definindo o elemento anterior como sendo ele mesmo.
	} 
	
		//Se a ja contem elementos na fila
		//recebe a lista para procurar a ultima posição
		queue_t *final = *queue;
		
		while(final->next != *queue) //Enquanto o proximo ponteiro do ultimo elemento for diferente da cabeça (encontra a ultimo elemento da fila)
		{
			final = final->next;
		
		}
		
			elem->next = final->next; 	// Ponteiro next do elemento final da fila é passado para o novo elemento;
			elem->next->prev = elem; 	// Ponteiro anterior da cabeça da fila;
			elem->prev = final;       	// Ponteiro anterior do elemento aponta pro ultimo;
			final->next = elem;      	// O ponteiro proximo do ultimo elemento aponta para o novo elemento;
		
	
}//fim de append

queue_t *queue_remove(queue_t **queue, queue_t *elem){
	
	if(queue == NULL) printf("Fila nao existe.\n");

	if(*queue == NULL) printf("A fila esta vazia");
		
	if (elem == NULL) printf("Elemento não existe");
		
		
		
	queue_t *aux = (*queue);
		
	if(aux == elem){
		
		if(aux->next == aux){
			//contem apenas um elemento
			(*queue) = NULL;
			elem->next = NULL;
			elem->prev = NULL;
			return elem ;
			
			
		}

		if(aux == *queue){
			//deve retirar sempre o primeiro elemento
			*queue = aux->next;
			(*queue)->prev = elem->prev;
			elem->prev->next = (*queue);
			elem->next = NULL;
			elem->prev = NULL;
			return elem;	//ta cerrrrto
					
		}
			
	} else {
		//deve retirar qualquer elemento
		while(aux->next != (*queue)){
			
			if(aux->next == elem){
				elem->next->prev = elem->prev;
				elem->prev->next = elem->next;
				elem->next = NULL;
				elem->prev = NULL;
			
				return elem;
			}
			
			aux = aux->next;
			
		}
	}
		printf("O elemento não existe.\n");
		return NULL;
	
}// fim de remove

int queue_size (queue_t *queue){

	if(queue == NULL){
		return(0);
	}else {
		int elementos = 0;
		queue_t *size = queue;
			
		//faz a contagem dos elementos da fila
		while(size->next != queue){
			elementos += 1; //soma um a contagem
			size=size->next; //aponta para o proximo elemento da fila
		}
			
		return elementos + 1; //retorna o tamanho da fila (soma um para uma contagem de 1 a n)
		
	}

} // fim de size

void queue_print (char *name, queue_t *queue, void print_elem (void*) ){
	
	printf("%s", name);	
	
	
	if(queue == NULL){
		printf(": []\n");
		return;
	}
	
	printf(": [");
	queue_t *impressao = queue;
	
	while(impressao->next != queue){
		// a fila é mostrada em uma coluna, do primeiro ao ultimo elemento
		print_elem(impressao); //imprime o elemento
		printf(" ");//coloca uma separacao
		impressao = impressao->next; 
		//pela condicao do while, eh impresso ate o penultimo elemento
	}
	
	print_elem(impressao); //imprime o ultimo elemento
	
	printf("]\n");
	
}
