#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_NOME 50
#define TAMANHO_CPF 17
#define TAMANHO_NASCIMENTO 13
#define TAMANHO_SEXO 4  

int main( ){
  char **cadastrarCliente( void );

  enum CONTINUA { NAO = 0, SIM = 1 };
  int resposta = SIM;
  char **dado = NULL;

  puts("\n");
  do{
    printf( "-> Digite os dados do cliente\n" );
    dado = cadastrarCliente( );
    
    printf( "\n-> Os dados digitados foram\n" );
    printf( "   > NOME : %s", dado[0] );
    printf( "   > CPF : %s", dado[1] );
    printf( "   > NASCIMENTO : %s", dado[2] );
    printf( "   > SEXO : %s\n\n", dado[3] );

    do{
      printf( "\n-> Deseja cadastrar mais um cliente?\n"
              "     [1] SIM               [0] NAO\n\n   > " );
      scanf( "%d", &resposta );
      getchar();
    }while( resposta != NAO && resposta != SIM );

    if( resposta == NAO ){
      printf( "\n          <<< PROGRAMA ENCERRADO >>>" );}

    puts("\n");
  }while( resposta == SIM );
  return 0;
}

char **cadastrarCliente( ){
  static char nome[TAMANHO_NOME], 
              cpf[TAMANHO_CPF],
              dataNascimento[TAMANHO_NASCIMENTO],
              sexo[TAMANHO_SEXO];
  static char *dados[] = { nome, cpf, dataNascimento, sexo };
  
  printf( "   > NOME [Fulano de Sicrano]\n      - " );
  fgets( nome, TAMANHO_NOME, stdin  );
  printf( "\n   > CPF [xxx.xxx.xxx-xx]\n      - " );
  fgets( cpf, TAMANHO_CPF, stdin  );
  printf( "\n   > Nascimento [dd/mm/aaaa]\n      - " );
  fgets( dataNascimento, TAMANHO_NASCIMENTO, stdin  );
  printf( "\n   > Sexo (F/M/0)\n      - " );
  fgets( sexo, TAMANHO_SEXO, stdin );

  return dados;
} 