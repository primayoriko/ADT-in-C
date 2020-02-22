/* 
	Naufal Prima Yoriko
	13518146
*/
#include <stdlib.h>
#include <stdio.h>
#include "stackt.h"

int main(){
    Stack A,B;
    int x,y,a,b;
    CreateEmpty(&A);CreateEmpty(&B);
    scanf("%d %d", &x, &y);
    for(int i=0;i<x;i++){
		scanf("%d", &a);
		if(a!=0) Push(&A, a);
		else{
			if (!IsEmpty(A)) Pop(&A,&a);
		}
	}
	for(int i=0;i<y;i++){
		scanf("%d", &a);
		if(a!=0) Push(&B, a);
		else{
			if (!IsEmpty(B)) Pop(&B,&a);
		}
	}
	/*while(!IsEmpty(B) ){
		Pop(&B,&b);
		printf("%d\n",b);
	}
	while(!IsEmpty(A) ){
		Pop(&A,&b);
		printf("%d\n",b);
	}*/
	boolean ans=true;
	while(!IsEmpty(B) & !IsEmpty(A)){
		Pop(&B,&b);
		Pop(&A,&a);
		//printf("%d %d\n", a,b);
		ans = (a==b);
	}
	if(ans & IsEmpty(B) & IsEmpty(A)) printf("Sama\n");
	else printf("Tidak sama\n");
    return 0;
}
