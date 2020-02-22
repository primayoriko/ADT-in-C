#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a  = (int *) malloc (sizeof(int));
    *a = 8;
    int *b;
    b = a;
    free(a);
    if(a==NULL) printf("hiya2");
    else printf("ggl cug");
    printf("\n%d", b);
}