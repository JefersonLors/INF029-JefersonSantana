#include <stdbool.h>

bool recuperaCadastrosDisciplinas();

bool recuperaCadastrosDisciplinas() {
  FILE *cadastroDisciplinaFPtr = fopen(arquivoDeDisciplinas, "r");

  if (!cadastroDisciplinaFPtr) {
    return false;
  } else {
    for (int posicao = 0; posicao < disciplinasCadastradas; posicao++) {
      fseek(cadastroDisciplinaFPtr, posicao * sizeof(Disciplinas), SEEK_SET);
      fread(&materia[posicao], sizeof(Disciplinas), 1, cadastroDisciplinaFPtr);
    }
    fclose(cadastroDisciplinaFPtr);
    return true;
  }
}