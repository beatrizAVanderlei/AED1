#include <stdlib.h>
#include <stdio.h> 

#define N 10 //tamanho padrão do vetor

void menu(){ //interface
    printf("Menu:\n");
    printf("1 - Consultar vetor\n");
    printf("2 - Remover elemento\n");
    printf("3 - Sair\n");
}

int existe(int tamanho, int valor, int v[]){ //verificar se o elemento existe no vettor
     int cont = 0;
     int i;

     for(i = 0; i < tamanho; i++){
          if(valor == v[i])
               cont++;
     }

     return cont;
}

void remover(int tamanho, int posicao, int v[]){ //remover um elemento do vetor
    int i;
    int j = tamanho - 1;
    int aux;
    
    for(i = 0; i < tamanho; i++){
        if(i == posicao){
            v[i] = 0;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;        }
    }
    
    for(i = posicao; i < j - 1; i++){
        aux = v[i];
        v[i] = v[i+1];
        v[i+1] = aux;
    }
}

void imprimir(int tamanho, int v[]){ //imprimir o vetor
    int i;

    printf("✧･ﾟVetor: ");

    for (i = 0; i < N; i++){
       printf ("%d ", v[i]);
    }
       printf ("\n");
}

void ordenar(int tamanho, int v[]){
    int maior = 0;
    int menor = 0;
    int i;
    int j = 0;
    int k = tamanho - 1;
    int aux;
    
    while(j < k){ //ordenação do vetor
    
        for(i = j; i <= k; i++){
            if(i == j){
               maior = j;
            }
            if(v[i] >= v[maior]){
                maior = i;
            }
          
        }
        
        aux = v[maior];
        v[maior] = v[j];
        v[j] = aux;
        j++;
        
        
        for(i = j; i <= k; i++){
            if(i == j){
               menor = j;
            }
            if(v[i] <= v[menor]){
                menor = i;
            }
          
        }
        
        aux = v[menor];
        v[menor] = v[k];
        v[k] = aux;
        k--;
     
    }
} 

int main(){
    int v[N] = {90, 3, 54, 78, 9, 85, 2, 5, 11, 1}; //preenchimento do vetor
    int comando;
    int valor;
    int posicao;
    
    ordenar(N, v);
    
    menu();
    
    printf("\nDigite o comando desejado: \n");
    scanf("%d", &comando);
    
    while(comando <= 3){
        if(comando == 1)
            imprimir(N, v);
        if(comando == 2){
            printf("Insira o elemento que deseja remover: \n");
            scanf("%d", &valor);

            int verificar = existe(N, valor, v); //verificar se o valor escolhido existe no vetor para remover

            if(verificar != 0){

               for(int i = 0; i < N; i++){
                    if(v[i] == valor)
                         posicao = i;
               }
            
               remover(N, posicao, v);
               imprimir(N, v);

               break;

            }

            else{
               printf("O valor escolhido não existe no vetor\n");
               break;
            }

        }
        if(comando == 3){
            printf("Ações finalizadas :)\n");
            return 0;
        }
        
        printf("\nDigite o comando desejado: \n");
        scanf("%d", &comando);
    }
    
    return 0;
}

