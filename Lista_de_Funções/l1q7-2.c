#include <stdio.h>
#include <stdlib.h>

#define quantidade 3
#define TAMANHO 20

int main( ){
  char **ler3palavras( void );
  
  char **palavras = NULL;
  enum CONTINUA { NAO = 0, SIM = 1 };
  int resposta = SIM;
  
  puts("\n");
  do{
    printf( "-> Digite três palavras\n");
    palavras = ler3palavras( );
    
    printf( "\n-> As palavras foram\n");
    for( int local = 0; local < quantidade; local++ ){
      printf( "   > palavra [%d] = %s\n", local, palavras[local] );}
    
    do{
      printf( "\n-> Deseja armazenar mais três palavras?\n"
              "       [1] SIM               [0] NAO\n\n   > " );
      scanf( "%d", &resposta );
    }while( resposta != NAO && resposta != SIM );

    if( resposta == NAO ){
      printf( "\n          <<< PROGRAMA ENCERRADO >>>" );}

    puts("\n");
  }while( resposta == SIM );
  return 0;
}

char **ler3palavras( ){
  static char palavra_1[TAMANHO],  
       palavra_2[TAMANHO], 
       palavra_3[TAMANHO];
  static char *palavras[quantidade] = { palavra_1, palavra_2, palavra_3 };

  for( int local = 0; local < quantidade; local++ ){
    printf( "   > palavra [%d] = ", local );
    scanf( "%s", palavras[local]);}

  
  return palavras;
} 