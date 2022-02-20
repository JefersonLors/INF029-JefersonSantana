#include <stdio.h>
#include <stdlib.h>

#define quantidade 4

struct numeros{
    int armazenados[quantidade];
};

typedef struct numeros Numeros;

int main( ){
  Numeros *ler4numeros( void );

  enum CONTINUA { NAO = 0, SIM = 1 };
  
  int resposta = SIM;
  
  Numeros *valores = NULL;

  puts("\n");
  do{
    printf( "-> Digite quatro números\n");
    valores = ler4numeros( );
    
    printf( "\n-> Os números digitados foram\n");
    for( int numero = 0; numero < quantidade; numero++ ){
      printf( "   > numero [%d] = %d\n", numero, valores->armazenados[numero] );}
    
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

Numeros *ler4numeros( ){
  static Numeros inteiros;

  for( int numero = 0; numero < quantidade; numero++ ){
    printf( "   > numero [%d] = ", numero );
    scanf( "%d", &inteiros.armazenados[numero] );}
  return &inteiros;
}