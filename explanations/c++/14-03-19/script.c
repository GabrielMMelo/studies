#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<locale.h>

typedef struct{
    char nome;
    int matricula;
    float notas[4];
    float notasFinais;
}Aluno;

int main() {

    int tam = 3;
    Aluno alunos[tam];
    float media = 0;
    float mediaFinal[4];

    printf("\nDigite o nome do aluno ");

    for (int i=0;i<tam;i++){		
       printf("\nNome \n");
       scanf("%s",&alunos[i].nome);
       printf("\nEscreva a matricula \n");
       scanf("%i",&alunos[i].matricula);
    }
        

    for (int i=0;i<tam;i++){
        printf("Nome: %s ",alunos[i].nome);// essa linha me buga, aqui ta sem o '&'
        // printf("Nome: %s\n",&alunos[i].nome);// essa linha me buga, aqui ta com o '&'
        printf("A matricula eh: %i\n\n",alunos[i].matricula);
    }

    printf("\nEscreva as 4 notas do aluno \n");	

    getchar();
    printf("\n\n");
    system("pause");
    return(0);	
}
