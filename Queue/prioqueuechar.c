/* 
	Naufal Prima Yoriko
	13518146
*/

#include <stdlib.h>
#include <stdio.h>
#include "prioqueuechar.h"

boolean IsEmpty (PrioQueueChar Q){
	return Head(Q) == Nil && Tail(Q) == Nil;
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueChar Q){
	return Tail(Q)%MaxEl(Q)+1 == Head(Q);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueueChar Q){
	//return (IsEmpty(Q))?0:((Tail(Q)>=Head(Q))?Tail(Q)+1-Head(Q):MaxEl(Q)-(Tail(Q)+1-Head(Q)));
	return (IsEmpty(Q))?0:((Tail(Q)>=Head(Q))?Tail(Q)+1-Head(Q):Tail(Q)+1+MaxEl(Q)-Head(Q));
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (PrioQueueChar * Q, int Max){
	(*Q).T = (infotype*) malloc ((Max+1)*sizeof(infotype));
    if((*Q).T == NULL) MaxEl(*Q) = Nil;
	else MaxEl(*Q) = Max;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
	free((*Q).T);
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (PrioQueueChar * Q, infotype X){
	if(IsEmpty(*Q)){
        Head(*Q)=1;
        Tail(*Q)=1;
		InfoTail(*Q)=X;
    }  
    else{
		boolean t = true;
		int j;
		infotype temp;
		Tail(*Q) = (Tail(*Q)%MaxEl(*Q))+1;
		int i = (Tail(*Q)==1)?MaxEl(*Q):Tail(*Q)-1;
		while(t){
			j = (i%MaxEl(*Q))+1;
			if(Prio(Elmt(*Q, i)) <= Prio(X)){
				t = false;
				(*Q).T[j] = X;
			}
			else if(i==Head(*Q)){
				t = false;
				(*Q).T[j].prio = (*Q).T[i].prio;
				(*Q).T[i].prio = Prio(X);
				(*Q).T[j].info = (*Q).T[i].info;
				(*Q).T[i].info = Info(X);
			}
			else{
				(*Q).T[j] = (*Q).T[i];
				i=(i==1)?MaxEl(*Q):i-1;
			}
		}
    }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Del (PrioQueueChar * Q, infotype * X){
	(*X)=InfoHead(*Q);
    if(Head(*Q)==Tail(*Q)){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else{
        Head(*Q)= (Head(*Q)%MaxEl(*Q))+1;
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
	infotype a;
	while(!IsEmpty(Q)){
		Del(&Q, &a);
		printf("%d %c\n", Prio(a), Info(a));
	}
	printf("#\n");
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
