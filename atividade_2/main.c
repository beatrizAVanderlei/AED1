#include <stdio.h> 

#define N 5 //constante de tamanho do vetor

typedef struct{
    char genero;
    float altura;
            
} Pessoa;

float retorno_a(Pessoa pessoas[]){ //altura média das pessoas
    float media, soma = 0.0;
    int i;
    
    for (i = 0; i < N; i++){
        soma = soma + pessoas[i].altura;
        
    }
    
    media = soma/N;
    
    return media;
    
}

float retorno_b(Pessoa pessoas[]){ //buscar a maior altura do vetor
    float maior_altura = 0.0;
    int i;
    
    for (i = 0; i < N; i++){
        if (maior_altura <= pessoas[i].altura){
            maior_altura = pessoas[i].altura;
        }
    }
    
    return maior_altura;
    
}

float retorno_c_m(Pessoa pessoas[]){ //retornar a media de altura das mulheres
    float media, soma = 0.0, qnt_m = 0;
    int i;
    
    for (i = 0; i < N; i++){
        if(pessoas[i].genero == 'm'){
            qnt_m++;
            soma += pessoas[i].altura;
        }
    }
    
    media = soma/qnt_m;
    
    return media;
    
}

float retorno_c_h(Pessoa pessoas[]){ //retornar a media de altura dos homens
    float media, soma = 0.0, qnt_h = 0;
    int i;
    
    for (i = 0; i < N; i++){
        if(pessoas[i].genero == 'h'){
            qnt_h++;
            soma += pessoas[i].altura;
        }
    }
    
    media = soma/qnt_h;
    
    return media;
    
}

int retorno_d(Pessoa pessoas[]){ //quantidade de homens
    int i, qnt_h = 0;
    
    for(i = 0; i < N; i++){
        if(pessoas[i].genero == 'h'){
            qnt_h++;
        }
    }
    
    return qnt_h;
    
}

void alterar_altura(Pessoa *p, float a) {
    p->altura = a;
}

int main(){
    float media, maior_altura, media_m, media_h;
    int qnt_h;
    Pessoa pessoas[N];

    //preenchimento do vetor
    
    pessoas[0].genero = 'm';
    pessoas[0].altura = 1.50;
    pessoas[1].genero = 'm';
    pessoas[1].altura = 1.90;
    pessoas[2].genero = 'h';
    pessoas[2].altura = 1.69;
    pessoas[3].genero = 'h';
    pessoas[3].altura = 1.84;
    pessoas[4].genero = 'm';
    pessoas[4].altura = 1.10;
    
    media = retorno_a(pessoas);
    maior_altura = retorno_b(pessoas);
    media_m = retorno_c_m(pessoas);
    media_h = retorno_c_h(pessoas);
    qnt_h = retorno_d(pessoas);
    
    printf("A média de alturas é: %.2f\n", media);
    printf("A média de altura das mulheres é: %.2f\n", media_m);
    printf("A média de altura dos homens é: %.2f\n", media_h);
    printf("A maior altura é: %.2f\n", maior_altura);
    printf("A quantidade de homens no vetor é: %d\n", qnt_h);
    
    alterar_altura(&pessoas[3], 1.99);
    
    media = retorno_a(pessoas);
    maior_altura = retorno_b(pessoas);
    media_m = retorno_c_m(pessoas);
    media_h = retorno_c_h(pessoas);
    
    printf("\nA média de alturas é: %.2f\n", media);
    printf("A média de altura das mulheres é: %.2f\n", media_m);
    printf("A média de altura dos homens é: %.2f\n", media_h);
    printf("A maior altura é: %.2f\n", maior_altura);
    
    return 0;
}
