// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Jeferson Leandro de Oliveira dos Reis Santana
//  email: lors.jefersn@gmail.com
//  Matrícula: 20212160060
//  Semestre: 2022.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021

// #################################################


#ifndef JefersonSantana20212160060_h
#define JefersonSantana20212160060_h
#include <stdbool.h>

#define TAMANHO_DATA 16

int charToInt( char );
bool ehNumero( char );
void limpaDado( char* );
bool bissexto( char* );

bool Q1( char * );
int* q2( char *dataNascimento, char *dataAtual );
int q3( const char texto[], char letra );
int q4( const char texto[], const char palavra[], int posicoes[] );
int q5( int valor );
unsigned q6( const unsigned valor, const unsigned contido );
    
bool ehNumero( char caracter ){
    if( caracter >= 48 && caracter <= 57 )
        return true;
    else return false;
}
void limpaDado( char *dado ){
    for( int caracter = 0; dado[caracter] != '\0'; caracter++ )
        if( dado[caracter+1] == '\0' && dado[caracter] == '\n' )
            dado[caracter] = '\0';
}
int charToInt( char digito ){
    switch( digito ){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return -1;
    }
}
bool bissexto( char *data ){
    int ano;
    for( int digito = 5; data[digito] != '\0'; digito++ ){
        if( data[digito+1] == '\0' ){
            ano = ( charToInt( data[digito-1] ) * 10 ) + charToInt( data[digito] );
            if( ano == 0 || ano % 4 == 0 ){
                return true;
            }else{
                return false;}}}
}
#endif
