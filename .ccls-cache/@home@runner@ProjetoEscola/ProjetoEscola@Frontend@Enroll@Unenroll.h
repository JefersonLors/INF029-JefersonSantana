
void desmatricularAluno( unsigned );
void desmatricularProfessor( unsigned );

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