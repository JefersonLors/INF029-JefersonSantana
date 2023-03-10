#ifndef MATRICULA_FILE_H
#define  MATRICULA_FILE_H
#include "_validar.h"

void matricularAluno( unsigned );
void desmatricularAluno( unsigned );
void matricularProfessor( unsigned );
void desmatricularProfessor( unsigned );
bool solicitaCodigoMatricula( char[] );
bool validaCodigoMatricula( char[] );
void ajusteGradeAluno( unsigned, unsigned );
void ajusteGradeProfessor( unsigned, unsigned );

void matricularAluno( unsigned id ){
    char codigoDeMatricula[TAM_COD_MAT];
    enum VALIDAR{ VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO = VALIDO,
                 ALUNO = VALIDO;

    do{
        printf( "\n========================================================================\n"
                "||                         MATRICULANDO ALUNO                         || \n"
                "========================================================================\n"
                "- Digite o Código de Matrícula [matriculaDoAluno/codigoDaDisciplina]\n-> ");
        DADO = solicitaCodigoMatricula( codigoDeMatricula );
        if( !DADO == INVALIDO ){
            strcpy( &codigoDeMatricula[0], ( caixaAlta( &codigoDeMatricula[0] ) ) );
            int disciplinaId = verificaCodigoDisciplina( &codigoDeMatricula[12] );
            if( disciplinaId != -1 ){
                char matriculaAluno[TAM_MAT - 1];
                strncpy( matriculaAluno, codigoDeMatricula, TAM_MAT - 2 );
                int alunoId = verificaMatriculaAluno( matriculaAluno );
                if( alunoId != -1 ){
                    if( ( strcmp( discente[id].dado.matricula, matriculaAluno ) ) == 0 ){
                        for( int grade = 0; grade < discente[alunoId].disciplinasCursando; grade++ ){
                            if( discente[alunoId].matrizCurricular[grade] == disciplinaId ){
                                ALUNO = INVALIDO; break;}}
                        if( ALUNO == VALIDO ){
                            if( discente[alunoId].disciplinasCursando < TAM_MATRIZ ){
                                int vagasRestantes = materia[disciplinaId].vagas - materia[disciplinaId].quantidadeMatriculado;
                                if( vagasRestantes > 0 ){
                                    discente[alunoId].matrizCurricular[discente[alunoId].disciplinasCursando++] = disciplinaId;
                                    materia[disciplinaId].quantidadeMatriculado++;
                                    printf( "%s cadastrado em %s \n", discente[alunoId].dado.nome, materia[disciplinaId].nome );
                                    atualizaCadastroDisciplina( disciplinaId );
                                    atualizaCadastroAluno( alunoId );
                                    break;
                                }else{ puts( "\t> Não há mais vagas nessa disciplina <\n" ); }
                            }else{ puts( "\t> Grade cheia <\n" ); }
                        }else{ puts( "\t> O aluno já está matriculado nesta disciplina <\n" ); }
                    }else{ puts( "\t> Matricula invalida <\n" );}
                }else{ puts( "\t> Aluno não cadastrado <\n" );}
            }else{ puts( "\t> Disciplina não cadastrada <\n" );}
        }else break;
    }while( DADO != INVALIDO  );
}
void desmatricularAluno( unsigned id ){
    char codigoDeDesatricula[TAM_COD_MAT];
    enum VALIDAR{ VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO = VALIDO,
                 ALUNO = INVALIDO;

    do{
        printf( "\n========================================================================\n"
                "||                        DESMATRICULANDO ALUNO                       || \n"
                "========================================================================\n"
                "- Digite o Codigo de Desmatricula [matriculaDoAluno/codigoDaDisciplina]\n-> ");
        DADO = solicitaCodigoMatricula( codigoDeDesatricula );
        if( !DADO == INVALIDO ){
            strcpy( &codigoDeDesatricula[0], ( caixaAlta( &codigoDeDesatricula[0] ) ) );
            int disciplinaId = verificaCodigoDisciplina( &codigoDeDesatricula[12] );
            if( disciplinaId != -1 ){
                char matriculaAluno[TAM_MAT - 1];
                strncpy( matriculaAluno, codigoDeDesatricula, TAM_MAT - 2 );
                int alunoId = verificaMatriculaAluno( matriculaAluno );
                if( alunoId != -1 ){
                    if( ( strcmp( discente[id].dado.matricula, matriculaAluno ) ) == 0 ){
                        for( int grade = 0; grade < discente[alunoId].disciplinasCursando; grade++ ){
                            if( discente[alunoId].matrizCurricular[grade] == disciplinaId ){
                                ALUNO = VALIDO; break;}}
                        if( ALUNO == VALIDO ){
                            ajusteGradeAluno( alunoId, disciplinaId );
                            materia[disciplinaId].quantidadeMatriculado--;
                            printf( "%s não está mais matriculado em %s \n", discente[alunoId].dado.nome, materia[disciplinaId].nome );
                            atualizaCadastroDisciplina( disciplinaId );
                            atualizaCadastroAluno( alunoId );
                            break;
                        }else{ puts( "\t> O aluno não está matriculado nesta disciplina <\n" ); }
                    }else{ puts( "\t> Matricula invalida <\n" );}
                }else{ puts( "\t> Aluno não cadastrado <\n" );}
            }else{ puts( "\t> Disciplina não cadastrada <\n" );}
        }else break;
    }while( DADO != INVALIDO );
}
void matricularProfessor( unsigned id ){
    char codigoDeMatricula[TAM_COD_MAT];
    enum VALIDAR{ VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO = VALIDO,
                 PROFESSOR = VALIDO;

    do{
        printf( "\n========================================================================\n"
                "||                       MATRICULANDO PROFESSOR                       || \n"
                "========================================================================\n"
                "- Digite o Codigo de matrícula [matriculaDoProfessor/codigoDaDisciplina]\n-> ");
        DADO = solicitaCodigoMatricula( codigoDeMatricula );
        if( !DADO == INVALIDO ){
            strcpy( &codigoDeMatricula[0], ( caixaAlta( &codigoDeMatricula[0] ) ) );
            int disciplinaId = verificaCodigoDisciplina( &codigoDeMatricula[12] );
            if( disciplinaId != -1 ){
                char matriculaProfessor[TAM_MAT - 1];
                strncpy( matriculaProfessor, codigoDeMatricula, TAM_MAT - 2 );
                int professorId = verificaMatriculaProfessor( matriculaProfessor );
                if( professorId != -1 ){
                    if( ( strcmp( docente[id].dado.matricula, matriculaProfessor ) ) == 0 ){
                        for( int grade = 0; grade < docente[professorId].disciplinasMinistrando; grade++ ){
                            if( docente[professorId].ministrando[grade] == disciplinaId ){
                                PROFESSOR = INVALIDO; break;}}
                        if( PROFESSOR == VALIDO ){
                            if( docente[professorId].disciplinasMinistrando < TAM_MINIS ){
                                if( materia[disciplinaId].professorId == 0 ){
                                    docente[professorId].ministrando[docente[professorId].disciplinasMinistrando++] = disciplinaId;
                                    materia[disciplinaId].professorId = professorId+1;
                                    printf( "%s está ministando %s \n", docente[professorId].dado.nome, materia[disciplinaId].nome );
                                    atualizaCadastroDisciplina( disciplinaId );
                                    atualizaCadastroProfessor( professorId );
                                    break;
                                }else{ puts( "\t> Este professor já está ministrando esta disciplina <\n" ); }
                            }else{ puts( "\t> Grade cheia <" ); }
                        }else{ puts( "\t> Já há um professor ministrando esta disciplina <\n" ); }
                    }else{ puts( "\t> Matricula invalida <\n" );}
                }else{ puts( "\t> Professor não cadastrado <\n" );}
            }else{ puts( "\t> Disciplina não cadastrada <\n" );}
        }else break;
    }while( DADO != INVALIDO );
}
void desmatricularProfessor( unsigned id ){
    char codigoDeDesmatricula[TAM_COD_MAT];
    enum VALIDAR{ VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO = VALIDO,
                 PROFESSOR = INVALIDO;

    do{
        printf( "\n========================================================================\n"
                "||                      DESMATRICULANDO PROFESSOR                     || \n"
                "========================================================================\n"
                "- Digite o Codigo de Desmatrícula [matriculaDoProfessor/codigoDaDisciplina]\n-> ");
        DADO = solicitaCodigoMatricula( codigoDeDesmatricula );
        if( !DADO == INVALIDO ){
            strcpy( &codigoDeDesmatricula[0], ( caixaAlta( &codigoDeDesmatricula[0] ) ) );
            int disciplinaId = verificaCodigoDisciplina( &codigoDeDesmatricula[12] );
            if( disciplinaId != -1 ){
                char matriculaProfessor[TAM_MAT - 1];
                strncpy( matriculaProfessor, codigoDeDesmatricula, TAM_MAT - 2 );
                int professorId = verificaMatriculaProfessor( matriculaProfessor );
                if( professorId != -1 ){
                    if( ( strcmp( docente[id].dado.matricula, matriculaProfessor ) ) == 0 ){
                        for( int grade = 0; grade < docente[professorId].disciplinasMinistrando; grade++ ){
                            if( docente[professorId].ministrando[grade] == disciplinaId ){
                                PROFESSOR = VALIDO; break;}}
                        if( PROFESSOR == VALIDO ){
                            ajusteGradeProfessor( professorId, disciplinaId );
                            materia[disciplinaId].professorId = -1;
                            printf( "%s não está ministando %s \n", docente[professorId].dado.nome, materia[disciplinaId].nome );
                            atualizaCadastroDisciplina( disciplinaId );
                            atualizaCadastroProfessor( professorId );
                            break;
                        }else{ puts( "O professor não está ministrando esta disciplina " ); }
                    }else{ puts( "\t> Matricula invalida <\n" );}
                }else{ puts( "\t> Professor não cadastrado <\n" );}
            }else{ puts( "\t> Disciplina não cadastrada <\n" );}
        }else break;
    }while( DADO != INVALIDO );
}
bool solicitaCodigoMatricula( char codigoDeMatricula[] ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;

    do{
        fgets( codigoDeMatricula, TAM_COD_MAT, stdin );
        if( sair(codigoDeMatricula[0], codigoDeMatricula[1] ) ){
            return false;
        }else{
            limpaTexto( codigoDeMatricula );
            DADO = validaCodigoMatricula( codigoDeMatricula );}
    }while( DADO == INVALIDO );

    return true;
}
bool validaCodigoMatricula( char codigoDeMatricula[] ){
    char matricula[TAM_MAT-1];
    char codigoDisciplina[TAM_COD_DISC];
    char *mensagemDeErro[3];
    int erro = 0;

    strncpy( matricula, codigoDeMatricula, 11  );

    if( !tamanhoCerto( TAM_COD_MAT, codigoDeMatricula ) ){
        mensagemDeErro[erro++] = "\t> Código inválido <\n";}

    for( int caracter = 0; codigoDeMatricula[caracter] != '\0'; caracter++ ){
        if( !ehNumero(codigoDeMatricula[caracter]) && !ehLetra(codigoDeMatricula[caracter] ) && codigoDeMatricula[caracter] != '/' ){
             mensagemDeErro[erro++] = "\t> Caracteres inválidos <\n";}
        if( codigoDeMatricula[caracter] == '/' && caracter != 11 ){
            puts( "\t> Código inválido <\n" );
            return false;}
    }
    if( !validaMatricula( matricula ) ){
        return false;}

    if( !validaCodigo( &codigoDeMatricula[TAM_MAT-1] ) ){
        return false;}

    mensagemDeErro[erro] = NULL;

    if( mensagemDeErro[0] == NULL ){
        return true;
    }else{
        for( int posicao = 0; mensagemDeErro[posicao] != NULL; posicao++ ){

            puts( mensagemDeErro[posicao] );}
        return false;}
}
void ajusteGradeAluno( unsigned id, unsigned apagar ){
    for( int disciplina = apagar; disciplina < discente[id].disciplinasCursando-1; disciplina++ ){
        discente[id].matrizCurricular[disciplina] = discente[id].matrizCurricular[disciplina + 1];}
    discente[id].disciplinasCursando--;
}
void ajusteGradeProfessor( unsigned id, unsigned apagar ){
    for( int disciplina = apagar; disciplina < docente[id].disciplinasMinistrando-1; disciplina++ ){
        docente[id].ministrando[disciplina] = docente[id].ministrando[disciplina=1];}
    docente[id].disciplinasMinistrando--;
}
#endif  //MATRICULAR_FILE_H
