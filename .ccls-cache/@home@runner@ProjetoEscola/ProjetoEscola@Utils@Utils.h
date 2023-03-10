#include "../DataStructs/DataStructs.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef Utils_h_included
#define Utils_h_included

/// SEÇÃO DE FUNÇÕES UTILITÁRIAS
void limpaTexto(char *);
bool tamanhoCerto(int, char *);

bool ehNumero(char);
bool ehLetra(char);

char *caixaAlta(char *);
char *caixaBaixa(char *);

int charParaInt(char);
bool sair(char sinal, char valor);
void padronizaNome(char *);

char diminuiLetra(char);
char aumentaLetra(char);
///==========//==========//=========//=========//

void limpaTexto(char *texto) {
  for (int caracter = 0; texto[caracter] != '\0'; caracter++) {
    if (texto[caracter + 1] == '\0')
      texto[caracter] = '\0';
  }
}

bool ehNumero(char digito) {
  if (digito < '0' || digito > '9') {
    return false;
  }
  return true;
}

bool tamanhoCerto(const int tamanho, char *dado) {
  int size;
  for (int contador = 0; dado[contador] != '\0'; contador++) {
    if (dado[contador + 1] == '\0') {
      size = contador + 1;
    }
  }

  if (size != tamanho - 2) {
    return false;
  }

  return true;
}

bool ehLetra(char caracter) {
  char caracteresEspeciais[] =
      "àèìòùÀÈÌÒÙáéíóúýÁÉÍÓÚÝâêîôûÂÊÎÔÛãñõÃÑÕäëïöüÿÄËÏÖÜ";

  if ((caracter >= 'A' && caracter <= 'Z') ||
      (caracter >= 'a' && caracter <= 'z')) {
    return true;
  }

  for (int i = 0; caracteresEspeciais[i] != '\0'; i++) {
    if (caracter == caracteresEspeciais[i]) {
      return true;
    }
  }
  return false;
}

char *caixaAlta(char *texto) {
  char *textoBackup = (char *)malloc((strlen(texto)) * sizeof(char));

  for (int caracter = 0; texto[caracter] != '\0'; caracter++) {
    textoBackup[caracter] = aumentaLetra(texto[caracter]);
  }

  // free( textoBackup );
  return textoBackup;
}

char *caixaBaixa(char *texto) {
  char *textoBackup = (char *)malloc((strlen(texto)) * sizeof(char));

  for (int caracter = 0; texto[caracter] != '\0'; caracter++) {
    textoBackup[caracter] = diminuiLetra(texto[caracter]);
  }
  // free( textoBackup );
  return textoBackup;
}

int charParaInt(char letra) {
  switch (letra) {
  case '0':
    return 0;
  case '1':
    return 1;
  case '2':
    return 2;
  case '3':
    return 3;
  case '4':
    return 4;
  case '5':
    return 5;
  case '6':
    return 6;
  case '7':
    return 7;
  case '8':
    return 8;
  case '9':
    return 9;
  default:
    return -1;
  }
}

bool sair(char sinal, char valor) {
  if (sinal == '-' && valor == '1')
    return true;
  else
    return false;
}

void padronizaNome(char nome[]) {
  strcpy(nome, caixaBaixa(nome));
  nome[0] = aumentaLetra(nome[0]);
  for (int caracter = 0; nome[caracter] != '\0'; caracter++) {
    if (nome[caracter - 1] == ' ') {
      nome[caracter] = aumentaLetra(nome[caracter]);
    }
  }
}

char diminuiLetra(char letra) {
  char caracteresEspeciais[] = "àèìòùáéíóúýâêîôûãñõçÀÈÌÒÙÁÉÍÓÚÝÂÊÎÔÛÃÑÕÇ";

  if (letra < 91 && letra > 64) {
    return letra + 32;
  } else {
    for (int caracterEsp = 20; caracterEsp < 40; caracterEsp++) {
      if (letra == caracteresEspeciais[caracterEsp]) {
        letra = caracteresEspeciais[caracterEsp - 20];
        return letra;
      }
    }
  }
  return letra;
}

char aumentaLetra(char letra) {
  char caracteresEspeciais[] = "àèìòùáéíóúýâêîôûãñõçÀÈÌÒÙÁÉÍÓÚÝÂÊÎÔÛÃÑÕÇ";

  if (letra < 123 && letra > 96) {
    return letra - 32;
  } else {
    for (int caracterEsp = 0; caracterEsp < 20; caracterEsp++) {
      if (letra == caracteresEspeciais[caracterEsp]) {
        letra = caracteresEspeciais[caracterEsp + 20];
        return letra;
      }
    }
  }
  return letra;
}
#endif // Utils_h_included
