#include "Backend/DataStructs/DataStructs.h";

#ifndef GERAIS_FILE_H
#define GERAIS_FILE_H

///==========//==========//=========//=========//

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

int verificaMatriculaProfessor(char *);
int verificaMatriculaAluno(char *);
int verificaNomeAluno(char *);
int verificaCpfAluno(char *);
int verificaCpfProfessor(char *);
int verificaCodigoDisciplina(char *);
int verificaNomeDisciplina(char *);
int verificaNomeProfessor(char *);

/// FUNÇÃO DE CRIAÇÃO DE ARQUIVOS
bool criaArquivos();

/// FUNÇÕES DE ARMAZENAMENTO DE DADOS
bool salvaDadosGerais();
bool salvaCadastroProfessor();
bool salvaCadastroDisciplina();
bool salvaCadastroAluno();

/// FUNÇÕES DE RECUPERAÇÃO DE DADOS
bool recuperaCadastrosAlunos();
bool recuperaCadastrosDisciplinas();
bool recuperaCadastrosProfessores();
bool recuperaDadosGerais();

/// FUNÇÕES DE ATUALIZAÇÃO DE DADOS
bool atualizaCadastroProfessor(unsigned);
bool atualizaCadastroAluno(unsigned);
bool atualizaCadastroDisciplina(unsigned);

///==========//==========//=========//=========//

/// DADOS QUANTITATIVOS PARA CONTROLE
int professoresCadastrados = 0, alunosCadastrados = 0,
    disciplinasCadastradas = 0;
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
      "àèìòùÀÈÌÒÙáéíóúýÁÉÍÓÚÝâêîôûÂÊÎÔÛãñõÃÑÕäëïöüÿÄËÏÖÜŸçÇ";

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
#endif /// GERAIS_FILE_H
