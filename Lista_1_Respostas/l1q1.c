#include <stdio.h>
#include <stdlib.h>

int main( ){
  int soma(int valor_1, int valor_2 );
  
  int valor_1 = 0,
      valor_2 = 0;
      
  enum CONTINUA { NAO = 0, SIM = 1 };
  
  int resposta = SIM; 

  puts("\n");
  do{
    printf( "-> Digite dois valores para saber sua soma\n");
    printf( "   > valor 1 = " );
    scanf( "%d", &valor_1 );
    printf( "   > valor 2 = " );
    scanf( "%d", &valor_2 );

    printf("\n   > ( %+d ) + ( %+d ) = %+d \n", valor_1, valor_2, soma( valor_1, valor_2 ) );
    
    do{
      printf( "\n-> Deseja somar de novo?\n"
              "   [1] SIM       [0] NAO\n\n   > " );
      scanf( "%d", &resposta );
    }while( resposta != NAO && resposta != SIM );

    if( resposta == NAO ){
      printf( "\n   <<< PROGRAMA ENCERRADO >>>" );}

    puts("\n");
  }while( resposta == SIM );
  return 0;
}
int soma( int v_1, int v_2 ){
  return v_1 + v_2;
}