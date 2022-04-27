// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Jeferson Leandro de Oliveira dos Reis Santana
//  email: lors.jefersn@gmail.com
//  Matrícula: 20212160060
//  Semestre: 2022.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include "JefersonSantana20212160060.h"

bool q1( char *data ){
    bool validaFormato( char* );
    bool validaCaracteres( char* );
    bool validaTamanho( char* );
    bool validaConsistencia( char* );

    if( validaTamanho( data ) ){
        if( validaCaracteres( data ) ){
            if( validaFormato( data ) ){
                if( validaConsistencia( data ) ){
                    return true;}}}}
    return false;
}
bool validaFormato( char *data ){
    int barras = 0;

    for( int tamanho = 1; data[tamanho] != '\0'; tamanho++ ){
        if( data[tamanho-1] == '/' ){
            barras++;
            if( barras == 1 ){
                if( (tamanho-1) != 1 && (tamanho-1) != 2 ){
                    return false;}
                if( data[tamanho+1] != '/' && data[tamanho+2] != '/' ){
                    return false;}}
            if( barras > 2 ){
                return false;}}
        if( data[tamanho+1] == '\0' && ( data[tamanho-2] != '/' && data[tamanho-4] != '/' ) ){
            return false;}}
    return true;
}
bool validaConsistencia( char *data ){
    int mes = 0;

    if( data[1] == '/' ){
        if( data[0] == '0' ){
            return false;}
        if( data[3] == '/' ){
            if( data[2] == '0' ){
                return false;}
        }else if( data[4] == '/' ){
            if( (data[2] > '1') || ( data[2] == '1' && data[3] > '2' ) || (data[3] == '0') ){
                return false;}}
    }else if( data[2] == '/' ){
        if( data[1] == '0' && data[0] == '0' ){
            return false;}
        if( data[4] == '/' ){
            if( data[3] == '0' ){
                return false;}
            mes = charToInt( data[3] );
            switch( mes ){
                case 1: case 3: case 5: case 7: case 8:
                    if( (data[0] == '3' && data[1] > '1')){
                        return false;}
                    break;
                case 4: case 6: case 9:
                    if( (data[0] == '3') && (data[1] > '0') ){
                        return false;}
                    break;
                default:
                    if( data[0] > '2' ){
                        return false;}
                    if( bissexto( data ) ){
                        if( (data[0] == '2' && data[1] > '9') ){
                        return false;}
                    }else{
                        if( (data[0] == '2') && (data[1] > '8') ){
                            return false;}}
            }
        }else if( data[5] == '/' ){
            if( (data[0] > '3') || (data[3] > '1') || (data[3] == '1' && data[4] > '2') || (data[4] == '0') ){
                return false;}
            mes = ( (charToInt( data[3] ) * 10) + charToInt( data[4] ));
            switch( mes ){
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    if( (data[0] == '3' && data[1] > '1') ){
                        return false;}
                    break;
                case 4: case 6: case 9: case 11:
                    if( (data[0] == '3' && data[1] > '0') ){
                        return false;}
                    break;
                default:
                    if( data[0] > '2' ){
                        return false;}
                    if( bissexto( data ) ){
                        if( (data[0] == '2' && data[1] > '9') ){
                        return false;}
                    }else{
                        if( (data[0] == '2' && data[1] > '8') ){
                            return false;}}
            }
        }
    }
    return true;
}
bool validaCaracteres( char *data ){
    for( int tamanho = 0; data[tamanho] != '\0'; tamanho++ ){
        if( ( ehNumero(data[tamanho] ) ) == 0 && data[tamanho] != '/' ){
            return false;}}
    return true;
}
bool validaTamanho( char *data ){
    for( int tamanho = 0; data[tamanho] != '\0'; tamanho++ ){
        if( data[tamanho+1] == '\0' && tamanho >= (TAMANHO_DATA - 11) && tamanho <= (TAMANHO_DATA - 7) ){
            return true;}}
    return false;
}

/////////////---------------------------------------/////////////

int *q2( char *hoje, char *nascimento ){
    int *tempo = (int*)malloc( 3*sizeof(int) );
    if( q1(hoje) && q1(nascimento) ){
        int MESES[12] = { 31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31 };

        int *converteDataInteiro( char* );
        int *hojeInt = converteDataInteiro(hoje),
            *nascimentoInt = converteDataInteiro(nascimento);


        ///TRATA OS ANOS
        /// 00 - ano atual - automaticamente 2000
        /// de ano atual pra cima - automaticamente 1900

        if( nascimentoInt[2] <= 99 ){
            if( nascimentoInt[2] <= hojeInt[2] && nascimentoInt[2] >= 0 ){
                nascimentoInt[2] += 2000;
            }else{
                nascimento[2] += 1900;}}

        if( hojeInt[2] <= 99 ){
            hojeInt[2] += 2000;}

        if( hojeInt[2] > nascimentoInt[2] ||
          ( hojeInt[2] == nascimentoInt[2] &&
            hojeInt[1] > nascimentoInt[1] ) ||
          ( hojeInt[2] == nascimentoInt[2] &&
            hojeInt[1] == nascimentoInt[1] &&
            hojeInt[0] > nascimentoInt[0] ) ){
            int diasAteOFinalDoAno = 0,
                diasDesdeOInicioDoAno = 0;

            ///CALCULA ANO
            tempo[2] = hojeInt[2] - nascimentoInt[2];
            if( tempo[2] > 0 && ( hojeInt[1] < nascimentoInt[1] ||
              ( hojeInt[1] == nascimentoInt[1] &&
                hojeInt[0] < nascimentoInt[0] ))) {
                tempo[2]--;}

            ///CALCULA MESES
            tempo[1] = 0;
            if( ( nascimentoInt[2] + tempo[2] ) < hojeInt[2] ){
                if( nascimentoInt[1] >= hojeInt[1] ){
                    for( int mes = nascimentoInt[1] + 1; mes <= 12; mes++ ){
                        tempo[1]++;}
                    for( int mes = 1; mes < hojeInt[1]; mes++ ){
                        tempo[1]++;}
                }else{
                    tempo[1] = hojeInt[1] - nascimentoInt[1] - 1;}
            }else if( ( nascimentoInt[2] + tempo[2] ) == hojeInt[2]  ){
                tempo[1] = hojeInt[1] - nascimentoInt[1] - 1;}
            ///CALCULA MESES
            ///3/4/2018
            ///12/03/2020
            /// 1 ano
            ///

            if( nascimentoInt[1] != 2 || ( nascimentoInt[1] == 2 && !bissexto(nascimento) ) ){
                if( ( hojeInt[0] + MESES[nascimentoInt[1]-1] - nascimentoInt[0] )
                    == (hojeInt[1]-2 < 0 ? (MESES[hojeInt[1]+10]  ): MESES[hojeInt[1]-2] ) ){
                    tempo[1] += 1;
                }else if( ( hojeInt[0] + MESES[nascimentoInt[1]-1] - nascimentoInt[0] ) >
                         (hojeInt[1]-2 < 0 ? (MESES[hojeInt[1]+10] ): MESES[hojeInt[1]-2] ) ){
                    tempo[1] += 1;
                    ///CALCULA DIAS
                    tempo[0] = ( hojeInt[0] + (hojeInt[1]-2 < 0 ? (MESES[hojeInt[1]+10]  ): MESES[hojeInt[1]-2]  ) - nascimentoInt[0] ) -
                        (hojeInt[1]-2 < 0 ? (MESES[hojeInt[1]+10]  ): MESES[hojeInt[1]-2]  );
                }else{
                    ///CALCULA DIAS
                    tempo[0] = hojeInt[0] + (hojeInt[1]-2 < 0 ? (MESES[hojeInt[1]+10]  ): MESES[hojeInt[1]-2]  ) - nascimentoInt[0]; }

                if( hojeInt[1] > 2 && bissexto(hoje) ){
                    tempo[0]++;}
            }else if( nascimentoInt[1] == 2 && bissexto(nascimento) ){
                puts( "aqui" );
                if( ( hojeInt[0] + MESES[nascimentoInt[1]-1] + 1 - nascimentoInt[0] )
                  == (hojeInt[1]-2 < 0 ? (MESES[hojeInt[1]+10] ): MESES[hojeInt[1]-2] ) ){
                    tempo[1] += 1;
                }else if( ( hojeInt[0] + MESES[nascimentoInt[1]-1] + 1 - nascimentoInt[0] ) >
                         (hojeInt[1]-2 < 0 ? (MESES[hojeInt[1]+10] ): MESES[hojeInt[1]-2] ) ){
                    tempo[1] += 1;
                    ///CALCULA DIAS
                    tempo[0] = ( hojeInt[0] + (hojeInt[1]-2 < 0 ? (MESES[hojeInt[1]+10] ): MESES[hojeInt[1]-2] ) - nascimentoInt[0] ) -
                        (hojeInt[1]-2 < 0 ? (MESES[hojeInt[1]+10] ): MESES[hojeInt[1]-2] );
                }else{
                    ///CALCULA DIAS
                    tempo[0] = hojeInt[0] + (hojeInt[1]-2 < 0 ? (MESES[hojeInt[1]+10] ): MESES[hojeInt[1]-2] ) - nascimentoInt[0]; }
                if( hojeInt[1] > 2 && bissexto(hoje) ){
                    tempo[0]++;}
            }else{
                if( ( nascimentoInt[2] + tempo[2] % 4 == 0 ) && hojeInt[1] > 2 ){
                    if( ( hojeInt[0] + MESES[nascimentoInt[1]-1] + 1 - nascimentoInt[0] ) == MESES[nascimentoInt[1]-1] + 1 ){
                        tempo[1] += 1;
                    }else if( ( hojeInt[0] + MESES[nascimentoInt[1]-1] + 1 - nascimentoInt[0] ) > MESES[nascimentoInt[1]-1] + 1 ){
                        tempo[1] += 1;
                        ///CALCULA DIAS
                        tempo[0] = ( hojeInt[0] + MESES[nascimentoInt[1]-1] + 1 - nascimentoInt[0] ) - MESES[nascimentoInt[1]-1] + 1 ;
                    }else{
                        ///CALCULA DIAS
                        tempo[0] = hojeInt[0] + MESES[nascimentoInt[1]-1] + 1 - nascimentoInt[0];}
                }else if( nascimentoInt[0] + 1 > MESES[nascimentoInt[1]-1] ){
                    puts("teste");
                    if( ( hojeInt[0] + MESES[nascimentoInt[1]] - 1 ) == MESES[hoje[1]] ){
                        tempo[1] += 1;
                    }else if( ( hojeInt[0] + MESES[nascimentoInt[1]] - 1 ) > MESES[nascimentoInt[1]] ){
                        tempo[1] += 1;
                        ///CALCULA DIAS
                        tempo[0] = ( hojeInt[0] + MESES[nascimentoInt[1]] - 1 ) - MESES[nascimentoInt[1]] ;
                    }else{
                        ///CALCULA DIAS
                        tempo[0] = hojeInt[0] + MESES[nascimentoInt[1]] - 1;}
                }
                if( hojeInt[1] > 2 && bissexto(hoje) ){
                    tempo[0]++;}
            }
            if( nascimentoInt[1] == 2 && bissexto(nascimento) && nascimentoInt[0] == 29 ){
                tempo[0]--;}
        }else{
            tempo[0] = tempo[1] = tempo[2] = -1; }
    }else{
        tempo[0] = tempo[1] = tempo[2] = -1; }
    return tempo;
}
int *converteDataInteiro( char *data ){
    int *dataInteiro = (int*)malloc(3*sizeof(int));
    for( int carac = 0; data[carac] != '\0'; carac++ ){
        if( data[carac] == '/' ){
            if( carac == 1 ){
                dataInteiro[0] = charToInt( data[carac-1] );
            }else if( carac == 2 ){
                dataInteiro[0] = ( charToInt(data[carac-2]) ) * 10;
                dataInteiro[0] += charToInt(data[carac-1]);
            }else if( carac == 3 || ( carac == 4 && data[carac-2] == '/' )
                      || ( carac == 4 && data[carac-2] == '/' ) ){
                dataInteiro[1] = charToInt(data[carac-1]);
            }else if( carac == 4 && data[carac-3] == '/' ){
                dataInteiro[1] = ( charToInt(data[carac-2]) ) * 10;
                dataInteiro[1] += charToInt(data[carac-1]);
            }else if( carac == 5 && data[carac-3] == '/' ){
                dataInteiro[1] = ( charToInt(data[carac-2]) ) * 10;
                dataInteiro[1] += charToInt(data[carac-1]);}
            if( data[carac+3] == '\0' ){
                dataInteiro[2] = charToInt( data[carac+1] ) * 10;
                dataInteiro[2] += charToInt( data[carac+2] );
            }else if( data[carac+5] == '\0' ){
                dataInteiro[2] = charToInt( data[carac+1] ) * 1000;
                dataInteiro[2] += charToInt( data[carac+2] ) * 100;
                dataInteiro[2] += charToInt( data[carac+3] ) * 10;
                dataInteiro[2] += charToInt( data[carac+4] );}}
    }return dataInteiro;
}

/////////////---------------------------------------/////////////

int q3( const char texto[], char letra ){
    int ocorrencias = 0;
    /*
    char as[] = "aàáâãä";
    char es[] = "eèéêë";
    char is[] = "iìíîï";
    char os[] = "oòóôöõ";
    char us[] = "uùúûü";
    char ys[] = "yýÿ";
    char As[] = "AÀÁÂÃÄ";
    char Es[] = "EÈÉÊË";
    char Is[] = "IÌÍÎÏ";
    char Os[] = "OÒÓÔÕÖ";
    char Us[] = "UÙÚÛÜ";
    char Ys[] = "YŸÝ";
    char Cs[] = "CÇ";
    char cs[] = "cç";
    char ns[] = "nñ";
    char Ns[] = "NÑ";
    char *especial;
    char *caracteresEspeciais[16] = { as, es, is, os, us, ys, As, Es, Is, Os, Us, Ys, Cs, cs, ns, Ns };

    for( int e = 0; e < 16; e++ ){
        especial = caracteresEspeciais[e];
        for( int u = 0; especial[u] != '\0'; u++ ){
            if(  ( int*)especial[u] == ( int*)letra ){
                for( int x = 0; texto[x] != '\0'; x++ ){
                    for( int z = 0; especial[z] != '\0'; z++ ){
                        if( ( (int*)texto[x] ) == ( ( int*)especial[z]) ){
                            ocorrencias++;
                        }}}}}}
    */
    for( int x = 0; texto[x] != '\0'; x++ ){
        if( ( (int*)texto[x] ) == ( ( int*)letra) ){;
            ocorrencias++;}}
    return ocorrencias;
}

/////////////---------------------------------------/////////////

int q4( const char texto[], const char palavra[], int posicoes[] ){
    int tamanhoTexto = 0,
        tamanhoPalavra = 0,
        contador = 1,
        ocorrencias = 0,
        marcador = 0;

    for( int carac = 0; palavra[carac+1] != '\0'; carac++ ){
        tamanhoPalavra++;}

    for( int x = 0; texto[x] != '\0'; x++ ){
        if( texto[x] == palavra[0] && texto[x+tamanhoPalavra-1] == palavra[tamanhoPalavra-1] ){
            contador = 1;
            for( int y = 1, w = x+1; y < tamanhoPalavra; y++, w++ ){
                if( texto[w] == palavra[y] ){
                    contador++;}
                if( contador == tamanhoPalavra ){
                    ocorrencias++;
                    posicoes[marcador] = x + 1,
                    posicoes[marcador+1] = x + tamanhoPalavra;
                    x += tamanhoPalavra - 1;
                    marcador += 2;
                    posicoes[marcador] = -1;
                }
            }
        }
    }
    posicoes[marcador] = -1;
    return ocorrencias;
}

/////////////---------------------------------------/////////////

int q5( int valor ){
    int valorInvertido  = 0;

    do{ valorInvertido *= 10;
        valorInvertido += valor % 10;
        valor /= 10;
    }while( valor );
    return valorInvertido;
}

/////////////---------------------------------------/////////////

unsigned q6( const unsigned valor, const unsigned contido ){
    unsigned tamanhoValor = 0,
             tamanhoContido = 0,
             valorBackup = valor,
             contidoBackup = contido,
             posicao = 0,
             vezes = 0;

    do{ tamanhoValor++;
    }while( valorBackup /= 10 );

    do{ tamanhoContido++;
    }while( contidoBackup /= 10 );

    unsigned *algarismosValor = (unsigned*)malloc( tamanhoValor*sizeof(unsigned) );

    posicao = tamanhoValor - 1;
    valorBackup = valor;

    do{ algarismosValor[posicao--] = valorBackup % 10;
    }while( valorBackup /= 10  );

    unsigned *algarismosContido = (unsigned*)malloc( tamanhoContido*sizeof(unsigned) );
    posicao = tamanhoContido - 1;
    contidoBackup = contido;

    do{ algarismosContido[posicao--] = contidoBackup % 10;
    }while( contidoBackup /= 10 );

    for( int y = 0; y < tamanhoValor; y++ ){
        if( algarismosValor[y] == algarismosContido[0] &&
            algarismosValor[y + tamanhoContido - 1] == algarismosContido[tamanhoContido - 1] ){
            int contador = 0;
            if( tamanhoContido > 1 ){
                for( int z = 0, w = y; algarismosValor[w] == algarismosContido[z]; z++, w++ ){ contador++; }
                if( contador == tamanhoContido ){
                    y += tamanhoContido - 1;}
            }else{ vezes++; }}}

    free( algarismosValor );
    free( algarismosContido );
    return vezes;
}
