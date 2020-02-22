/* Nama : Naufal Prima Yoriko
	13518146
	19 Sept 2019
*/

#include "matriks.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


int main(){
	int a,b,c;
	indeks i,j,x,y,p,q;
	ElType elm, mul;
	MATRIKS A, B, C;
	scanf("%d %d", &a, &b);
	BacaMATRIKS(&A, a, b);
	MakeMATRIKS(a,b, &C);
	scanf("%d", &c);
	BacaMATRIKS(&B, c, c);
	
	for(i=GetFirstIdxBrs(A);i<=GetLastIdxBrs(A);i++){
		for(j=GetFirstIdxKol(A);j<=GetLastIdxKol(A);j++){
			elm=0;
			for(x=GetFirstIdxBrs(A);x<=GetLastIdxBrs(A);x++){
				for(y=GetFirstIdxKol(A);y<=GetLastIdxKol(A);y++){
					p= (c+1)/2+(x-i);
					q= (c+1)/2+(y-j);
					if(p>c || q>c || p<1 || q<1){
						mul = 0;
					}
					else{
						mul = Elmt(B,p,q);
					}
					elm += mul * Elmt(A,x,y);
				}
			}
			Elmt(C,i,j) = elm;
		}
	}
	TulisMATRIKS(C);
	return 0;
}
