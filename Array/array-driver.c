#include <stdio.h>
#include "array.h"

int main(){
    ElType a,b;
    TabInt A1, A2, A3;
    MakeEmpty(&A1);
    MakeEmpty(&A2);
    BacaIsi(&A1);
    BacaIsi(&A2);
    TulisIsiTab(A1);
    TulisIsiTab(A2);
    A1 = InverseTab(A1);
    /*CopyTab(A1, &A2);
    A3= PlusTab(A1,A2);
    TulisIsiTab(A3);
    A3 = MinusTab(A1,A2);
    TulisIsiTab(A3);
    A3 = KaliTab(A1,A2);
    TulisIsiTab(A3);
    A3 = KaliKons(A1, 5);
    TulisIsiTab(A3); */
    if(IsLess(A1,A2)){
        CopyTab(A1, &A2);
        A1 = InverseTab(A1);
        //AddAsLastEl(&A1, 888);
        AddElUnik(&A1, 99);
        DelEli(&A1,2,&a);
        printf("%d %d %d %d %d %d %d", a, ValMax(A1), ValMin(A1), IdxMinTab(A1), IdxMaxTab(A1), Search1(A1,2), Search2(A1,2));
        TulisIsiTab(A1);
        TulisIsiTab(A2);
        if(SearchSentinel(A1, 9)){
            InsSortAsc(&A1);
            MaxSortDesc(&A2);
            TulisIsiTab(A1);
            TulisIsiTab(A2);
            if(!SearchB(A1, 999)){
                Del1Urut(&A1, 2);
                Add1Urut(&A1, 1);
                printf("%d", SearchUrut(A2,2));

                TulisIsiTab(A1);
                TulisIsiTab(A2);
            }
        }
    }
    BacaIsi(&A2);

    return 0;
}