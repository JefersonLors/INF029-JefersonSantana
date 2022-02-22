#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAMANHO_NOME 20
#define TAMANHO_CPF 20
#define TAMANHO_NASCIMENTO 15

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
  char *mensagemDeErro;

  char *validaNome( char* );
  char *validaCpf( char* );
  char *validaNascimento( char* );
  char *validaSexo( char );

  do{
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
    printf( "\n   > Sexo (F/M)\n      - " );
    scanf( "%c", &cliente.sexo );
    getchar();
    mensagemDeErro = validaSexo( cliente.sexo );
    if( mensagemDeErro != NULL ){
      puts( mensagemDeErro );}
  }while( mensagemDeErro != NULL );

  return &cliente;
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

  if( !(cpf[3] == '.') || !(cpf[7] == '.') || !(cpf[11] == '-') ){
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

  if( !(nascimento[2] == '/') || !(nascimento[5] == '/') ){
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
char *validaSexo( char sexo ){
  static char *erro =  NULL;

  if( (tolower(sexo) != 'f') && (tolower(sexo) != 'm') ){
     erro = "\t\t^ Essa opção é inválida! Digite f ou m.";}
  else{
    erro = NULL;}

  return erro;
}

/// cd Lista_1_Respostas
/// gcc l1q9.c -o l1q9
/// ./l1q9
