#include "../DataStructs/DataStructs.h"

#ifndef DataVerifies_h_included
#define DataVerifies_h_included

int verificaMatriculaProfessor(char *);
int verificaMatriculaAluno(char *);
int verificaNomeAluno(char *);
int verificaCpfAluno(char *);
int verificaCpfProfessor(char *);
int verificaCodigoDisciplina(char *);
int verificaNomeDisciplina(char *);
int verificaNomeProfessor(char *);

int verificaMatriculaProfessor(char *matricula) {
  if (professoresCadastrados > 0)
    for (int cadastrado = 0; cadastrado < professoresCadastrados; cadastrado++)
      if ((strcmp(matricula, docente[cadastrado].dado.matricula)) == 0)
        return cadastrado;
  return -1;
}
int verificaMatriculaAluno(char *matricula) {
  if (alunosCadastrados > 0)
    for (int cadastrado = 0; cadastrado < alunosCadastrados; cadastrado++)
      if ((strcmp(matricula, discente[cadastrado].dado.matricula)) == 0)
        return cadastrado;
  return -1;
}
int verificaCpfAluno(char *cpf) {
  if (alunosCadastrados > 0)
    for (int cadastrado = 0; cadastrado < alunosCadastrados; cadastrado++)
      if ((strcmp(cpf, discente[cadastrado].dado.cpf)) == 0)
        return cadastrado;
  return -1;
}
int verificaNomeAluno(char *nomeAluno) {
  if (alunosCadastrados > 0)
    for (int cadastrado = 0; cadastrado < alunosCadastrados; cadastrado++)
      if ((strcmp(discente[cadastrado].dado.nome, nomeAluno)) == 0)
        return cadastrado;
  return -1;
}
int verificaCpfProfessor(char *cpf) {
  if (professoresCadastrados > 0)
    for (int cadastrado = 0; cadastrado < professoresCadastrados; cadastrado++)
      if ((strcmp(cpf, docente[cadastrado].dado.cpf)) == 0)
        return cadastrado;
  return -1;
}
int verificaCodigoDisciplina(char *codigoMatricula) {
  if (disciplinasCadastradas > 0)
    for (int cadastrada = 0; cadastrada < disciplinasCadastradas; cadastrada++)
      if ((strcmp(codigoMatricula, materia[cadastrada].codigo)) == 0)
        return cadastrada;
  return -1;
}
int verificaNomeDisciplina(char *nomeDisciplina) {
  if (disciplinasCadastradas > 0)
    for (int cadastrado = 0; cadastrado < disciplinasCadastradas; cadastrado++)
      if ((strcmp(nomeDisciplina, materia[cadastrado].nome)) == 0)
        return cadastrado;
  return -1;
}
int verificaNomeProfessor(char *nomeProfessor) {
  if (professoresCadastrados > 0)
    for (int posicao = 0; posicao < professoresCadastrados; posicao++)
      if ((strcmp(docente[posicao].dado.nome, nomeProfessor)) == 0)
        return posicao;
  return -1;
}

#endif // DataVerifies_h_included
