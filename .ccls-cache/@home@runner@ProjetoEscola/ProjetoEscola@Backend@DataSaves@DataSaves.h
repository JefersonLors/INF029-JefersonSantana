#include "../DataStructs/DataStructs.h";

#ifndef DataSaves_h_included
#define DataSaves_h_included

/// FUNÇÕES DE ARMAZENAMENTO DE DADOS
bool salvaDadosGerais();
bool salvaCadastroProfessor();
bool salvaCadastroDisciplina();
bool salvaCadastroAluno();

bool salvaDadosGerais() {
  FILE *dadosGeraisFPtr = fopen(arquivoDeDadosGerais, "w");
  char PROFESSORES[] = "PROFESSORES", ALUNOS[] = "ALUNOS",
       DISCIPLINAS[] = "DISCIPLINAS";

  if (dadosGeraisFPtr == NULL) {
    return false;
  } else {
    fprintf(dadosGeraisFPtr, "%s  %s  %s\n\t%d\t\t\t%d\t\t %d", PROFESSORES,
            ALUNOS, DISCIPLINAS, professoresCadastrados, alunosCadastrados,
            disciplinasCadastradas);
    fclose(dadosGeraisFPtr);
    return true;
  }
}

bool salvaCadastroProfessor() {
  FILE *cadastroProfessorFPtr = fopen(arquivoDeProfessores, "a+");

  if (!cadastroProfessorFPtr) {
    return false;
  } else {
    fseek(cadastroProfessorFPtr,
          (professoresCadastrados - 1) * sizeof(Professor), SEEK_SET);
    fwrite(&docente[professoresCadastrados - 1], sizeof(Professor), 1,
           cadastroProfessorFPtr);
    fclose(cadastroProfessorFPtr);
    return true;
  }
}


bool salvaCadastroAluno() {
  FILE *cadastroAlunoFPtr = fopen(arquivoDeAlunos, "a+");

  if (!cadastroAlunoFPtr) {
    return false;
  } else {
    fseek(cadastroAlunoFPtr, (alunosCadastrados - 1) * sizeof(Aluno), SEEK_SET);
    fwrite(&discente[alunosCadastrados - 1], sizeof(Aluno), 1,
           cadastroAlunoFPtr);
    fclose(cadastroAlunoFPtr);
    return true;
  }
}

bool salvaCadastroDisciplina() {
  FILE *cadastroDisciplinaFPtr = fopen(arquivoDeDisciplinas, "a+");

  if (!cadastroDisciplinaFPtr) {
    return false;
  } else {
    fseek(cadastroDisciplinaFPtr,
          (disciplinasCadastradas - 1) * sizeof(Disciplinas), SEEK_SET);
    fwrite(&materia[disciplinasCadastradas - 1], sizeof(Disciplinas), 1,
           cadastroDisciplinaFPtr);
    fclose(cadastroDisciplinaFPtr);
    return true;
  }
  return true;
}

#endif // ataSaves_h_included
