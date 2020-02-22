/* Nama : Naufal Prima Yoriko
   NIM : 13518146
   Tanggal : 9 September 2019
*/
#include <stdio.h>
#include "array.h"

int main()
{
	/* KAMUS */
	int i, X, count;
	TabInt T;
	/* Algoritma */
	count = 0;
	MakeEmpty(&T);
	BacaIsi(&T);
	scanf("%d", &X);
	TulisIsiTab(T); printf("\n");
	for (i = GetFirstIdx(T); i<= GetLastIdx(T); i++)
		{
			if (Elmt(T, i)==X)
				{
					count+=1;
				}
		}
	printf("%d\n", count);
	if (count == 0)
		{
			printf("%d tidak ada\n", X);
		}
	else
		{
			printf("%d\n", Search2(T, X));
			if (X == ValMax(T))
				{
					printf("maksimum\n");
				}
			if (X == ValMin(T))
				{
					printf("minimum\n");
				}
			InsSortAsc(&T);
			if (Neff(T)%2==1)
				{
					if (X == (Elmt(T, (Neff(T)/2+1))))
						{
							printf("median\n");
						}
				}
			else
				{
					if (X == (Elmt(T, (Neff(T)/2))))
						{
							printf("median\n");
						}
				}
		}
	return 0;
}
