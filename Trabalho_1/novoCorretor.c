#include <stdio.h>
#include <string.h>
#include <locale.h>

void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();

int main(){
    setlocale( LC_ALL, "" );

    puts( "\tTESTE QUESTAO 1\n" );
    testQ1(); // 10 testes
    puts( "\tTESTE QUESTAO 2\n" );
    testQ2(); // 35 testes
    puts( "\tTESTE QUESTAO 3\n" );
    testQ3(); // 13 testes
    puts( "\tTESTE QUESTAO 4\n" );
    testQ4(); // 22 testes
    puts( "\tTESTE QUESTAO 5\n" );
    testQ5(); // 10 testes
    puts( "\tTESTE QUESTAO 6\n" );
    testQ6(); // 10 testes


}

void testQ1(){
    char str[11];
    strcpy(str,"29/02/2015");
    printf("%-*s - data %s\n", 10, str, ( q1(str) ? "correta" : "incorreta" )  );
    strcpy(str,"29/02/2012");
    printf("%-*s - data %s\n", 10, str, ( q1(str) ? "correta" : "incorreta" )  );
    strcpy(str,"9/13/2014");
    printf("%-*s - data %s\n", 10, str, ( q1(str) ? "correta" : "incorreta" )  );
    strcpy(str,"45/4/2014");
    printf("%-*s - data %s\n", 10, str, ( q1(str) ? "correta" : "incorreta" )  );
    strcpy(str,"12/1/15");
    printf("%-*s - data %s\n", 10, str, ( q1(str) ? "correta" : "incorreta" )  );
    strcpy(str,"1/9/2016");
    printf("%-*s - data %s\n", 10, str, ( q1(str) ? "correta" : "incorreta" )  );
    strcpy(str,"//2016");
    printf("%-*s - data %s\n", 10, str, ( q1(str) ? "correta" : "incorreta" )  );
    strcpy(str,"1//20");
    printf("%-*s - data %s\n", 10, str, ( q1(str) ? "correta" : "incorreta" )  );
    strcpy(str,"1/R/2016");
    printf("%-*s - data %s\n", 10, str, ( q1(str) ? "correta" : "incorreta" )  );
    strcpy(str,"1/12/19");
    printf("%-*s - data %s\n", 10, str, ( q1(str) ? "correta" : "incorreta" )  );
    puts("");
}

void testQ2(){
    char datainicial[11], datafinal[11];
    int *dma;

    //teste 1
    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma[0] != -1 );
    printf("%d\n", dma[0] == 0);
    printf("%d\n", dma[1] == 0);
    printf("%d\n", dma[2] == 1);
    /*
    //teste 2 - retornos
    strcpy(datainicial,"01/30/2015");
    strcpy(datafinal,"01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma[0] == -1 );

    strcpy(datainicial,"01/3/2015");
    strcpy(datafinal,"40/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma[0] == -1 );

    strcpy(datainicial,"01/06/2016");
    strcpy(datafinal,"01/06/2015");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma[0] == -1 );

    //teste 3
    strcpy(datainicial,"06/06/2017");
    strcpy(datafinal,"07/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma[0] != -1);
    printf("%d\n", dma[0] == 1);
    printf("%d\n", dma[1] == 1);
    printf("%d\n", dma[2] == 0);

    //teste 4
    strcpy(datainicial,"06/06/2017");
    strcpy(datafinal,"05/07/2018");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma[0] != -1);
    printf("%d\n",dma[0] == 29);
    printf("%d\n",dma[1] == 0);
    printf("%d\n",dma[2] == 1);

    //teste 5
    strcpy(datainicial,"26/07/2017");
    strcpy(datafinal,"25/08/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma[0] != -1);
    printf("%d\n",dma[0] == 30);
    printf("%d\n",dma[1] == 0);
    printf("%d\n",dma[2] == 0);

    //teste 6
    strcpy(datainicial,"26/06/2017");
    strcpy(datafinal,"26/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma[0] != -1);
    printf("%d\n",dma[0] == 0);
    printf("%d\n",dma[1] == 1);
    printf("%d\n",dma[2] == 0);

    //teste 8
    strcpy(datainicial,"27/02/2016");
    strcpy(datafinal,"03/03/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma[0] != -1);
    printf("%d\n",dma[0] == 4);
    printf("%d\n",dma[1] == 0);
    printf("%d\n",dma[2] == 1);

    //teste 9
    strcpy(datainicial,"27/02/2015");
    strcpy(datafinal,"03/03/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma[0] != -1);
    printf("%d\n",dma[0] == 5);
    printf("%d\n",dma[1] == 0);
    printf("%d\n",dma[2] == 1);

    //teste 10
    strcpy(datainicial,"28/01/2016");
    strcpy(datafinal,"29/02/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma[0] != -1);
    printf("%d\n",dma[0] == 1);
    printf("%d\n",dma[1] == 1);
    printf("%d\n",dma[2] == 0);
    */
}

void testQ3(){
    char str[250];

    strcpy(str,"Renato Lima Novais");
    printf("%d\n", q3(str, 'a' ) == 3 );
    printf("%d\n",q3(str, 'b' ) == 0);
    printf("%d\n",q3(str, 'l' ) == 0);
    printf("%d\n",q3(str, 'l' ) == 1);
    printf("%d\n",q3(str, 'L' ) == 1);

    strcpy(str,"Letícia, signifiCa fEliCIdADE");
    printf("%d\n",q3(str, 'c' ) == 3);
    printf("%d\n",q3(str, 'C' ) == 3);
    printf("%d\n",q3(str, 'c' ) == 1);
    printf("%d\n",q3(str, 'C' ) == 2);
    printf("%d\n",q3(str, 'R' ) == 0);
    printf("%d\n",q3(str, 'e' ) == 3);
    printf("%d\n",q3(str, 'E' ) == 2);
    printf("%d\n",q3(str, 'S' ) == 0);

}


void testQ4(){
    char strTexto[250];
    char strBusca[50];
    int  posicoes[30];
    int i;

    strcpy(strTexto,"Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca,"rato");
    q4(strTexto, strBusca, posicoes);
    printf("TEXTO: %s\nBUSCA: %s\n\nRESULTADOS\n\n%d OCORRENCIAS\nPOSICOES: ", strTexto, strBusca, q4(strTexto, strBusca, posicoes) );
    for( int c = 0; posicoes[c] != -1; c +=2 ){
        printf( "[ %d, %d ] ", posicoes[c], posicoes[c+1] );}

    puts( "\n" );

    strcpy(strTexto,"Ola, o mundo e muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca,"mui");
    q4(strTexto, strBusca, posicoes);
    printf("TEXTO: %s\nBUSCA: %s\n\nRESULTADOS\n\n%d OCORRENCIAS\nPOSICOES: ", strTexto, strBusca, q4(strTexto, strBusca, posicoes) );
    for( int c = 0; posicoes[c] != -1; c +=2 ){
        printf( "[ %d, %d ] ", posicoes[c], posicoes[c+1] );}

    puts( "\n" );

    strcpy(strTexto,"Programar é legal?");
    strcpy(strBusca,"sim");
    q4(strTexto, strBusca, posicoes);
    printf("TEXTO: %s\nBUSCA: %s\n\nRESULTADOS\n\n%d OCORRENCIAS\nPOSICOES: ", strTexto, strBusca, q4(strTexto, strBusca, posicoes) );
    for( int c = 0; posicoes[c] != -1; c +=2 ){
        printf( "[ %d, %d ] ", posicoes[c], posicoes[c+1] );}

    puts( "\n" );

    strcpy(strTexto,"maraaaavilha, meu prograaaama funcionou");
    strcpy(strBusca,"aa");
    q4(strTexto, strBusca, posicoes);
    printf("TEXTO: %s\nBUSCA: %s\n\nRESULTADOS\n\n%d OCORRENCIAS\nPOSICOES: ", strTexto, strBusca, q4(strTexto, strBusca, posicoes) );
    for( int c = 0; posicoes[c] != -1; c +=2 ){
        printf( "[ %d, %d ] ", posicoes[c], posicoes[c+1] );}

    puts( "\n" );

    /*
    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca,"rato");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n",posicoes[0]==5);
    printf("%d\n",posicoes[1]==8);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==37);


    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Ola, o mundo e muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca,"mui");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n",posicoes[0]==16);
    printf("%d\n",posicoes[1]==18);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==36);
    printf("%d\n",posicoes[4]==52);
    printf("%d\n",posicoes[5]==54);

    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Programar é legal?");
    strcpy(strBusca,"sim");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 0);

    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"maraaaavilha, meu prograaaama funcionou");
    strcpy(strBusca,"aa");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 4);
    printf("%d\n",posicoes[0]==4);
    printf("%d\n",posicoes[1]==5);
    printf("%d\n",posicoes[2]==6);
    printf("%d\n",posicoes[3]==7);
    printf("%d\n",posicoes[4]==24);
    printf("%d\n",posicoes[5]==25);
    printf("%d\n",posicoes[6]==26);
    printf("%d\n",posicoes[7]==27);
    */
}

void testQ5(){
    printf("%-*d --> %*d \n", 4, 345, 4, q5(345) );
    printf("%-*d --> %*d \n", 4, 78, 4, q5(78) );
    printf("%-*d --> %*d \n", 4, 3, 4, q5(3) );
    printf("%-*d --> %*d \n", 4, 5430, 4, q5(5430) );
    printf("%-*d --> %*d \n", 4, 1000, 4, q5(1000) );
    printf("%-*d --> %*d \n", 4, 0, 4, q5(0) );
    printf("%-*d --> %*d \n", 4, 707, 4, q5(707) );
    printf("%-*d --> %*d \n", 4, 80, 4, q5(80) );
    printf("%-*d --> %*d \n", 4, 8, 4, q5(8) );
    printf("%-*d --> %*d \n\n", 4, 1234, 4, q5(1234) );
    /*
    printf("%d\n",q5(345) == 543);
    printf("%d\n",q5(78) == 87);
    printf("%d\n",q5(3) == 3);
    printf("%d\n",q5(5430) == 345);
    printf("%d\n",q5(1000) == 1);
    printf("%d\n",q5(0) == 0);
    printf("%d\n",q5(707) == 707);
    printf("%d\n",q5(80) == 8);
    printf("%d\n",q5(8) == 8);
    printf("%d\n",q5(1234) == 4321);
    */
}

void testQ6(){
    printf("%-*d aparece em %-*d ===== %d vezes\n", 4, 3, 10, 34567368, q6(34567368, 3) );
    printf("%-*d aparece em %-*d ===== %d vezes\n", 4, 4576, 10, 34567368, q6(34567368, 4576) );
    printf("%-*d aparece em %-*d ===== %d vezes\n", 4, 3, 10, 3539343, q6(3539343, 3) );
    printf("%-*d aparece em %-*d ===== %d vezes\n", 4, 39, 10, 3539343, q6(3539343, 39) );
    printf("%-*d aparece em %-*d ===== %d vezes\n", 4, 44, 10, 5444, q6(5444, 44) );
    printf("%-*d aparece em %-*d ===== %d vezes\n", 4, 44, 10, 54444, q6(54444, 44) );
    printf("%-*d aparece em %-*d ===== %d vezes\n", 4, 23, 10, 1234562354, q6(1234562354, 23) );
    printf("%-*d aparece em %-*d ===== %d vezes\n", 4, 13, 10, 1234, q6(1234, 13) );
    printf("%-*d aparece em %-*d ===== %d vezes\n", 4, 4, 10, 544444, q6(544444, 4) );
    printf("%-*d aparece em %-*d ===== %d vezes\n", 4, 32, 10, 1234562354, q6(1234562354, 32) );
    /*
    printf("%d\n",q6(34567368, 3) == 2);
    printf("%d\n",q6(34567368, 4576) == 0);
    printf("%d\n",q6(3539343, 3) == 4);
    printf("%d\n",q6(3539343, 39) == 1);
    printf("%d\n",q6(5444, 44) == 1);
    printf("%d\n",q6(54444, 44) == 2);
    printf("%d\n",q6(1234562354, 23) == 2);
    printf("%d\n",q6(1234, 13) == 0);
    printf("%d\n",q6(544444, 4) == 5);
    printf("%d\n",q6(1234562354, 32) == 0);
    */
}


