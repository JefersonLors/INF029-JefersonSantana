#ifndef LISTA_FILE_H
#define LISTA_FILE_H

#include "_validar.h"
#include <string.h>

///FUNCÕES DE PESQUISA
void buscarAlunosPorPalavraChave( );
void buscarProfessoresPorPalavraChave( );
void aniversarianteMes( );
void filtroPorPalavraChave( );
void professoresComFiltroTamanhoGrade( );
void alunosComFiltroTamanhoGrade( );
int *dispositivoBuscadorDeAluno( char* );
int *dispositivoBuscadorDeProfessor( char* );

///FUNÇÕES DE ORDENAÇÃO DE DADOS DE ALUNOS
void ordenaAlunosPorSexo( Aluno * );
void ordenaAlunosPorOrdemAlfabetica( Aluno * );
void ordenaAlunosPorNascimento( Aluno * );

///FUNÇÕES DE ORDENAÇÃO DE DADOS DE PROFESSORES
void ordernaProfessoresPorSexo( Professor* );
void ordernaProfessoresPorOrdemAlfabetica(  Professor* );
void ordernaProfessoresPorNascimento( Professor* );

///FUNÇÕES DE RELATÓRIOS DE DADOS DE DISCIPLINAS
void relatorioAlunos( Aluno[] );
void relatorioProfessores( Professor[] );
void relatorioDisciplinas( );
void disciplinaComAlunos( int );
void disciplinasComFiltroVagas( );
///=========//==========//=========//=========//

void listarProfessores( ){
    int menuListarProfessor( );
    Professor professoresOrdenados[professoresCadastrados];
    char resposta = '\0';
    enum MENU{ Filtro_Geral = '1', Filtro_Sexo = '2', Filtro_Nome = '3',
               Filtro_Nascimento = '4', Filtro_por_tamanho_de_grade = '5',
               Filtro_por_palavra_chave = '6', Voltar = '0'};

    if( professoresCadastrados > 0 ){
        for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
            professoresOrdenados[posicao] = docente[posicao];}
        do{
            resposta = menuListarProfessor( );
            switch( resposta ){
                case Filtro_Geral:
                    relatorioProfessores( docente );
                    break;
                case Filtro_Sexo:
                    ordernaProfessoresPorSexo( professoresOrdenados );
                    relatorioProfessores( professoresOrdenados );
                    break;
                case Filtro_Nome:
                    ordernaProfessoresPorOrdemAlfabetica( professoresOrdenados );
                    relatorioProfessores( professoresOrdenados );
                    break;
                case Filtro_Nascimento:
                    ordernaProfessoresPorNascimento( professoresOrdenados );
                    relatorioProfessores( professoresOrdenados );
                    break;
                case Filtro_por_tamanho_de_grade:
                    professoresComFiltroTamanhoGrade( );
                    break;
                case Filtro_por_palavra_chave:
                    buscarProfessoresPorPalavraChave( );
                    break;
                case Voltar: break;}
        }while( resposta != Voltar );
    }else{ puts( "\t> Não há professores cadastrados <\n" );}
}
void listarAlunos( ){
    int menuListarAluno( );
    Aluno alunosOrdenados[alunosCadastrados];
    char resposta = '\0';
    enum MENU{ Filtro_Geral = '1', Filtro_Sexo = '2', Filtro_Nome = '3',
               Filtro_Nascimento = '4', Filtro_por_tamanho_de_grade = '5',
               Filtro_por_palavra_chave = '6', Voltar = '0'};

    if( alunosCadastrados > 0 ){
        for( int posicao = 0; posicao < alunosCadastrados; posicao++ ){
            alunosOrdenados[posicao] = discente[posicao];}

        do{
            resposta = menuListarAluno( );
            switch( resposta ){
                case Filtro_Geral:
                    relatorioAlunos( discente );
                    break;
                case Filtro_Sexo:
                    ordenaAlunosPorSexo( alunosOrdenados );
                    relatorioAlunos( alunosOrdenados );
                    break;
                case Filtro_Nome:
                    ordenaAlunosPorOrdemAlfabetica( alunosOrdenados );
                    relatorioAlunos( alunosOrdenados );
                    break;
                case Filtro_Nascimento:
                    ordenaAlunosPorNascimento( alunosOrdenados );
                    relatorioAlunos( alunosOrdenados );
                    break;
                case Filtro_por_tamanho_de_grade:
                    alunosComFiltroTamanhoGrade( );
                    break;
                case Filtro_por_palavra_chave:
                    buscarAlunosPorPalavraChave( );
                    break;
                case Voltar: break;}
        }while( resposta != Voltar );
    }else{ puts( "\t> Não há alunos cadastrados <\n" );}
}
void listarDisciplinas( ){
    int solicitaCodigoFiltro( );
    int posicao;
    int menuListarDisciplinas( );
    char resposta = '\0';
    enum MENU{ Filtro_Geral = '1', Filtro_disciplinas_com_alunos = '2',
               Filtro_disciplinas_vagas = '3',  Voltar = '0'};

    if( disciplinasCadastradas > 0 ){
        do{
            resposta = menuListarDisciplinas( );
            switch( resposta ){
                case Filtro_Geral :
                    relatorioDisciplinas( );
                    break;
                case Filtro_disciplinas_com_alunos:
                    posicao = solicitaCodigoFiltro( );
                    if( posicao > -1 ){
                        disciplinaComAlunos( posicao );}
                    break;
                case Filtro_disciplinas_vagas:
                    disciplinasComFiltroVagas( );
                    break;
                case Voltar: break;}
        }while( resposta != Voltar );
    }else{ puts( "\t> Não há disciplinas cadastradas <\n" );}
}
void ordernaProfessoresPorSexo( Professor *professores ){
    Professor aux;

    for( int ordenador = professoresCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( professores[i].dado.sexo > professores[i+1].dado.sexo ){
				aux = professores[i];
                professores[i] = professores[i+1];
                professores[i+1] = aux;}}}
}
void ordernaProfessoresPorOrdemAlfabetica( Professor *professores ){
    Professor aux;

    for( int ordenador = professoresCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( (strcmp(professores[i].dado.nome, professores[i+1].dado.nome)) > 0 ){
				strcpy(aux.dado.nome, professores[i].dado.nome);
                strcpy(professores[i].dado.nome, professores[i+1].dado.nome);
                strcpy(professores[i+1].dado.nome, aux.dado.nome);}}}
}
void ordernaProfessoresPorNascimento( Professor *professores ){
    Professor aux;
    char AAMM_1[ 6 ], AAAA_1[5],
         AAMM_2[ 6 ], AAAA_2[5];

   for( int ordenador = professoresCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
            strcpy( AAAA_1, &professores[i].dado.nascimento[6]);
            strcpy( AAAA_2, &professores[i+1].dado.nascimento[6]);
			if( strcmp( AAAA_1, AAAA_2 ) > 0 ){
				strcpy(aux.dado.nascimento, professores[i].dado.nascimento);
                strcpy(professores[i].dado.nascimento, professores[i+1].dado.nascimento);
                strcpy(professores[i+1].dado.nascimento, aux.dado.nascimento);
            }else if( strcmp( AAAA_1, AAAA_2 ) == 0 ){
                strncpy( AAMM_1, professores[i].dado.nascimento, 5 );
                strncpy( AAMM_2, professores[i+1].dado.nascimento, 5 );
                if( strcmp( AAMM_1, AAMM_2 ) > 0 ){
                    strcpy(aux.dado.nascimento, professores[i].dado.nascimento);
                    strcpy(professores[i].dado.nascimento, professores[i+1].dado.nascimento);
                    strcpy(professores[i+1].dado.nascimento, aux.dado.nascimento);}}}}
}
void ordenaAlunosPorSexo( Aluno *alunos ){
    Aluno aux;

    for( int ordenador = alunosCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( alunos[i].dado.sexo > alunos[i+1].dado.sexo ){
				aux = alunos[i];
                alunos[i] = alunos[i+1];
                alunos[i+1] = aux;}}}
}
void ordenaAlunosPorOrdemAlfabetica( Aluno *alunos ){
    Aluno aux;

    for( int ordenador = alunosCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( (strcmp(alunos[i].dado.nome, alunos[i+1].dado.nome)) > 0 ){
				strcpy(aux.dado.nome, alunos[i].dado.nome);
                strcpy(alunos[i].dado.nome, alunos[i+1].dado.nome);
                strcpy(alunos[i+1].dado.nome, aux.dado.nome);}}}
}
void ordenaAlunosPorNascimento( Aluno *alunos ){
    Aluno aux;
    char AAMM_1[ 6 ], AAAA_1[5],
         AAMM_2[ 6 ], AAAA_2[5];

    for( int ordenador = alunosCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
            strcpy( AAAA_1, &alunos[i].dado.nascimento[6]);
            strcpy( AAAA_2, &alunos[i+1].dado.nascimento[6]);
			if( strcmp( AAAA_1, AAAA_2 ) > 0 ){
				strcpy(aux.dado.nascimento, alunos[i].dado.nascimento);
                strcpy(alunos[i].dado.nascimento, alunos[i+1].dado.nascimento);
                strcpy(alunos[i+1].dado.nascimento, aux.dado.nascimento);
            }else if( strcmp( AAAA_1, AAAA_2 ) == 0 ){
                strncpy( AAMM_1, alunos[i].dado.nascimento, 5 );
                strncpy( AAMM_2, alunos[i+1].dado.nascimento, 5 );
                if( strcmp( AAMM_1, AAMM_2 ) > 0 ){
                    strcpy(aux.dado.nascimento, alunos[i].dado.nascimento);
                    strcpy(alunos[i].dado.nascimento, alunos[i+1].dado.nascimento);
                    strcpy(alunos[i+1].dado.nascimento, aux.dado.nascimento);}}}}
}
void aniversarianteMes( ){
    int* aniversariantesDoMes;
    int* professoresAniversariantes (char* mesAtual);
    int* alunosAniversariantes (char* mesAtual);
    char mesAtual[4];
    int mesAtualNum;

    do{
        printf ("\n===============================\n"
                "||      ANIVERSARIANTES      || \n"
                "===============================\n"
                "- Insira o mês que deseja realizar a busca:\n"
                "-> ");
        fgets(mesAtual, 4, stdin);
        if( sair( mesAtual[0], mesAtual[1] ) ){
            break;
        }else{
            limpaTexto( mesAtual );
            mesAtualNum = charParaInt(mesAtual[0])*10 + charParaInt(mesAtual[1]);
            if( mesAtualNum > 12 || mesAtualNum < 1 ){
                puts( "> Mês inválido! <\n" );
            }else{
                printf( "=======================================================================================\n"
                        "                               ANIVERSARIANTES DO MÊS\n"
                        "=======================================================================================\n");
                aniversariantesDoMes = alunosAniversariantes( mesAtual );
                if( aniversariantesDoMes[0] != -1  ){
                    printf( "\n   ALUNOS \n" );
                    printf( "%*s  %*s  \n", TAM_NAC+11, "NASCIMENTO", 14, "NOME" );
                    for( int corredor = 0; aniversariantesDoMes[corredor] != -1; corredor++ ){
                        printf( "%*s %*s \n", TAM_NAC+11, discente[aniversariantesDoMes[corredor]].dado.nascimento,
                                             10, discente[aniversariantesDoMes[corredor]].dado.nome );}
                }else{ puts( "\n> Não há alunos aniversariantes neste mês <\n" );}

                aniversariantesDoMes = professoresAniversariantes( mesAtual );

                if( aniversariantesDoMes[0] != -1  ){
                    printf( "\n   PROFESSORES\n" );
                    printf( "%*s  %*s  \n", TAM_NAC+11, "NASCIMENTO", 14, "NOME" );
                    for( int corredor = 0; aniversariantesDoMes[corredor] != -1; corredor++ ){
                        printf( "%*s %*s \n", TAM_NAC+11, docente[aniversariantesDoMes[corredor]].dado.nascimento,
                                              10, docente[aniversariantesDoMes[corredor]].dado.nome );}
                }else{ puts( "\n> Não há professores aniversariantes neste mês <\n" );}}}
    }while( true );
    puts( "\n" );
}
int *alunosAniversariantes( char *mesAtual){
    Aluno aniversarianteDoMes[alunosCadastrados],
          alunoBackup;
    int quantidade = 0;
    char mes[3],
         dia_1[3],
         dia_2[3];

    for( int i = 0; i < alunosCadastrados; i++){
        aniversarianteDoMes[i] = discente[i];
        if( mesAtual[0] == discente[i].dado.nascimento[3] && mesAtual[1] == discente[i].dado.nascimento[4]){
            quantidade++;}}
    quantidade++;

     int *alunosAniversariantesId = (int *)malloc( quantidade*sizeof( int ) ),
         corredor = 0;

    for( int x = 1; x < alunosCadastrados; x++ ){
        for( int i = 0; i < alunosCadastrados-1; i++){
            dia_1[0] = aniversarianteDoMes[i].dado.nascimento[0];
            dia_1[1] = aniversarianteDoMes[i].dado.nascimento[1];
            dia_1[2] = '\0';
            dia_2[0] = aniversarianteDoMes[i+1].dado.nascimento[0];
            dia_2[1] = aniversarianteDoMes[i+1].dado.nascimento[1];
            dia_2[2] = '\0';
            if( strcmp( dia_1, dia_2 ) > 0  ){
                strcpy( alunoBackup.dado.nascimento, aniversarianteDoMes[i].dado.nascimento );
                strcpy( aniversarianteDoMes[i].dado.nascimento, aniversarianteDoMes[i+1].dado.nascimento  );
                strcpy( aniversarianteDoMes[i+1].dado.nascimento, alunoBackup.dado.nascimento );
            }}}

    for( int i = 0; i < alunosCadastrados; i++){
        mes[0] = aniversarianteDoMes[i].dado.nascimento[3];
        mes[1] = aniversarianteDoMes[i].dado.nascimento[4];
        mes[2] = '\0';

        if( ( strcmp( mesAtual, mes) ) == 0 ){
            for( int y = 0; y < alunosCadastrados; y++ ){
                if( strcmp( aniversarianteDoMes[i].dado.nascimento, discente[y].dado.nascimento ) == 0){
                    alunosAniversariantesId[corredor++] = y;
                }}}}
    alunosAniversariantesId[ corredor ] = -1;

    return alunosAniversariantesId;
}
int *professoresAniversariantes(char* mesAtual){
    Professor aniversarianteDoMes[professoresCadastrados],
          professoresBackup;
    int quantidade = 0;
    char mes[3],
         dia_1[3],
         dia_2[3];

    for( int i = 0; i < professoresCadastrados; i++){
        aniversarianteDoMes[i] = docente[i];
        if( mesAtual[0] == docente[i].dado.nascimento[3] && mesAtual[1] == docente[i].dado.nascimento[4]){
            quantidade++;}}
    quantidade++;

     int *professoresAniversariantesId = (int *)malloc( quantidade*sizeof( int ) ),
         corredor = 0;

    for( int x = 1; x < professoresCadastrados; x++ ){
        for( int i = 0; i < professoresCadastrados-1; i++){
            dia_1[0] = aniversarianteDoMes[i].dado.nascimento[0];
            dia_1[1] = aniversarianteDoMes[i].dado.nascimento[1];
            dia_1[2] = '\0';
            dia_2[0] = aniversarianteDoMes[i+1].dado.nascimento[0];
            dia_2[1] = aniversarianteDoMes[i+1].dado.nascimento[1];
            dia_2[2] = '\0';
            if( strcmp( dia_1, dia_2 ) > 0  ){
                strcpy( professoresBackup.dado.nascimento, aniversarianteDoMes[i].dado.nascimento );
                strcpy( aniversarianteDoMes[i].dado.nascimento, aniversarianteDoMes[i+1].dado.nascimento  );
                strcpy( aniversarianteDoMes[i+1].dado.nascimento, professoresBackup.dado.nascimento );
            }}}

    for( int i = 0; i < professoresCadastrados; i++){
        mes[0] = aniversarianteDoMes[i].dado.nascimento[3];
        mes[1] = aniversarianteDoMes[i].dado.nascimento[4];
        mes[2] = '\0';

        if( ( strcmp( mesAtual, mes) ) == 0 ){
            for( int y = 0; y < professoresCadastrados; y++ ){
                if( strcmp( aniversarianteDoMes[i].dado.nascimento, docente[y].dado.nascimento ) == 0){
                    professoresAniversariantesId[corredor++] = y;
                }}}}
    professoresAniversariantesId[ corredor ] = -1;

    return professoresAniversariantesId;
}
void relatorioAlunos( Aluno alunosOrdenados[] ){
    printf("====================================================================="
           "====================================================================\n"
           "                                                          ALUNOS CADASTRADOS\n"
           "====================================================================="
           "====================================================================\n");
    printf( " %*s  %*s  %*s  %*s  %*s  \n", TAM_MAT+4, "MATRÍCULA", TAM_CPF, "CPF",
                                            TAM_NAC+11, "NASCIMENTO", 14, "SEXO", 14, "NOME" );
    for( int posicao = 0; posicao < alunosCadastrados; posicao++ ){
        printf( "%*s  %*s  %*s      %*c      %-*s\n", TAM_MAT+5, alunosOrdenados[posicao].dado.matricula,
                                               TAM_CPF+5, alunosOrdenados[posicao].dado.cpf,
                                               TAM_NAC+5, alunosOrdenados[posicao].dado.nascimento,
                                               9, alunosOrdenados[posicao].dado.sexo,
                                               TAM_NOME, alunosOrdenados[posicao].dado.nome );}
    puts( "\n" );
}
void relatorioProfessores( Professor professoresOrdenados[] ){
    printf( "===================================================================="
            "=====================================================================\n"
            "                                                        PROFESSORES CADASTRADOS\n"
            "====================================================================="
            "====================================================================\n");
    printf( " %*s  %*s  %*s  %*s  %*s  \n", TAM_MAT+5, "MATRÍCULA", TAM_CPF, "CPF",
                                            TAM_NAC+11, "NASCIMENTO", 12, "SEXO ", 14, "NOME" );
    for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
         printf( " %*s  %*s  %*s  %*c          %-s\n", TAM_MAT+5, professoresOrdenados[posicao].dado.matricula,
                                                       TAM_CPF+5, professoresOrdenados[posicao].dado.cpf,
                                                       TAM_NAC+5, professoresOrdenados[posicao].dado.nascimento,
                                                       9, professoresOrdenados[posicao].dado.sexo,
                                                       professoresOrdenados[posicao].dado.nome );}
    puts( "\n" );
}
void relatorioDisciplinas(  ){
    printf( "===================================================================="
            "=====================================================================\n"
            "                                                         DISCIPLINAS CADASTRADAS\n"
            "======================================================================"
            "===================================================================\n");
    printf( "%*s %*s %*s %*s %*s\n", TAM_COD_DISC+4, "CÓDIGO", TAM_SEM+4, "SEMESTRE",
                                     11,"RELAÇÃO", 18, "PROFESSOR", 18, "NOME" );
    for( int posicao = 0; posicao < disciplinasCadastradas; posicao++ ){
        printf( "%*s  %*s  %*d/%2.d      %-*s  %-*s\n", TAM_COD_DISC+3, materia[posicao].codigo,
                                                        TAM_SEM+2, materia[posicao].semestre,
                                                        4 ,materia[posicao].quantidadeMatriculado,
                                                        materia[posicao].vagas,
                                                        20, docente[materia[posicao].professorId-1].dado.nome,
                                                        20 ,materia[posicao].nome );}
    puts( "\n" );
}
void disciplinaComAlunos( int posicao ){
    printf( "=======================================================================================\n"
            "                                    DISCIPLINA\n"
            "=======================================================================================\n");
    printf( "%*s %*s %*s %*s %*s\n", TAM_COD_DISC+4, "CÓDIGO", TAM_SEM+4, "SEMESTRE",
                                     11,"RELAÇÃO", 18, "PROFESSOR", 18, "NOME" );

    printf( "%*s  %*s  %*d/%02d      %-*s  %-*s\n", TAM_COD_DISC+3, materia[posicao].codigo,
                                                      TAM_SEM+2, materia[posicao].semestre,
                                                      4 ,materia[posicao].quantidadeMatriculado,
                                                      materia[posicao].vagas ,
                                                      20, docente[materia[posicao].professorId-1].dado.nome,
                                                      20 ,materia[posicao].nome );

    printf( "=======================================================================================\n"
        "                                     MATRICULADOS\n"
        "=======================================================================================\n");
    printf( "%*s %*s  \n", TAM_MAT+3, "MATRÍCULA", 15, "NOME" );

    int contadorDeAlunos = 0;
    for( int matriculado = 0; matriculado < alunosCadastrados; matriculado++ ){
        for( int cursando = 0; cursando < discente[matriculado].disciplinasCursando; cursando ++ ){
            if( discente[matriculado].matrizCurricular[cursando ] == posicao ){
                contadorDeAlunos++;
                printf( " %*s      %-*s\n", TAM_MAT+2, discente[matriculado].dado.matricula,
                               TAM_NOME+6,discente[matriculado].dado.nome );}}}
    if( contadorDeAlunos == 0 ){
        puts( "\n\t> Não há alunos matriculados nessa disciplina < " );}
    puts( "\n" );
}
void disciplinasComFiltroVagas( ){
    int vagas;

    do{
        printf ("\n==============================\n"
                "||      FILTRO - VAGAS      || \n"
                "==============================\n");
        printf("- Digite a quantidade de vagas:\n-> ");
        scanf( "%3d", &vagas );
        getchar( );

        if( vagas == -1 ){
            break;
        }else{
            if( vagas < 0 ){
                puts( "\n> Valor de vagas inválida <\n" );
            }else{
                printf( "=======================================================================================\n"
                        "                             DISCIPLINAS ENCONTRADAS \n"
                        "=======================================================================================\n");
                printf( "%*s %*s %*s %*s %*s\n", TAM_COD_DISC+4, "CODIGO", TAM_SEM+4, "SEMESTRE",
                                                 11,"VAGAS", 18, "PROFESSOR", 18, "NOME" );
                for( int posicao = 0; posicao < disciplinasCadastradas; posicao++ ){
                    if( materia[posicao].vagas > vagas ){
                        printf( "%*s  %*s  %*d      %-*s     %-*s\n", TAM_COD_DISC+3, materia[posicao].codigo,
                                                                          TAM_SEM+2, materia[posicao].semestre,
                                                                          9, materia[posicao].vagas,
                                                                          20, docente[materia[posicao].professorId-1].dado.nome, 20, materia[posicao].nome );}}}}
    }while( true );
    puts( "\n" );
}
void alunosComFiltroTamanhoGrade( ){
    int matriculado = 0,
        contador = 0;

    do{
        printf( "\n===============================\n"
                "|| Filtro - TAMANHO DA GRADE || \n"
                "===============================\n"
                "- Digite a quantidade de Disciplinas:\n"
                "- Menos de -> " );
        scanf( "%d", &matriculado );
        getchar( );

        if( matriculado == -1 ){
            break;
        }else{
            if( matriculado < 0 ) {
                puts( "\n > Quantidade de disciplinas inválida < \n" );
            }else{
                printf( "====================================================================="
                        "====================================================================\n"
                        "                                                         ALUNOS ENCONTRADOS \n"
                        "====================================================================="
                        "====================================================================\n"
                  );
                printf( " %*s  %*s  %*s  %*s  %*s  \n", TAM_MAT+4, "MATRÍCULA", TAM_CPF, "CPF",
                                                TAM_NAC+11, "NASCIMENTO", 14, "SEXO", 14, "NOME" );
                for( int posicao = 0; posicao < alunosCadastrados; posicao++ ){
                    if( discente[posicao].disciplinasCursando < matriculado ){
                        printf( "%*s  %*s  %*s  %*c          %-*s\n", TAM_MAT+5, discente[posicao].dado.matricula,
                                                   TAM_CPF+5, discente[posicao].dado.cpf,
                                                   TAM_NAC+5, discente[posicao].dado.nascimento,
                                                   9, discente[posicao].dado.sexo,
                                                   TAM_NOME, discente[posicao].dado.nome );}}}}
    }while( true );
    puts( "\n" );
}
void professoresComFiltroTamanhoGrade( ){
    int matriculado = 0;

    do{
        printf("\n===============================\n"
                "|| Filtro - TAMANHO DA GRADE || \n"
                "===============================\n"
                "- Digite a quantidade de Disciplinas:\n"
                "- Menos de -> " );
        scanf( "%d", &matriculado );
        getchar( );

        if( matriculado == -1 ){
            break;
        }else{
            if( matriculado < 0 ) {
                puts( "\n > Quantidade de disciplinas inválida < \n" );
            }else{
                printf("====================================================================="
                       "====================================================================\n"
                       "                                                       PROFESSORES ENCONTRADOS \n"
                       "======================================================================"
                       "===================================================================\n");
                printf( " %*s  %*s  %*s  %*s  %*s  \n", TAM_MAT+4, "MATRÍCULA", TAM_CPF, "CPF",
                                                TAM_NAC+11, "NASCIMENTO", 14, "SEXO", 14, "NOME" );

                for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
                    if( docente[posicao].disciplinasMinistrando < matriculado ){
                        printf( "%*s  %*s  %*s     %*c        %-*s\n", TAM_MAT+5, docente[posicao].dado.matricula,
                                                                       TAM_CPF+5, docente[posicao].dado.cpf,
                                                                       TAM_NAC+5, docente[posicao].dado.nascimento,
                                                                       9, docente[posicao].dado.sexo,
                                                                       TAM_NOME, docente[posicao].dado.nome );}}}}
    }while( true );
    puts( "\n" );
}
int solicitaCodigoFiltro( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    char codigo[TAM_COD_DISC];
    int posicao;

    do{
        printf("\n================================\n"
                "|| Filtro - CÓDIGO DISCIPLINA || \n"
                "================================\n"
                "- Digite o código da disciplina:\n"
                "-> ");
        fgets(codigo, TAM_COD_DISC, stdin);

        if( sair( codigo[0], codigo[1] ) ){
            return -1;
        }else{
            limpaTexto(codigo);
            strcpy( codigo, caixaAlta( codigo ) );
            DADO = validaCodigo( codigo );
            if( DADO == VALIDO ){
                posicao = verificaCodigoDisciplina( codigo );
                if( posicao < 0 ){
                    puts( "\n > Essa disciplina não está cadastrada < \n" );
                    DADO = INVALIDO;}}}
    }while( DADO == INVALIDO );
    return posicao;
}
void filtroPorPalavraChave( ){
    char palavraChave[TAM_NOME];
    enum CHAVE { VALIDA = 1, INVALIDA = 0 };
    enum CHAVE CHAVE;
    int *encontradosId;

    do{
        printf( "\n================================\n"
        "||   Filtro - PALAVRA CHAVE   || \n"
        "================================\n"
        "\nPESQUISE OS CADASTRADOS\n\n"
        "- Digite a palavra chave (min 3 letras): \n"
        "-> ");
        fgets(palavraChave, TAM_NOME, stdin);
        if( sair( palavraChave[0], palavraChave[1]) ){
            break;}
        else if( strlen(palavraChave) > 3 ){
            limpaTexto(palavraChave);
            if( validaNome( palavraChave ) ){
                encontradosId = dispositivoBuscadorDeAluno( palavraChave );
                if( !(encontradosId[0] == -1) ){
                    printf("\n==================================================================="
                           "======================================================================\n"
                           "                                                          ALUNOS ENCONTRADOS: \n"
                           "======================================================================"
                           "===================================================================\n");
                    printf( " %*s  %*s  %*s  %*s  %*s  \n", TAM_MAT+4, "MATRÍCULA", TAM_CPF, "CPF",
                                                TAM_NAC+11, "NASCIMENTO", 14, "SEXO", 14, "NOME" );
                    for( int posicao = 0; encontradosId[posicao] != -1; posicao++ ){
                        printf( "%*s  %*s  %*s    %*c         %-*s\n", TAM_MAT+5, discente[encontradosId[posicao]].dado.matricula,
                                                                   TAM_CPF+5, discente[encontradosId[posicao]].dado.cpf,
                                                                   TAM_NAC+5, discente[encontradosId[posicao]].dado.nascimento,
                                                                   9, discente[encontradosId[posicao]].dado.sexo,
                                                                   TAM_NOME, discente[encontradosId[posicao]].dado.nome );}
                }else{
                    puts( "\n > Nenhum aluno foi encontrado < \n" );}

                encontradosId = dispositivoBuscadorDeProfessor( palavraChave );

                if( !(encontradosId[0] == -1) ){
                    printf( "\n===================================================================="
                            "=====================================================================\n"
                            "                                                          PROFESSORES ENCONTRADOS: \n"
                            "======================================================================="
                            "==================================================================\n");
                    printf( " %*s  %*s  %*s  %*s  %*s  \n", TAM_MAT+4, "MATRÍCULA", TAM_CPF, "CPF",
                                                TAM_NAC+11, "NASCIMENTO", 14, "SEXO", 14, "NOME" );
                    for( int posicao = 0; encontradosId[posicao] != -1; posicao++ ){
                        printf( "%*s  %*s  %*s     %*c       %-*s\n", TAM_MAT+5, docente[encontradosId[posicao]].dado.matricula,
                                                                   TAM_CPF+5, docente[encontradosId[posicao]].dado.cpf,
                                                                   TAM_NAC+5, docente[encontradosId[posicao]].dado.nascimento,
                                                                   9, docente[encontradosId[posicao]].dado.sexo,
                                                                   TAM_NOME, docente[encontradosId[posicao]].dado.nome );}
                }else{puts( "\n > Nenhum professor foi encontrado < \n" );}}
        }else{ puts( "\t> Digite no mínimo 3 letras < \n" );}
    }while( true );
    puts( "\n" );
}
void buscarAlunosPorPalavraChave( ){
    char palavraChave[TAM_NOME];
    enum CHAVE { VALIDA = 1, INVALIDA = 0 };
    enum CHAVE CHAVE;
    int *alunosEncontradosId;

    do{

        printf( "\n================================\n"
        "||   Filtro - PALAVRA CHAVE   || \n"
        "================================\n"
        "\nPESQUISE ALUNOS CADASTRADOS\n\n"
        "- Digite a palavra chave (min 3 letras): \n"
        "-> ");
        fgets(palavraChave, TAM_NOME, stdin);

        if( sair( palavraChave[0], palavraChave[1]) ){
            break;
        }else if( strlen(palavraChave) > 3 ){
            limpaTexto(palavraChave);
            if( validaNome( palavraChave ) ){
                alunosEncontradosId = dispositivoBuscadorDeAluno( palavraChave );

                if( !(alunosEncontradosId[0] == -1) ){
                    printf("\n==================================================================="
                           "======================================================================\n"
                           "                                                       ALUNOS ENCONTRADOS: \n"
                           "======================================================================"
                           "===================================================================\n");
                    printf( " %*s  %*s  %*s  %*s  %*s  \n", TAM_MAT+4, "MATRÍCULA", TAM_CPF, "CPF",
                                                TAM_NAC+11, "NASCIMENTO", 14, "SEXO", 14, "NOME" );
                    for( int posicao = 0; alunosEncontradosId[posicao] != -1; posicao++ ){
                        printf( "%*s  %*s  %*s    %*c         %-*s\n", TAM_MAT+5, discente[alunosEncontradosId[posicao]].dado.matricula,
                                                                       TAM_CPF+5, discente[alunosEncontradosId[posicao]].dado.cpf,
                                                                       TAM_NAC+5, discente[alunosEncontradosId[posicao]].dado.nascimento,
                                                                       9, discente[alunosEncontradosId[posicao]].dado.sexo,
                                                                        TAM_NOME, discente[alunosEncontradosId[posicao]].dado.nome );}
                }else{puts( "\n > Nenhum aluno foi encontrado < \n" );}}
        }else{ puts( "\t> Digite no mínimo 3 letras < \n" );}
    }while( true );
    puts( "\n" );
}
int *dispositivoBuscadorDeAluno( char *chave ){
    int *alunosEncontradosId = (int*)malloc( alunosCadastrados*sizeof(int) ),
        corredor = 0,
        tamanhoChave = strlen( chave );
    char *recorte = (char*)malloc(tamanhoChave*sizeof(char));

    if( alunosCadastrados > 0){
        for( int posicao = 0; posicao < alunosCadastrados; posicao++ ){
            for( int caracter = 0; discente[posicao].dado.nome[caracter] != '\0'; caracter++ ){
                if( discente[posicao].dado.nome[caracter] == chave[0] &&
                    discente[posicao].dado.nome[caracter+tamanhoChave-1] == chave[tamanhoChave-1] ){
                    strncpy( recorte, &discente[posicao].dado.nome[caracter], tamanhoChave );
                    if( strcmp( chave, recorte ) == 0 ){
                        free( recorte );
                        alunosEncontradosId[corredor++] = posicao; }}}}}
    alunosEncontradosId[corredor] = -1;
    return alunosEncontradosId;
}
void buscarProfessoresPorPalavraChave( ){
    char palavraChave[TAM_NOME];
    enum CHAVE { VALIDA = 1, INVALIDA = 0 };
    enum CHAVE CHAVE;
    int *professoresEncontradosId;

    do{

        printf( "\n================================\n"
        "||   Filtro - PALAVRA CHAVE   || \n"
        "================================\n"
        "\nPESQUISE PROFESSORES CADASTRADOS\n\n"
        "- Digite a palavra chave (min 3 letras): \n"
        "-> ");
        fgets(palavraChave, TAM_NOME, stdin);
        if( sair( palavraChave[0], palavraChave[1]) ){
            break;
        }else if( strlen(palavraChave) > 3 ){
            limpaTexto(palavraChave);
            if( validaNome( palavraChave ) ){
                professoresEncontradosId = dispositivoBuscadorDeProfessor( palavraChave );
                if( !(professoresEncontradosId[0] == -1) ){
                    printf( "\n==================================================================="
                            "======================================================================\n"
                            "                                                      PROFESSORES ENCONTRADOS: \n"
                            "====================================================================="
                            "====================================================================\n");
                    printf( " %*s  %*s  %*s  %*s  %*s  \n", TAM_MAT+4, "MATRÍCULA", TAM_CPF, "CPF",
                                                TAM_NAC+11, "NASCIMENTO", 14, "SEXO", 14, "NOME" );
                    for( int posicao = 0; professoresEncontradosId[posicao] != -1; posicao++ ){
                        printf( "%*s  %*s  %*s     %*c       %-*s\n", TAM_MAT+5, docente[professoresEncontradosId[posicao]].dado.matricula,
                                                                      TAM_CPF+5, docente[professoresEncontradosId[posicao]].dado.cpf,
                                                                      TAM_NAC+5, docente[professoresEncontradosId[posicao]].dado.nascimento,
                                                                      9, docente[professoresEncontradosId[posicao]].dado.sexo,
                                                                      TAM_NOME, docente[professoresEncontradosId[posicao]].dado.nome );}
                }else{ puts( "\n > Nenhum professor foi encontrado < \n" );}}
        }else{ puts( "\t> Digite no mínimo 3 letras < \n" ); }
    }while( true );
    puts( "\n" );
}
int *dispositivoBuscadorDeProfessor( char *chave ){
    int *professoresEncontradosId = (int*)malloc( professoresCadastrados*sizeof(int) ),
        corredor = 0, ///incluir mensagem para falha na alocação de memória
        tamanhoChave = strlen( chave );
    char *recorte = (char*)malloc(tamanhoChave*sizeof(char));

    if( professoresCadastrados > 0){
        for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
            for( int caracter = 0; docente[posicao].dado.nome[caracter] != '\0'; caracter++ ){
                if( docente[posicao].dado.nome[caracter] == chave[0] &&
                    docente[posicao].dado.nome[caracter+tamanhoChave-1] == chave[tamanhoChave-1] ){
                    strncpy( recorte, &docente[posicao].dado.nome[caracter], tamanhoChave );
                    if( strcmp( chave, recorte ) == 0 ){
                        free( recorte );
                        professoresEncontradosId[corredor++] = posicao; }}}}}
    professoresEncontradosId[corredor] = -1;
    return professoresEncontradosId;
}
#endif //LISTAS_FILE_H

