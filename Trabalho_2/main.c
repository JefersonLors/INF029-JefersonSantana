#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "agregados.h"

int main( ){
    bool confirma = false;

    int resposta = 0,
        quantidade = 0,
        valor = 0;
    
    primeiro *Ihead = NULL;
    segundo *IIhead = NULL;
    terceiro *IIIhead = NULL;
    quarto *IVhead = NULL;
    quinto *Vhead = NULL;
    sexto *VIhead = NULL;
    setimo *VIIhead = NULL;
    oitavo *VIIIhead = NULL;
    nono *IXhead = NULL;
    decimo *Xhead = NULL;
    
    do{
        switch( MENU( ) ){
            case 1: 
                printf( "\n\n==================== INSERINDO ====================\n\n"
                        "SELECIONE A COLUNA PARA INSERIR O ELEMENTO [0 SAIR]\n\n"
                        " [1]  [2]  [3]  [4]  [5]  [6]  [7]  [8]  [9]  [10]\n\n");
                do{
                    printf( " [R] = " );
                    scanf( "%d", &resposta );
                    if( resposta == 0 ){
                        break;
                    }else if( resposta == 1 ){
                        printf( "\n\n==================== COLUNA [1] ====================\n\n"
                                "INSIRA OS ELEMENTOS [0 SAIR]\n\n" );
                        if( Ihead == NULL ) {
                            tamanho.Primeiro = getTamanho( );
                        }else{
                            quantidade = 1;
                            do{
                                printf( "[%d] = ", quantidade );
                                scanf( "%d", &valor );
                                if( inserirPrimeiro( valor, &Ihead  ) ){
                                    quantidade++;
                                }else{
                                    puts( "\nOps! O valor não foi adicionado!\n");}
                            }while( quantidade <= tamanho.Primeiro );}
                    }else if( resposta == 2 ){
                        
                    }else if( resposta == 3 ){
                        
                    }else if( resposta == 4 ){
                        
                    }else if( resposta == 5 ){
                        
                    }else if( resposta == 6 ){
                        
                    }else if( resposta == 7 ){
                        
                    }else if( resposta == 8 ){
                        
                    }else if( resposta == 9 ){
                        
                    }else if ( resposta == 10 ){
                        
                    }else{
                        puts( "\n { Escolha uma opção válida! }\n");}
            
                }while( true );
        

            break;
            
            case 2:
            break;
            
            case 3:
            break;
            
            case 4:
            break;
            
            case 5:
            break;
            
            case 6:
            break;
            
            default:
                confirma = encerramento( );
                break;        
        }
    }while( !confirma );
    puts("\n\n\t\t\t<<< PROGRAMA ENCERRADO >>>\n\n");
    return 0;
}
