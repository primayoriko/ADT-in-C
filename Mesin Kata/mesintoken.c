/*
	Naufal Prima Yoriko
	13518146
*/

#include <stdio.h>
#include <stdlib.h>
#include "mesintoken.h"
#include "mesinkar.h"
#include "boolean.h"

boolean EndKata;
boolean EndToken;
Token CToken;

void IgnoreBlank(){
	while (CC == BLANK && CC!= MARK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTTOKEN(){
	START();
    IgnoreBlank();
    if(CC == MARK) {
		EndToken = true;
	}
    else{
        EndToken = false;
        SalinToken();
    }
}
/* I.S. : CC sembarang
   F.S. : EndToken = true, dan CC = MARK;
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */

void ADVTOKEN(){
	IgnoreBlank();
    if(CC == MARK){
		EndToken = true;
	}
    else{
        SalinToken();
		IgnoreBlank();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinToken(){
	IgnoreBlank();
	if((CC - '0' > 9) || (CC -'0' < 0)){
		CToken.tkn = CC;
		CToken.val = -1;
        ADV();
	}
	else{
        CToken.tkn ='b';
        CToken.val=0;
        while(CC!=BLANK && CC!=MARK && (CC - '0' <= 9) && (CC -'0' >= 0)){
            CToken.val *= 10;
            CToken.val += CC - '0';
            ADV();
        }
	}	
}
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
