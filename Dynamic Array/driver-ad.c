#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

int main(){
    TabInt R;
    int N;
    MakeEmpty(&R, 3);
    printf("%d\n", MaxEl(R));
    BacaIsi(&R);
    CompactTab(&R);
    printf("%d\n", Neff(R));
    printf("%d\n", MaxEl(R));
    BacaIsi(&R);
    return 0;
}   