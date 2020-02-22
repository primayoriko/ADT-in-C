/* Naufal Prima Yoriko
 * 13518146
 * 12 September 2019
 * 
*/

#include <stdlib.h>
#include <stdio.h>
#include "arraydinpos.h"
#include "boolean.h"


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
	TI(*T)= (ElType*) malloc ((maxel+1)*sizeof(ElType));
    MaxEl(*T)=maxel;
    for(int i=GetFirstIdx(*T);i<=MaxEl(*T);i++){
		Elmt(*T, i) = ValUndef;
	}
}
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

void Dealokasi(TabInt *T){
	free(TI(*T));
    MaxEl(*T)=0;
}
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
    IdxType N;
    // Algoritma
    N =GetFirstIdx(T)-2;
    do{
        N++;
    } while ((N==MaxEl(T))? false : Elmt(T,N+1)!=ValUndef);
    return N;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElement(TabInt T){
	return MaxEl(T);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
	return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabInt T){
	return GetFirstIdx(T) + NbElmt(T)-1;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
	return (i>= IdxMin && i<= MaxEl(T));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabInt T, IdxType i){
	return (i>= GetFirstIdx(T) && i<= GetLastIdx(T));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
	return GetLastIdx(T)==0;
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
	return GetLastIdx(T)==MaxEl(T);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
	//Kamus Lokal
    IdxType i;
    int N;
    //Algoritma
    do{
        scanf("%d", &N);
    }
    while (!(N>= 0 && N<= MaxEl(*T)));
    for(i=GetFirstIdx(*T);i<=N;i++){
        scanf("%d", &Elmt(*T, i));
    }
}
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTab(TabInt T){
	// Kamus Lokal
    IdxType i;
    // Algoritma
    printf("[");
    for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
        printf("%d", Elmt(T,i));
        if(i!=GetLastIdx(T)){
            printf(",");
        }
    }
    printf("]");
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
	// Kamus Lokal
    IdxType i;
    TabInt Tsum;
    // Algoritma
    MakeEmpty(&Tsum, MaxEl(T1));
    for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++){
        Elmt(Tsum, i) = (plus)?Elmt(T1,i) + Elmt(T2,i):Elmt(T1,i) - Elmt(T2,i);
    }
    return Tsum;
}
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen T1-T2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
	// Kamus Lokal
    boolean res;
    IdxType i , N;
    // Algoritma
    res = true;
    if (NbElmt(T2) != NbElmt(T1)){
        res = false;
    }
    else {
        if(!IsEmpty(T1)){
            i = GetFirstIdx(T1) - 1;
            do {
                i++;
                if (Elmt(T1, i) != Elmt(T2, i)) {
                    res = false;
                }
            } while (Elmt(T1, i) == Elmt(T2, i) && i < GetLastIdx(T1));
        }
    }
    return res;
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
	 // Kamus Lokal
    IdxType i;
    // Algoritma
    if (IsEmpty(T)){
        i= IdxUndef;
    }
    else{
        i = GetFirstIdx(T)-1;
        do{
            i++;
        }
        while(X != Elmt(T,i) && i<GetLastIdx(T));
        if(X != Elmt(T,i) && i==GetLastIdx(T)){
            i = IdxUndef;
        }
    }
    return i;
	
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB(TabInt T, ElType X){
	// Kamus Lokal
    IdxType i;
    boolean Found;
    // Algoritma
    Found = false;
    if(!IsEmpty(T)){
        i = GetFirstIdx(T)-1;
        do{
            i++;
            if(Elmt(T,i)==X){
                Found = true;
            }
        }
        while(!Found && i<GetLastIdx(T));
    }
    return Found;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
	ElType maks,min;
    IdxType i;
    // Algoritma
    maks = Elmt(T,GetFirstIdx(T));
    min = maks;
    for(i = GetFirstIdx(T)+1;i<=GetLastIdx(T);i++){
        if(maks < Elmt(T,i)){
            maks = Elmt(T,i);
        }
        if(min > Elmt(T,i)){
            min = Elmt(T,i);
        }
    }
    *Max = maks;
    *Min = min;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
	//Algoritma
    MakeEmpty(Tout, MaxEl(Tin));
    for(IdxType i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++){
        Elmt(*Tout, i)= Elmt(Tin, i);
    }
}
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
ElType SumTab(TabInt T){
	//Kamus Lokal
    int sum;
    //Algoritma
    sum=0;
    for(IdxType i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
        sum+= Elmt(T, i);
    }
    return sum;
	
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
int CountX(TabInt T, ElType X){
	//Kamus Lokal
    int cnt;
    //Algoritma
    cnt=0;
    for(IdxType i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
        if(X == Elmt(T, i)){
            cnt++;
        }
    }
    return cnt;
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
boolean IsAllGenap(TabInt T){
	//Kamus Lokal
    boolean genap;
    if(IsEmpty(T)){
        genap=false;
    }
    else{
        genap=true;
        IdxType i=GetFirstIdx(T)-1;
        do{
            i++;
            if (Elmt(T,i)%2!=0){
                genap=false;
            }
        }
        while (genap && i<GetLastIdx(T));
    }
    return genap;
}
/* Menghailkan true jika semua elemen T genap. T boleh kosong */

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
	// Kamus Lokal
    IdxType i, j, cnt;
    ElType temp;
    // Algoritma
    for(i = GetFirstIdx(*T); i < GetLastIdx(*T);i++){
        cnt = i;
        for(j = i+1;j <= GetLastIdx(*T); j++){
            if((asc)?(Elmt(*T,cnt) > Elmt(*T,j)):(Elmt(*T,cnt) < Elmt(*T,j))){
                cnt = j;
            }
        }
        temp = Elmt(*T,i);
        Elmt(*T,i) = Elmt(*T,cnt);
        Elmt(*T,cnt) = temp;
    }
}
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X){
	//Algoritma
    Elmt(*T, GetLastIdx(*T)+1) = X;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
	//Algoritma
    *X = Elmt(*T, GetLastIdx(*T));
    Elmt(*T, GetLastIdx(*T)) = ValUndef;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
	TabInt Tcop;
    MakeEmpty(&Tcop, MaxEl(*T)+num);
    for(IdxType i=GetFirstIdx(*T);i<=GetLastIdx(*T);i++){
        Elmt(Tcop, i)= Elmt(*T, i);
    }
    Dealokasi(T);
    CopyTab(Tcop, T);
}
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTab(TabInt *T, int num){
	TabInt Tcop;
    int last;
    last = (GetLastIdx(*T) < MaxEl(*T) - num) ?GetLastIdx(*T) : MaxEl(*T) - num;
    for(IdxType i=GetFirstIdx(*T);i<=last;i++){
        Elmt(Tcop, i)= Elmt(*T, i);
    }
    Dealokasi(T);
    CopyTab(Tcop, T);
}
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTab(TabInt *T){
	TabInt Tcop;
    MakeEmpty(&Tcop, GetLastIdx(*T));
    for(IdxType i=GetFirstIdx(*T);i<=GetLastIdx(*T);i++){
        Elmt(Tcop, i)= Elmt(*T, i);
    }
    Dealokasi(T);
    CopyTab(Tcop, T);
}
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */


