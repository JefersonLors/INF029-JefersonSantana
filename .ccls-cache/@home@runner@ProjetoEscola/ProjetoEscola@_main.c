#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include "./Backend/Backend.h";
#include "./Frontend/Frontend.h";

int main() {
  setlocale(LC_ALL, "");
  char menuPrincipal();
  void cadastrar();
  void atualizar();
  void listar();

  char opcao = '\0';

  enum MENU {
    Encerrar_Programa = '0',
    Realizar_Cadastro = '1',
    Atualizar_Cadastro = '2',
    Listar_Informacoes = '3',
    Filtro_por_palavra_chave = '4'
  };

  if (criaArquivos() && recuperaDadosGerais() && recuperaCadastrosAlunos() &&
      recuperaCadastrosProfessores() && recuperaCadastrosDisciplinas()) {
    do {
      opcao = menuPrincipal();
      switch (opcao) {
      case Realizar_Cadastro:
        cadastrar();
        break;
      case Atualizar_Cadastro:
        atualizar();
        break;
      case Listar_Informacoes:
        listar();
        break;
      case Filtro_por_palavra_chave:
        filtroPorPalavraChave();
        break;
      case Encerrar_Programa:
        printf("\n <<<<<<<<< Programa Encerrado >>>>>>>>>\n\n");
        break;
      }
    } while (opcao != Encerrar_Programa);
    salvaDadosGerais();
    return EXIT_SUCCESS;
  } else {
    puts("\t > FALHA NA RECUPERAÇÃO DE DADOS < \n");
    return EXIT_FAILURE;
  }
}
void cadastrar() {
  char menuCadastrar();
  bool cadastrarAluno();
  bool cadastrarProfessor();
  bool cadastrarDisciplina();

  char opcao = '\0';
  enum MENU { Aluno = '1', Professor = '2', Disciplina = '3', Voltar = '0' };

  do {
    opcao = menuCadastrar();
    switch (opcao) {
    case Professor:
      if (!cadastrarProfessor()) {
        puts("\t> Ops! Professor não cadastrado! <\n");
      } else {
        salvaCadastroProfessor();
        salvaDadosGerais();
      }
      break;
    case Aluno:
      if (!cadastrarAluno()) {
        puts("\t> Ops! Aluno não cadastrado! <\n");
      } else {
        salvaCadastroAluno();
        salvaDadosGerais();
      }
      break;
    case Disciplina:
      if (!cadastrarDisciplina()) {
        puts("\t> Ops! Discplina não cadastrada! <\n");
      } else {
        salvaCadastroDisciplina();
        salvaDadosGerais();
      }
      break;
    case Voltar:
      break;
    }
  } while (opcao != Voltar);
}
void listar() {
  void listarProfessores();
  void listarAlunos();
  void listarDisciplinas();
  void aniversarianteMes();
  char menuListar();

  char opcao = '\0';
  enum MENU {
    Aluno = '1',
    Professor = '2',
    Disciplina = '3',
    Aniversariantes = '4',
    Voltar = '0'
  };

  do {
    opcao = menuListar();
    switch (opcao) {
    case Professor:
      listarProfessores();
      break;
    case Aluno:
      listarAlunos();
      break;
    case Disciplina:
      listarDisciplinas();
      break;
    case Aniversariantes:
      aniversarianteMes();
      break;
    case Voltar:
      break;
    }
  } while (opcao != Voltar);
}
void atualizar() {
  bool atualizarProfessor();
  bool atualizarAluno();
  bool atualizarDisciplina();
  char menuAtualizar();

  char opcao = '\0';
  enum MENU { Aluno = '1', Professor = '2', Disciplina = '3', Voltar = '0' };

  do {
    opcao = menuAtualizar();
    switch (opcao) {
    case Professor:
      atualizarProfessor();
      break;
    case Aluno:
      atualizarAluno();
      break;
    case Disciplina:
      atualizarDisciplina();
      break;
    case Voltar:
      break;
    }
  } while (opcao != Voltar);
}
