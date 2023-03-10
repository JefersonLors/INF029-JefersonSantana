

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