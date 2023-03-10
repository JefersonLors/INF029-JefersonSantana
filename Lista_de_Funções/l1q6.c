#include <stdio.h>
#include <stdlib.h>

#define quantidade 4

int main( ){
  char *ler3letras( void );

  enum CONTINUA { NAO = 0, SIM = 1 };
  
  int resposta = SIM;
  char *letras = NULL;

  puts("\n");
  do{
    printf( "-> Digite três letras\n");
    letras = ler3letras( );
    
    printf( "\n-> As letras digitadas foram\n");
    for( int subscrito = 0; subscrito < (quantidade - 1); subscrito++ ){
      printf( "   > letra [%d] = %c\n", subscrito, letras[subscrito] );}
    
    do{
      printf( "\n-> Deseja armazenar mais três letras?\n"
              "       [1] SIM               [0] NAO\n\n   > " );
      scanf( "%d", &resposta );
      getchar( );
    }while( resposta != NAO && resposta != SIM );

    if( resposta == NAO ){
      printf( "\n          <<< PROGRAMA ENCERRADO >>>" );}

    puts("\n");
  }while( resposta == SIM );
  return 0;
}

char *ler3letras( ){
  static char letras[ quantidade ] = {' ',' ',' ','\0'}; 

  for( int subscrito = 0; subscrito < (quantidade - 1); subscrito++ ){
    printf( "   > letra [%d] = ", subscrito );
    scanf( "%c", &letras[subscrito] );
    getchar();}
  return letras;
}