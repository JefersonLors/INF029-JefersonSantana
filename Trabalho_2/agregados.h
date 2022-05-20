#ifndef AGREGADOS_H
#define AGREGADOS_H

typedef struct primeiro{
    int valor;
    struct primeiro *next;
}primeiro;

typedef struct segundo{
    int valor;
    struct segundo *next;
}segundo;

typedef struct terceiro{
    int valor;
    struct terceiro *next;
}terceiro;

typedef struct quarto{
    int valor;
    struct quarto *next;
}quarto;

typedef struct quinto{
    int valor;
    struct tequinto *next;
}quinto;

typedef struct sexto{
    int valor;
    struct sexto *next;
}sexto;

typedef struct setimo{
    int valor;
    struct setimo *next;
}setimo;

typedef struct oitavo{
    int valor;
    struct oitavo *next;
}oitavo;

typedef struct nono{
    int valor;
    struct nono *next;
}nono;

typedef struct decimo{
    int valor;
    struct decimo *next;
}decimo;

struct{
    unsigned Primeiro,
             Segundo,
             Terceiro,
             Quatro,
             Quinto,
             Sexto,
             Setimo,
             Oitavo,
             Nono,
             Decimo;
}tamanho;
unsigned MENU( void );
bool encerramento( void ); 

///FUNÇÕES DE INSERÇÃO
bool inserirPrimeiro( int, primeiro** );
bool inserirSegundo( int, segundo** );
bool inserirTerceiro( int, terceiro** );
bool inserirQuatro( int, quarto** );
bool inserirQuinto( int, quinto** );
bool inserirSexto( int, sexto** );
bool inserirSetimo( int, setimo** );
bool inserirOitavo( int, oitavo** );
bool inserirNovo( int, nono** );
bool inserirDecimo( int, decimo** );
////------------------
////FUNÇÕES DE CRIAÇÃO DE SLOTS
bool criaPrimeiro( int, primeiro** );
bool criaSegundo( int, segundo** );
bool criaTerceiro( int, terceiro** );
bool criaQuatro( int, quarto** );
bool criaQuinto( int, quinto** );
bool criaSexto( int, sexto** );
bool criaSetimo( int, setimo** );
bool criaOitavo( int, oitavo** );
bool criaNovo( int, nono** );
bool criaDecimo( int, decimo** );
////------------------
short getTamanho( void );

unsigned MENU( void ){
    unsigned resposta = 0;
    do{
        printf( "\n================== BANCO DINÂMICO ==================\n\n"
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
bool encerramento( ){
    do{ printf( "\n\nSe você encerrar o programa todos os dados serão perdidos.\n"
                "        Você confirma esse encerramento?\n\n"
                "         [1] SIM                [2] NÃO\n\n"
                " R <- " );
        switch( getchar( ) ){
            case '1': return true;
            case '2': return false;
            default: puts("Resposta inválida!");}
    }while( true );
}
bool inserirPrimeiro( int numero, primeiro **head ){
    primeiro *atual, 
             *novo;
    
    if( (*head) == NULL ){
        (*head) = (primeiro*)malloc( sizeof(primeiro) );
        (*head)->valor = numero;
        (*head)->next = NULL;
    }else{
        atual = (*head);
        while( atual->next != NULL ){
            atual = atual->next;}
        novo = (primeiro*)malloc( sizeof(primeiro) );
        novo->valor = numero;
        novo->next = NULL;
        atual->next = novo;}
    return true;
}
bool inserirSegundo( int numero, segundo**head ){
    return true;
}
bool inserirTerceiro( int numero , terceiro**head ){
    return true;
}
bool inserirQuatro( int numero, quarto**head ){
    return true;
}
bool inserirQuinto( int numero, quinto**head ){
    return true;
}
bool inserirSexto( int numero, sexto**head ){
    return true;
}
bool inserirSetimo( int numero, setimo**head ){
    return true;
}
bool inserirOitavo( int numero, oitavo**head ){
    return true;
}
bool inserirNovo( int numero, nono**head ){
    return true;
}
bool inserirDecimo( int numero, decimo**head ){
    return true;
}

bool criaPrimeiro( int tamanho, primeiro**head ){
    return true;
}
bool criaSegundo( int tamanho, segundo**head ){
    return true;
}
bool criaTerceiro( int tamanho, terceiro**head ){
    return true;
}
bool criaQuatro( int tamanho, quarto**head ){
    return true;
}
bool criaQuinto( int tamanho, quinto**head ){
    return true;
}
bool criaSexto( int tamanho, sexto**head ){
    return true;
}
bool criaSetimo( int tamanho, setimo**head ){
    return true;
}
bool criaOitavo( int tamanho, oitavo**head ){
    return true;
}
bool criaNovo( int tamanho, nono**head ){
    return true;
}
bool criaDecimo( int tamanho, decimo**head ){
    return true;
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
#endif