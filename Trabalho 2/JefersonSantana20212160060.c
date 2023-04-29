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

int main()
{
  inicializar();
  printf("Cria Estrutura\n");
  criarEstruturaAuxiliar(1, 4);
  showAuxStruct(1);

  /*teste insere*/
  printf("\nInsere: ");
  inserirNumeroEmEstrutura(1, 2);
  printf("length B1 => %d\n", base[0].length);
  showAuxStruct(1);
  
  printf("\nInsere: ");
  inserirNumeroEmEstrutura(1, 13);
  printf("length B1 => %d\n", base[0].length);
  showAuxStruct(1);
  printf("\nInsere: ");
  inserirNumeroEmEstrutura(1, 103);
  printf("length B1 => %d\n", base[0].length);
  showAuxStruct(1);

  printf("\nInsere: ");
  inserirNumeroEmEstrutura(1, 213);
  printf("length B1 => %d\n", base[0].length);
  showAuxStruct(1);

  /*teste exclui especifico*/
  printf("\nExclui: ");
  excluirNumeroEspecificoDeEstrutura(1, 103);
  printf("length B1 => %d\n", base[0].length);
  showAuxStruct(1);
  
  printf("\nExclui: ");
  excluirNumeroEspecificoDeEstrutura(1, 5);
  printf("length B1 => %d\n", base[0].length);
  showAuxStruct(1);

  printf("\nExclui: ");
  excluirNumeroEspecificoDeEstrutura(1, 2);
  printf("length B1 => %d\n", base[0].length);
  showAuxStruct(1);

  // printf("\nExclui: ");
  // excluirNumeroDoFinaldaEstrutura(1);
  // printf("length B1 => %d\n", base[0].length);
  // showAuxStruct(1);
  
  // printf("\nExclui: ");
  // excluirNumeroDoFinaldaEstrutura(1);
  // printf("length B1 => %d\n", base[0].length);
  // showAuxStruct(1);

  // printf("\nExclui: ");
  // excluirNumeroDoFinaldaEstrutura(1);
  // printf("length B1 => %d\n", base[0].length);
  // showAuxStruct(1);

  /*Teste exclui ultimo*/
  // printf("\nExclui: ");
  // excluirNumeroDoFinaldaEstrutura(1);
  // printf("length B1 => %d\n", base[0].length);
  // showAuxStruct(1);

  // printf("\nExclui: ");
  // excluirNumeroDoFinaldaEstrutura(1);
  // printf("length B1 => %d\n", base[0].length);
  // showAuxStruct(1);
  
  // printf("\nExclui: ");
  // excluirNumeroDoFinaldaEstrutura(1);
  // printf("length B1 => %d\n", base[0].length);
  // showAuxStruct(1);

  // printf("\nExclui: ");
  // excluirNumeroDoFinaldaEstrutura(1);
  // printf("length B1 => %d\n", base[0].length);
  // showAuxStruct(1);

  // printf("\nbase 1 => %d\n", base[0].length);

  // int *aux = NULL;
  
  // getDadosEstruturaAuxiliar(1, aux);

  // int i = 0;

  // while(aux[i] != EMPTY ){
  //   printf("%d\t", aux[i]);
  // }
}
int getDadosEstruturaAuxiliar(int position, int *auxVector)
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
    int length = base[position - 1].length;

    auxVector = (int *)malloc(sizeof(int) * length+1);

    auxStruct *actFloor = base[position - 1].auxStruct;

    int i = 0;
    while( i < length && actFloor ){
      puts("aqui");
      auxVector[i] = actFloor->value;
      actFloor = actFloor->next;
      printf("%d -> %d\n", i, auxVector[i] );
      i++;
    } 
    auxVector[i] = EMPTY;
    return SUCESSO;
  }
}
int criarEstruturaAuxiliar(int position, int size)
{
  if (outOfRange(position))
  {
    return POSICAO_INVALIDA;
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
      return SUCESSO;
    }
    else
    {
      while (actFloor->next && !actFloor->next->isEmpty )
      {
        actFloor = actFloor->next;
      }
      actFloor = actFloor->next;

      actFloor->isEmpty = !actFloor->isEmpty;
      actFloor->value = value;
      base[position - 1].length++;

      if (!actFloor->next || base[position - 1].length == base[position - 1].size_max)
      {
        base[position - 1].isFull = !base[position - 1].isFull;
      }
      if (base[position - 1].isEmpty == true)
      {
        base[position - 1].isEmpty = !base[position - 1].isEmpty;
      }
      return SUCESSO;
    }
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

    if( base[position - 1].length == 0 ){
      base[position - 1].isEmpty = !base[position - 1].isEmpty;
    }
    if (base[position - 1].isFull)
    {
      base[position - 1].isFull = !base[position - 1].isFull;
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
          base[position - 1].isFull = !base[position - 1].isFull;
        }
        if( base[position - 1].length == 0 ){
          base[position - 1].isEmpty = !base[position - 1].isEmpty;
        }
        return SUCESSO;
      }
      if( !actFloor->next || actFloor->next->isEmpty){
        return NUMERO_INEXISTENTE;
      }
      actFloor = actFloor->next;
    }
    return NUMERO_INEXISTENTE;
  }
}
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
    base[i].isFull = false;
    i++;
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
      printf("%d -> %s\n", act->value, (act->isEmpty ? "vazio" : "nao vazio") );
    }
    act = act->next;
  }
}