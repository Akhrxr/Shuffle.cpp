/***************************************************************************************
* Akhror Rakhmatov,1794798 arakhmat@ucsc.edu, PA5 
*  Shuffle.c
*  Uses functions in List.cpp to find and shuffle a list
****************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"List.h"

void shuffle(List& D);

void shuffle(List& D) {
    List A, B;
    if (D.length() > 1) {
        int len = D.length();
        int count = len/2;
        for (D.moveFront(); D.position() != count;) {
            int i = D.moveNext();
            A.insertBefore(i);
        }
        while (D.position() != len) {
            int i = D.moveNext();
            B.insertBefore(i);
        }
        D.clear();
        A.moveFront();
        B.moveFront();
        while(A.position() != A.length() && B.position() != B.length()){
            int u = B.moveNext();
            int y = A.moveNext();
            D.insertBefore(u);
            D.insertBefore(y);
        }
        while(B.position() != B.length()){
            int u = B.moveNext();
            D.insertBefore(u);
        }
        while(A.position() != A.length()){
            int y = A.moveNext();
            D.insertBefore(y);
        }
    }
}



int main(int argc, char **argv) {
    List D;
    if (argc != 2) {
        fprintf( stderr, "Incorrect number of command line arguments, please include one positive integer\n" );
        exit(1);
    }
    int size_tot = atoi(argv[1]);
    printf("Shuffle %d\n", size_tot);
    printf("deck size       shuffle count\n");
    printf("------------------------------\n");
    for (int size = 1; size <= size_tot; ++size) {
        for (int i = 0; i < size; ++i) {
            D.insertBefore(i);
        }
        List E = D;
        shuffle(D);
        int shufcount = 1;
        while (!E.equals(D)) {
            shuffle(D);
            ++shufcount;
        }
        printf("%d                  %d\n", size, shufcount);
        D.clear();
    }
    return 0;
}