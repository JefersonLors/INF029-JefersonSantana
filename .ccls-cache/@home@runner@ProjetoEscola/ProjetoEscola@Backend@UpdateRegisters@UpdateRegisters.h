#include "../DataStructs/DataStructs.h";

#ifndef UpdateRegisters_h_included
#define UpdateRegisters_h_included

/// FUNÇÕES DE ATUALIZAÇÃO DE DADOS
bool atualizaCadastroProfessor(unsigned);
bool atualizaCadastroAluno(unsigned);
bool atualizaCadastroDisciplina(unsigned);

bool atualizaCadastroDisciplina(unsigned idDisciplina) {
  FILE *cadastroDisciplinaFPtr = fopen(arquivoDeDisciplinas, "r+");

  if (!cadastroDisciplinaFPtr) {
    return false;
  } else {
    fseek(cadastroDisciplinaFPtr, (idDisciplina) * sizeof(Disciplinas),
          SEEK_SET);
    fwrite(&materia[idDisciplina], sizeof(Disciplinas), 1,
           cadastroDisciplinaFPtr);
    fclose(cadastroDisciplinaFPtr);
    return true;
  }
  return true;
}
bool atualizaCadastroAluno(unsigned idAluno) {
  FILE *cadastroAlunoFPtr = fopen(arquivoDeAlunos, "r+");

  if (!cadastroAlunoFPtr) {
    return false;
  } else {
    fseek(cadastroAlunoFPtr, (idAluno) * sizeof(Aluno), SEEK_SET);
    fwrite(&discente[idAluno], sizeof(Aluno), 1, cadastroAlunoFPtr);
    fclose(cadastroAlunoFPtr);
    return true;
  }
}
bool atualizaCadastroProfessor(unsigned idProfessor) {
  FILE *cadastroProfessorFPtr = fopen(arquivoDeProfessores, "r+");

  if (!cadastroProfessorFPtr) {
    return false;
  } else {
    fseek(cadastroProfessorFPtr, idProfessor * sizeof(Professor), SEEK_SET);
    fwrite(&docente[idProfessor], sizeof(Professor), 1, cadastroProfessorFPtr);
    fclose(cadastroProfessorFPtr);
    return true;
  }
}

#endif // UpdateRegisters_h_included
