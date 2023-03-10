#include "../Register/Register.h"
#include "../Utils/Utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool solicitaCodigoMatricula(char[]);

/// FUNÇÕES DE AJUSTES
void ajusteDisciplinasCadastradas(unsigned id);
void ajusteAlunosCadastrados(unsigned id);
void ajusteProfessoresCadastrados(unsigned id);
void ajusteGradeAluno(unsigned, unsigned);
void ajusteGradeProfessor(unsigned, unsigned);
bool solicitaCodigoMatricula(char codigoDeMatricula[]) {
  enum VALIDAR { VALIDO = true, INVALIDO = false };
  bool DADO;

  do {
    fgets(codigoDeMatricula, TAM_COD_MAT, stdin);
    if (sair(codigoDeMatricula[0], codigoDeMatricula[1])) {
      return false;
    } else {
      limpaTexto(codigoDeMatricula);
      DADO = validaCodigoMatricula(codigoDeMatricula);
    }
  } while (DADO == INVALIDO);

  return true;
}

void ajusteGradeAluno(unsigned id, unsigned apagar) {
  for (int disciplina = apagar;
       disciplina < discente[id].disciplinasCursando - 1; disciplina++) {
    discente[id].matrizCurricular[disciplina] =
        discente[id].matrizCurricular[disciplina + 1];
  }
  discente[id].disciplinasCursando--;
}

void ajusteGradeProfessor(unsigned id, unsigned apagar) {
  for (int disciplina = apagar;
       disciplina < docente[id].disciplinasMinistrando - 1; disciplina++) {
    docente[id].ministrando[disciplina] =
        docente[id].ministrando[disciplina = 1];
  }
  docente[id].disciplinasMinistrando--;
}

void ajusteProfessoresCadastrados(unsigned id) {
  for (int cadastrado = id; cadastrado < professoresCadastrados - 1;
       cadastrado++) {
    docente[cadastrado] = docente[cadastrado + 1];
  }
  professoresCadastrados--;
}
void ajusteAlunosCadastrados(unsigned id) {
  for (int cadastrado = id; cadastrado < alunosCadastrados - 1; cadastrado++) {
    discente[cadastrado] = discente[cadastrado + 1];
  }
  alunosCadastrados--;
}
void ajusteDisciplinasCadastradas(unsigned id) {
  for (int cadastrada = id; cadastrada < disciplinasCadastradas - 1;
       cadastrada++) {
    materia[cadastrada] = materia[cadastrada + 1];
  }
  disciplinasCadastradas--;
}
