#include <stdio.h>
#include <stdlib.h>

//lista duplamente encadeada sem ordenação
typedef struct {
    int dado;
    struct no *prox;
    struct no *ant;
}no;


no *inicio;
no *fim;



void inicializa_lista(){
 inicio=NULL;
 fim=NULL;
}


int lista_vazia(){

  if(inicio==NULL){
    return 1;
  }else {
   return 0;
  }

}


void inserir_inicio_lista(int valor){

  //cria um novo no
  no *novo=(no*)malloc(sizeof(no));

  novo->dado =valor;
  novo->prox=NULL;
  novo->ant = NULL;

  if(inicio==NULL){ //primeira vez

    inicio=novo;
    fim=novo;

  }else{

     inicio->ant = novo;
     novo->prox= inicio;
     inicio=novo;    //Ajusta-se o inicio

  }

}


void inserir_fim_lista(int valor){

  //cria um novo no
  no *novo=(no*)malloc(sizeof(no));

  novo->dado =valor;
  novo->prox=NULL;
  novo->ant = NULL;

  if(inicio==NULL){ //primeira vez

    inicio=novo; //inicio aponta pro novo no
    fim=novo;

  }else{
    fim->prox=novo;// Novo nó será apontado pelo último nó da fila
    novo->ant= fim;
    fim=novo;    //Ajusta-se o fim
  }

}


void insere_ordenado(int valor){
    no *novo=(no*)malloc(sizeof(no));

    novo->dado =valor;
    novo->prox=NULL;
    novo->ant = NULL;
    if(inicio==NULL){ //primeira vez

        inicio=novo; //inicio aponta pro novo no
        fim=novo;

    }else{
        no *aux;
        aux = inicio;
        no *res;
        int j;
        j = 0;
        while(aux != NULL){
            if(valor <= aux->dado){
                if(j < 1){
                    inicio->ant = novo;
                    novo->prox = inicio;
                    inicio = novo;
                    break;
                } else{
                    novo->prox = aux;
                    novo->ant = res;
                    res->prox = novo;
                    aux->ant = novo;
                    break;
                }
            } else{
                if(valor > fim->dado){
                    fim->prox = novo;// Novo nó será apontado pelo último nó da fila
                    novo->ant = fim;
                    fim = novo;
                    break;
                } else{

                }
            }

            res = aux;
            aux = aux->prox;
            j++;
        }
    }

}


int remove_inicio_lista( )
{
  no *aux;     //ponteiro auxiliar
  int y;   //variável que recebe o valor de retorno

  if(lista_vazia()==1){

    printf("Nao e possivel remover\n");
    printf("Lista Vazia!!\n");
    return 0;

  }else{

       if(inicio==fim){


        aux=inicio;  //aponta para o nó inicial
        y =inicio->dado; //passa o valor da struc para a variável

        inicializa_lista();


        free(aux);

        return(y);

      }else{

        aux=inicio;  //aponta para o nó inicial
        y =aux->dado; //passa o valor da struc para a variável

        inicio=inicio->prox; //aponta para a proxima posição
        free(aux); //liberado.

        return(y);

     }

  }
}


int remove_ordenado( )
{
  no *aux;             //ponteiro auxiliar
  int y;   //variável que recebe o valor de retorno

  if(lista_vazia()==1){

    printf("Nao e possivel remover\n");
    printf("Lista Vazia!!\n");
    return 0;

  }else{

    int valor;
    mostra_lista();
    printf("Qual valor deseja excluir? ");
    scanf("%i", &valor);

    int num;
    aux = inicio;

    while(aux != NULL){
        if(aux->dado == valor){
            if(aux->ant == NULL){
                inicio = aux->prox;
                num = aux->dado;
                free(aux);
                return num;
                break;
            } else if(aux->prox == NULL){
                fim = aux->ant;
                fim->prox=NULL;
                num = aux->dado;
                free(aux);
                return num;
                break;
            } else{
                no *aux1;
                no *aux2;

                aux1 = aux->ant;
                aux2 = aux->prox;

                aux1->prox = aux->prox;
                aux2->ant = aux->ant;

                aux->ant=NULL;
                aux->prox=NULL;

                num = aux->dado;

                free(aux);

                return num;
                break;
            }
        }

        aux = aux->prox;
    }
  }
}

int remove_fim_lista( )
{
  no *aux;             //ponteiro auxiliar
  int y;   //variável que recebe o valor de retorno


  if(lista_vazia()==1){

    printf("Nao e possivel remover\n");
    printf("Lista Vazia!!\n");
    return 0;

  }else{

    if(inicio==fim){//se so tem um unico nó

        aux=fim;  //aponta para o nó inicial
        y =fim->dado; //passa o valor da struc para a variável
        inicializa_lista();
        free(aux);
        return(y);

     }else{
         aux=fim;            //aponta para o nó inicial
         y =aux->dado; //passa o valor da struc para a variável
         fim=fim->ant;
         fim->prox = NULL;

         free(aux); //liberado.
        return(y);
    }
  }

}






void mostra_lista()
{
    no *aux;
    aux =inicio;

  if(lista_vazia()==1){
    printf("\n Lista Vazia ");

  }else{

	printf("\n Lista : ");
	while(aux != NULL)
	{
		printf(" | %d ", aux->dado);
		aux = aux->prox; //incrementa o ponteiro
	}
  }
}


void menu(){
 int op;  //opção recursiva

 do{
     printf("\n\n");
     printf("1 - Inserir fim lista \n");
     printf("2 - Inserir inicio lista \n");
     printf("3 - Remover inicio Lista \n");
     printf("4 - Remover fim Lista \n");
     printf("5 - Inserir Ordenado \n");
     printf("6 - Remover Ordenado \n");
     printf("7 - Mostrar lista \n");
     printf("8 - Sair \n ");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){

     case 1:{
      int x;

      printf("Informe o valor: ");
      scanf("%d",&x);
      inserir_fim_lista(x);
      break;
     }

     case 2:{
      int x;

      printf("Informe o valor: ");
      scanf("%d",&x);
      inserir_inicio_lista(x);
      break;
     }

     case 3:{
        int x;
        x=remove_inicio_lista( );

        if(x!=0){
            printf("\n\tValor retirado: %d \n\n",x);

        }
        break;

     }



     case 4:{
        int x;
        x=remove_fim_lista( );

        if(x!=0){
            printf("\n\tValor retirado: %d \n\n",x);

        }
        break;

     }


     case 5:{
        int x;

        printf("Informe o valor: ");
        scanf("%d",&x);
        insere_ordenado(x);
        break;
     }

     case 6:{
        int x;
        x=remove_ordenado();

        if(x!=0){
            printf("\n\tValor retirado: %d \n\n",x);

        }
        break;

     }

    case 7:

        mostra_lista();
        break;

     case 8:
       op=8;


    }
 }while(op != 8);


}


int main()
{

    inicializa_lista();

    menu();

    printf("\n\n");
    return 0;
}
