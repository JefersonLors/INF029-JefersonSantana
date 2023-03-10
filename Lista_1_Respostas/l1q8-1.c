#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_NOME 50
#define TAMANHO_CPF 16
#define TAMANHO_NASCIMENTO 12

struct dados{
    char nome[TAMANHO_NOME], 
         cpf[TAMANHO_CPF],
         dataNascimento[TAMANHO_NASCIMENTO],
         sexo;
};

typedef struct dados Dados;

int main( ){
  Dados *cadastrarCliente( void );

  enum CONTINUA { NAO = 0, SIM = 1 };
  int resposta = SIM;
  Dados *cliente = NULL;

  puts("\n");
  do{
    printf( "-> Digite os dados do cliente\n");
    cliente = cadastrarCliente( );
    
    printf( "\n-> Os dados digitados foram\n");
    printf( "   > NOME : %s", cliente->nome );
    printf( "   > CPF : %s", cliente->cpf );
    printf( "   > NASCIMENTO : %s", cliente->dataNascimento );
    printf( "   > SEXO : %c", cliente->sexo );
    puts("\n");

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

Dados *cadastrarCliente( ){
  static Dados cliente;
  
  printf( "   > NOME [Fulano de Sicrano]\n      - " );
  fgets( cliente.nome, TAMANHO_NOME, stdin  );
  printf( "\n   > CPF [xxx.xxx.xxx-xx]\n      - " );
  fgets( cliente.cpf, TAMANHO_CPF, stdin  );
  printf( "\n   > Nascimento [dd/mm/aaaa]\n      - " );
  fgets( cliente.dataNascimento, TAMANHO_NASCIMENTO, stdin  );
  printf( "\n   > Sexo (F/M)\n      - " );
  scanf( "%c", &cliente.sexo ); 
  getchar();
  
  return &cliente;
} 