#ifndef _AGREGADOS_H
#define _AGREGADOS_H

#define TAM_BASE 10

typedef struct numero{
    int valor;
    struct numero *next;
}coluna;

struct{
    int quantidadesBackup,
        TAMANHOBackup,
        *DADOS;
}backup;

char *estruturaBackup = "estruturaBackup.txt";

unsigned MENU( void );
bool encerramento( void ); 
bool insereValor( int, coluna** );
bool excluiValor( int, int, coluna* );
void listaGeral( coluna** );
void listaOrdenada( int*, coluna** );
void listagGeralOrdenada( int*, coluna** );
bool criaColuna( int, coluna** );
short getTamanho( void );
bool aumentaColuna( int, coluna* );
unsigned menuColunas( void );
bool criarArquivos( void );
bool criaBackup( int*, int*, coluna** );
bool recuperaBackup( int*, int*, coluna** );
bool solicitaBAckup( void );

unsigned MENU( void ){
    unsigned resposta = 0;
    
    do{ printf( "\n================== BANCO DINÂMICO ==================\n\n"
                "    MENU\n"
                " [1] <- INSERIR ELEMENTO\n"
                " [2] <- LISTAR TODOS OS ELEMENTOS\n"
                " [3] <- LISTAR ELEMENTOS ORDENADOS\n"
                " [4] <- LISTAR TODOS OS ELEMENTOS ORDENADOS\n"
                " [5] <- EXCLUIR ELEMENTO\n"
                " [6] <- INCREMENTAR ESTRUTURA\n"
                " [7] <- SAIR\n\n"
                " [R] <- " );
        scanf( "%u", &resposta ); getchar( );
    }while( resposta > 7 || resposta < 1 );
    return resposta;
}
unsigned menuColunas( void ){
    int resposta = 0;
        printf( "SELECIONE A COLUNA PARA INSERIR O ELEMENTO [0 SAIR]\n\n"
            " [1]  [2]  [3]  [4]  [5]  [6]  [7]  [8]  [9]  [10]\n\n"
            " [ ] = " );
    scanf( "%d", &resposta );

    while( resposta < 0 || resposta > 10){
        printf( "\nOpção inválida!\n\n" 
                "\n[R] = " );
        scanf( "%d", &resposta );}
    return resposta;
}
bool encerramento( ){
    char resposta;
    do{ printf( "\n\n=================== ENCERRAMENTO ===================\n\n"
                "\n\t            Confirma encerramento?\n\n"
                "\t         [1] SIM                [2] NÃO\n\n"
                " [ ] <- " );
        resposta = getchar( ); getchar( ); 
        switch( resposta ){
            case '1': return true;
            case '2': return false;
            default: puts("\n\t\t\t\tResposta inválida!");}
    }while( true );
}
bool solicitaBAckup( void ){
    char resposta;
    do{ printf( "\n\n====================== BACKUP ======================\n\n"
                "\n\t            Deseja salvar os dados?\n\n"
                "\t         [1] SIM                [2] NÃO\n\n"
                " [ ] <- " );
        resposta = getchar( ); getchar( ); 
        switch( resposta ){
            case '1': return true;
            case '2': return false;
            default: puts("\n\t\t\t\tResposta inválida!");}
    }while( true );  
}
short getTamanho( void ){
    int tamanho;

    printf( "\n|Ops! Essa lista não tem espaço      |\n"
                "|Digite o tamanho dela para criarmos.|\n\n"
                "Novo tamanho = ");
    scanf( "%d", &tamanho );    
    while( tamanho < 1 ){
        printf( "\n{ Tamanho inválido! }\n\n"
                "Novo tamanho = " );
        scanf( "%d", &tamanho );}
    return tamanho;
}
bool criaColuna( int tamanho, coluna **head ){
    coluna *atual,
           *novo;
    
    (*head) = (coluna*)malloc( sizeof(coluna) );
    (*head)->valor = 0;
    (*head)->next = NULL;
    atual = (*head);
    
    while( tamanho > 1 ){
        novo = (coluna*)malloc( sizeof(coluna) );
        novo->valor = 0;
        novo->next = NULL;
        atual->next = novo;
        atual = atual->next;
        tamanho--;}
    atual->next = NULL;
    return true;
}
bool insereValor( int valor, coluna**head ){
    coluna *atual = (*head);

    while( atual->valor != 0 ){
        atual = atual->next;}
    atual->valor = valor;
    
    return true;    
}
bool excluiValor( int tamanho,int valor, coluna *head ){
    int contador = 0;
    if( head != NULL ){
        coluna *atual = head;
        while( atual != NULL ){
            contador++;
            if( atual->valor == valor ){
                coluna *proximo = atual->next;
                while( proximo != NULL ){
                    contador++;
                    atual->valor = proximo->valor;
                    atual = atual->next;
                    proximo = atual->next;}
                if( contador == tamanho ){
                    atual->valor = 0;}
             return true;}
            atual = atual->next;
    }}return false;
}
bool aumentaColuna( int complemento, coluna *head ){
    if( head != NULL ){
        coluna *atual = head,
               *novo = NULL; 
    
        while( atual->next !=NULL ){
            atual = atual->next;}
        
        while( complemento > 0 ){
            novo = (coluna*)malloc( sizeof(coluna) );
            novo->valor = 0;
            novo->next = NULL;
            atual->next = novo;
            atual = atual->next;
            complemento--;}
        atual->next = NULL;
        return true;
    }else return false;
}
void listaGeral( coluna **BASE ){
    coluna *atual = *BASE;
    unsigned preenchido = 0;
    
    for( int e = 0; e < TAM_BASE; e++ ){
        printf( " [ %d ]  ->", e+1 );   
        if( BASE[e] != NULL ){
            preenchido = 0;
            atual = BASE[e];
            while( atual != NULL ){
                preenchido++; 
                printf( "\t[ %d ]", atual->valor );
                atual = atual->next;}
                printf( "\t= %d %s", preenchido, (preenchido > 1 ? "SLOTS" : "SLOT" ) ); 
        }else{ printf( "\tVAZIO");}
        puts( "\n" );}  
}
void listaOrdenada( int *TAMANHOS, coluna**BASE ){
    coluna *primeiraHeadBAckup = NULL,
           *segundaHeadBAckup = NULL,
           *terceiraHeadBAckup = NULL,
           *quartaHeadBAckup = NULL,
           *quintaHeadBAckup = NULL,
           *sextaHeadBAckup = NULL,
           *setimaHeadBAckup = NULL,
           *oitavaHeadBAckup = NULL,
           *nonaHeadBAckup = NULL,
           *decimaHeadBAckup = NULL;

    coluna *BASE_BACKUP[TAM_BASE] = { primeiraHeadBAckup, segundaHeadBAckup, terceiraHeadBAckup,
                                      quartaHeadBAckup, quintaHeadBAckup, sextaHeadBAckup,
                                      setimaHeadBAckup, oitavaHeadBAckup, nonaHeadBAckup,
                                      decimaHeadBAckup };

    for( int e = 0; e < TAM_BASE; e++ ){
        if( TAMANHOS[e] > 0  ){
            criaColuna( TAMANHOS[e], &BASE_BACKUP[e]);}}
   
    for( int x = 0; x < TAM_BASE; x++ ){
        coluna *atual = BASE[x],
               *atualBackup = BASE_BACKUP[x];
        
        while( atualBackup != NULL ){
            atualBackup->valor = atual->valor;
            atual = atual->next;
            atualBackup = atualBackup->next;}}
    
    coluna *primeiro,
           *seguinte;
    for( int coluna = 0; coluna < TAM_BASE; coluna++ ){
        primeiro = BASE_BACKUP[coluna];
        while( primeiro != NULL ){
            seguinte = primeiro->next;
            while( seguinte != NULL ){
                if( primeiro->valor > seguinte->valor ){
                    int valorBackup = primeiro->valor;
                    primeiro->valor = seguinte->valor;
                    seguinte->valor = valorBackup;}
                seguinte = seguinte->next;
            }primeiro = primeiro->next;
        }
    }
    listaGeral(BASE_BACKUP);
}
void listagGeralOrdenada( int *quantidade, coluna **BASE ){
    int tamanho = 0,
        corredor = 0;
    for( int x = 0; x < TAM_BASE; x++ ){
        tamanho += quantidade[x];}

    int *elementos = (int*)malloc( tamanho*sizeof( int ) ); 
    coluna *atual = NULL;
    
    for( int coluna = 0; coluna < TAM_BASE; coluna++ ){
        atual = BASE[coluna];
        while( atual != NULL ){
            elementos[corredor] = atual->valor;
            atual = atual->next;
            corredor++;}}
    
    for( int x = 1; x < tamanho; x++  ){
        for(  int y = 0; y < tamanho-1; y++ ){
            if( elementos[y] > elementos[y+1] ){
                int backUp = elementos[y];
                elementos[y] = elementos[y+1];
                elementos[y+1] = backUp;}}}

    printf( "[ ] ->" );
    for( int x = 0; x < tamanho; x++ ){
        if( elementos[x] != 0 ){
            printf( "\t%d", elementos[x] );}}
    puts("\n\n");
}

bool criarArquivos( ){
    FILE *dadosBackup;

    if( ( dadosBackup = fopen(estruturaBackup, "r" ) ) == NULL ){
        dadosBackup = fopen( estruturaBackup, "w" );
        if( dadosBackup != NULL ){
            fclose( dadosBackup );
            return true;
        }else{
            return false;}
    }else{
        dadosBackup = fopen( estruturaBackup, "r+" );
        if( dadosBackup != NULL ){
            fclose( dadosBackup );
            return true;
        }else{
            fclose( dadosBackup );
            return false;}}
}
bool criaBackup( int *TAMANHOS, int *quantidades, coluna **BASE){
    int corredor = 0;
    coluna *elemento;
    FILE *arquivoDadosBackup = fopen( estruturaBackup, "w+" );

    if( arquivoDadosBackup != NULL ){
        for( int colunas = 0; colunas < TAM_BASE; colunas++ ){
            fprintf( arquivoDadosBackup, "%d %d\n", 
                     TAMANHOS[colunas], quantidades[colunas] );
            elemento = BASE[colunas];
            while( elemento != NULL ){
                fprintf( arquivoDadosBackup, "%d ", elemento->valor );
                elemento = elemento->next;}
        }
        fclose( arquivoDadosBackup );
        return true;
    }else{ return false; }
}
bool recuperaBackup( int *TAMANHOS, int *quantidades, coluna **BASE ){
    int corredor = 0;
    coluna *elemento;
    FILE *arquivoDadosBackup = fopen( estruturaBackup, "r" );

    if( arquivoDadosBackup != NULL ){
        for( int colunas = 0; colunas < TAM_BASE; colunas++ ){
            fscanf( arquivoDadosBackup, "%d %d\n", 
                     &TAMANHOS[colunas], &quantidades[colunas] );
        
            if( TAMANHOS[colunas] > 0 ){
                criaColuna( TAMANHOS[colunas], &BASE[colunas] );}

            elemento = BASE[colunas];

            while( elemento != NULL ){
                fscanf( arquivoDadosBackup, "%d ", &elemento->valor );
                elemento = elemento->next;}
        }
        fclose( arquivoDadosBackup );
        return true;
    }else{ 
        return false; }
}
#endif