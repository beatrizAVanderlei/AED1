#include <stdlib.h>
#include <stdio.h> 

typedef struct lista{
    int info;
    struct lista* prox;
} Lista;

Lista* inicializa(void){ //inicializar a lista
    return NULL;
}

Lista* inserir(Lista* l, int i){ //inserir elementos da lista
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo -> info = i;
    novo -> prox = l;
    
    return novo;
}

void imprimir(Lista* l){ //imprimir a lista
    Lista* p; 
    printf("{");
    for(p = l; p != NULL; p = p -> prox)
        printf(" %d ", p -> info);
    printf("}\n");
}
    
Lista* busca(Lista* l, int v){ //buscar um elemento na lista
    Lista* p;
    for(p = l; p != NULL; p = p -> prox){
        if(p -> info == v){
            return p;
        }
    }
    
    return NULL;
}

Lista* remover(Lista* l, int v){ //remover um elemento da lista
    Lista* ant = NULL;
    Lista* p = l;
    
    while((p != NULL) && (p -> info != v)){ //busca do elemento
        ant = p;
        p = p -> prox;
    }
    
    if(p == NULL)
        return l; //não tem o elemento
        
    if(ant == NULL)
        l = p -> prox;
    
    else
        ant -> prox = p -> prox;
    
    free(p);
    return l;
}

Lista* concatena(Lista* L1, Lista* L2){ //concatenação das listas
    Lista* l = inicializa(); //lista auxiliar
    Lista* p;
    
    for(p = L1; p != NULL; p = p -> prox){
        l = inserir(l, p -> info);
    }
    for(p = L2; p != NULL; p = p -> prox){
        l = inserir(l, p -> info);
    }
    
    return l;
}

void liberar(Lista* l){ //liberar espaço de memoria da lista
    Lista* prox = NULL;
    Lista* p;
    
    for(p = l; p != NULL; p = prox){
        prox = p -> prox;
        free(p);
    }
}

int main(){
    Lista* l1;
    Lista* l2;
    Lista* l;

    //inicializando as listas
    
    l1 = inicializa();
    l2 = inicializa();

    //inserindo elementos nas listas
    
    l1 = inserir(l1, 5);
    l1 = inserir(l1, 2);
    l1 = inserir(l1, 1);
    l2 = inserir(l2, 8);
    l2 = inserir(l2, 9);
    l2 = inserir(l2, 0);
    
    l = concatena(l1, l2);
    
    printf("l1 = ");
    imprimir(l1);
    printf("l2 = ");
    imprimir(l2);
    printf("l = ");
    imprimir(l);

    //liberando o espaço de memoria
    
    liberar(l1);
    liberar(l2);
    liberar(l);
    
    return 0;
}
