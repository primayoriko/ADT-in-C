#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bintree.h"


int main(){
    BinTree a, b = AlokNode(2), c = AlokNode(3);
    a = Tree(1,b,c);
    printf("\n%d\n", Akar(b));
    BinTree A = BuildBalanceTree(7);
    PrintPreorder(A);
    printf("\n");
    PrintInorder(a);
    printf("\n");
    PrintPostorder(a);
    printf("\n");
    PrintTree(A, 3);
    printf("\n");
    printf("%d\n", NbElmt(A));
    printf("%d\n", NbDaun(A));
    printf("%d\n", Level(A, 2));
    printf("%d\n", Tinggi(A));
    return 0;
}