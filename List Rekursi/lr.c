#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"

address lastel(List L){
    while(L!=Nil) L = Next(L);
    return L;
}

int main(){
    List L, S;
    L= Alokasi(1);
    S = Alokasi(999);
    infotype X[50],a,b;
    address j;
    for(int i=0; i<13; i++){
        X[i] = i;
        //printf("%d\n", Info(r));
        L= Konso(X[i], L);
        S = KonsB(S,X[i]);
    }
    List B,A = Copy(L);
    MCopy(S,&B);
    List D, C = Concat(A,B);
    MConcat(A,B,&D);
    //if(First(L)== Next(lastel(L))) printf("ya\n");
    //DelAfter(&L, &j, lastel(L));
    //DelFirst(&L,&j);
    //DelLast(&L,&j);
    /*address y = Alokasi(1000);
    address yc = Alokasi(1000);
    InsertAfter(&L,y, First(L));
    InsertAfter(&L,yc, Next(First(L)));*/
    //InsertLast(&L,y);
    //InsertFirst(&L,yc);

    /*printf("%d %d\n", NbElmt(L), NbElmt(S));
    PrintInfo(L);
    printf("\n");
    PrintInfo(S);
    printf("\n");

    printf("%d %d\n", Max(L), Max(S));*/

    PrintList(A);
    printf("\n");
    PrintList(B);
    printf("\n");
    //printf("%d %d\n", NbElmtList(A), FirstElmt(A));
  //  PrintList(Tail(A));
    printf("\n");
    //PrintList(C);
    printf("\n");
  //  PrintList(D);
    printf("\n");
    if(Search(A, 10))printf("yes10\n");
    if(Search(A, 1))printf("yes1\n");
    if(Search(A, 12))printf("yes12\n");
    if(Search(A, 100))printf("yes100\n");
    return 0;
}

// 16 17 19 22
