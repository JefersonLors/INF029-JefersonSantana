#include <stdio.h>
#include <stdlib.h>

#define quantidade 3

struct palavras{
    char palavra[50];
};

typedef struct palavras Palavras;

int main( ){
  Palavras *ler3palavras( void );

  enum CONTINUA { NAO = 0, SIM = 1 };
  int resposta = SIM;
  Palavras *palavras = NULL;

  puts("\n");
  do{
    printf( "-> Digite três palavras\n");
    palavras = ler3palavras( );
    
    printf( "\n-> As palavras foram\n");
    for( int local = 0; local < quantidade; local++ ){
      printf( "   > palavra [%d] = %s\n", local, palavras[local].palavra );}
    
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

Palavras *ler3palavras( ){
  static Palavras armazem[quantidade];

  for( int local = 0; local < quantidade; local++ ){
    printf( "   > palavra [%d] = ", local );
    scanf( "%s", armazem[local].palavra );}
  return armazem;
} 