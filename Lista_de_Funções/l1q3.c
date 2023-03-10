#include <stdio.h>
#include <stdlib.h>

int main( ){
  int fatorial(int valor);
  
  int valor = 0,
      fat = 0;

  enum CONTINUA { NAO = 0, SIM = 1 };
  
  int resposta = SIM; 

  puts("\n");
  do{
    printf( "-> [ Fatorial é um número natural, inteiro e positivo\n"
            "     representado por n!. Assim, seja n = 3\n"
            "     3! = 3.(3-1).(3-2) = 6 ]\n\n");
    
    printf( "-> Digite um número para saber seu fatorial\n");
    printf( "   > numero = " );
    scanf( "%d", &valor );

    fat = fatorial( valor );

    if( fat == 0 ){
      printf("\n   < Não é possível calcular o fatorial deste número\n" );
    }else{ 
      printf("\n   > %d! = %d \n", valor, fat );}

    do{
      printf( "\n-> Deseja obter o fatorial de outro número?\n"
              "       [1] SIM               [0] NAO\n\n   > " );
      scanf( "%d", &resposta );
    }while( resposta != NAO && resposta != SIM );

    if( resposta == NAO ){
      printf( "\n          <<< PROGRAMA ENCERRADO >>>" );}

    puts("\n");
  }while( resposta == SIM );
  return 0;
}

int fatorial( int valor ){
  int fatorial = valor;

  if( valor < 0 ){
    return 0;
  }else if( valor == 0 ){
    return 1; 
  }else{
    while( fatorial > 1 ){
      valor *= --fatorial;}
    return valor;}
}