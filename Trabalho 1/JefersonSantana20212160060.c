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

#include <stdio.h>
#include "JefersonSantana20212160060.h" 
#include <stdlib.h>
#include <string.h>

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  if( validaCaracteres( data ) ){
    if( validaFormato( data ) ){
      if( validaConsistencia( data ) ){
        return 1;
      }
    }
  }
  return 0;
}
bool validaCaracteres( char *data ){
  for( int i = 0; data[i] != '\0'; i++ ){
      if( !ehNumero(data[i]) && data[i] != '/' ){
          return false;
      }
  }
  return true;
}
bool validaFormato( char *data ){
  int barras = 0;

  for( int tamanho = 1; data[tamanho] != '\0'; tamanho++ ){
    if( data[tamanho-1] == '/' ){
      barras++;
      if( barras == 1 ){
        if( (tamanho-1) != 1 && (tamanho-1) != 2 ){
          return false;}
        if( data[tamanho+1] != '/' && data[tamanho+2] != '/' ){
          return false;
        }
      }
      if( barras > 2 ){
        return false;
      }
    }
    if( data[tamanho+1] == '\0' && ( data[tamanho-2] != '/' && data[tamanho-4] != '/' ) ){
      return false;
    }
  }
  return true;
}
bool validaConsistencia( char *stringData ){
  DataQuebrada data = quebraData( stringData );

  if( data.iDia <= 31 && data.iMes <= 12 ){
    if( data.iDia < 31 && data.iMes != 2 ){
      return true;
    }else if( data.iDia > 28 && data.iMes == 2 ){
      if( bissexto(data.iAno) ){
        return true;
      }else{
        return false;
      }
    }else if( data.iDia > 30 && 
      data.iMes != 1 &&
      data.iMes != 3 &&
      data.iMes != 5 &&
      data.iMes != 7 &&
      data.iMes != 8 &&
      data.iMes != 10 &&
      data.iMes != 12 ){
        return false;
    }else{
        return true;
    }
  }
  return false;
}
bool bissexto( int ano ){
  if( ano % 4 == 0 ){
    if( ano % 100 == 0 ){
      if( ano % 400 == 0 ){
        return true;
      }
    }else{
      return true;
    }
  }
  return false;
}
bool ehNumero( int character ){
  if( 47 < character && character < 58 ){
    return true;
  }
  return false;
}
DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	
	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	
	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char *dataInicial, char *dataFinal)
{
  DataQuebrada dataIni = quebraData(dataInicial);
  DataQuebrada dataFin = quebraData(dataFinal);
  DiasMesesAnos resultado;
  resultado.retorno = 1;
  resultado.qtdAnos = 0;
  resultado.qtdDias = 0;
  resultado.qtdMeses = 0;

  if (!q1(dataInicial))
  {
    resultado.retorno = 2;
    return resultado;
  }
  if (!q1(dataFinal))
  {
    resultado.retorno = 3;
    return resultado;
  }
  switch (comparaDatas(dataIni, dataFin))
  {
  case 1:
    resultado.retorno = 4;
    return resultado;

  case 0:
    return resultado;

  default:
    resultado = calculaTempoEntreDatas(dataIni, dataFin);
    return resultado;
  }
}
DiasMesesAnos calculaTempoEntreDatas(DataQuebrada dataInicial, DataQuebrada dataFinal)
{
  DiasMesesAnos resultado;
  if( dataFinal.iAno < 100 ){
    dataFinal.iAno += 2000;
  }
  if( dataInicial.iAno < 100 ){
    dataInicial.iAno += 2000;
  }
  if (dataFinal.iDia < dataInicial.iDia)
  {
    if (dataFinal.iMes == 3)
    {
      if (bissexto(dataFinal.iAno))
      {
        dataFinal.iDia += 29;
      }
      else
      {
        dataFinal.iDia += 28;
      }
    }
    else if (dataFinal.iMes == 5 || dataFinal.iMes == 7 || dataFinal.iMes == 10 || dataFinal.iMes == 12)
    {
      dataFinal.iDia += 30;
    }
    else
    {
      dataFinal.iDia += 31;
    }
    dataFinal.iMes -= 1;
  }
  if (dataFinal.iMes < dataInicial.iMes)
  {
    dataFinal.iMes += 12;
    dataFinal.iAno -= 1;
  }
  resultado.retorno = 1;
  resultado.qtdAnos = dataFinal.iAno - dataInicial.iAno;
  resultado.qtdMeses = dataFinal.iMes - dataInicial.iMes;
  resultado.qtdDias = dataFinal.iDia - dataInicial.iDia;

  return resultado;
}
int comparaDatas(DataQuebrada  dataAQuebrada, DataQuebrada dataBQuebrada)
{
  if (dataAQuebrada.iAno > dataBQuebrada.iAno)
  {
    return 1;
  }
  if (dataAQuebrada.iAno < dataBQuebrada.iAno)
  {
    return -1;
  }
  if (dataAQuebrada.iAno == dataBQuebrada.iAno)
  {
    if (dataAQuebrada.iMes > dataBQuebrada.iMes)
    {
      return 1;
    }
    if (dataAQuebrada.iMes < dataBQuebrada.iMes)
    {
      return -1;
    }
    if (dataAQuebrada.iMes == dataBQuebrada.iMes)
    {
      if (dataAQuebrada.iDia > dataBQuebrada.iDia)
      {
        return 1;
      }
      if (dataAQuebrada.iDia < dataBQuebrada.iDia)
      {
        return -1;
      }
      if (dataAQuebrada.iDia == dataBQuebrada.iDia)
      {
        return 0;
      }
    }
  }
}
/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
  int ocorrencias = 0;
  
  if( isCaseSensitive != 1 ){
    for( int x = 0; texto[x] != '\0'; x++ ){
      if( texto[x] ==  c || texto[x] - 32 ==  c || texto[x] + 32 ==  c){
        ocorrencias++;
      }
    }
  }else{
    for( int x = 0; texto[x] != '\0'; x++ ){
      if( texto[x] ==  c ){
        ocorrencias++;
      }
    }
  }
  return ocorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int buscaSize = strlen(strBusca);
  int ocorrencias = 0;
  int i = 0;
  int subA = -1;
  int compensa = 0;
  
  for( int x = 0; strTexto[x] != '\0'; x++ ){
    int y = 0;
    if( (int)strTexto[x] < 0 ){
      compensa++;
    }
    if( (int)strTexto[x] == (int)strBusca[y] ){
      subA = x;
      while( strBusca[y] != '\0' ){
        if( (int)strTexto[x] != (int)strBusca[y] ){
          break;
        }
        x++;
        y++;
      }
      if( strBusca[y] == '\0' ){
        posicoes[i++] = subA+1 - (compensa/2);
        posicoes[i++] = x - (compensa/2);
        ocorrencias++;
        x--;
      }else{
        x = subA;
      }
    }
  }
  return ocorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5( int valor ){
  int valorInvertido = 0;

  do{ 
    valorInvertido *= 10;
    valorInvertido += valor % 10;
    valor /= 10;
  } while( valor );
  return valorInvertido;
}

// CONJUNTO DE FUNÇÕES QUE COMPREENDEM A Q6
/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */
int q6(int base, int chave){
  int *vetorBase = recebe_inteiro_e_retorna_vetor(base);
  int *vetorChave = recebe_inteiro_e_retorna_vetor(chave);
  
  int indexB = 0;
  int indexC = 0;
  int indexBackUp = 0;
  int qtdOcorrencias = 0;

  while( vetorBase[indexB] != FIM_VETOR ){
    indexC = 0;
    indexBackUp = indexB;
    if ( vetorBase[indexB] == vetorChave[indexC] ){
      while( vetorBase[indexB] == vetorChave[indexC] && vetorChave[indexC] != FIM_VETOR ){
        indexB++;
        indexC++;
      }
    }
    
    if( vetorChave[indexC] == FIM_VETOR ){
      qtdOcorrencias++;
      indexB--;
    }else{
      indexB = indexBackUp;
    }
    indexB++;
  }
  return qtdOcorrencias;
}
int *recebe_inteiro_e_retorna_vetor(int num){
  int casasDecimais = 1;
  int *vetorInteiro = NULL;
  int parteInteira = num;
  INT *novoNum = NULL;
  INT *numAtual = NULL;                                                   

  if( parteInteira / 10 == 0 ){
    vetorInteiro = malloc(sizeof(int)*2);
    vetorInteiro[0] = num;
    vetorInteiro[1] = FIM_VETOR;
    return vetorInteiro;
    
  }else{
    novoNum = malloc(sizeof(INT));
    novoNum->valor = parteInteira % 10;
    novoNum->prox = NULL;
    numAtual = novoNum;
    parteInteira = parteInteira / 10;
    
    while( parteInteira != 0 ){
      novoNum = malloc(sizeof(INT));
      novoNum->valor = parteInteira % 10;
      novoNum->prox = numAtual;
      numAtual = novoNum;
      casasDecimais++;  
      parteInteira = parteInteira / 10;  
    }
  }
  
  vetorInteiro = malloc(sizeof(int)*casasDecimais+1);
  INT *cobaia = numAtual;
  int i = 0;
  
  while( cobaia != NULL){
    vetorInteiro[i] = cobaia->valor;
    cobaia = cobaia->prox;
    i++;
  }
  vetorInteiro[i] = FIM_VETOR;
  return vetorInteiro;
}
void mostra_conteudo_de_vetor(int *vetor){
  int i = 0;
  while(vetor[i] != FIM_VETOR){
    printf("%d\t", vetor[i]);
    i++;
  }
}
