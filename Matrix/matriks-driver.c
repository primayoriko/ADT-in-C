#include "test.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    MATRIKS M1;
    BacaMATRIKS(&M1, m,n);
    //TulisMATRIKS(M1);
    M1 = Echelon(M1, false);
    //M1 = EchelonReduc(M1, false);
    printf("\nsuccess\n");
    TulisMATRIKS(M1); 
    /*char r= (IsSparse(M1))? 't' : 'f';
    printf("%c\n", r); */
    BacaMATRIKS(&M1,3,3);

    return 0;
}