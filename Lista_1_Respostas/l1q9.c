#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAMANHO_NOME 20
#define TAMANHO_CPF 20
#define TAMANHO_NASCIMENTO 15
#define TAMANHO_SEXO 4

#define bool _Bool
#define true 1
#define false 0

struct{
    char nome[TAMANHO_NOME],
         cpf[TAMANHO_CPF],
         dataNascimento[TAMANHO_NASCIMENTO],
         sexo[TAMANHO_SEXO];
}cliente;

int main( ){
  bool cadastrarCliente( void ); ///deve devolver bool

  enum CONTINUA { NAO = 0, SIM = 1 };
  int resposta = SIM;

  puts("\n");
  do{
    printf( "-> Digite os dados do cliente\n");
    if( cadastrarCliente( ) ){
      printf( "\t\tCADASTRO FINALIZADO COM SUCESSO!!" );
      printf( "\n-> Os dados digitados foram\n");
      printf( "   > NOME : %s", cliente.nome );
      printf( "   > CPF : %s", cliente.cpf );
      printf( "   > NASCIMENTO : %s", cliente.dataNascimento );
      printf( "   > SEXO : %s\n\n", cliente.sexo );
    
      do{
        printf( "\n-> Deseja cadastrar mais um cliente?\n"
                "     [1] SIM               [0] NAO\n\n   > " );
        scanf( "%d", &resposta );
        getchar();
      }while( resposta != NAO && resposta != SIM );  
    }else{
      printf( "ops! O cliente não foi cadastrado!" );
      do{
        printf( "\n-> Deseja tentar novamente?\n"
                "     [1] SIM               [0] NAO\n\n   > " );
        scanf( "%d", &resposta );
        getchar();
      }while( resposta != NAO && resposta != SIM );
    }

    if( resposta == NAO ){
      printf( "\n          <<< PROGRAMA ENCERRADO >>>" );}

    puts("\n");
  }while( resposta == SIM );
  return 0;
}

bool cadastrarCliente( ){
  char *mensagemDeErro;

  char *validaNome( char* );
  char *validaCpf( char* );
  char *validaNascimento( char* );
  char *validaSexo( char* );

  do{ ///incluir teste de saida
    printf( "\n   > NOME [Fulano de Sicrano]\n      - " );
    fgets( cliente.nome, TAMANHO_NOME, stdin  );
    mensagemDeErro = validaNome( cliente.nome );
    if( mensagemDeErro != NULL ){
      puts( mensagemDeErro );}
  }while( mensagemDeErro != NULL );

  do{
    printf( "\n   > CPF [xxx.xxx.xxx-xx]\n      - " );
    fgets( cliente.cpf, TAMANHO_CPF, stdin  );
    mensagemDeErro = validaCpf( cliente.cpf );
    if( mensagemDeErro != NULL ){
      puts( mensagemDeErro );}
  }while( mensagemDeErro != NULL );

  do{
    printf( "\n   > Nascimento [dd/mm/aaaa]\n      - " );
    fgets( cliente.dataNascimento, TAMANHO_NASCIMENTO, stdin  );
    mensagemDeErro = validaNascimento( cliente.dataNascimento );
    if( mensagemDeErro != NULL ){
      puts( mensagemDeErro );}
  }while( mensagemDeErro != NULL );

  do{
    printf( "\n   > Sexo (F/M/O)\n      - " );
    fgets( cliente.sexo, TAMANHO_SEXO, stdin );
    mensagemDeErro = validaSexo( cliente.sexo );
    if( mensagemDeErro != NULL ){
      puts( mensagemDeErro );}
  }while( mensagemDeErro != NULL );

  return true;
}

char *validaNome( char *nome ){
  char *erro = NULL;

  for( int letra = 0; nome[letra] != '\0'; letra++ ){
    if ( (isalpha(nome[letra]) == 0) && (nome[letra] != '\n') && (nome[letra] != ' ') ){
      erro = "\t\t^ Esse nome é inválido! Utilize apenas letras.";
      break;}}

  return erro;
}
char *validaCpf( char *cpf ){
  static char *erro = NULL;

  if( !(cpf[3] == '.') || !(cpf[7] == '.') || !(cpf[11] == '-') ){///MELHORAR VERIFICAO DE FORMATO
    erro = "\t\t^ Esse cpf é inválido! Atente-se ao formato.";
  }else{
    for( int digito = 0; cpf[digito] != '\0'; digito++ ){
      if( digito != 3 && digito != 7 && digito != 11 && isdigit(cpf[digito]) == 0 && cpf[digito] != '\n' ){
        erro = "\t\t^ Esse cpf é inválido! Utilize apenas números.";
        break;}}
        erro = NULL;}

  return erro;
}
char *validaNascimento( char *nascimento ){
  static char *erro = NULL;

  if( !(nascimento[2] == '/') || !(nascimento[5] == '/') ){ ///MELHORAR VERIFICAO DE FORMATO
    erro = "\t\t^ Essa data é inválida! Atente-se ao formato.";
  }else{
    if( ((nascimento[0] == '0') && (nascimento[1] == '0')) || (nascimento[0] > '3') ||
        ((nascimento[0] == '3') && (nascimento[1] > '1')) ) {
      erro = "\t\t^ Essa data é inválida! Esse dia é inválido.";
    }else if( ((nascimento[3] == '0') && (nascimento[4] == '0')) || (nascimento[3] > '2') ||
              ((nascimento[3] == '1') && (nascimento[4] > '2')) ){
      erro = "\t\t^ Essa data é inválida! Esse mês é inválido.";
    }else if( (nascimento[6] > '2') || ((nascimento[6] == '2') && (nascimento[7] > '0')) ||
              ((nascimento[7] == '0') && (nascimento[8] > '2')) || ((nascimento[8] == '2') && (nascimento[9] > '2') )){
      erro = "\t\t^ Essa data é inválida! A pessoa nasceu no futuro?";
    }else if( (nascimento[6] == '0') || ((nascimento[7] < '9') && (nascimento[7] != '0')) ){
      erro = "\t\t^ Essa data é inválida! A pessoa está morta.";
    }else{
      for( int digito = 0; nascimento[digito] != '\0'; digito++ ){
        if( (digito != 2) && (digito != 5) && (isdigit(nascimento[digito]) == 0) && (nascimento[digito] != '\n') ){
          erro = "\t\t^ Essa data é inválida! Utilize apenas números.";
          break;}}
      erro = NULL;}}

  return erro;
}
char *validaSexo( char *sexo ){
  static char *erro =  NULL;

  if( (tolower(sexo[0]) != 'f') && (tolower(sexo[0]) != 'm') && (tolower(sexo[0]) != 'o') ){
     erro = "\t\t^ Essa opção é inválida! Digite f ou m.";}
  else{
    erro = NULL;}

  return erro;
}