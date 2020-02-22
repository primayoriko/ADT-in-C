/*
    Naufal Prima Yoriko
    13518146
*/

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmpty (List L){
    return First(L) == Nil;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address n;
    n = (ElmtList*) malloc(sizeof(ElmtList));
    if(n != Nil){
        Info(n) = X;
        Next(n) = Nil;
        return n;
    }
    else{
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    address res = Nil;
    if (!IsEmpty(L)){
        address P = First(L);
        while(Info(P)!=X && Next(P)!=Nil){
            P = Next(P);
        }
        if(Info(P)==X) res = P;
    }
    return res;
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address newEl = Alokasi(X);
    address P = First(*L);
    if(IsEmpty(*L)){
        First(*L) = newEl;
    }
    else{
        Next(newEl) = P;
        First(*L)= newEl;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    infotype q = X;
    address newEl = Alokasi(q);
    if(IsEmpty(*L)){
        First(*L) = newEl;
    }
    else{
        address P = First(*L);
        while(Next(P)!= Nil) P = Next(P);
        Next(P)= newEl;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    address P = First(*L);
    First(*L) = Next(P);
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    address P = First(*L);
    if(Next(P) == Nil) First(*L) = Nil;
    else{
        while(Next(Next(P))!= Nil) P = Next(P);
        address y = Next(P);
        Next(P) = Nil;
        P = y;
    } 
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    address F = First(*L);
    if(IsEmpty(*L)){
        First(*L) = P;
    }
    else{
        Next(P) = F;
        First(*L)= P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
    address F = First(*L);
    while(F!= Prec) F = Next(F);
    address Nxt = Next(F);
    Next(F) = P;
    Next(P) = Nxt;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
    address F = First(*L);
    if(IsEmpty(*L)) First(*L) = P;
    else{
        while(Next(F)!= Nil) F = Next(F);
        Next(F)= P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L); 
    address Nxt = Next(*P);
    First(*L) = Nxt;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelP (List *L, infotype X){
    if(!IsEmpty(*L)){
        address Pre = Nil, P = First(*L), Nxt;
        while (Next(P)!=Nil && Info(P)!=X){
            //printf("%d\n", Info(P));
            Pre = P;
            P = Next(P);
        }
        if(Info(P)==X){
            Nxt = Next(P);
            if(Pre != Nil) Next(Pre) = Nxt;
            else First(*L) = Nxt;
            Dealokasi(&P);
        }
    }
}

/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
    address Pre = Nil, F = First(*L);
    while (Next(F)!=Nil){
        Pre = F;
        F = Next(F);
    } 
    *P = F;
    F = Next(*P);
    if(Pre != Nil) Next(Pre) = F;
    else First(*L) = F;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    address F = First(*L);
    while(F!= Prec) F = Next(F);
    address Nxt = Next(F);
    *Pdel = Nxt;
    Next(F) = Next(Nxt);
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    printf("[");
    address P = First(L);
    boolean f=false;
    while(P!=Nil){
        if(f) printf(",");
        f=true;
        if(f) printf("%d", Info(P));
        P=Next(P);
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
    int N = 0;
    address P = First(L);
    while(P!=Nil){
        N++;
        P=Next(P);
    }
    return N;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
    address P = First(L);
    infotype M = Info(P);
    while(P!=Nil){
        if(M<Info(P)) M = Info(P);
        P=Next(P);
    }
    return M;
}
/* Mengirimkan nilai Info(P) yang maksimum */

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
    address f1 = First(*L1), f2 = First(*L2);
    if(!IsEmpty(*L1)){
        First(*L3) = f1;
        while(Next(f1)!=Nil) f1 = Next(f1);
        Next(f1) = f2; 
    }
    else First(*L3) = f2;
    CreateEmpty(L1);
    CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */