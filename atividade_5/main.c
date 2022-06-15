#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <ctype.h>

#define N 20 //constante que indica o tamanho do vetor

int comparai(char *str1, char *str2) {
    char *t1, *t2;
    int i, resultado;
    t1 = strdup(str1);
    t2 = strdup(str2);
    
    for(i =0; t1[i] != '\0'; i++) {
        t1[i] = toupper(t1[i]);
    }
    for(i =0; t2[i] != '\0'; i++) {
        t2[i] = toupper(t2[i]);
    }
    resultado = strcmp(t1, t2);
    
    free(t1);
    free(t2);
    
    return resultado;
 
}

void intercala(int p, int q, int r, char **v){
    char **w;                               
    w = (char **) malloc ((r-p) * sizeof (char*));
    int i = p, j = q;                      
    int k = 0;
    
    for(i=0; i< (r-p); i++){
        w[i] = (char *) malloc (sizeof(char) * 50);
    }
    
    i = p;

    while (i < q && j < r) {               
        if (comparai(v[i], v[j]) >= 0)  {
            strcpy(w[k++], v[i++]);  
        }
        else  {
            strcpy(w[k++], v[j++]); 
        }
   }   
   
    while (i < q)  {
        strcpy(w[k++], v[i++]); 
    }
    
    while (j < r) {
        strcpy(w[k++], v[j++]); 
    }
    
    for (i = p; i < r; i++)  {
        strcpy(v[i], w[i-p]);
    }
    
    for(i=0; i < (r-p); i++)
         free(w[i]);  
}

void mergesort(int p, int r, char **v){ //algoritmo de ordenação
    if(p < r-1){
        int q = (p+r)/2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}


int main(){
    
    char **v;
    int i;
    
    v = (char **) malloc(sizeof(char*) * N);

    for(i=0; i < N; i++){ //alocando espaço de memória
        v[i] = (char *) malloc (sizeof(char) * 50);
    }

    //preenchendo o vetor
    
    strcpy(v[0], "São Paulo");
    strcpy(v[1], "São Carlos");
    strcpy(v[2], "nova York"); 
    strcpy(v[3], "Nova Iguaçu");
    strcpy(v[4], "Paulo Afonso");
    strcpy(v[5], "rio De Janeiro");
    strcpy(v[6], "Recife");
    strcpy(v[7], "Florianopolis");
    strcpy(v[8], "Tokyo");
    strcpy(v[9], "san Francisco");
    strcpy(v[10], "Buenos Aries");
    strcpy(v[11], "Paris");
    strcpy(v[12], "Londres");
    strcpy(v[13], "Manaus");
    strcpy(v[14], "Sorocaba");
    strcpy(v[15], "Muriae");
    strcpy(v[16], "Salvador");
    strcpy(v[17], "Zacarias");
    strcpy(v[18], "são paulo");
    strcpy(v[19], "alagoas");
    
    mergesort(0, N, v);
        
    for(int i = 0; i < N; i++){
        printf("%s\n", v[i]);
    }

    //liberando memória

    free(v);
    
    return 0;
}
