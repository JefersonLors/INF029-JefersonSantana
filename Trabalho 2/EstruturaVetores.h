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
// ##################################################
#include <stdbool.h>

#ifndef EstruturaVetores_h
#define EstruturaVetores_h

enum
{
  TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11,
  NOVO_TAMANHO_INVALIDO,
  NUMERO_INEXISTENTE,
  ESTRUTURA_AUXILIAR_VAZIA,
  TAMANHO_INVALIDO,
  SEM_ESPACO_DE_MEMORIA,
  POSICAO_INVALIDA,
  JA_TEM_ESTRUTURA_AUXILIAR,
  SEM_ESTRUTURA_AUXILIAR,
  SEM_ESPACO,
  SUCESSO,
  EMPTY = -274,
};

#define TAM 10

typedef struct reg
{
  int conteudo;
  struct reg *prox;
} No;

typedef struct auxStruct
{
  int value;
  bool isEmpty;
  struct auxStruct *next;
} auxStruct;

typedef struct baseStruct
{
  auxStruct *auxStruct;
  int size_max;
  int length;
  bool auxStructExists;
  bool isFull;
  bool isEmpty;
} baseStruct;

/// FUNÇÕES BÁSICAS DOS PROGRAMA
int criarEstruturaAuxiliar(int posicao, int tamanho);
int inserirNumeroEmEstrutura(int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
No *montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No **inicio);
void inicializar();
void finalizar();

// OUTRAS FUNÇÕES UTILIZADAS NO PROGRAMA
bool outOfRange(int posicao);
void showAuxStruct(int position);
auxStruct *createAuxStruct(int size);
void insertionSort(int *vector, int size);
int getMinimumVectorSize( );
int getListSize( No *init );
void deleteList( auxStruct ** );
#endif