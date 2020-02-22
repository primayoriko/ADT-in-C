/* Naufal Prima Yoriko
 * 13518146
 * 12 September 2019
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"


int main(){
	TabInt T;
	int maxel,q,a,b;
	scanf("%d", &maxel);
	MakeEmpty(&T, maxel);
	BacaIsi(&T);
	scanf("%d", &q);
	for(int i=0;i<q;i++){
		scanf("%d", &a);
		if(a==2){
			scanf("%d", &b);
			GrowTab(&T, b);
			printf("%d ",MaxEl(T));TulisIsiTab(T);printf("\n");
		}
		else if(a==3){
			scanf("%d", &b);
			if(MaxEl(T)< b){
				printf("array terlalu kecil\n");
			}
			else{
				ShrinkTab(&T, b);
				printf("%d ",MaxEl(T));TulisIsiTab(T);printf("\n");
			}
		}
		else if(a==1){
			scanf("%d", &b);
			if(IsFull(T)){
				printf("array sudah penuh\n");
			}
			else{
				AddAsLastEl(&T, b);
				printf("%d ",MaxEl(T));TulisIsiTab(T);printf("\n");
			}
		}
		else{
			CompactTab(&T);
			printf("%d ",MaxEl(T));TulisIsiTab(T);printf("\n");
		}
	}
	return 0;
}

