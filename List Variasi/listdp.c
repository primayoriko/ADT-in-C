/* 
    Naufal Prima Yoriko
    13518146
*/

#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"


boolean IsEmpty (List L){
    return First(L) == Nil && Last(L) == Nil;
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
    Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address n;
    n = (ElmtList*) malloc(sizeof(ElmtList));
    if(n != Nil){
        Info(n) = X;
        Next(n) = Nil;
        Prev(n) = Nil;
        return n;
    }
    else{
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
    free(P);
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
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address newEl = Alokasi(X);
    address P = First(*L);
    if(IsEmpty(*L)){
        First(*L) = newEl;
        Last(*L) = newEl;
    }
    else{
        Next(newEl) = P;
        Prev(P) = newEl;
        First(*L)= newEl;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address newEl = Alokasi(X);
    if(IsEmpty(*L)){
        First(*L) = newEl;
        Last(*L) = newEl;
    }
    else{
        address P = Last(*L);
        Last(*L) = newEl;
        Prev(newEl) = P;
        Next(P) = newEl;
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
    if(First(*L)!= Nil) Prev(First(*L)) = Nil;
    *X = Info(P);
    Dealokasi(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    address P = Last(*L);
    Last(*L) = Prev(P);
    if(Last(*L) != Nil) Next(Last(*L)) = Nil;
    *X = Info(P);
    Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    if(IsEmpty(*L)){
        First(*L) = P;
        Last(*L) = P;
    }
    else{
        address F = First(*L);
        Next(P) = F;
        Prev(F) = P;
        First(*L)= P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
    if(IsEmpty(*L)){
        First(*L) = P;
        Last(*L) = P;
    }
    else{
        address F = Last(*L);
        Next(F) = P;
        Prev(P) = F;
        Last(*L)= P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
    address F = First(*L);
    while(F!= Prec) F = Next(F);
    address Nxt = Next(F);
    Next(F) = P;
    Prev(P) = F;
    Next(P) = Nxt;
    if(Nxt!=Nil) Prev(Nxt) = P;
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ){
    address F = Last(*L);
    while(F!= Succ) F = Prev(F);
    address Nxt = Prev(F);
    Prev(F) = P;
    Next(P) = F;
    Prev(P) = Nxt;
    if(Nxt!=Nil) Next(Nxt) = P;
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L); 
    address Nxt = Next(*P);
    First(*L) = Nxt;
    if(First(*L)!= Nil) Prev(First(*L)) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
    *P = Last(*L); 
    address Nxt = Prev(*P);
    Last(*L) = Nxt;
    if(Last(*L)!= Nil) Next(Last(*L)) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
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
            if(Pre != Nil)Next(Pre) = Nxt;
            else First(*L) = Nxt;
            if(Nxt != Nil) Prev(Nxt) = Pre;
            else Last(*L) = Pre;
            Dealokasi(P);
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec){
    address F = First(*L);
    while(F!= Prec) F = Next(F);
    address Nxt = Next(F);
    *Pdel = Nxt;
    if(Nxt != Nil){
        Next(F) = Next(Nxt);
        if(Next(Nxt)!=Nil) Prev(Next(Nxt)) = F;
    }   
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ){
    address F = Last(*L);
    while(F!= Succ) F = Prev(F);
    address Nxt = Prev(F);
    *Pdel = Nxt;
    if(Nxt!=Nil){
        Prev(F) = Prev(Nxt);
        if(Prev(Nxt)!=Nil) Next(Prev(Nxt)) = F;
    } 
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
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
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L){
    printf("[");
    address P = Last(L);
    boolean f=false;
    while(P!=Nil){
        if(f) printf(",");
        f=true;
        if(f) printf("%d", Info(P));
        P=Prev(P);
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */