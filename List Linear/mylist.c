#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

address lastel(List L){
    address t =First(L);
    while(Next(t)!=Nil) t = Next(t);
    return t;
}

int main(){
    List L, S;
    CreateEmpty(&L);
    CreateEmpty(&S);
    infotype X[50];
    for(int i=0; i<50; i++){
        X[i] = i;
        address r = Alokasi(X[i]);
        address x = Alokasi(X[i]);
        //printf("%d\n", Info(r));
        InsertFirst(&L, r);
        InsertLast(&S, x);
    }
    address y = Alokasi(1000);
    address yc = Alokasi(1000);
    InsertAfter(&L,y, First(L));
    InsertAfter(&L,yc, lastel(L));

    DelP(&S, 49);
    DelP(&S, 0);
    DelP(&S, 3);

    printf("%d %d\n", NbElmt(L), NbElmt(S));
    PrintInfo(L);
    printf("\n");
    PrintInfo(S);
    printf("\n");
    
    printf("%d %d\n", Max(L), Max(S));
    return 0;
}