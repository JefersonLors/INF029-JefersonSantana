#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO_NOME 30
#define TAMANHO_CPF 20
#define TAMANHO_NASCIMENTO 14
#define TAMANHO_SEXO 7

bool caracterNumerico( char caracter ){
  if( caracter >= '0' && caracter <= '9' )
    return true;
  else return false;
}
char diminuiTamanho( char letra ){
  if( letra >= 'a' && letra <= 'z' )
    return letra;
  else return (letra + 32);
}
bool verificaSaida( char sinal, char numero ){
  if( sinal == '-' && numero == '1')
    return true;
  else return false;
}

int main( ){
  bool cadastrarCliente( void );

  enum CONTINUA { NAO = 0, SIM = 1 };
  int resposta = SIM;

  puts("\n");
  do{
    printf( "-> Digite os dados do cliente\n");
    if( cadastrarCliente( ) ){
      printf( "\n\t\t\tCADASTRO FINALIZADO COM SUCESSO!!\n" );

      do{
        printf( "\n\t\t\tDeseja cadastrar mais um cliente?\n"
                "\t\t   [1] SIM\t\t\t\t\t\t[0] NAO\n\n\t\t\t> " );
        scanf( "%d", &resposta );
        getchar( );
      }while( resposta != NAO && resposta != SIM );  
    }else{
      printf( "\n\t\tOps! O cliente não foi cadastrado!\n" );
      do{
        printf( "\n\t\t\t Deseja tentar novamente?\n"
                "\t\t\t[1] SIM           [0] NAO\n\n\t\t\t> " );
        scanf( "%d", &resposta );
        getchar( );
      }while( resposta != NAO && resposta != SIM );
    }

    if( resposta == NAO ){
      printf( "\n          <<< PROGRAMA ENCERRADO >>>" );}

    puts("\n");
  }while( resposta == SIM );
  return 0;
}

bool cadastrarCliente( ){
  char nome[TAMANHO_NOME],
       cpf[TAMANHO_CPF],
       dataNascimento[TAMANHO_NASCIMENTO],
       sexo[TAMANHO_SEXO];
  
  char **mensagemDeErro;
  char **validaNome( char* );
  char **validaCpf( char* );
  char **validaNascimento( char* );
  char **validaSexo( char* );

  do{ 
    printf( "\n   > NOME [Fulano de Sicrano] - MAX 20 carac. \n      - " );
    fgets( nome, TAMANHO_NOME, stdin );
    if( verificaSaida(nome[0], nome[1]) ) return false;
    mensagemDeErro = validaNome( nome );
    for( int posicao = 0; mensagemDeErro[posicao] != NULL; posicao++ ){
      puts( mensagemDeErro[posicao] );}
  }while( mensagemDeErro[0] != NULL );

  do{
    printf( "\n   > CPF [xxx.xxx.xxx-xx]\n      - " );
    fgets( cpf, TAMANHO_CPF, stdin  );
    if( verificaSaida(cpf[0], cpf[1]) ) return false;
    mensagemDeErro = validaCpf( cpf );
    for( int posicao = 0; mensagemDeErro[posicao] != NULL; posicao++ ){
      puts( mensagemDeErro[posicao] );}
  }while( mensagemDeErro[0] != NULL );

  do{
    printf( "\n   > Nascimento [dd/mm/aaaa]\n      - " );
    fgets( dataNascimento, TAMANHO_NASCIMENTO, stdin );
    if( verificaSaida(dataNascimento[0], dataNascimento[1]) ) return false;
    mensagemDeErro = validaNascimento( dataNascimento );
    for( int posicao = 0; mensagemDeErro[posicao] != NULL; posicao++ ){
      puts( mensagemDeErro[posicao] );}
  }while( mensagemDeErro[0] != NULL );

  do{
    printf( "\n   > Sexo (F/M/O)\n      - " );
    fgets( sexo, TAMANHO_SEXO, stdin );
    if( verificaSaida(sexo[0], sexo[1]) ) return false;
    mensagemDeErro = validaSexo( sexo );
    for( int posicao = 0; mensagemDeErro[posicao] != NULL; posicao++ ){
      puts( mensagemDeErro[posicao] );}
  }while( mensagemDeErro[0] != NULL );
  /*// DESCOMENTE PARA CHECAR OS DADOS
  printf( "\n-> Os dados digitados foram\n");
  printf( "   > NOME : %s", nome );
  printf( "   > CPF : %s", cpf );
  printf( "   > NASCIMENTO : %s", dataNascimento );
  printf( "   > SEXO : %s\n\n", sexo );*/
  return true;
}

char **validaNome( char *nome ){
  static char *erro[2];
  int loc = 0;

  for( int letra = 0; nome[letra] != '\0'; letra++ ){
    if( letra > 20 ){
      erro[loc++] = "\t\t^ Utilize no máximo 20 caracteres";
      break;}}
  
  erro[loc] = NULL;
  return erro;
}
char **validaCpf( char *cpf ){
  static char *erro[4];
  int loc = 0;

  if( cpf[14] != '\n' ){
    erro[loc++] = "\t\t^ Esse cpf é inválido!";
  }else{
    for( int digito = 0; cpf[digito] != '\0'; digito++ ){
        if( digito != 3 && digito != 7 && digito != 11 && 
            caracterNumerico(cpf[digito]) == 0 && cpf[digito] != '\n' ){
          erro[loc++] = "\t\t^ Esse cpf é inválido! Utilize apenas números, pontos e um traço";
          break;}}
  
    if( !(cpf[3] == '.') || !(cpf[7] == '.') || !(cpf[11] == '-') ){
      erro[loc++] = "\t\t^ Esse cpf é inválido! Atente-se ao formato.";}} 

  erro[loc] = NULL;
  return erro;
}
char **validaNascimento( char *nascimento ){
  static char *erro[8];
  int loc = 0;

  if( nascimento[10] != '\n'){
      erro[loc++] = "\t\t^ Essa data é inválida!";
  }else{
    for( int digito = 0; nascimento[digito] != '\0'; digito++ ){
      if( (digito != 2) && (digito != 5) && (caracterNumerico(nascimento[digito]) == 0) &&
          (nascimento[digito] != '\n') ){
          erro[loc++] = "\t\t^ Utilize apenas números e barras";
          break;}}
    
    if( !(nascimento[2] == '/') || !(nascimento[5] == '/') ){
      erro[loc++] = "\t\t^ Atente-se ao formato";
    }else{
      if( ((nascimento[0] == '0') && (nascimento[1] == '0')) || (nascimento[0] > '3') ||
          ((nascimento[0] == '3') && (nascimento[1] > '1')) ) {
        erro[loc++] = "\t\t^ Esse dia é inválido";
      }if( ((nascimento[3] == '0') && (nascimento[4] == '0')) || (nascimento[3] > '2') ||
                ((nascimento[3] == '1') && (nascimento[4] > '2')) ){
        erro[loc++] = "\t\t^ Esse mês é inválido";
      }if( (nascimento[6] > '2') || (nascimento[6] == '0') ||
           ((nascimento[6] == '2') && ((nascimento[7] > '0') || 
           (nascimento[8] > '2'))) || ((nascimento[7] == '0') && 
           (nascimento[8] > '2')) || ((nascimento[8] == '2') && 
           (nascimento[9] > '2')) || ((nascimento[7] < '9') && 
           (nascimento[7] != '0')) ){
        erro[loc++] = "\t\t^ Ano invalido";}}}

  erro[loc] = NULL;
  return erro;
}
char **validaSexo( char *sexo ){
  static char *erro[2];
  int loc = 0;
  
  if( (diminuiTamanho(sexo[0]) != 'f') && (diminuiTamanho(sexo[0]) != 'm') && 
      (diminuiTamanho(sexo[0]) != 'o') ){
    erro[loc++] = "\t\t^ Essa opção é inválida! Digite F, M ou O.";}

  erro[loc] = NULL;
  return erro;
}
