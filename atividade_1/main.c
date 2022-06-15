#include <stdio.h>

//declaração de variavéis globais

int comando = 0;
double vt = 0.0, v1, v2;

void imprimir_comandos (){ //interface da atividade
    printf("\nLista de comandos da calculadora:\n");
    printf("1 Somar\n");
    printf("2 Subtrair\n");
    printf("3 Multiplicar\n");
    printf("4 Dividir\n");
    printf("5 Sair\n");
}


int main(){
    printf("੭* ‧₊° Bem vindo a sua calculadora ੭* ‧₊°\n");

    imprimir_comandos();

    while(1){
        printf("\nDigite o comando desejado:\n");
        scanf("%d", &comando);

        switch(comando){
            case 1: //soma
                printf("Digite os dois valores desejados:\n");
                scanf("%lf %lf", &v1, &v2);

                vt = v1 + v2;

                printf("\nO valor final é: %.2lf\n", vt);
            
                break;

            case 2: //subtração
                printf("Digite os dois valores desejados:\n");
                scanf("%lf %lf", &v1, &v2);

                vt = v1-v2;

                printf("\nO valor final é: %.2lf\n", vt);

                break;

            case 3: //multiplicação
                printf("Digite os dois valores desejados:\n");
                scanf("%lf %lf", &v1, &v2);

                vt = v1*v2;

                printf("\nO valor final é: %.2lf\n", vt);

                break;

            case 4: //divisão
                printf("Digite os dois valores desejados:\n");
                scanf("%lf %lf", &v1, &v2);

                if (v2 == 0){ //verificação da divisão
                    printf("\nNão foi possível realizar a divisão\n");
                }

                else{

                    vt = v1/v2;

                    printf("\nO valor final é: %.2lf\n", vt);
                }

                break;

            case 5: //saída
                printf("\nAções finalizadas\n");
                return 0;

            default:
                printf("\nComando inválido\n");
            }

    imprimir_comandos();

    }

    return 0;
}
