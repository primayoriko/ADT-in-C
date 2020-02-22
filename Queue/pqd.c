#include <stdlib.h>
#include <stdio.h>
#include "prioqueuechar.h"

int main(){
    PrioQueueChar Q;
    infotype arr[100];
    infotype a,b,c,d,t;
    CreateEmpty(&Q, 100);
    for(int i=0;i<100;i++){
        arr[i].info = 'a';
        arr[i].prio = (i*61) % 79;
        Add(&Q,arr[i]);
    }
    //PrintPrioQueueChar(Q);
    /*a.info = '3';
    b.info = '4';
    c.info = '5';
    d.info = '6';
    a.prio = 40;
    b.prio = 10;
    c.prio = 1000;
    d.prio = 50;
    //PrintPrioQueueChar(Q);
    Add(&Q,a);
    Add(&Q,b);
    Del(&Q, &t);
    printf("<%d> <%c>\n\n", Prio(t), Info(t));
    PrintPrioQueueChar(Q);
    Add(&Q,c);
    Add(&Q,d);
    printf("<%d> <%d>\n\n", Head(Q), Tail(Q));
    Del(&Q, &t);
    Add(&Q,t);
    printf("<%d> <%d>\n\n", Head(Q), Tail(Q));
    Del(&Q, &t);
    Add(&Q,t);
    Del(&Q, &t);
    Add(&Q,t);
    Del(&Q, &t);
    Add(&Q,t);
    printf("<%d> <%d>\n\n", Head(Q), Tail(Q));
    PrintPrioQueueChar(Q);*/
    Del(&Q, &t);
    printf("<%d> <%c>\n\n", Prio(t), Info(t));
    return 0;
}