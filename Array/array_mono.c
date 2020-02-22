/* Nama : Naufal Prima Yoriko
   NIM : 13518146
   Tanggal : 9 September 2019
*/
#include <stdio.h>
#include "array.h"

int main()
{
	/* KAMUS */
	TabInt T;
	int i;
	boolean countAsc, countDesc, countEq;
	/* ALGORITMA */
	countAsc = false;
	countDesc = false;
	MakeEmpty(&T);
	BacaIsi(&T);
	for (i = 1; i<Neff(T); i++)
		{
			if (Elmt(T, i)>Elmt(T, i+1))
				{
					countDesc=true;
				}
			if (Elmt(T, i)<Elmt(T, i+1))
				{
					countAsc=true;
				}
		}
	if (countAsc && countDesc)
		{
			printf("Array tidak monotonik\n");
		}
	else if (countAsc)
		{
			printf("Array monotonik tidak mengecil\n");
			
		}
	else if (countDesc)
		{
			printf("Array monotonik tidak membesar\n");
		}
	else
		{
			printf("Array monotonik statik\n");
		}
	return 0;
}
