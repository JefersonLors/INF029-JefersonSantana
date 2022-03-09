#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define bool _Bool 
#define true 1
#define false 0

#define TAMANHO_DATA 12

int main( ){ 
    bool validaData( char* );    
    char data[TAMANHO_DATA] = { };
    
    putchar('\n');
    do{
        putchar('\n');
        printf( "> Insira uma data \n\t < " );
        fgets( data, TAMANHO_DATA, stdin );
        validaData( data );
    }while( 1 );
    
}
bool validaData( char *data ){
    bool validaFormato( char* );
    bool validaConsistencia( char* );

    if( validaFormato( data ) ){
        puts( "\t ^ Formato valido! " );
        if( validaConsistencia( data ) ){
            puts( "\t ^ Data consistente!" );
            return true;}}
    return false;
}
bool validaFormato( char *data ){
    int barras = 0,
        tamanho = 1;
    
    while( data[tamanho-1] != '\0' ){
        if( (isdigit(data[tamanho-1])) == 0 && data[tamanho-1] != '/' && data[tamanho-1] != '\n' ){
            puts( "\t ^ Data invalida. Utilize apenas números." );
            return false;}
        if( data[tamanho-1] == '/' ){
            barras++;
            if( barras == 1 ){
                if( (tamanho-1) != 1 && (tamanho-1) != 2 ){
                    puts( "\t ^ Data invalida!_1");
                    return false;}
                if( data[tamanho+1] != '/' && data[tamanho+2] != '/' ){
                    puts( "\t ^ Data invalida!_2");
                    return false;}}
            if( barras > 2 ){
                puts( "\t ^ Data invalida!_4");
                return false;}}
        if( data[tamanho] == '\0' && tamanho < (TAMANHO_DATA - 5) ){
            puts( "\t ^ Data invalida!_5");
            return false;}
        tamanho++;}
    return true;
}
bool validaConsistencia( char *data ){ 
    int charToInt( char );
    int mes = 0,
        ano = 0;
    enum BISSEXTO { SIM = 1, NAO = 0 };
    enum BISSEXTO ANO_BISSEXTO;

    ///quando tirar a quebra de linha tem que adaptar
    for( int digito = 5; data[digito] != '\0'; digito++ ){  
        if( data[digito+1] == '\0' ){
            ano = ( charToInt( data[digito-2] ) * 10 ) + charToInt( data[digito-1] );
            if( ano == 0 || ano % 4 == 0 ){
                ANO_BISSEXTO = SIM;
            }else{
                ANO_BISSEXTO = NAO;}}}
    
    if( data[1] == '/' ){
        if( data[0] == '0' ){
            puts( "\t ^ Data invalida! - 1");
            return false;}
        if( data[3] == '/' ){ 
            if( data[2] == '0' ){
                puts( "\t ^ Data invalida! - 2");
                return false;}
        }else if( data[4] == '/' ){ 
            if( (data[2] > '1') || ( data[2] == '1' && data[3] > '2' ) || (data[3] == '0') ){
                puts( "\t ^ Data invalida! - 3");
                return false;}}
    }else if( data[2] == '/' ){
        if( data[1] == '0' ){
            puts( "\t ^ Data invalida! - 4");
            return false;}
        if( data[4] == '/' ){ 
            if( data[3] == '0' ){
                puts( "\t ^ Data invalida! - 5");
                return false;}
            mes = charToInt( data[3] );
            switch( mes ){
                case 1: case 3: case 5: case 7: case 8: 
                    if( (data[0] == '3' && data[1] > '1')){ 
                        puts( "\t ^ Data invalida! - 4");
                        return false;}
                    break;
                case 4: case 6: case 9: 
                    if( (data[0] == '3') && (data[1] > '0') ){ 
                        puts( "\t ^ Data invalida! - 5");
                        return false;}
                    break; 
                default: 
                    if( data[0] > '2' ){
                        puts( "\t ^ Data invalida! - 6");
                        return false;}
                    if( ANO_BISSEXTO == SIM ){
                        if( (data[0] == '2' && data[1] > '9') ){
                        puts( "\t ^ Data invalida! - 7");
                        return false;}
                    }else{
                        if( (data[0] == '2') && (data[1] > '8') ){
                            puts( "\t ^ Data invalida! - 8");
                            return false;}}
            }
        }else if( data[5] == '/' ){ 
            if( (data[0] > '3') || (data[3] > '1') || (data[3] == '1' && data[4] > '2') || (data[4] == '0') ){
                puts( "\t ^ Data invalida! - 9");
                return false;}
            mes = ((charToInt( data[3] ) * 10) + charToInt( data[4] ));
            switch( mes ){
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    if( (data[0] == '3' && data[1] > '1') ){ 
                        puts( "\t ^ Data invalida! - 10");
                        return false;}
                    break;
                case 4: case 6: case 9: case 11: 
                    if( (data[0] == '3' && data[1] > '0') ){ 
                        puts( "\t ^ Data invalida! - 11");
                        return false;}
                    break; 
                default: 
                    if( data[0] > '2' ){
                        puts( "\t ^ Data invalida! - 12");
                        return false;}
                    if( ANO_BISSEXTO == SIM ){
                        if( (data[0] == '2' && data[1] > '9') ){
                        puts( "\t ^ Data invalida! - 13");
                        return false;}
                    }else{
                        if( (data[0] == '2' && data[1] > '8') ){
                            puts( "\t ^ Data invalida! - 14");
                            return false;}}
            }
        }
    }
    return true;    
}
int charToInt( char digito ){
    switch( digito ){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return -1;
    }
}
    /// 0 0 / 0 0 / 0 0 0 0 '\n' '\0'
    /// 0 1 2 3 4 5 6 7 8 9   0    1
    
    /// 0 / 0 0 / 0 0 0 0 '\n' '\0'
    /// 0 1 2 3 4 5 6 7 8   9    0    
    
    /// 0 0 / 0 / 0 0 0 0 '\n' '\0'
    /// 0 1 2 3 4 5 6 7 8   9    0    
    
    /// 0 / 0 / 0 0 0 0 '\n' '\0'
    /// 0 1 2 3 4 5 6 7   8    9   
    
    /// 0 0 / 0 0 / 0 0 '\n' '\0'
    /// 0 1 2 3 4 5 6 7   8    9    
    
    /// 0 / 0 0 / 0 0 '\n' '\0'
    /// 0 1 2 3 4 5 6   7    8 
    
    /// 0 0 / 0 / 0 0 '\n' '\0'
    /// 0 1 2 3 4 5 6   7    8 
    
    /// 0 / 0 / 0 0 '\n' '\0'
    /// 0 1 2 3 4 5   6    7
