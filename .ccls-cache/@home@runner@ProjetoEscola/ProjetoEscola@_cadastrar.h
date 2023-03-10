#ifndef CADASTRO_FILE_H
#define CADASTRO_FILE_H
#include "./_validar.h"
#include "_atualizar.h"

///FUNÇÕES DE SOLICITAÇÃO DE DADOS DE PROFESSORES
bool solicitaMatriculaProfessor( );
bool solicitaNomeProfessor( );
bool solicitaNascimentoProfessor( );
bool solicitaCpfProfessor( );
bool solicitaSexoProfessor( );

///FUNÇÕES DE SOLICITAÇÃO DE DADOS DE ALUNOS
bool solicitaMatriculaAluno( );
bool solicitaNomeAluno( );
bool solicitaNascimentoAluno( );
bool solicitaCpfAluno( );
bool solicitaSexoAluno( );

///FUNÇÕES DE SOLICITAÇÃO DE DADOS DE DISCIPLINAS
bool solicitaNomeDisciplina( );
bool solicitaCodigo( );
bool solicitaSemestre( );
bool solicitaVagas( );
bool solicitaProfessor( );
///==========//==========//=========//=========//

bool cadastrarProfessor( ){
    if( professoresCadastrados < quantMaxProfessor ){
        printf ("=================================================\n"
                "||           CADASTRANDO - PROFESSOR           || \n"
                "=================================================\n");
        professoresCadastrados++;
        if( solicitaMatriculaProfessor( ) )
            if( solicitaNomeProfessor( ) )
                if( solicitaNascimentoProfessor( ) )
                    if( solicitaCpfProfessor( ) )
                        if( solicitaSexoProfessor( ) ){
                            puts( "< CADASTRO DE PROFESSOR FINALIZADO COM SUCESSO! >\n" );
                            return true;}
        professoresCadastrados--;
        return false;
    }else{
        puts( "\t> Quantidade máxima atingida <\n" );
        return false; }
}

bool solicitaMatriculaProfessor( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = professoresCadastrados - 1;
    char matriculaTemp[TAM_MAT];

    strcpy( docente[posicao].dado.matricula, " " );

    do{
        printf("- Digite o numero de matrícula: [EX: 01234567890]\n-> ");
        fgets( matriculaTemp, TAM_MAT, stdin);

        if( sair( matriculaTemp[0], matriculaTemp[1] ) ){
            return false;
        }else{
            limpaTexto(matriculaTemp);
            DADO = validaMatricula( matriculaTemp );
            if( DADO == VALIDO && ( ( verificaMatriculaProfessor( matriculaTemp ) ) > -1
                || ( verificaMatriculaAluno( matriculaTemp ) ) > -1 ) ){
                puts( "\t> Matrícula repetida <\n");
                DADO = INVALIDO;}}
    }while( DADO == INVALIDO );

    strcpy( docente[posicao].dado.matricula, matriculaTemp );

    return true;
}
bool solicitaNomeProfessor( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = professoresCadastrados - 1;
    char nomeTemp[TAM_NOME];

    do{
        printf("- Digite o nome do professor:\n-> ");
        fgets(nomeTemp, TAM_NOME, stdin);
        limpaTexto(nomeTemp);

        if( sair( nomeTemp[0], nomeTemp[1] ) ){
            return false;
        }else{
            DADO = validaNome( nomeTemp );}
    }while( DADO == INVALIDO );

    padronizaNome( nomeTemp );
    strcpy( docente[posicao].dado.nome, nomeTemp);

    return true;
}
bool solicitaNascimentoProfessor( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = professoresCadastrados - 1;
    char nascimentoTemp[TAM_NAC];

    do{
        printf("- Digite a data de nascimento: [EX: 00/00/0000]\n-> ");
        fgets(nascimentoTemp, TAM_NAC, stdin);

        limpaTexto(nascimentoTemp);
        if( sair( nascimentoTemp[0], nascimentoTemp[1] ) ){
            return false;
        }else{ DADO = validaNascimento( nascimentoTemp );}
    }while( DADO == INVALIDO );

    strcpy( docente[posicao].dado.nascimento, nascimentoTemp );

    return true;
}
bool solicitaCpfProfessor(){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = professoresCadastrados - 1;
    char cpfTemp[TAM_CPF];

    strcpy( docente[posicao].dado.cpf, " " );

    do{
        printf("- Digite o CPF: [EX: 000.000.000-00]\n-> ");
        fgets(cpfTemp, TAM_CPF, stdin);

        if( sair( cpfTemp[0], cpfTemp[1] ) ){
            return false;
        }else{
            limpaTexto(cpfTemp);
            DADO = validaCpf ( cpfTemp );
            if( DADO == VALIDO && ( ( verificaCpfProfessor( cpfTemp ) ) > -1
                || ( verificaCpfAluno( cpfTemp ) ) > -1 ) ){
                puts( "\t> CPF repetido <\n");
                DADO = INVALIDO;}}
    }while( DADO == INVALIDO );

    strcpy( docente[posicao].dado.cpf, cpfTemp );

    return true;
}
bool solicitaSexoProfessor( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = professoresCadastrados - 1;
    char sexoTemp[4];

    do{
        printf("- Digite o sexo: [Opções: F, M OU O]\n-> ");
        fgets( sexoTemp, 4, stdin);

        if( sair( sexoTemp[0], sexoTemp[1] ) ){
            return false;
        }else{ DADO = validaSexo(sexoTemp[0]);}
    }while( DADO == INVALIDO );

    docente[posicao].dado.sexo = aumentaLetra(sexoTemp[0]);

    return true;
}

bool cadastrarAluno(){
    if( alunosCadastrados < quantMaxAluno ){
        printf ("================================================\n"
                "||            CADASTRANDO - ALUNO             || \n"
                "================================================\n");
        alunosCadastrados++;
        if( solicitaMatriculaAluno( ) )
           if( solicitaNomeAluno( ) )
                if( solicitaNascimentoAluno( ) )
                    if( solicitaCpfAluno( ) )
                        if( solicitaSexoAluno( ) ){
                            puts( "<<< CADASTRO DE ALUNO FINALIZADO COM SUCESSO! >>>\n" );
                            return true;}
        alunosCadastrados--;
        return false;
    }else{
        puts( "\t> Quantidade máxima atingida <\n" );
        return false; }
}

bool solicitaMatriculaAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = alunosCadastrados - 1;
    char matriculaTemp[TAM_MAT];

    strcpy( discente[posicao].dado.matricula, " " );

    do{
        printf("- Digite a matricula do Aluno: [EX: 01234567890]\n-> ");
        fgets( matriculaTemp, TAM_MAT, stdin);

        if( sair( matriculaTemp[0], matriculaTemp[1] ) ){
            return false;
        }else{
            limpaTexto( matriculaTemp );
            DADO = validaMatricula( matriculaTemp );
            if( DADO == VALIDO && ( ( verificaMatriculaProfessor( matriculaTemp ) ) > -1
                || ( verificaMatriculaAluno( matriculaTemp ) ) > -1 ) ){
                puts( "\t> Matricula repetida <\n");
                DADO = INVALIDO;}}
    }while( DADO == INVALIDO );

    strcpy( discente[posicao].dado.matricula, matriculaTemp );

    return true;
}
bool solicitaNomeAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = alunosCadastrados - 1;
    char nomeTemp[TAM_NOME];

    do{
        printf("- Digite o nome do Aluno:\n-> ");
        fgets( nomeTemp, TAM_NOME, stdin);

        limpaTexto( nomeTemp );
        if( sair( nomeTemp[0], nomeTemp[1]) ){
            return false;
        }else{ DADO = validaNome( nomeTemp );}
    }while( DADO == INVALIDO );

    padronizaNome( nomeTemp );
    strcpy( discente[posicao].dado.nome, nomeTemp );

    return true;
}
bool solicitaCpfAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = alunosCadastrados - 1;
    char cpfTemp[TAM_CPF];

    strcpy( discente[posicao].dado.cpf, " " );

    do{
        printf("- Digite o CPF: [EX: 000.000.000-00]\n-> ");
        fgets( cpfTemp, TAM_CPF, stdin);

        if( sair( cpfTemp[0], cpfTemp[1])){
            return false;
        }else{
            limpaTexto( cpfTemp );
            DADO = validaCpf ( cpfTemp );
            if( DADO == VALIDO && ( ( verificaCpfAluno( cpfTemp ) ) > -1
                || ( verificaCpfProfessor( cpfTemp ) ) > -1 ) ){
                puts( "\t> CPF repetido <\n");
                DADO = INVALIDO;}}
    }while( DADO == INVALIDO );

    strcpy( discente[posicao].dado.cpf, cpfTemp );

    return true;
}
bool solicitaNascimentoAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = alunosCadastrados - 1;
    char nascimentoTemp[TAM_NAC];

    do{
        printf("- Digite a data de nascimento: [EX: 00/00/0000]\n-> ");
        fgets( nascimentoTemp, TAM_NAC, stdin);

        if( sair( nascimentoTemp[0], nascimentoTemp[1] )){
            return false;
        }else{
            limpaTexto(nascimentoTemp);
            DADO = validaNascimento( nascimentoTemp );}
    }while( DADO == INVALIDO );

    strcpy( discente[posicao].dado.nascimento, nascimentoTemp );

    return true;
}
bool solicitaSexoAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = alunosCadastrados - 1;
    char sexoTemp[4];

    do{
        printf("- Digite o sexo: [Opções: F, M OU O]\n-> ");
        fgets( sexoTemp, 4, stdin);

        if( sair( sexoTemp[0], sexoTemp[1] ) ){
            return false;
        }else{
            DADO = validaSexo(sexoTemp[0]);}
    }while( DADO == INVALIDO );

    discente[posicao].dado.sexo = aumentaLetra(sexoTemp[0]);

    return true;
}
bool cadastrarDisciplina(){
    if( disciplinasCadastradas < quantMaxDisciplina ){
        printf ("=============================================\n"
                "||         CADASTRANDO - DISCIPLINA        || \n"
                "=============================================\n");
        disciplinasCadastradas++;
        if( solicitaNomeDisciplina( ) )
            if( solicitaCodigo( ) )
                if( solicitaSemestre( ) )
                    if( solicitaVagas( ) )
                       if( solicitaProfessor( ) ){
                            puts( "< CADASTRO DE DISCIPLINA FINALIZADO COM SUCESSO! >\n" );
                            return true;}
        disciplinasCadastradas--;
        return false;
    }else{
        puts( "\t> Quantidade máxima atingida <\n" );
        return false; }
}

bool solicitaNomeDisciplina( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = disciplinasCadastradas - 1;
    char nomeTemp[TAM_NOME_DISC];

    strcpy( materia[posicao].nome, " " );

    do{
        printf("- Digite o nome da disciplina:\n-> ");
        fgets( nomeTemp, TAM_NOME_DISC, stdin);

        if( sair( nomeTemp[0], nomeTemp[1] )){
            return false;
        }else{
            limpaTexto( nomeTemp );
            DADO = validaNome( nomeTemp );
            if( DADO == VALIDO ){
                strcpy( nomeTemp, caixaAlta( nomeTemp ) );
                if( verificaNomeDisciplina( nomeTemp ) > -1 ){
                    puts( "\t> Este nome já está associado a uma disciplina <\n" );
                    DADO = INVALIDO;}}}
    }while( DADO == INVALIDO );

    strcpy( materia[posicao].nome, nomeTemp );

    return true;
}
bool solicitaCodigo( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = disciplinasCadastradas - 1;
    char codigoTemp[TAM_COD_DISC],
         ALFA[TAM_COD_DISC];

    strcpy( materia[posicao].codigo, " " );

    do{
        printf("- Digite o código da disciplina: [EX: EXE123]\n-> ");
        fgets( codigoTemp, TAM_COD_DISC, stdin);

        if( sair( codigoTemp[0], codigoTemp[1] ) ){
            return false;
        }else{
            limpaTexto( codigoTemp );
            
            strncpy( ALFA, codigoTemp, 3 );
            strncpy( ALFA, caixaAlta( ALFA ), 3 );
            strncpy( &ALFA[3], &codigoTemp[3], 3 );
            strcpy( codigoTemp, ALFA );
            DADO = validaCodigo( codigoTemp );}
            if( DADO == VALIDO && ( ( verificaCodigoDisciplina( codigoTemp ) ) > -1 ) ){
                puts( "\t> Código associado a outra disciplina <\n" );
                DADO = INVALIDO;}
    }while( DADO == INVALIDO );

    strcpy( materia[posicao].codigo, codigoTemp );

    return true;
}
bool solicitaSemestre( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = disciplinasCadastradas - 1;
    char semestreTemp[TAM_SEM];

    do{
        printf( "- Digite o semestre da disciplina: [EX: 2022.1]\n-> ");
        fgets( semestreTemp, TAM_SEM, stdin);

        if( sair( semestreTemp[0], semestreTemp[1] ) ){
            return false;
        }else{
            limpaTexto( semestreTemp );
            DADO = validaSemestre( semestreTemp );}
    }while( DADO == INVALIDO );

    strcpy( materia[posicao].semestre, semestreTemp );

    return true;
}
bool solicitaVagas( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = disciplinasCadastradas - 1,
        vagasTemp = 0;

    do{
        printf("- Digite o número de vagas da disciplina:\n-> ");
        scanf( "%d", &vagasTemp );
        getchar( );
        if( vagasTemp == -1 ){
            return false;
        }else{
            DADO = validaVagas( vagasTemp );}
    }while( DADO == INVALIDO );

    materia[posicao].vagas = vagasTemp;

    return true;
}
bool solicitaProfessor( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = disciplinasCadastradas - 1;
    char professorTemp[TAM_NOME];

    do{
        printf("- Digite o professor da disciplina:\n-> ");
        fgets( professorTemp, TAM_NOME, stdin );

        if( sair( professorTemp[0], professorTemp[1] ) ){
            return false;
        }else{
            limpaTexto( professorTemp );
            DADO = validaProfessores( professorTemp );}
    }while( DADO == INVALIDO );

    padronizaNome( professorTemp );

    int docenteId = verificaNomeProfessor( professorTemp );
    if( docente[docenteId].disciplinasMinistrando < TAM_MINIS ){
        docente[docenteId].ministrando[docente[docenteId].disciplinasMinistrando++] = posicao;
        materia[posicao].professorId = docenteId+1; ///os professores comecam a ser inseridos do 1 com id para ministrar disciplina
        atualizaCadastroProfessor(docenteId);}
    return true;
}
#endif ///CADASTRO_FILE_H
