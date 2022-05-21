#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "_agregados.h"

int main( ){
    criarArquivos();
    bool confirma = false;
    
    int resposta = 0,
        quantidade[TAM_BASE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        valor = 0;
    
    unsigned TAMANHOS[TAM_BASE] = { 0 }; 
    
    coluna *primeiraHead = NULL,
           *segundaHead = NULL,
           *terceiraHead = NULL,
           *quartaHead = NULL,
           *quintaHead = NULL,
           *sextaHead = NULL,
           *setimaHead = NULL,
           *oitavaHead = NULL,
           *nonaHead = NULL,
           *decimaHead = NULL;
    
    coluna *BASE[TAM_BASE] = { primeiraHead, segundaHead, terceiraHead, quartaHead, quintaHead,
                               sextaHead, setimaHead, oitavaHead, nonaHead, decimaHead };

    if( recuperaBackup( TAMANHOS, quantidade, BASE ) ) {
        do{ switch( MENU( ) ){
                case 1: 
                    do{
                        printf( "\n\n==================== INSERINDO ====================\n\n");
                        resposta = menuColunas( );
                        if( resposta == 0 ){break;}
                        
                        printf( "\n\n==================== COLUNA [%d] ====================\n\n", resposta );  
                        if( BASE[resposta-1] == NULL ) {
                            TAMANHOS[resposta-1] = getTamanho( );
                            criaColuna( TAMANHOS[resposta-1], &BASE[resposta-1] );}
                        
                        printf( "\n\nINSIRA OS ELEMENTO DA COLUNA [%d] [0 SAIR]\n\n"
                                "TAMANHO COLUNA: %d\n\n", resposta, TAMANHOS[resposta-1] );
                        
                        if( quantidade[resposta-1] + 1 <= TAMANHOS[resposta-1] ){
                            printf( "[%d] = ", quantidade[resposta-1]+1 );
                            scanf( "%d", &valor );
                            
                            if( valor == 0 ){
                                puts( "\n\nInserção encerrada\n" );
                                break;}
                            if( insereValor( valor, &BASE[resposta-1] ) ){
                                quantidade[resposta-1]++;
                            }else{
                                puts( "\nOps! O valor não foi adicionado!\n");}
                        }else{ puts( "\nlista cheia!\n");}
                    }while( true );
                break;
                case 2: 
                    printf( "\n\n==================== LISTA GERAL ====================\n\n" );
                    listaGeral( BASE ); 
                    break;
                case 3: 
                    printf( "\n\n==================== LISTA ORDENADA ====================\n\n" );
                    listaOrdenada( TAMANHOS, BASE ); 
                    break;
                case 4: 
                    printf( "\n\n================= LISTA GERAL ORDENADA ==================\n\n" );
                    listagGeralOrdenada( quantidade, BASE ); 
                    break;
                case 5:
                    do{ printf( "\n\n==================== EXCLUINDO ====================\n\n" );
                        resposta = menuColunas( );
                        if( resposta == 0 ){break;}
                        
                        printf( "\n\n==================== COLUNA [%d] ====================\n\n" 
                                "\n\nINSIRA O ELEMENTO DA COLUNA [%d] PARA EXCLUIR [0 SAIR]\n\n"
                                , resposta, resposta );
                        
                        printf( "[X] = " );
                        scanf( "%d", &valor );
                        
                        if( valor == 0 ){
                            puts( "\n\nExclusão encerrada\n" );
                            break;}
                        if( excluiValor( quantidade[resposta-1], valor, BASE[resposta-1] ) ){
                            puts( "\nValor excluído!\n");
                        }else{
                            puts( "\nOps! O valor não está na coluna.\n");}
                    }while( true );
                break;
                case 6:
                    do{
                        printf( "\n\n==================== INCREMENTADO ====================\n\n");
                        resposta = menuColunas( );
                        if( resposta == 0 ){break;}
                        
                        printf( "\n\n==================== COLUNA [%d] ====================\n\n" 
                                "\n\nINSIRA O TAMANHO DO COMPLEMENTO PARA A COLUNA [%d] [0 SAIR]\n\n"
                                , resposta, resposta );
                        
                        printf( "[+] = " );
                        scanf( "%d", &valor );
                        
                        if( valor == 0 ){
                            puts( "\n\nComplemento encerrado\n" );
                            break;}
                        if( aumentaColuna( valor, BASE[resposta-1] ) ){
                            TAMANHOS[resposta-1] += valor;
                            printf( "\nNovo tamanho da COLUNA [%d]: \n", resposta );
                        }else{ 
                            puts( "\nOps! Coluna não incrementada.\n"); }
                    }while( true );
                break;
                default:
                    if( (confirma = encerramento( )) ){
                        if( solicitaBAckup() ){
                            if( criaBackup( TAMANHOS, quantidade, BASE ) ){
                                puts("\n\t\t\t\t\tBackup criado");
                            }else{ puts("\n\n\t\tOps!Não foi possível criar o backup :( ");}
                        }else{ puts("\n\t\t\t\t\tDados apagados ");}}
                    break;}
        }while( !confirma );
    }else{ puts("\n\n\t\tPuts! Não foi possível recuperar os dados :( ");}
    puts("\n\n\t\t\t\t<<< PROGRAMA ENCERRADO >>>\n\n");
    return 0;
}
