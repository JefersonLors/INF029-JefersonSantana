// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Dados do Aluno -----
//  Nome: Jeferson Leandro de Oliveira dos Reis Santana
//  email: 20212160060@ifba.edu.br
//  Matrícula: 20212160060
//  Semestre: 2023.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 31/03/2023 - 19/08/2016

// #################################################

#ifndef TRABALHO1_PRIMEIROULTIMONOMEMATRICULA_H
#define TRABALHO1_PRIMEIROULTIMONOMEMATRICULA_H

#include <stdbool.h>

#define FIM_VETOR -1

typedef struct INTEIRO{
  int valor;
  struct INTEIRO *prox;
}INT;

typedef struct DQ
{
  int iDia; 
  int iMes;
  int iAno;
  int valido; // 0 se inválido, e 1 se válido 

} DataQuebrada;

typedef struct Qtd
{
  int qtdDias;
  int qtdMeses;
  int qtdAnos;
  int retorno;

} DiasMesesAnos;

//questões
int q1(char data[]);
DiasMesesAnos q2(char datainicial[], char datafinal[]);
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);

//outras funções utilizadas
int *recebe_inteiro_e_retorna_vetor(int);
void mostra_conteudo_de_vetor(int*);
bool validaFormato( char* );
bool validaCaracteres( char* );
bool validaConsistencia( char* );
bool ehNumero( int num );
bool bissexto( int ano );
DataQuebrada quebraData(char data[]);
int comparaDatas(DataQuebrada dataInicial, DataQuebrada dataFinal); /// -1 0 1
DiasMesesAnos calculaTempoEntreDatas(DataQuebrada dataInicial, DataQuebrada dataFinal);

#endif  // TRABALHO1_PRIMEIROULTIMONOMEMATRICULA_H