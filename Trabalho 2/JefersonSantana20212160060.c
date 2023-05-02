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

#include "JefersonSantana20212160060.h"
#include <stdlib.h>
#include <stdio.h>

baseStruct *base = NULL;

int Main()
{
  inicializar();
  printf("Cria Estrutura\n");
  criarEstruturaAuxiliar(1, 4);
  criarEstruturaAuxiliar(10, 4);
  showAuxStruct(1);

  /*teste insere*/
  printf("\nInsere: ");
  inserirNumeroEmEstrutura(1, 213);
  printf("length B1 => %d\n", base[0].length);
  showAuxStruct(1);

  printf("\nInsere: ");
  inserirNumeroEmEstrutura(1, 2);
  printf("length B1 => %d\n", base[0].length);
  showAuxStruct(1);

  printf("\nInsere: ");
  inserirNumeroEmEstrutura(1, 103);
  printf("length B1 => %d\n", base[0].length);
  showAuxStruct(1);

  printf("\nInsere: ");
  inserirNumeroEmEstrutura(1, 13);
  printf("length B1 => %d\n", base[0].length);
  showAuxStruct(1);

  printf("\nInsere: ");
  inserirNumeroEmEstrutura(10, 213);
  printf("length B10 => %d\n", base[9].length);
  showAuxStruct(10);

  printf("\nInsere: ");
  inserirNumeroEmEstrutura(10, 17);
  printf("length B10 => %d\n", base[9].length);
  showAuxStruct(10);

  printf("\nInsere: ");
  inserirNumeroEmEstrutura(10, 50);
  printf("length B10 => %d\n", base[9].length);
  showAuxStruct(10);

  int result = inserirNumeroEmEstrutura(10, 987);
  showAuxStruct(10);

  No *lista = montarListaEncadeadaComCabecote();
  destruirListaEncadeadaComCabecote(&lista);
  finalizar();

  // int *auxK = (int *)malloc(sizeof(int) * getListSize(lista) + 1);

  // getDadosListaEncadeadaComCabecote(lista, auxK);

  // printf("lista: [s = %d]", getListSize(lista));

  // int i = 0;

  // while (auxK[i] != EMPTY)
  // {
  //   printf("%d\t", auxK[i]);
  //   i++;
  // }
}
/// FUNÇÕES BÁSICAS DOS PROGRAMA
void finalizar()
{
  int i = 0;

  while (i < TAM)
  {
    deleteList(&base[i].auxStruct);
    i++;
  }
}
void destruirListaEncadeadaComCabecote(No **init)
{
  No *act = *init;
  No *prev = NULL;

  while (act)
  {
    prev = act;
    act = act->prox;
    free(prev);
    prev = NULL;
  }
  *init = NULL;
}
void getDadosListaEncadeadaComCabecote(No *init, int auxVector[])
{
  No *act = init;

  int i = 0;

  while (act)
  {
    auxVector[i] = act->conteudo;
    act = act->prox;
    i++;
  }
  auxVector[i] = EMPTY;
}
No *montarListaEncadeadaComCabecote()
{
  No *init = NULL;
  No *end = NULL;

  No *first = NULL;
  No *new = NULL;
  No *last = NULL;

  int i = 0;

  while (i < TAM)
  {
    if (base[i].auxStructExists && !base[i].isEmpty)
    {
      auxStruct *act = base[i].auxStruct;

      new = (No *)malloc(sizeof(No));
      new->conteudo = act->value;
      new->prox = NULL;
      first = new;
      last = new;

      act = act->next;
      while (act && !act->isEmpty)
      {
        new = (No *)malloc(sizeof(No));

        new->conteudo = act->value;
        new->prox = NULL;
        last->prox = new;
        last = new;

        act = act->next;
      }
      if (!last)
      {
        end = last;
      }
    }
    if (!init)
    {
      init = first;
    }
    if (end)
    {
      end->prox = first;
    }
    end = last;

    i++;
  }
  last->prox = NULL;
  return init;
}
int modificarTamanhoEstruturaAuxiliar(int position, int newSize)
{
  if (outOfRange(position))
  {
    return POSICAO_INVALIDA;
  }
  else if (!base[position - 1].auxStructExists)
  {
    return SEM_ESTRUTURA_AUXILIAR;
  }
  else if ((base[position - 1].size_max + newSize) < 1)
  {
    return NOVO_TAMANHO_INVALIDO;
  }
  else
  {
    int resizeTo = base[position - 1].size_max + newSize;
    auxStruct *last = base[position - 1].auxStruct;

    if (resizeTo > base[position - 1].size_max)
    {
      while (last->next)
      {
        last = last->next;
      }
      last->next = createAuxStruct(newSize);
      if (newSize > 0 && !last->next)
      {
        return SEM_ESPACO_DE_MEMORIA;
      }
      else
      {
        base[position - 1].size_max = base[position - 1].size_max + newSize;

        if (base[position - 1].isFull)
        {
          base[position - 1].isFull = !base[position - 1].isFull;
        }
      }
    }
    else
    {
      int i = 0;
      while (i < resizeTo-1)
      {
        last = last->next;
        i++;
      }
      deleteList(&last->next);
      last->next = NULL;
      base[position - 1].size_max = resizeTo;

      if (base[position - 1].isFull)
      {
        base[position - 1].length = resizeTo;
      }
      else if( base[position - 1].length > resizeTo ){
        if( !base[position - 1].isFull ){
          base[position - 1].isFull = !base[position - 1].isFull;
        }
        base[position - 1].length = resizeTo;
      }
    }
    return SUCESSO;
  }
}
int getQuantidadeElementosEstruturaAuxiliar(int position)
{
  if (outOfRange(position))
  {
    return POSICAO_INVALIDA;
  }
  else if (!base[position - 1].auxStructExists)
  {
    return SEM_ESTRUTURA_AUXILIAR;
  }
  else if (base[position - 1].isEmpty)
  {
    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  else
  {
    return base[position - 1].length;
  }
}
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int auxVector[])
{
  int result = getDadosDeTodasEstruturasAuxiliares(auxVector);

  if (result == SUCESSO)
  {
    insertionSort(auxVector, getVectorSize(auxVector, EMPTY));
  }
  return result;
}
int getDadosDeTodasEstruturasAuxiliares(int auxVector[])
{
  int i = 0;

  while (i < TAM)
  {
    if ( !base[i].isEmpty)
    {
      break;
    }
    i++;
  }
  if (i == TAM)
  {
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }
  else
  {
    int i = 0;
    int totalSize = 0;

    while( base[i].isEmpty ){
      i++;
    }
    totalSize += base[i].length;

    getDadosEstruturaAuxiliar(i + 1, auxVector);
    i++;

    while (i < TAM)
    {
      if( !base[i].isEmpty ){
        getDadosEstruturaAuxiliar(i + 1, &auxVector[totalSize]);
        totalSize += base[i].length;
      }
      i++;
    }
    auxVector[totalSize] = EMPTY;
    return SUCESSO;
  }
}
int getDadosOrdenadosEstruturaAuxiliar(int position, int auxVector[])
{
  int result = getDadosEstruturaAuxiliar(position, auxVector);

  if (result == SUCESSO)
  {
    insertionSort(auxVector, base[position - 1].length);
  }
  return result;
}
int getDadosEstruturaAuxiliar(int position, int auxVector[])
{
  if (outOfRange(position))
  {
    return POSICAO_INVALIDA;
  }
  else if (!base[position - 1].auxStructExists)
  {
    return SEM_ESTRUTURA_AUXILIAR;
  }
  else
  {
    auxStruct *actFloor = base[position - 1].auxStruct;

    int i = 0;
    int length = base[position - 1].length;

    while (i < length && actFloor)
    {
      auxVector[i] = actFloor->value;
      actFloor = actFloor->next;
      i++;
    }
    return SUCESSO;
  }
}
int criarEstruturaAuxiliar(int position, int size)
{
  if (outOfRange(position))
  {
    return POSICAO_INVALIDA;
  }
  else if (size < 1)
  {
    return TAMANHO_INVALIDO;
  }
  else if (base[position - 1].auxStructExists)
  {
    return JA_TEM_ESTRUTURA_AUXILIAR;
  }
  else
  {
    base[position - 1].auxStruct = createAuxStruct(size);

    if (base[position - 1].auxStruct)
    {
      base[position - 1].size_max = size;
      base[position - 1].isFull = false;
      base[position - 1].isEmpty = true;
      base[position - 1].auxStructExists = true;
      return SUCESSO;
    }
    else
    {
      return SEM_ESPACO;
    }
  }
}
int inserirNumeroEmEstrutura(int position, int value)
{
  if (outOfRange(position))
  {
    return POSICAO_INVALIDA;
  }
  else if (base[position - 1].isFull)
  {
    return SEM_ESPACO;
  }
  else if (!base[position - 1].auxStructExists)
  {
    return SEM_ESTRUTURA_AUXILIAR;
  }
  else
  {
    auxStruct *actFloor = base[position - 1].auxStruct;

    if (base[position - 1].isEmpty)
    {
      actFloor->value = value;
      actFloor->isEmpty = !actFloor->isEmpty;
      base[position - 1].length++;
      base[position - 1].isEmpty = !base[position - 1].isEmpty;
    }
    else
    {
      while (actFloor->next && !actFloor->next->isEmpty)
      {
        actFloor = actFloor->next;
      }
      actFloor = actFloor->next;

      actFloor->isEmpty = !actFloor->isEmpty;
      actFloor->value = value;
      base[position - 1].length++;

      if (!actFloor->next || base[position - 1].length == base[position - 1].size_max)
      {
        base[position - 1].isFull = true;
      }
      if (base[position - 1].isEmpty == true)
      {
        base[position - 1].isEmpty = false;
      }
    }
    return SUCESSO;
  }
}
int excluirNumeroDoFinaldaEstrutura(int position)
{
  if (outOfRange(position))
  {
    return POSICAO_INVALIDA;
  }
  else if (!base[position - 1].auxStructExists)
  {
    return SEM_ESTRUTURA_AUXILIAR;
  }
  else if (base[position - 1].isEmpty)
  {
    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  else
  {
    auxStruct *actFloor = base[position - 1].auxStruct;

    while (actFloor->next && !actFloor->next->isEmpty)
    {
      actFloor = actFloor->next;
    }
    actFloor->value = EMPTY;
    actFloor->isEmpty = !actFloor->isEmpty;

    base[position - 1].length--;

    if (base[position - 1].length == 0)
    {
      base[position - 1].isEmpty = true;
    }
    if (base[position - 1].isFull)
    {
      base[position - 1].isFull = false;
    }
    return SUCESSO;
  }
}
int excluirNumeroEspecificoDeEstrutura(int position, int value)
{
  if (outOfRange(position))
  {
    return POSICAO_INVALIDA;
  }
  else if (!base[position - 1].auxStructExists)
  {
    return SEM_ESTRUTURA_AUXILIAR;
  }
  else if (base[position - 1].isEmpty)
  {
    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  else
  {
    auxStruct *actFloor = base[position - 1].auxStruct;

    while (actFloor)
    {
      if (actFloor->value == value)
      {
        while (actFloor->next && !actFloor->isEmpty)
        {
          actFloor->value = actFloor->next->value;
          actFloor = actFloor->next;
        }

        actFloor->isEmpty = !actFloor->isEmpty;
        actFloor->value = EMPTY;
        base[position - 1].length--;

        if (base[position - 1].isFull)
        {
          base[position - 1].isFull = false;
        }
        if (base[position - 1].length == 0)
        {
          base[position - 1].isEmpty = true;
        }
        return SUCESSO;
      }
      if (!actFloor->next || actFloor->next->isEmpty)
      {
        return NUMERO_INEXISTENTE;
      }
      actFloor = actFloor->next;
    }
    return NUMERO_INEXISTENTE;
  }
}
void inicializar()
{
  base = (baseStruct *)malloc(sizeof(baseStruct) * TAM);
  int i = 0;

  while (i < TAM)
  {
    base[i].auxStruct = NULL;
    base[i].auxStructExists = false;
    base[i].length = 0;
    base[i].size_max = 0;
    base[i].isEmpty = true;
    base[i].isFull = false;
    i++;
  }
}

// OUTRAS FUNÇÕES UTILIZADAS NO PROGRAMA
bool outOfRange(int position)
{
  if (position < 1 || position > TAM)
  {
    return true;
  }
  else
  {
    return false;
  }
}
auxStruct *createAuxStruct(int size)
{
  auxStruct *new = (auxStruct *)malloc(sizeof(auxStruct));
  auxStruct *first = new;
  auxStruct *last = first;

  first->next = NULL;
  first->value = EMPTY;
  first->isEmpty = true;

  while (size > 1)
  {
    new = (auxStruct *)malloc(sizeof(auxStruct));
    new->value = EMPTY;
    new->isEmpty = true;
    new->next = NULL;

    last->next = new;
    last = new;

    size--;
  }
  return first;
}
void showAuxStruct(int position)
{
  printf("\nConteudo:\n");
  auxStruct *act = base[position - 1].auxStruct;
  while (act != NULL)
  {
    if (act->value == EMPTY)
    {
      puts("EMPTY");
    }
    else
    {
      printf("%d -> %s\n", act->value, (act->isEmpty ? "vazio" : "nao vazio"));
    }
    act = act->next;
  }
}
void insertionSort(int *vector, int size)
{
  int key;

  for (int i = 1; i < size; i++)
  {
    key = vector[i];
    int j = i - 1;
    while (j >= 0 && vector[j] > key)
    {
      vector[j + 1] = vector[j];
      j--;
    }
    vector[j + 1] = key;
  }
}
int getVectorSize(int *vector, int ends)
{
  int i = 0;
  while (vector[i] != ends)
    i++;
  return i;
}
int getListSize(No *init)
{
  No *act = init;
  int i = 0;

  while (act)
  {
    i++;
    act = act->prox;
  }
  return i;
}
void deleteList(auxStruct **init)
{
  auxStruct *actAux = *init;
  auxStruct *prevAux = NULL;

  while (actAux)
  {
    prevAux = actAux;
    actAux = actAux->next;
    free(prevAux);
    prevAux = NULL;
  }
  *init = NULL;
}