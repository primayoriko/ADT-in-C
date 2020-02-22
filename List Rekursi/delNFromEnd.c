/*
	Naufal Prima Yoriko
	13518146
*/

#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"

List delNFromEnd(List L, int n){
	if(!IsEmpty(L)){
		List Arr[1000];
		int N=1;
		while(!IsEmpty(L)){
			Arr[N] = L;
			L = Next(L);
			N++;
		}
		Arr[0] = Nil;
		Arr[N] = Nil;
		int a = N-n;
		Dealokasi(Arr[a]);
		if(a == 1) return Arr[2];
		else{
			SetNext(Arr[a-1],Arr[a+1]);
		}
		return Arr[1];
	}
	return Nil;
}

/*int NbElmt(List L){
  int N = 0;
  address X;
  while(!IsEmpty(L)){
      N++;
      SetNext(L,X);
      L=X;
  }
  return N;
}*/

/*List delNFromEndHelper(List L , int* n, boolean *end){
  if(Next(L)==Nil){

  }
  if(*end){
    if(*n == 0) return Next(P)
    else n--;
  }
  else{
    delNFromEnd
  }
} */


/* List Kons(List X, List L){
  SetNext(X,L);
  return X;
}

List delNFromEnd(List L, int n){
	if(NbElmt(L)==n){
		List A = Next(L);
		Dealokasi(L);
		return A;
	}
	else{
		L = Kons(L, delNFromEnd(Next(L),n));
		return L;
	}
}

*/

/* L terdefinisi, tidak mungkin kosong.
 * int main(){

	return 0;
}*/
/* Elemen ke-n L dari belakang akan dihapus dan didealokasi,
   lalu mengembalikan head dari list
   misal L = [1, 2, 3, 4, 5] dan n = 2
         L akan menjadi [1, 2, 3, 5] */
