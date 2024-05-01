//Usando pilha
#include<conio.h>
#include<stdio.h>
#include<windows.h>



struct no{
    int valor;
    no *anterior;
};

no *topo;


void pilhavazia(){
    topo=NULL;
}//fecha pilhavazia

void empilha(int pvalor){
    no *novo;
    novo= (no*)malloc(sizeof(no));    
    novo->valor=pvalor;
    novo->anterior=topo;
    topo=novo;

    
//Novo nó (anterior) aponta para topo;
//Topo aponta para o novo nó


    printf("Elemento %d inserido com sucesso",novo->valor);
    getch();
    system("cls");
}//fecha empilha


void mostra(){
    no *aux=topo;
    if(topo== NULL){
    	printf("A pilha esta vazia!");
	}else{
		while(aux!=NULL){
	        printf("\n%d",aux->valor);
	        aux=aux->anterior;
    	}//fecha while	
	}
    
    getch();
    system("cls");
    
}//fecha mostra


void excluirTudo(){
    no *aux=topo;
    while(aux!=NULL){
        topo=aux->anterior;
        free(aux);
        aux=topo;
    }//fecha while
    printf("Pilha excluida com sucesso");
    getch();
    system("cls");
}//fim excluir

void excluirTopo(){
    no *aux=topo;
    
        topo=aux->anterior;
        free(aux);
        aux=topo;
    printf("Topo excluido com sucesso");
    getch();
    system("cls");
}//fim excluir


main(){
    int valor,op;
    
    do{
        printf("Escolha uma op��o");
        printf("\nDigite 0 para sair");
        printf("\nDigite 1 para inserir");
        printf("\nDigite 2 para mostrar a pilha");
        printf("\nDigite 3 para exibir o valor do topo");
        printf("\nDigite 4 para excluir toda pilha");
        printf("\nDigite 5 para exclui topo da pilha");
        scanf("%d",&op);
        
        switch(op){
                
                case 1: 
                    printf("Digite o valor que deseja inserir: ");
                    scanf("%d",&valor);
                    empilha(valor);
                    break;
                    
                case 2:
                    mostra();
                    break;
                case 3:
                    printf("\n%d",topo->valor);
                    getch();
                    system("cls");
                    break;
                case 4:
                    excluirTudo();
                    break;
                case 5: 
                	excluirTopo();
                	break;
                    
        }//fecha switch
        
    }while(op!=0);
    
    
}//fecha main
