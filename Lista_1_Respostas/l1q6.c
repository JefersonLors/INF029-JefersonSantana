#include <stdio.h>
#include <stdlib.h>

#define quantidade 3

int main( ){
  char *ler3letras( void );

  enum CONTINUA { NAO = 0, SIM = 1 };
  
  int resposta = SIM;
  char *letras = NULL;

  puts("\n");
  do{
    printf( "-> Digite três números\n");
    letras = ler3numeros( );
    
    printf( "\n-> Os números digitados foram\n");
    for( int subscrito = 0; subscrito < quantidade; subscrito++ ){
      printf( "   > numero [%d] = %d\n", subscrito, numeros[subscrito] );}
    
    do{
      printf( "\n-> Deseja armazenar mais três números?\n"
              "       [1] SIM               [0] NAO\n\n   > " );
      scanf( "%d", &resposta );
    }while( resposta != NAO && resposta != SIM );

    if( resposta == NAO ){
      printf( "\n          <<< PROGRAMA ENCERRADO >>>" );}

    puts("\n");
  }while( resposta == SIM );
  return 0;
}

int *ler3numeros( ){
  static int numero[ quantidade ]; 

  for( int subscrito = 0; subscrito < quantidade; subscrito++ ){
    printf( "   > numero [%d] = ", subscrito );
    scanf( "%d", &numero[subscrito] );}
  return numero;
}