/*Baseado no que foi visto nas aulas até o momento e nos exemplos dentro da aba arquivos, 
crie uma lista que faça o controle de alunos matriculados no 4º Semestre do Curso de Análise e 
Desenvolvimento de Sistemas da Fatec Taquaritinga.*/

//RA: 0220482113006  Nome: Ana Beatriz G. Lopes



#include <stdio.h>
#include <stdlib.h>

typedef struct listMatrcl{
	int RA;
	char tel[15];
	char nome[30];
	struct listMatrcl *prox;
} listMatrcl;

int tam;

listMatrcl *alocar(){
	listMatrcl *novo = (listMatrcl *) malloc(sizeof(listMatrcl));
	if (!novo){
		printf("Sem memoria!\n");
		exit(1);
	}
	return novo;
}

void inicia(listMatrcl *LISTA){
	LISTA->prox = NULL;
	tam = 0;
}

void AdicionarInicio(listMatrcl *LISTA){
	listMatrcl *novo = alocar();
	
	if(novo == NULL){
	    printf("Sem memoria!\n");
	}else{
	  	novo->prox = LISTA->prox;
    	LISTA->prox = novo;
    	printf("RA: ");
    	scanf("%d", &novo->RA);
    	printf("nome: ");
    	scanf("%s", &novo->nome);
    	printf("tel: ");
    	scanf("%s", &novo->tel);
	}
	
	tam++;
}

void AdicionarFim(listMatrcl *LISTA){
	listMatrcl *novo = alocar();
	
	novo->prox = NULL;
	if(LISTA->prox == NULL)
		LISTA->prox = novo;
	else{
		listMatrcl *tmp = LISTA->prox;
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		tmp->prox = novo;
	}
	printf("RA: ");
	scanf("%d", &novo->RA);
	printf("nome: ");
	scanf("%s", &novo->nome);
	printf("tel: ");
	scanf("%s", &novo->tel);
	
	tam++;
}

void AdicionarN(listMatrcl *LISTA){
	int pos, count;
	
	printf("Inserir na posicao: [1 ate %d]: ", tam);
	scanf("%d", &pos);
	
	if(pos > 0 && pos <= tam){
		if(pos == 1){
			AdicionarInicio(LISTA);
		}
		else{
			listMatrcl *atual = LISTA->prox, *anterior = LISTA;
			listMatrcl *novo = alocar();
			for(count=1; count < pos; count++){
				anterior = atual; atual = atual->prox;
			}
			anterior->prox = novo;
			novo->prox = atual;
			printf("RA: ");
	        scanf("%d", &novo->RA);
	        printf("nome: ");
	        scanf("%s", &novo->nome);
	        printf("tel: ");
	        scanf("%s", &novo->tel);
			tam++;
		}
	}
	else{
		printf("Elemento invalido!\n");
	}
}

void ExibirLista(listMatrcl *LISTA){
	if (LISTA->prox == NULL)
		printf("Lista vazia!");
	else{
		listMatrcl *tmp;
		for (tmp = LISTA->prox; tmp != NULL; tmp = tmp->prox){
			printf("|RA:%d\t|Nome: %s\t|Tel: %s\n\n", tmp->RA, tmp->nome, tmp->tel);
	    }
	}
	printf("Alunos Cadastrados: %d\n", tam);
	printf("\n\n");
}

void ExibirElementoN(listMatrcl *LISTA){
	int pos, count;
	
	printf("Exibir Posicao: [1 ate %d]: ", tam);
	printf("\n\n");
	scanf("%d",&pos);
	
	if(pos>0 && pos <= tam){
		listMatrcl *atual = LISTA->prox, *anterior = LISTA;
		
		for(count=1; count < pos; count++){
			anterior = atual;
			atual = atual->prox;
		}
		printf("\n\n");
		printf("\tMatricula: %d\nRA: %d\nNome: %s\nTel: %s",pos, atual->RA, atual->nome, atual->tel);
		printf("\n\n");
	}
}

void RemoverInicio(listMatrcl *LISTA){
	if (LISTA->prox == NULL)
		printf("Lista vazia!");
	else{
		listMatrcl *tmp = LISTA->prox;
		LISTA->prox = tmp->prox;
		printf("RA: %d\nNome: %s\nTel: %s\n  Removido com sucesso!",tmp->RA, tmp->nome, tmp->tel);
		free(tmp);
		tam--;
	}
	printf("\n\n");
}

void RemoverFim(listMatrcl *LISTA){
	listMatrcl *aux;
	
	if (LISTA->prox == NULL)
		printf("Lista vazia!");
	else{
		listMatrcl *ultimo = LISTA->prox, *penultimo = LISTA; 
		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
			tam--;
		}
		penultimo->prox = NULL;
		printf("ultima matricula removida com sucesso!");
		printf("RA: %d",ultimo->RA);
		printf("Nome: %s",ultimo->nome);
		printf("Telefone: %s",ultimo->tel);
	}
	printf("\n\n");
}

void RetirarN(listMatrcl *LISTA){
	int pos, count;
	
	printf("Remover da posicao: [1 ate %d]: ", tam);
	scanf("%d",&pos);
	
	if(pos>0 && pos <= tam){
		if(pos==1){
			return RemoverInicio(LISTA);
		}
		else{
			listMatrcl *atual = LISTA->prox, *anterior = LISTA;
			
			for(count=1; count < pos; count++){
				anterior = atual;
				atual = atual->prox;
			}
			
			anterior->prox=atual->prox;
			tam--;
			printf("Matrícula %d excluida", pos);
			printf("RA %d",atual->RA);
			printf("Nome: %s",atual->nome);
			printf("Telefone: %s",atual->tel);
		}
	}
}

void Liberar(listMatrcl *LISTA){
	listMatrcl *atual = LISTA->prox, *proximo;
	while(atual != NULL){
		proximo = atual->prox;
		free(atual);
		atual = proximo;
	}
	
	inicia(LISTA);
}

int main(void){
	
	listMatrcl *LISTA = alocar();
	inicia(LISTA);
	int opt;
	
	do{
		printf("\n\n");
		printf(" 1-Inserir no inicio da lista\n");
		printf(" 2-Inserir no fim da lista\n");
		printf(" 3-Inserir em um ponto da lista\n");
		printf(" 4-Remover do inicio da lista\n");
		printf(" 5-Remover do fim da lista\n");
		printf(" 6-Remover de um ponto da lista\n");
		printf(" 7-Exibir elementos da lista \n");
		printf(" 8-Consultar elemento \n");
		printf(" 9-Liberar os elementos da lista \n");
		printf(" 0-Sair \n");
		printf("==================================\n");
		printf("Escolha a opcao: ");
		scanf("%d", &opt);
		printf("\n\n");
		switch(opt)
		{
			case 1: 
				AdicionarInicio(LISTA);
				break;
			case 2: 
				AdicionarFim(LISTA);
				break;
			case 3: 
				AdicionarN(LISTA);
				break;
			case 4: 
				RemoverInicio(LISTA);
				break;
			case 5: 
				RemoverFim(LISTA);
				break;
			case 6: 
				RetirarN(LISTA);
				break;
			case 7: 
				ExibirLista(LISTA);
				break;
			case 8: 
				ExibirElementoN(LISTA);
				break;
			case 9: 
				Liberar(LISTA);
				ExibirLista(LISTA);
				break;
			case 0: 
				Liberar(LISTA);
				break;
			default: 
				printf("Comando invalido\n\n");
		}
	}while(opt <= 9 && opt != 0);
	Liberar(LISTA);
	return 0;
}
