#ifndef DataStructs_h_included
#define DataStructs_h_included

/// TAMANHO DOS DADOS: ALUNOS/PROFESSORES
#define TAM_CPF 16
#define TAM_NAC 12
#define TAM_NOME 32
#define TAM_MAT 13
#define TAM_COD_MAT 20

/// TAMANHO DOS DADOS: DISCIPLINAS
#define TAM_COD_DISC 8
#define TAM_SEM 8
#define TAM_NOME_DISC 31
#define TAM_TURMA 40

/// QUANTIDADE MÁXIMA DE CADASTROS
#define quantMaxAluno 10
#define quantMaxProfessor 10
#define quantMaxDisciplina 10

/// TAMANHO DA GRADE DO ALUNO
#define TAM_MATRIZ 8

/// QUANTIDADE DE TURMAS DE UM PROFESSOR
#define TAM_MINIS 4
///==========//==========//=========//=========//

/// SEÇÃO DE REGISTROS
/// REGISTRO DE DADOS COMUNS: ALUNO/PROFESSOR
struct dados {
  char cpf[TAM_CPF];
  char nascimento[TAM_NAC];
  char nome[TAM_NOME];
  char matricula[TAM_MAT];
  char sexo;
};
typedef struct dados Dados;

/// REGISTRO DE PROFESSOR
struct professor {
  Dados dado;
  int ministrando[TAM_MINIS];
  int disciplinasMinistrando; /// inicializar e testar
} docente[quantMaxProfessor];
typedef struct professor Professor;

/// REGISTRO DE ALUNO
struct aluno {
  Dados dado;
  int matrizCurricular[TAM_MATRIZ];
  int disciplinasCursando; /// inicializar e testar
} discente[quantMaxAluno];
typedef struct aluno Aluno;

/// REGISTRO DE DISCIPLINAS
struct Disciplinas {
  char nome[TAM_NOME_DISC];
  char codigo[TAM_COD_DISC];
  char semestre[TAM_SEM];
  int vagas;
  int quantidadeMatriculado;
  int professorId; /// PODERIA UTILIZAR O ID DO PROFESSOR
} materia[quantMaxDisciplina];
typedef struct Disciplinas Disciplinas;

/// REGISTROS DE DADOS DE CONTROLE
struct {
  int professoresCadastradosBackup;
  int alunosCadastradosBackup;
  int disciplinasCadastradasBackup;
} dadosGerais;

///==========//==========//=========//=========//

/// SEÇÃO DE ARQUIVOS
char *arquivoDeProfessores = "arquivo_de_professores.txt";
char *arquivoDeAlunos = "arquivo_de_alunos.txt";
char *arquivoDeDisciplinas = "arquivo_de_disciplinas.txt";
char *arquivoDeDadosGerais = "arquivo_de_dados_gerais.txt";

/// DADOS QUANTITATIVOS PARA CONTROLE
int professoresCadastrados = 0;
int alunosCadastrados = 0;
int disciplinasCadastradas = 0;
///==========//==========//=========//=========//

#endif
