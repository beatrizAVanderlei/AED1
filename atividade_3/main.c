#include <stdio.h>
#include <string.h>
#include <ctype.h>

int conta_char (char* str, char c){ //contar a quantidade de um caracter especifico de uma string
    int i, qnt = 0;
    
    for (i = 0; str[i] != '\0'; i++){
        if ((str[i] == toupper(c)) || (str[i] == tolower(c))){
            qnt++;
        }
        
    }
    return qnt;
}

int conta_vogais (char* str){ //contar a quantidad de vogais presentes na string
    int i, qnt = 0;
    
    for (i = 0; str[i] != '\0'; i++){
        if ((str[i] == 'a') || (str[i] == 'A') || (str[i] == 'e') || (str[i] == 'E') || (str[i] == 'i') || (str[i] == 'I') || (str[i] == 'o') || (str[i] == 'O') || (str[i] == 'u') || (str[i] == 'U')){
            qnt++;
        }
    }
    return qnt;
}

int main(){
    char string[256];
    char caracter;
    int vogais, qnt_caracteres;
    
    printf("Insira a sua string:\n");
    scanf("%[^\n]", string);
    getchar();
    printf("Insira o caracter que deseja procurar:\n");
    scanf("%c", &caracter);
    
    
    vogais = conta_vogais(string);
    qnt_caracteres = conta_char(string, caracter);
    
    printf ("\n➜ A string %s possuí a letra %c %d veze(s)\n", string, caracter, qnt_caracteres);
    printf ("➜ A string %s possuí %d vogais\n", string, vogais);
    
    return 0;
}
