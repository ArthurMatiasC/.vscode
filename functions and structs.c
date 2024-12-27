#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main (){

   struct dadosCadastrais{
    // nome altura, peso, CPF e sexo
    char nome[10]; 
    char CPF[15];
    float altura;
    int peso;
    char sexualidade;

   } pessoa[2];
   // deve haver um jeito de chamar cada dado cadastral usando funcoes !!

   for(int i = 0; i < 2; i++){

   printf("*Bem vindo a tela de login !!*");
   printf("\n\n Dados cadastrais:\n1. Nome: ");
   scanf(" %s", &pessoa[i].nome); 
   getchar();
   printf("\n2. CPF: ");
   scanf(" %s", &pessoa[i].CPF);
   printf("\n3. Altura: ");
   scanf(" %f", &pessoa[i].altura);
   printf("\n4. Peso (em Kg): ");
   scanf(" %i", &pessoa[i].peso);
   
   float IMC = pessoa[i].altura/pessoa[i].peso;

   printf("\n\nEsse eh o seu IMC: %f", IMC);

   printf("\n%f\n\n", pessoa[i].altura);

   }
 

 printf("%i %f", pessoa[1].peso, pessoa[2].altura);



    return 0;
}