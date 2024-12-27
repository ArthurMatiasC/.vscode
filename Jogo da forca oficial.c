#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool letraDiferente(char letraDigitada, char Pal1[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (letraDigitada == Pal1[i]) {
            return false; // A letra digitada é igual a um dos elementos
        }
    }
    return true; // A letra digitada é diferente de todos os elementos
}

int main() {
   
   char Nu1[15], Nu2[15], Pal[20], letrasJaDigitadas[15], letraDigitada, letrasCJaDigitadas[15]; //Pal1 e 2 com size 4
   int vitoria = 0, NumTentativas = 15, n1 = 10;
   
   printf("*Bem vindo ao jogo da forca !!*");
   printf("\n\nDigitem seus nomes de usuario: ");
   scanf(" %s", Nu1);  // O espaço antes do %s consome possíveis espaços ou novas linhas
   scanf(" %s", Nu2);
   // eh possivel a criacao de um banco de dados com varias palavras, ou a digitacao de uma unica palavra, ou ainda uma palavra ja inserida no codigo.
   printf("\nDigite uma palavra, o segundo participante deve acerta-la (a palavra deve conter ate 6 caracteres):");
   scanf(" %s", Pal);
   
   memset(letrasJaDigitadas, ' ', n1);
   memset(letrasCJaDigitadas, ' ', n1);

   int tamanho = strlen(Pal);

   char dica[tamanho];

   for(int i = 0; i < tamanho; i++){
    dica[i] = '_';
   }

   while(vitoria != tamanho && NumTentativas > 0){
   
   //printf("%c", letrasCJaDigitadas[1]);
   for(int i = 0; i < tamanho; i++){
    printf(" %c ", dica[i]);
   }
   printf("\nNumero de tentativas:%i", NumTentativas);
   
   if(letrasJaDigitadas[0] != ' '){
      printf("\n\nLetras ja digitadas: ");
      for(int i = 0; i < n1; i++){
        printf("%c", letrasJaDigitadas[i]);
      }
   }
   
   printf("\nUsuario %s, digite uma letra: ", Nu1);
   scanf(" %c", &letraDigitada);
   getchar();

   bool letraCorreta = false;

   // Alteracoes principais no codigo: agora ha um input da palavra, que tem ate 20 caracteres
   for(int i = 0; i < tamanho; i++){
        int letraRepetida = 0;
       for(int f = 0; f < n1; f++){
           if(letrasJaDigitadas[f] == letraDigitada || letrasCJaDigitadas[f] == letraDigitada){
               printf("\nLetra invalida !!\n");
               letraDigitada = '\0';
               letraRepetida = 1;
               break;
           }
       }
       if(letraRepetida) continue;
   }
      for(int i = 0; i < tamanho; i++){
        if(Pal[i] == letraDigitada){
           dica[i] = letraDigitada;
           letraCorreta = true;
           vitoria++;
           for(int g = 0; g < n1; g++){
               if(letrasCJaDigitadas[g] == ' '){
                letrasCJaDigitadas[g] = letraDigitada;
                break;
               } 
           }
           
        } 
       }

       if (letraCorreta == true) {
           printf("\nLetra correta!\n");
           NumTentativas--;
           for(int g = 0; g < n1; g++){
               if(letrasCJaDigitadas[g] == ' '){
                letrasCJaDigitadas[g] = letraDigitada;
                break;
               } 
           }
       }   
       else{
           printf("\na letra nao faz parte da palavra !!\n");
           NumTentativas--;
           for(int g = 0; g < n1; g++){
               if(letrasJaDigitadas[g] == ' '){
                letrasJaDigitadas[g] = letraDigitada;
                break;
               } 
            }
        }
        //quando letraDigitada e diferente de Pal[1,2,3], printf("Nao faz parte da palavra !!");
   
     
    letraDigitada = '\0';
 }
   
   if(vitoria == tamanho){
       printf("\n\nparabens %s, Voce acertou a palavra !!", Nu1);
   }
   else if(NumTentativas == 0){
       printf("\n\nAcabaram as tentativas para %s!!", Nu1);
   }

  return 0;
  
}  