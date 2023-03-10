#ifndef VALIDA_FILE_H
#define VALIDA_FILE_H
#include <string.h>
#include "_gerais.h"

///FUNCÕES DE VALIDAÇÃO DE DADOS DE PROFESSORES E ALUNOS
bool validaMatricula( char *matricula );
bool validaCpf( char *cpf );
bool validaSexo( char sexo );
bool validaNascimento( char *data );
bool validaNome( char *nome );

///FUNCÕES DE VALIDAÇÃO DE DADOS DE DISCIPLINAS
bool validaCodigo( char* );
bool validaSemestre( char* );
bool validaVagas( int );
bool validaProfessores( char* );
///=========//==========//=========//=========//=========//

bool validaMatricula( char *matricula ){
    char *mensagensDeErro[4] = { };
    int erro = 0;

    if ( !tamanhoCerto(TAM_MAT, matricula) ){
        mensagensDeErro[erro++] = "\t> Tamanho inválido <";}

    for(int i = 0; matricula[i] != '\0'; i++){
        if( !ehNumero(matricula[i]) ){
            mensagensDeErro[erro++] = "\t> Caractere inserido inválido <";}}

    mensagensDeErro[erro] = NULL;

    if( mensagensDeErro[0] != NULL ){
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        puts("\n");
        return false;}
    puts("\n");
    return true;
}
bool validaNome(char *nome){
    for(int i = 0; nome[i] != '\0'; i++){
        if(!(ehLetra(nome[i])) && !(nome[i] == ' ')){
            puts( "\t> Caractere inválido <" );
            puts("\n");
            return false;}}
    puts("\n");
    return true;
}
bool validaNascimento( char *data ){
    char *mensagensDeErro[3] = { };
    int erro = 0;

    if ( !tamanhoCerto(TAM_NAC, data) ){
        mensagensDeErro[erro++] = "\t> Tamanho inválido <";}

    for(int i = 0; data[i] != '\0'; i++){
        if( !ehNumero(data[i]) && !(data[i] == '/')){
            mensagensDeErro[erro++] = "\t> Caractere inserido inválido <";
            break;}}
    mensagensDeErro[erro] = NULL;

    for( int caracter = 0; data[caracter] != '\0'; caracter++ ){
        if( !ehNumero(data[caracter]) && !(caracter == 2) && !(caracter == 5 ) ){
            puts( "\t> Data inválida <" );
            puts("\n");
            return false;  }}
    if( !(data[2] == '/') || !(data[5] == '/') ){
        puts( "\t> Formato inválido <" );
        puts("\n");
        return false;}

    int dia = (charParaInt(data[0])*10)+charParaInt(data[1]),
        mes = (charParaInt(data[3])*10)+charParaInt(data[4]),
        ano = (charParaInt(data[6])*1000)+charParaInt(data[7])*100+charParaInt(data[8]*10)+charParaInt(data[9]);

    if(  dia > 0 && dia <= 31 && mes > 0 && mes <= 12 && ano >= 1899  && ano <= 2003){
        if( ( mes == 4 || mes == 6 || mes == 9 || mes == 11 ) && dia > 30  ){
            puts("\t> Data inválida <");
            puts("\n");
            return false;
        }else if( mes == 2 && dia > 29 ){
            puts("\t> Data inválida <");
            puts("\n");
            return false;}

    }else{
        puts("\t> Data inválida <");
        return false;}

    if( mensagensDeErro[0] == NULL ){
        puts("\n");
        return true;
    }else{
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        puts("\n");
        return false;}
}
bool validaCpf (char *cpf){
    char *mensagensDeErro[3] = { };
    int erro = 0;

    if ( !tamanhoCerto(TAM_CPF, cpf) ){
        mensagensDeErro[erro++] = "\t> Tamanho inválido <";}

    for(int i = 0; cpf[i] != '\0'; i++){
        if( !ehNumero(cpf[i]) && !(cpf[i] == '.') && !(cpf[i] == '-') ){
            mensagensDeErro[erro++] = "\t> Caractere inserido inválido <";
            break;}}

    mensagensDeErro[erro] = NULL;

    for( int caracter = 0; cpf[caracter] != '\0'; caracter++ ){
        if( !ehNumero(cpf[caracter]) && !(caracter == 3) && !(caracter == 7) && !(caracter == 11) ){
            puts( "\t> CPF inválido < " );
            puts("\n");
            return false;}}

    if( (cpf[3] != '.') || (cpf[7] != '.') || (cpf[11] != '-') ){
        puts( "\t> Formato inválido <" );
        return false;}

    if( mensagensDeErro[0] != NULL ){
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        puts("\n");
        return false;}

    return true;
}
bool validaSexo( char sexo ){
    if (!(sexo == 'm') && !(sexo == 'M') && !(sexo == 'F') &&
        !(sexo == 'f') && !(sexo == 'o') && !(sexo == 'O') ){
        puts( "\t> Opção inválida <\n" );
        return false;
    }else{
      puts("\n");
      return true;}
}
bool validaCodigo( char *codigo ){
    char *mensagensDeErro[3] = { };
    int erro = 0;

    if ( !tamanhoCerto(TAM_COD_DISC, codigo) ){
        mensagensDeErro[erro++] = "\t> Tamanho inválido <";}

    for(int i = 0; codigo[i] != '\0'; i++){
        if( !ehNumero(codigo[i]) && !ehLetra(codigo[i])){
            mensagensDeErro[erro++] = "\t> Caractere inserido inválido <";
            break;}}

    mensagensDeErro[erro] = NULL;

    for(int caracter = 0; caracter < ((TAM_COD_DISC-2)/2); caracter++ ){
        if( !ehLetra(codigo[caracter]) || !ehNumero(codigo[(caracter+((TAM_COD_DISC-2)/2))] )){
            puts("\t> Código invalido <");
            puts("\n");
            return false;}}

    if( mensagensDeErro[0] != NULL ){
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        puts("\n");
        return false;}
  puts("\n");
  return true;
}
bool validaSemestre( char *semestre ){
    char *mensagensDeErro[3] = { };
    int erro = 0;

     if ( !tamanhoCerto(TAM_SEM, semestre) ){
        mensagensDeErro[erro++] = "\t> Tamanho inválido <";}

    for(int i = 0; semestre[i] != '\0'; i++){
        if( !ehNumero(semestre[i]) && !(semestre[i] == '.') ){
            mensagensDeErro[erro++] = "\t> Caractere inserido inválido <";
            break;}}

    mensagensDeErro[erro] = NULL;

    for( int caracter = 0; semestre[caracter] != '\0'; caracter++ ){
        if( !ehNumero(semestre[caracter]) && caracter != 4 ){
            puts( "\t> Semestre inválido <" );
            puts("\n");
            return false;}}

    if( (semestre[0] < '2')){
        puts( "\t> Semestre inválido <" );
        puts("\n");
        return false;}

    if( (semestre[1] != '0')){
        puts( "\t> Semestre inválido <" );
        puts("\n");
        return false;}

    if ((semestre[5] != '1') && (semestre[5] != '2')){
        puts ( "\t> Semestre invalido <" );
        puts("\n");
        return false;}

    if( mensagensDeErro[0] == NULL ){
        puts("\n");
        return true;
    }else{
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        puts("\n");
        return false;}
}
bool validaVagas( int vagas ){
    if ( !(ehNumero(vagas))){
        puts( "\t> Caractere inválido <\n" );
        return false;}

    if( vagas < 0 ){
        puts( "\t> Valor inválido <\n" );
        return false;
    }else{
      return true;}
}
bool validaProfessores( char *professor ){
    if( validaNome( professor ) ){
        int tamanho = 0;
        char *professorAtualBackup = (char*)malloc( (strlen( professor ))*sizeof(char) ),
             *professorDaLista = NULL;

        strcpy( professorAtualBackup, caixaAlta(professor) );

        if( professoresCadastrados > 0 ){
            for( int cadastrado = 0; cadastrado < professoresCadastrados; cadastrado++){
                tamanho = strlen( docente[cadastrado].dado.nome  );
                professorDaLista = (char*)malloc( tamanho*sizeof(char) );
                strcpy( professorDaLista, caixaAlta(docente[cadastrado].dado.nome ));

                if( (strcmp( professorAtualBackup, professorDaLista)) == 0 ){
                    free( professorAtualBackup );
                    free( professorDaLista );
                    return true;}}
            puts("\t> Professor invalido <\n" );
            free( professorAtualBackup );
            free( professorDaLista );
            return false;
        }else{
            puts("\t> Professor invalido <\n" );
            free( professorAtualBackup );
            free( professorDaLista );
            return false;}
    }else{ return false;}
}

#endif ///VALIDA_FILE_H
