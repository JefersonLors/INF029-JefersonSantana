#include "DataStructs/DataStructs.h";

bool recuperaCadastrosAlunos() {
  FILE *cadastroAlunoFPtr = fopen(arquivoDeAlunos, "r");

  if (!cadastroAlunoFPtr) {
    return false;
  } else {
    for (int posicao = 0; posicao < alunosCadastrados; posicao++) {
      fseek(cadastroAlunoFPtr, posicao * sizeof(Aluno), SEEK_SET);
      fread(&discente[posicao], sizeof(Aluno), 1, cadastroAlunoFPtr);
    }
    fclose(cadastroAlunoFPtr);
    return true;
  }
}
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
bool recuperaCadastrosProfessores() {
  FILE *cadastroProfessorFPtr = fopen(arquivoDeProfessores, "r");

  if (!cadastroProfessorFPtr) {
    return false;
  } else {
    for (int posicao = 0; posicao < professoresCadastrados; posicao++) {
      fseek(cadastroProfessorFPtr, posicao * sizeof(Professor), SEEK_SET);
      fread(&docente[posicao], sizeof(Professor), 1, cadastroProfessorFPtr);
    }
    fclose(cadastroProfessorFPtr);
    return true;
  }
}
bool recuperaDadosGerais() {
  FILE *dadosGeraisFPtr = fopen(arquivoDeDadosGerais, "r");
  char PROFESSORES[] = "PROFESSORES", ALUNOS[] = "ALUNOS",
       DISCIPLINAS[] = "DISCIPLINAS";

  if (dadosGeraisFPtr == NULL) {
    return false;
  } else {
    fscanf(dadosGeraisFPtr, "%s  %s  %s\n\t%d\t\t\t%d\t\t %d", PROFESSORES,
           ALUNOS, DISCIPLINAS, &professoresCadastrados, &alunosCadastrados,
           &disciplinasCadastradas);
    fclose(dadosGeraisFPtr);
    return true;
  }
}