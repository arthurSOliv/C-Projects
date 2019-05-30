#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
 int item;
 struct pilha *ant;
}pilha;

int contador;
pilha *nova_celula;
pilha *topo;
int valor;

void menu(){
 int op;  //opção recursiva


 do{
     printf("\n");
     printf("1 - Empilhar \n");
     printf("2 - Desempilhar \n");
     printf("3 - Mostrar tamanho \n");
     printf("4 - Sair \n ");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){
     case 1:
      insere_pilha();
      break;

     case 2:
        printf("Valor retirado: %d",desempilha());
        break;
     case 3:

        printf("\n\t Tamanho pilha = %d",tamanho_pilha());
        break;

     case 4:
        op=4;

    }

 }while(op != 4);


}


void inicializa_pilha(){
    topo=NULL;
    contador =0;
}

bool pilha_vazia(){
    if(topo == NULL){
        return true;
    }else{
        return false;
    }
}

int tamanho_pilha(){
    return contador;
}

void insere_pilha(){

    int valor;

    system("cls");
    printf("Informe o valor: >_");
    scanf("%d",&valor);

    nova_celula =(pilha *)malloc(sizeof(pilha));

    if(nova_celula == NULL){
       printf("Erro: espaco insuficiente!!");

    }else{

        nova_celula->item = valor; //insere o valor na nova célula
        nova_celula->ant = topo;  //prox recebe o valor da célula de baixo

        topo= nova_celula;  //topo aponta para o endereço da nova célula

        contador++;

    }
}

int desempilha( ){

    int valor;

    pilha *temp; //variavel temporaria para não perder o topo

    if(pilha_vazia()){

       printf("\n Pilha vazia!!!\n");
       return 0;

    }else{

        valor =topo->item; //variavel recebe o valor do item
        temp = topo;       //variavel temporaria recebe o topo para não perder
        topo=topo->ant;   //topo aponta pra celula de baixo

        free(temp);

        contador--; //tira o valor do contador
        return valor; //diz que deu tudo certo

    }
}

int elemento_topo(){//obtem o elemento topo da pilha

    int valor;

    if(pilha_vazia()){

       printf("Pilha vazia!!!");
       return 0;

     }else{
        valor=topo->item;
        return valor;
     }


}

//finalia pilha por questão de segurança
int finaliza_pilha(){

    pilha *temp;     //variavel temporaria

     if(pilha_vazia()){ //so limpa a pilha se tiver elementos para limpar

       printf("Pilha vazia!!!");
       return 0;

     }else{

        while(topo !=NULL){
            temp=topo; //variavel temporaria recebe topo para não perder o topo
            temp->ant = NULL;  //Desconecta a célula de cima da de baixo //celula aponta pra null
            topo=topo->ant;

            free(temp);

        }

        contador=0;
        return 1;

     }
}


int main()
{

    inicializa_pilha();

    menu();


    printf("\n\n");






    return 0;
}
