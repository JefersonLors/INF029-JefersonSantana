#include "../Enroll/Enroll.h"
#include "../Interfaces/Interfaces.h"
#include <string.h>

#ifndef Update_h_included
#define Update_h_included

/// FUNÇÕES DE ATUALIZAÇÃO DE DADOS DE PROFESSORES
bool atualizaMatriculaProfessor(unsigned);
bool atualizaNomeProfessor(unsigned);
bool atualizaNascimentoProfessor(unsigned);
bool atualizaCpfProfessor(unsigned);
bool atualizaSexoProfessor(unsigned);
bool atualizaGradeProfessor(unsigned);

/// FUNÇÕES DE ATUALIZAÇÃO DE DADOS DE ALUNOS
bool atualizaMatriculaAluno(unsigned);
bool atualizaNomeAluno(unsigned);
bool atualizaNascimentoAluno(unsigned);
bool atualizaCpfAluno(unsigned);
bool atualizaSexoAluno(unsigned);
bool atualizaGradeAluno(unsigned);

/// FUNÇÕES DE ATUALIZAÇÃO DE DADOS DE DISCIPLINAS
bool atualizaNomeDisciplina(unsigned);
bool atualizaCodigo(unsigned);
bool atualizaSemestre(unsigned);
bool atualizaVagas(unsigned);
bool atualizaProfessor(unsigned);

/// FUNÇÕES DE EXCLUSÃO DE CADASTROS
bool excluiCadastroProfessor(unsigned);
bool excluiCadastroAluno(unsigned);
bool excluiCadastroDisciplina(unsigned);

/// FUNÇÕES DE AJUSTES
void ajusteDisciplinasCadastradas(unsigned id);
void ajusteAlunosCadastrados(unsigned id);
void ajusteProfessoresCadastrados(unsigned id);
///==========//==========//=========//=========//

char subMenuEscolhaDeDado_1();
char subMenuEscolhaDeDado_2();
char subMenuTipoDeAtualizacao();
char subMenuTipoDeAtualizacaoGrade();

bool atualizarProfessor() {
  enum TIPO { MODIFICAR = '1', EXCLUIR = '2', Voltar = '0' };

  enum MENU {
    CPF = '1',
    NOME = '2',
    MATRICULA = '3',
    NASCIMENTO = '4',
    SEXO = '5',
    GRADE = '6',
    Tudo = '7'
  };
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;

  int idProfessor = -1, escolha;
  char nomeProfessorTemp[TAM_NOME];

  do {
    printf("====================================\n"
           "||      ATUALIZANDO PROFESSOR     || \n"
           "====================================\n"
           "- Digite o nome do professor:\n-> ");
    fgets(nomeProfessorTemp, TAM_NOME, stdin);
    printf("\n");
    limpaTexto(nomeProfessorTemp);

    if (sair(nomeProfessorTemp[0], nomeProfessorTemp[1])) {
      return false;
    } else {
      DADO = validaNome(nomeProfessorTemp);
      if (DADO == VALIDO) {
        padronizaNome(nomeProfessorTemp);
        idProfessor = verificaNomeProfessor(nomeProfessorTemp);
        if (idProfessor == -1) {
          puts("\t > Professor não cadastrado <\n");
          DADO = INVALIDO;
        }
      }
    }
  } while (DADO == INVALIDO);
  do {
    printf("DOCENTE: %s\n\n", docente[idProfessor].dado.nome);
    switch (subMenuTipoDeAtualizacao()) {
    case MODIFICAR:
      do {
        printf("DOCENTE: %s\n\n", docente[idProfessor].dado.nome);
        escolha = subMenuEscolhaDeDado_1();
        switch (escolha) {
        case CPF:
          if (!atualizaCpfProfessor(idProfessor)) {
            puts("\t> Cpf não atualizado < \n");
          } else {
            atualizaCadastroProfessor(idProfessor);
            puts("\t> Cpf atualizado < \n");
          }
          break;
        case NOME:
          if (!atualizaNomeProfessor(idProfessor)) {
            puts("\t> Nome não atualizado < \n");
          } else {
            atualizaCadastroProfessor(idProfessor);
            puts("\t> Nome atualizado < \n");
          }
          break;
        case MATRICULA:
          if (!atualizaMatriculaProfessor(idProfessor)) {
            puts("\t> Matricula não atualizada < \n");
          } else {
            atualizaCadastroProfessor(idProfessor);
            puts("\t> Matricula atualizada <\n");
          }
          break;
        case NASCIMENTO:
          if (!atualizaNascimentoProfessor(idProfessor)) {
            puts("\t> Data de Nascimento não atualizada <\n");
          } else {
            atualizaCadastroProfessor(idProfessor);
            puts("\t> Data de Nascimento atualizada <\n");
          }
          break;
        case SEXO:
          if (!atualizaSexoProfessor(idProfessor)) {
            puts("\t> Sexo não atualizado <\n ");
          } else {
            atualizaCadastroProfessor(idProfessor);
            puts("\t> Sexo atualizado <\n ");
          }
          break;
        case GRADE:
          if (!atualizaGradeProfessor(idProfessor)) {
            puts("\t > Grade não atualizada <\n");
          } else {
            atualizaCadastroProfessor(idProfessor);
            puts("\t Grade atualizada <\n");
          }
          break;
        case Tudo:
          if (atualizaCpfProfessor(idProfessor)) {
            if (atualizaCadastroProfessor(idProfessor) &&
                atualizaNomeProfessor(idProfessor)) {
              if (atualizaCadastroProfessor(idProfessor) &&
                  atualizaMatriculaProfessor(idProfessor)) {
                if (atualizaCadastroProfessor(idProfessor) &&
                    atualizaNascimentoProfessor(idProfessor)) {
                  if (atualizaCadastroProfessor(idProfessor) &&
                      atualizaSexoProfessor(idProfessor)) {
                    if (atualizaCadastroProfessor(idProfessor) &&
                        atualizaGradeProfessor(idProfessor)) {
                      atualizaCadastroProfessor(idProfessor);
                      puts("\t > Dados atualizados! < \n");
                    } else
                      puts("\t > Grade não atualizada < \n");
                  } else
                    puts("\t > Sexo não atualizado < \n");
                } else
                  puts("\t > Data de Nascimento não atualizada < \n ");
              } else
                puts("\t > Matricula não atualizada < \n");
            } else
              puts("\t > Nome não atualizado < \n");
          } else
            puts("\t> Cpf não atualizado < \n");
          break;
        case Voltar:
          break;
        }
      } while (escolha != Voltar);
      break;
    case EXCLUIR:
      if (subMenuConfirmaExclusao() == '1') {
        excluiCadastroProfessor(idProfessor);
        for (int id = 0; id < professoresCadastrados; id++) {
          atualizaCadastroProfessor(id);
        }
        salvaDadosGerais();
        return true;
      }
      break;
    case Voltar:
      return true;
    }
  } while (true);
}
bool atualizaMatriculaProfessor(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char matriculaTemp[TAM_MAT];
  do {
    printf("- Digite o novo numero de matrícula: [EX: 01234567890]\n-> ");
    fgets(matriculaTemp, TAM_MAT, stdin);
    printf("\n");

    if (sair(matriculaTemp[0], matriculaTemp[1])) {
      return false;
    } else {
      limpaTexto(matriculaTemp);
      DADO = validaMatricula(matriculaTemp);
      if (DADO == VALIDO && ((verificaMatriculaProfessor(matriculaTemp)) > -1 ||
                             (verificaMatriculaAluno(matriculaTemp)) > -1)) {
        puts("> Matrícula repetida <");
        DADO = INVALIDO;
      } else {
        strcmp(docente[id].dado.matricula, matriculaTemp);
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool atualizaNomeProfessor(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char nomeTemp[TAM_NOME];

  do {
    printf("- Digite o novo nome do professor:\n-> ");
    fgets(nomeTemp, TAM_NOME, stdin);
    printf("\n");
    limpaTexto(nomeTemp);

    if (sair(nomeTemp[0], nomeTemp[1])) {
      return false;
    } else {
      DADO = validaNome(nomeTemp);
      if (DADO == VALIDO) {
        padronizaNome(nomeTemp);
        strcpy(docente[id].dado.nome, nomeTemp);
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool atualizaNascimentoProfessor(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char nascimentoTemp[TAM_NAC];

  do {
    printf("- Digite a nova data de nascimento: [EX: 00/00/0000]\n-> ");
    fgets(nascimentoTemp, TAM_NAC, stdin);
    printf("\n");
    limpaTexto(nascimentoTemp);

    if (sair(nascimentoTemp[0], nascimentoTemp[1])) {
      return false;
    } else {
      DADO = validaNascimento(nascimentoTemp);
      if (DADO == VALIDO) {
        strcpy(docente[id].dado.nascimento, nascimentoTemp);
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool atualizaCpfProfessor(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char cpfTemp[TAM_CPF];

  do {
    printf("- Digite o novo CPF: [EX: 000.000.000-00]\n-> ");
    fgets(cpfTemp, TAM_CPF, stdin);
    printf("\n");

    if (sair(cpfTemp[0], cpfTemp[1])) {
      return false;
    } else {
      limpaTexto(cpfTemp);
      DADO = validaCpf(cpfTemp);

      if (DADO == VALIDO && ((verificaCpfProfessor(cpfTemp)) > -1 ||
                             (verificaCpfAluno(cpfTemp)) > -1)) {
        puts("> CPF repetido <");
        DADO = INVALIDO;
      } else {
        strcpy(docente[id].dado.cpf, cpfTemp);
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool atualizaSexoProfessor(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char sexoTemp[4];

  do {
    printf("- Digite o novo sexo: [Opções: F, M OU O]\n-> ");
    fgets(sexoTemp, 4, stdin);
    printf("\n");

    if (sair(sexoTemp[0], sexoTemp[1])) {
      return false;
    } else {
      DADO = validaSexo(sexoTemp[0]);
      if (DADO == VALIDO) {
        docente[id].dado.sexo = aumentaLetra(sexoTemp[0]);
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool atualizaGradeProfessor(unsigned id) {
  enum TIPO { MATRICULAR = '1', DESMATRICULAR = '2', Voltar = '0' };
  char escolha;

  do {
    escolha = subMenuTipoDeAtualizacaoGrade();
    switch (escolha) {
    case MATRICULAR:
      matricularProfessor(id);
      break;
    case DESMATRICULAR:
      desmatricularProfessor(id);
      break;
    case Voltar:
      break;
    }
  } while (escolha != Voltar);

  return true;
}
bool excluiCadastroProfessor(unsigned id) {
  /// exclui das disciplinas
  for (int posicao = 0; posicao < disciplinasCadastradas; posicao++) {
    if ((materia[posicao].professorId - 1) == id) {
      materia[posicao].professorId = -1;
      atualizaCadastroDisciplina(posicao);
    }
  }
  ajusteProfessoresCadastrados(id);

  return true;
}
bool atualizarAluno() {
  enum TIPO { MODIFICAR = '1', EXCLUIR = '2', Voltar = '0' };

  enum MENU {
    CPF = '1',
    NOME = '2',
    MATRICULA = '3',
    NASCIMENTO = '4',
    SEXO = '5',
    GRADE = '6',
    Tudo = '7'
  };
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;

  int idAluno = -1, escolha;
  char nomeAlunoTemp[TAM_NOME];

  do {
    printf("====================================\n"
           "||        ATUALIZANDO ALUNO       || \n"
           "====================================\n"
           "- Digite o nome do aluno:\n-> ");
    fgets(nomeAlunoTemp, TAM_NOME, stdin);
    printf("\n");
    limpaTexto(nomeAlunoTemp);

    if (sair(nomeAlunoTemp[0], nomeAlunoTemp[1])) {
      return false;
    } else {
      DADO = validaNome(nomeAlunoTemp);
      if (DADO == VALIDO) {
        padronizaNome(nomeAlunoTemp);
        idAluno = verificaNomeAluno(nomeAlunoTemp);
        if (idAluno == -1) {
          puts("\t > Aluno não cadastrado < \n");
          DADO = INVALIDO;
        }
      }
    }
  } while (DADO == INVALIDO);
  do {
    printf("DISCENTE: %s\n\n", discente[idAluno].dado.nome);
    switch (subMenuTipoDeAtualizacao()) {
    case MODIFICAR:
      do {
        printf("DISCENTE: %s\n\n", discente[idAluno].dado.nome);
        escolha = subMenuEscolhaDeDado_1();
        switch (escolha) {
        case CPF:
          if (!atualizaCpfAluno(idAluno)) {
            puts("\t> Cpf não atualizado < \n");
          } else {
            atualizaCadastroAluno(idAluno);
            puts("\t> Cpf atualizado < \n");
          }
          break;
        case NOME:
          if (!atualizaNomeAluno(idAluno)) {
            puts("\t > Nome não atualizado < ");
          } else {
            atualizaCadastroAluno(idAluno);
            puts("\t> Nome atualizado < \n");
          }
          break;
        case MATRICULA:
          if (!atualizaMatriculaAluno(idAluno)) {
            puts("\t> Matricula não atualizada < \n");
          } else {
            atualizaCadastroAluno(idAluno);
            puts("\t > Matricula atualizada < \n");
          }
          break;
        case NASCIMENTO:
          if (!atualizaNascimentoAluno(idAluno)) {
            puts("\t > Data de Nascimento não atualizada < \n");
          } else {
            atualizaCadastroAluno(idAluno);
            puts("\t > Data de Nascimento atualizada <\n");
          }
          break;
        case SEXO:
          if (!atualizaSexoAluno(idAluno)) {
            puts("\t> Sexo não atualizado < \n");
          } else {
            atualizaCadastroAluno(idAluno);
            puts("\t > Sexo atualizado < \n");
          }
          break;
        case GRADE:
          if (!atualizaGradeAluno(idAluno)) {
            puts("\t > Grade não atualizada < \n");
          } else {
            atualizaCadastroAluno(idAluno);
            puts("\t > Grade atualizada <\n");
          }
          break;
        case Tudo:
          if (atualizaCpfAluno(idAluno)) {
            if (atualizaCadastroAluno(idAluno) && atualizaNomeAluno(idAluno)) {
              if (atualizaCadastroAluno(idAluno) &&
                  atualizaMatriculaAluno(idAluno)) {
                if (atualizaCadastroAluno(idAluno) &&
                    atualizaNascimentoAluno(idAluno)) {
                  if (atualizaCadastroAluno(idAluno) &&
                      atualizaSexoAluno(idAluno)) {
                    if (atualizaCadastroAluno(idAluno) &&
                        atualizaGradeAluno(idAluno)) {
                      atualizaCadastroAluno(idAluno);
                      puts("\t> Dados atualizados < \n");
                    } else
                      puts("\t> Grade não atualizada < \n");
                  } else
                    puts("\t> Sexo não atualizado < \n");
                } else
                  puts("\t> Data de Nascimento não atualizada < \n");
              } else
                puts("\t> Matricula não atualizada < \n");
            } else
              puts("\t> Nome não atualizado < \n");
          } else
            puts("\t> Cpf não atualizado < \n");
          break;
        case Voltar:
          break;
        }
      } while (escolha != Voltar);
      break;
    case EXCLUIR:
      if (subMenuConfirmaExclusao() == '1') {
        excluiCadastroAluno(idAluno);
        for (int id = 0; id < alunosCadastrados; id++) {
          atualizaCadastroAluno(id);
        }
        salvaDadosGerais();
        return true;
      }
      break;
    case Voltar:
      return true;
    }
  } while (true);
}
bool atualizaMatriculaAluno(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char matriculaTemp[TAM_MAT];
  do {
    printf("- Digite o novo numero de matrícula: [EX: 01234567890]\n-> ");
    fgets(matriculaTemp, TAM_MAT, stdin);
    printf("\n");

    if (sair(matriculaTemp[0], matriculaTemp[1])) {
      return false;
    } else {
      limpaTexto(matriculaTemp);
      DADO = validaMatricula(matriculaTemp);
      if (DADO == VALIDO && ((verificaMatriculaProfessor(matriculaTemp)) > -1 ||
                             (verificaMatriculaAluno(matriculaTemp)) > -1)) {
        puts("\t> Matrícula repetida < \n");
        DADO = INVALIDO;
      } else {
        strcpy(discente[id].dado.matricula, matriculaTemp);
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool atualizaNomeAluno(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char nomeTemp[TAM_NOME];

  do {
    printf("- Digite o novo nome do aluno:\n-> ");
    fgets(nomeTemp, TAM_NOME, stdin);
    printf("\n");
    limpaTexto(nomeTemp);

    if (sair(nomeTemp[0], nomeTemp[1])) {
      return false;
    } else {
      DADO = validaNome(nomeTemp);
      if (DADO == VALIDO) {
        padronizaNome(nomeTemp);
        strcpy(discente[id].dado.nome, nomeTemp);
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool atualizaNascimentoAluno(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char nascimentoTemp[TAM_NAC];

  do {
    printf("- Digite a nova data de nascimento: [EX: 00/00/0000]\n-> ");
    fgets(nascimentoTemp, TAM_NAC, stdin);
    printf("\n");
    limpaTexto(nascimentoTemp);

    if (sair(nascimentoTemp[0], nascimentoTemp[1])) {
      return false;
    } else {
      DADO = validaNascimento(nascimentoTemp);
      if (DADO == VALIDO) {
        strcpy(discente[id].dado.nascimento, nascimentoTemp);
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool atualizaCpfAluno(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char cpfTemp[TAM_CPF];

  do {
    printf("- Digite o novo CPF: [EX: 000.000.000-00]\n-> ");
    fgets(cpfTemp, TAM_CPF, stdin);
    printf("\n");

    if (sair(cpfTemp[0], cpfTemp[1])) {
      return false;
    } else {
      limpaTexto(cpfTemp);
      DADO = validaCpf(cpfTemp);

      if (DADO == VALIDO && ((verificaCpfProfessor(cpfTemp)) > -1 ||
                             (verificaCpfAluno(cpfTemp)) > -1)) {
        puts("> CPF repetido <");
        DADO = INVALIDO;
      } else {
        strcpy(discente[id].dado.cpf, cpfTemp);
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool atualizaSexoAluno(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char sexoTemp[4];

  do {
    printf("- Digite o novo sexo: [Opções: F, M OU O]\n-> ");
    fgets(sexoTemp, 4, stdin);
    printf("\n");

    if (sair(sexoTemp[0], sexoTemp[1])) {
      return false;
    } else {
      DADO = validaSexo(sexoTemp[0]);
      if (DADO == VALIDO) {
        discente[id].dado.sexo = aumentaLetra(sexoTemp[0]);
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool atualizaGradeAluno(unsigned id) {
  enum TIPO { MATRICULAR = '1', DESMATRICULAR = '2', Voltar = '0' };
  char escolha;

  do {
    escolha = subMenuTipoDeAtualizacaoGrade();
    switch (escolha) {
    case MATRICULAR:
      matricularAluno(id);
      break;
    case DESMATRICULAR:
      desmatricularAluno(id);
      break;
    case Voltar:
      break;
    }
  } while (escolha != Voltar);
  return true;
}
bool excluiCadastroAluno(unsigned id) {
  /// exclui das disciplinas
  if (discente[id].disciplinasCursando > 0) {
    for (int idDisciplina = 0; idDisciplina < disciplinasCadastradas;
         idDisciplina++) {
      for (int posicao = 0; posicao < discente[id].disciplinasCursando;
           posicao++) {
        if (idDisciplina == discente[id].matrizCurricular[posicao])
          materia[idDisciplina].quantidadeMatriculado--;
        atualizaCadastroDisciplina(idDisciplina);
      }
    }
  }
  ajusteAlunosCadastrados(id);

  return true;
}
bool atualizarDisciplina() {
  enum TIPO { MODIFICAR = '1', EXCLUIR = '2', Voltar = '0' };

  enum MENU {
    CODIGO = '1',
    NOME = '2',
    SEMESTRE = '3',
    VAGAS = '4',
    PROFESSOR = '5',
    Tudo = '6'
  };
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;

  int idDisciplina = -1, escolha;
  char nomeDisciplinaTemp[TAM_NOME_DISC];

  do {
    printf("===================================\n"
           "||     ATUALIZANDO DISCIPLINA    || \n"
           "===================================\n"
           "- Digite o nome da disciplina:\n-> ");
    fgets(nomeDisciplinaTemp, TAM_NOME_DISC, stdin);
    printf("\n");
    limpaTexto(nomeDisciplinaTemp);

    if (sair(nomeDisciplinaTemp[0], nomeDisciplinaTemp[1])) {
      return false;
    } else {
      DADO = validaNome(nomeDisciplinaTemp);
      if (DADO == VALIDO) {
        strcpy(nomeDisciplinaTemp, caixaAlta(nomeDisciplinaTemp));
        idDisciplina = verificaNomeDisciplina(nomeDisciplinaTemp);
        if (idDisciplina == -1) {
          puts("\t > Disciplina não cadastrada < \n ");
          DADO = INVALIDO;
        }
      }
    }
  } while (DADO == INVALIDO);
  do {
    printf("DISCPLINA: %s\n\n", materia[idDisciplina].nome);
    switch (subMenuTipoDeAtualizacao()) {
    case MODIFICAR:
      do {
        printf("DISCPLINA: %s\n\n", materia[idDisciplina].nome);
        escolha = subMenuEscolhaDeDado_2();
        switch (escolha) {
        case CODIGO:
          if (!atualizaCodigo(idDisciplina)) {
            puts("\t > Codigo não atualizado < \n");
          } else {
            atualizaCadastroDisciplina(idDisciplina);
            puts("\t > Codigo atualizado < \n");
          }
          break;
        case NOME:
          if (!atualizaNomeDisciplina(idDisciplina)) {
            puts("\t > Nome não atualizado < \n");
          } else {
            atualizaCadastroDisciplina(idDisciplina);
            puts("\t> Nome atualizado < \n");
          }
          break;
        case SEMESTRE:
          if (!atualizaSemestre(idDisciplina)) {
            puts("\t> Semestre não atualizado < \n");
          } else {
            atualizaCadastroDisciplina(idDisciplina);
            puts("\t > Semestre atualizado <\n");
          }
          break;
        case VAGAS:
          if (!atualizaVagas(idDisciplina)) {
            puts("\t> Vagas não atualizadas <\n");
          } else {
            atualizaCadastroDisciplina(idDisciplina);
            puts("\t> Vagas atualizadas <\n");
          }
          break;
        case PROFESSOR:
          if (!atualizaProfessor(idDisciplina)) {
            puts("\t > Professor não atualizado < \n");
          } else {
            atualizaCadastroDisciplina(idDisciplina);
            puts("\t> Professor atualizado < \n");
          }
          break;
        case Tudo:
          if (atualizaCodigo(idDisciplina)) {
            if (atualizaCadastroDisciplina(idDisciplina) &&
                atualizaNomeDisciplina(idDisciplina)) {
              if (atualizaCadastroDisciplina(idDisciplina) &&
                  atualizaSemestre(idDisciplina)) {
                if (atualizaCadastroDisciplina(idDisciplina) &&
                    atualizaVagas(idDisciplina)) {
                  if (atualizaCadastroDisciplina(idDisciplina) &&
                      atualizaProfessor(idDisciplina)) {
                    atualizaCadastroDisciplina(idDisciplina);
                    puts("\t> Dados atualizados!");
                  } else
                    puts("\t> Professor não atualizado <\n");
                } else
                  puts("\t> Semestre não atualizada <\n");
              } else
                puts("\t> Vagas não atualizada <\n");
            } else
              puts("\t> Nome não atualizado <\n");
          } else
            puts("\t> Codigo não atualizado <\n");
          break;
        case Voltar:
          break;
        }
      } while (escolha != Voltar);
      break;
    case EXCLUIR:
      if (subMenuConfirmaExclusao() == '1') {
        excluiCadastroDisciplina(idDisciplina);
        for (int id = 0; id < disciplinasCadastradas; id++) {
          atualizaCadastroDisciplina(id);
        }
        salvaDadosGerais();
        return true;
      }
      break;
    case Voltar:
      return true;
    }
  } while (true);
}
bool atualizaNomeDisciplina(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char nomeDisciplinaTemp[TAM_NOME_DISC];

  do {
    printf("- Digite o novo nome da disciplina:\n-> ");
    fgets(nomeDisciplinaTemp, TAM_NOME_DISC, stdin);
    printf("\n");

    if (sair(nomeDisciplinaTemp[0], nomeDisciplinaTemp[1])) {
      return false;
    } else {
      limpaTexto(nomeDisciplinaTemp);
      strcpy(nomeDisciplinaTemp, caixaAlta(nomeDisciplinaTemp));
      DADO = validaNome(nomeDisciplinaTemp);
      if (DADO == VALIDO) {
        if ((verificaNomeDisciplina(nomeDisciplinaTemp)) == -1) {
          strcpy(materia[id].nome, nomeDisciplinaTemp);
        } else {
          DADO = INVALIDO;
          puts("\t> Esse nome já está associado a outra disciplina <\n");
        }
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool atualizaCodigo(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char codigoDisciplinaTemp[TAM_COD_DISC];

  do {
    printf("- Digite o novo código da disciplina: [EX: EXE123]\n-> ");
    fgets(codigoDisciplinaTemp, TAM_COD_DISC, stdin);
    printf("\n");

    if (sair(codigoDisciplinaTemp[0], codigoDisciplinaTemp[1])) {
      return false;
    } else {
      limpaTexto(codigoDisciplinaTemp);
      DADO = validaCodigo(codigoDisciplinaTemp);
      if (DADO == VALIDO) {
        if ((verificaCodigoDisciplina(materia[id].codigo)) == -1) {
          strcpy(materia[id].codigo, caixaAlta(codigoDisciplinaTemp));
        } else {
          DADO = INVALIDO;
          puts("\t> Código associado a outra disciplina <\n");
        }
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool atualizaSemestre(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char semestreTemp[TAM_SEM];

  do {
    printf("- Digite o novo semestre da disciplina: [EX: 2022.1]\n-> ");
    fgets(semestreTemp, TAM_SEM, stdin);
    printf("\n");

    if (sair(semestreTemp[0], semestreTemp[1])) {
      return false;
    } else {
      limpaTexto(semestreTemp);
      DADO = validaSemestre(semestreTemp);
    }
  } while (DADO == INVALIDO);
  strcpy(materia[id].semestre, semestreTemp);
  return true;
}
bool atualizaVagas(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  int vagasTemp;

  do {
    printf("- Digite o novo número de vagas da disciplina:\n-> ");
    scanf("%d", &vagasTemp);
    getchar();
    printf("\n");
    if (vagasTemp == -1) {
      return false;
    } else {
      DADO = validaVagas(vagasTemp);
      if (DADO == VALIDO && vagasTemp >= materia[id].quantidadeMatriculado) {
        materia[id].vagas = vagasTemp;
      } else {
        puts("\t > O número de vagas é menor que a turma atual < \n");
        DADO == INVALIDO;
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool atualizaProfessor(unsigned id) {
  enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
  enum VALIDAR DADO;
  char professorTemp[TAM_NOME];

  do {
    printf("- Digite o novo professor da disciplina:\n-> ");
    fgets(professorTemp, TAM_NOME, stdin);
    printf("\n");

    if (sair(professorTemp[0], professorTemp[1])) {
      return false;
    } else {
      limpaTexto(professorTemp);
      DADO = validaProfessores(professorTemp);
      if (DADO == VALIDO) {
        padronizaNome(professorTemp);
        int sucessorId = verificaNomeProfessor(professorTemp);
        if (sucessorId > -1) {
          if (docente[sucessorId].disciplinasMinistrando < TAM_MINIS) {
            int antecessorId = verificaNomeProfessor(
                docente[materia[id].professorId].dado.nome);
            docente[antecessorId].disciplinasMinistrando--;
            atualizaCadastroProfessor(antecessorId);
            materia[id].professorId = sucessorId + 1;
            docente[sucessorId]
                .ministrando[docente[sucessorId].disciplinasMinistrando++] = id;
            atualizaCadastroProfessor(sucessorId);
          } else {
            puts("\t > A grade desse professor já está cheia <\n");
          }
        } else {
          puts("\t> Esse professor não está cadastrado <\n");
        }
      }
    }
  } while (DADO == INVALIDO);

  return true;
}
bool excluiCadastroDisciplina(unsigned id) {
  for (int discId = 0; discId < alunosCadastrados; discId++) {
    if (discente[discId].disciplinasCursando > 0) {
      for (int posicao = 0; posicao < discente[discId].disciplinasCursando;
           posicao++) {
        if (id == discente[discId].matrizCurricular[posicao])
          ajusteGradeAluno(discId, id);
        atualizaCadastroAluno(discId);
      }
    }
  }

  for (int docId = 0; docId < professoresCadastrados; docId++) {
    if (docente[docId].disciplinasMinistrando > 0) {
      for (int posicao = 0; posicao < docente[docId].disciplinasMinistrando;
           posicao++) {
        if (id == docente[docId].ministrando[posicao])
          ajusteGradeProfessor(docId, id);
        atualizaCadastroProfessor(docId);
      }
    }
  }
  ajusteDisciplinasCadastradas(id);
  return true;
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
#endif // Update_h_included
