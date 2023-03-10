#include "../"

#ifndef Enroll_h_included
#define Enroll_h_included

void matricularAluno( unsigned );
void matricularProfessor( unsigned );

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

#endif  //Enroll_h_included
