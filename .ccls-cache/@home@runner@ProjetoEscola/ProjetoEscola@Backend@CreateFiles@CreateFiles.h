#include "../DataStructs/DataStructs.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifndef CreateFiles_h
#define CreateFiles_h

/// FUNÇÃO DE CRIAÇÃO DE ARQUIVOS
bool criaArquivos();

bool criaArquivos() {
  FILE *files;

  files = fopen(arquivoDeDadosGerais, "r");
  if (!files) {
    files = fopen(arquivoDeDadosGerais, "w");
    if (!files)
      return false;
    fclose(files);
  }

  files = fopen(arquivoDeProfessores, "r");
  if (!files) {
    files = fopen(arquivoDeProfessores, "w");
    if (!files)
      return false;
    fclose(files);
  }
  files = fopen(arquivoDeAlunos, "r");
  if (!files) {
    files = fopen(arquivoDeAlunos, "w");
    if (!files)
      return false;
    fclose(files);
  }

  files = fopen(arquivoDeDisciplinas, "r");
  if (!files) {
    files = fopen(arquivoDeDisciplinas, "w");
    if (!files)
      return false;
    fclose(files);
  }
  return true;
}
#endif // Create_files_h