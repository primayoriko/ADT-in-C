/*
	Naufal Prima Yoriko
	13518146
*/

#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"
#include "mesinkar.h"
#include "boolean.h"

void Salin(Kata* dest, Kata src){
	dest->Length = src.Length;
	for(int i=1; i<=src.Length;i++){
		dest->TabKata[i] = src.TabKata[i]; 
	}
}

int main(){
	Kata Q;
	int val,cnt=0;
	STARTKATA();
	Salin(&Q, CKata);
	while(!EndKata){
		ADVKATA();		
		if(CKata.Length >= Q.Length && !EndKata){
			for(int i=1; i<=(CKata.Length-Q.Length+1) ;i++){
				val=1;
				for(int j = i; j< i + Q.Length; j++){
					if(CKata.TabKata[j] != Q.TabKata[j-i+1]) val=0;
					if(j-i+1==Q.Length && CKata.TabKata[j] == Q.TabKata[j-i+1]){
						 cnt+=val;
						 //printf("%d\n", j);
					}
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
