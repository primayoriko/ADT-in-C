#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"

address Alokasi (infotype X){
  address n;
  n = (ElmtList*) malloc(sizeof(ElmtList));
  if(n != Nil){
      Info(n) = X;
      Next(n) = Nil;
      return n;
  }
  else return Nil;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P,
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address P){
  free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L){
  if (L == Nil) return 1;
  return 0;
}
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
int IsOneElmt(List L){
  if(!IsEmpty(L) && Next(L)==Nil) return 1;
  return 0;
}
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

/* *** Selektor *** */
infotype FirstElmt (List L){
  return Info(L);
}
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
List Tail(List L){
  if(IsEmpty(L) || IsOneElmt(L)) return Nil;
  return Next(L);
}
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
List Konso(infotype e, List L){
  address n = Alokasi(e);
  if(n == Nil) return L;
  Next(n)= L;
  return n;
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya.
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
List KonsB(List L, infotype e){
  address n = Alokasi(e);
  if(n != Nil){
    if(IsEmpty(L)) L = n;
    else{
      List P = L;
      while(!IsOneElmt(P)) P = Next(P);
      Next(P)= n;
    }
  }
  return L;
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */

/* *** Operasi Lain *** */
List Copy (List L){
  if(!IsEmpty(L)){
    address PrevL = Nil, F = L,P,R;
    do{
      P = Alokasi(Info(F));
      if (P == Nil) return L;
      if (PrevL!=Nil) Next(PrevL) = P;
      else R = P;
      PrevL=P;
      F = Next(F);
    } while(F!=Nil);
    return R;
  }
  return Nil;
}
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */
void MCopy (List Lin, List *Lout){
  *Lout = Copy(Lin);
}
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
List Concat (List L1, List L2){
  if (IsEmpty(L1)) return Copy(L2);
  else{
    return Konso(FirstElmt(L1),Concat(Tail(L1),L2));
  }
}
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
void MConcat (List L1, List L2, List *LHsl){
  *LHsl = Concat(L1,L2);
}
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
void PrintList (List L){
  while(!IsEmpty(L)){
      printf("%d\n", Info(L));
      L=Next(L);
  }
}
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
int NbElmtList (List L){
  int N = 0;
  while(!IsEmpty(L)){
      N++;
      L=Next(L);
  }
  return N;
}
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
boolean Search (List L, infotype X){
  while(!IsEmpty(L) && FirstElmt(L)!=X) L = Next(L);
  return !IsEmpty(L);
}
/* Mengirim true jika X adalah anggota list, false jika tidak */

infotype MaxList (List L){
	if(IsEmpty(L)) return -99999;
	infotype A = MaxList(Tail(L));
	if(A>FirstElmt(L)) return A;
	return FirstElmt(L);
}
/* Mengirimkan nilai info(P) yang maksimum */

infotype MinList (List L){
	if(IsEmpty(L)) return 99999;
	infotype A = MinList(Tail(L));
	if(A<FirstElmt(L)) return A;
	return FirstElmt(L);
}
/* Mengirimkan nilai info(P) yang minimum */

infotype SumList (List L){
	if(IsEmpty(L)) return 0;
	return FirstElmt(L)+SumList(Tail(L));
}
/* Mengirimkan total jumlah elemen List L */

float AverageList (List L){
	float sum = 0;
	float n = (float)NbElmtList(L);
	while(!IsEmpty(L)){
		sum += (float)FirstElmt(L);
		L = Tail(L);
	}
	if(n!=0) return sum/n;
	else return 0;
}
/* Mengirimkan nilai rata-rata elemen list L */

/*** Operasi-Operasi Lain ***/
List InverseList (List L){
	if(IsEmpty(L)) return Nil;
	return KonsB(InverseList(Tail(L)),Info(L));
}
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */

void SplitPosNeg (List L, List *L1, List *L2){
	if(!IsEmpty(L)){
		if(FirstElmt(L)<0) *L2 = KonsB(*L2, FirstElmt(L));
		else *L1 = KonsB(*L1, FirstElmt(L));
		SplitPosNeg(Tail(L), L1, L2);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */ 
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */

void SplitOnX (List L, infotype X, List *L1, List *L2){
	if(!IsEmpty(L)){
		if(FirstElmt(L)<X) *L1 = KonsB(*L1, FirstElmt(L));
		else *L2 = KonsB(*L2, FirstElmt(L));
		SplitOnX(Tail(L), X, L1, L2);
	}
}
/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama. */

int ListCompare (List L1, List L2){
	if(IsEmpty(L1) && IsEmpty(L2)) return 0;
	if(IsEmpty(L1)) return -1;
	if(IsEmpty(L2)) return 1;
	if(FirstElmt(L1) < FirstElmt(L2)) return -1;
	if(FirstElmt(L1) > FirstElmt(L2)) return 1;
	return ListCompare(Tail(L1),Tail(L2));
}
/* Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2 */
/* Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L: */
/* L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i] */
/* L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* L1>L2: kebalikan dari L1<L2 */

boolean IsAllExist (List L1, List L2){
	if(IsEmpty(L1)) return false;
	boolean t = true;
	while(t && !IsEmpty(L1)){
		t = Search(L2,FirstElmt(L1));
		L1 = Tail(L1);
	}
	return t;
}
/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */
