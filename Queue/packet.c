/* 
	Naufal Prima Yoriko
	13518146
*/

#include <stdlib.h>
#include <stdio.h>
#include "prioqueuechar.h"

int main(){
	int pre;
	PrioQueueChar Q;
	infotype a;
	int n, q;
	char c;
	
	scanf("%d", &n);
	CreateEmpty(&Q, n);
	pre = 1;
	for(int i = 1;i<=n;i++){
		boolean loop;
		scanf("%d %c", &q, &c);
		a.info = c;
		a.prio = q;
		Add(&Q, a);
		//printf(">>%d %d\n",Head(Q), Prio(InfoHead(Q)));
		//printf(">>%d %d\n\n",Tail(Q), Prio(InfoTail(Q)));
		loop=true;
		while (loop && !IsEmpty(Q)){
			Del(&Q,&a);
			if(Prio(a) == pre){
				printf("%d %c\n", i, Info(a));
				pre++;
			} 
			else {
				Add(&Q, a);
				loop=false;
			}
		}
	}
	return 0;
}
