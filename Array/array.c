/* Nama : Naufal Prima Yoriko
 *  NIM : 13518146
 *  Tanggal : 4 Sept 2019 */

#include <stdio.h>
#include "array.h"

void MakeEmpty (TabInt * T){
    Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
    return Neff(T);
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
    return IdxMax;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
    //Kamus Lokal
    return IdxMin;
}

IdxType GetLastIdx (TabInt T){
    return IdxMin +(NbElmt(T)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
    return (i >= IdxMin && i<=IdxMax);
}

boolean IsIdxEff (TabInt T, IdxType i){
    return (i >= GetFirstIdx(T) && i<= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
    return (NbElmt(T)==0);
}

boolean IsFull (TabInt T){
    return (IdxMax == NbElmt(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
    // Kamus Lokal
    IdxType i,N;
    // Algoritma
    do{
        scanf("%d", &N);
    }
    while (N<0 || N>MaxNbEl(*T));
    for (i=GetFirstIdx(*T);i<=N;i++){
        scanf("%d", &Elmt(*T,i));
    }
    Neff(*T) = N;
}

void BacaIsiTab (TabInt * T){
    // Kamus Lokal
    IdxType i;
    ElType input;
    // Algoritma
    i=GetFirstIdx(*T);
    Neff(*T) = 0;
    do{
        scanf("%d", &input);
        if(input!=-9999){
            Elmt(*T, i)=input;
            Neff(*T)++;
            i++;
        }
    }
    while(input!=-9999 && !IsFull(*T));
}

void TulisIsi (TabInt T) {
    // Kamus Lokal
    IdxType i;
    // Algoritma
    if (IsEmpty(T)) {
        printf("Tabel kosong\n");
    }
    else {
        for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
            printf("[%d]%d\n", i, Elmt(T,i));
        }
    }
}

void TulisIsiTab (TabInt T){
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

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2){
    // Kamus Lokal
    IdxType i;
    TabInt Tsum;
    // Algoritma
    for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++){
        Elmt(Tsum, i) = Elmt(T1,i) + Elmt(T2,i);
    }
    Neff(Tsum) = Neff(T1);
    return Tsum;
}
TabInt MinusTab (TabInt T1, TabInt T2){
    // Kamus Lokal
    IdxType i;
    TabInt Tsum;
    // Algoritma
    for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++){
        Elmt(Tsum, i) = Elmt(T1,i) - Elmt(T2,i);
    }
    Neff(Tsum) = Neff(T1);
    return Tsum;
}
TabInt KaliTab (TabInt T1, TabInt T2){
    // Kamus Lokal
    IdxType i;
    TabInt Tsum;
    // Algoritma
    for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++){
        Elmt(Tsum, i) = Elmt(T1,i) * Elmt(T2,i);
    }
    Neff(Tsum) = Neff(T1);
    return Tsum;
}
TabInt KaliKons (TabInt Tin, ElType c){
    // Kamus Lokal
    IdxType i;
    TabInt Tsum;
    // Algoritma
    for(i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++){
        Elmt(Tsum, i) = c * Elmt(Tin,i);
    }
    Neff(Tsum) = Neff(Tin);
    return Tsum;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2){
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

boolean IsLess (TabInt T1, TabInt T2){
    // Kamus Lokal
    boolean res;
    IdxType i , N;
    // Algoritma
    res = true;
    N = (NbElmt(T1)<NbElmt(T2))?NbElmt(T1):NbElmt(T2);
    if(N!=0){
        i = GetFirstIdx(T1) - 1;
        do {
            i++;
            if (Elmt(T1, i) > Elmt(T2, i)) {
                res = false;
            }
        } while (Elmt(T1, i) == Elmt(T2, i) && i < N);
        if(i==N && Elmt(T1, i) == Elmt(T2, i) && NbElmt(T1)>=NbElmt(T2)){
            res = false;
        }
    }
    else{
        if(NbElmt(T1)>=NbElmt(T2)){
            res = false;
        }
    }
    return res;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X){
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

IdxType Search2 (TabInt T, ElType X){
    // Kamus Lokal
    IdxType i;
    boolean Found;
    // Algoritma
    Found = false;
    if (!IsEmpty(T)){
        i = GetFirstIdx(T)-1;
        do{
            i++;
            if(Elmt(T,i)==X){
                Found = true;
            }
        }
        while(!Found && i<GetLastIdx(T));
    }
    if(!Found){
        i = IdxUndef;
    }
    return i;
}

boolean SearchB (TabInt T, ElType X){
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

boolean SearchSentinel (TabInt T, ElType X){
    // Kamus Lokal
    IdxType i, sentinel;
    // Algoritma
    sentinel = 0;
    if(!IsEmpty(T)){
        i = GetFirstIdx(T)-1;
        do{
            i++;
            if(X == Elmt(T,i)){
                sentinel = i;
            }
        }
        while(X != Elmt(T,i) && i<GetLastIdx(T));
    }
    return sentinel!=0;
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
    // Kamus Lokal
    ElType maks;
    IdxType i;
    // Algoritma
    maks = Elmt(T,GetFirstIdx(T));
    for(i = GetFirstIdx(T)+1;i<=GetLastIdx(T);i++){
        if(maks < Elmt(T,i)){
            maks = Elmt(T,i);
        }
    }
    return maks;
}

ElType ValMin (TabInt T){
    // Kamus Lokal
    ElType min;
    IdxType i;
    // Algoritma
    min = Elmt(T,GetFirstIdx(T));
    for(i = GetFirstIdx(T)+1;i<=GetLastIdx(T);i++){
        if(min > Elmt(T,i)){
            min = Elmt(T,i);
        }
    }
    return min;
}

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T){
    // Kamus Lokal
    IdxType i, idxMaks;
    ElType  maks;
    // Algoritma
    idxMaks = GetFirstIdx(T);
    maks = Elmt(T,GetFirstIdx(T));
    for(i = GetFirstIdx(T)+1;i<=GetLastIdx(T);i++){
        if(maks < Elmt(T,i)){
            maks = Elmt(T,i);
            idxMaks = i;
        }
    }
    return idxMaks;
}

IdxType IdxMinTab (TabInt T){
    ElType min;
    IdxType i, idxMin;
    // Algoritma
    idxMin = GetFirstIdx(T);
    min = Elmt(T,GetFirstIdx(T));
    for(i = GetFirstIdx(T)+1;i<=GetLastIdx(T);i++){
        if(min > Elmt(T,i)){
            min = Elmt(T,i);
            idxMin = i;
        }
    }
    return idxMin;
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout){
    // Kamus Lokal
    IdxType i;
    // Algoritma
    for(i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++){
        Elmt(*Tout,i)= Elmt(Tin, i);
    }
    Neff(*Tout)= Neff(Tin);
}

TabInt InverseTab (TabInt T){
    // Kamus Lokal
    IdxType i;
    TabInt Trev;
    // Algoritma
    for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
        Elmt(Trev,i)= Elmt(T,NbElmt(T)+1-i);
    }
    Neff(Trev)= Neff(T);
    return Trev;
}

boolean IsSimetris (TabInt T){
    // Kamus Lokal
    IdxType i;
    boolean simetris;
    // Algoritma
    simetris = true;
    if(!IsEmpty(T)){
        i = GetFirstIdx(T)-1;
        do{
            i++;
            if (Elmt(T,i)!=Elmt(T,GetLastIdx(T)+1-i)){
                simetris = false;
            }
        }
        while(Elmt(T,i)==Elmt(T,GetLastIdx(T)+1-i)&&i<GetLastIdx(T)/2);
    }
    return simetris;
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T){
    // Kamus Lokal
    IdxType i, j, min;
    ElType temp;
    // Algoritma
    for(i= GetFirstIdx(*T); i<GetLastIdx(*T);i++){
        min = i;
        for(j=i+1;j<=GetLastIdx(*T); j++){
            if(Elmt(*T,min)<Elmt(*T,j)){
                min = j;
            }
        }
        temp = Elmt(*T,i);
        Elmt(*T,i) = Elmt(*T,min);
        Elmt(*T,min) = temp;
    }
}
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
void InsSortAsc (TabInt * T){
    // Kamus Lokal
    IdxType i, j, min;
    ElType temp;
    // Algoritma
    for(i = GetFirstIdx(*T); i < GetLastIdx(*T);i++){
        min = i;
        for(j = i+1;j <= GetLastIdx(*T); j++){
            if(Elmt(*T,min) > Elmt(*T,j)){
                min = j;
            }
        }
        temp = Elmt(*T,i);
        Elmt(*T,i) = Elmt(*T,min);
        Elmt(*T,min) = temp;
    }
}
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X){
    //Algoritma
    Elmt(*T, GetLastIdx(*T)+1) = X;
    Neff(*T)++;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
void AddEli (TabInt * T, ElType X, IdxType i){
    // Kamus Lokal
    IdxType j;
    // Algoritma
    for(j=GetLastIdx(*T);j>=i;j--){
        Elmt(*T, j+1) = Elmt(*T, j);
    }
    Elmt(*T, i) = X;
    Neff(*T)++;
}
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X){
    //Algoritma
    *X = Elmt(*T, GetLastIdx(*T));
    Neff(*T)--;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
void DelEli (TabInt * T, IdxType i, ElType * X){
    // Kamus Lokal
    IdxType j;
    // Algoritma
    *X = Elmt(*T, i);
    for(j=i;j<GetLastIdx(*T);j++){
        Elmt(*T, j) = Elmt(*T, j+1);
    }
    Neff(*T)--;
}
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X){
    // Algoritma
    if(SearchSentinel(*T, X)){
        printf("nilai sudah ada\n");
    }
    else{
        Elmt(*T, GetLastIdx(*T)+1) = X;
        Neff(*T)++;
    }
}
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
    Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
    dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X){
    // Kamus Lokal
    IdxType l,r,mid;
    //Algoritma
    l=GetFirstIdx(T);
    r=GetLastIdx(T);
    mid=(l+r)/2;
    while(l<r){
        if(X>Elmt(T, mid)){
            l = mid+1;
        }
        else{
            r = mid;
        }
        mid=(l+r)/2;
    }
    if(X!=Elmt(T,l) || IsEmpty(T)){
        l=IdxUndef;
    }
    return l;
}

ElType MaxUrut (TabInt T){
    return Elmt(T, GetLastIdx(T));
}

ElType MinUrut (TabInt T){
    return Elmt(T, GetFirstIdx(T));
}

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min){
    *Max = MaxUrut(T);
    *Min = MinUrut(T);
}

void Add1Urut (TabInt * T, ElType X){
    // Kamus Lokal
    IdxType i;
    //Algoritma
    if(IsEmpty(*T)){
        Elmt(*T,GetFirstIdx(*T)) = X;
        Neff(*T)++;
    }
    else{
        if(!IsFull(*T) && !SearchSentinel(*T,X)){
            i=GetLastIdx(*T);
            while(Elmt(*T,i)>X && i>=GetFirstIdx(*T)){
                Elmt(*T,i+1)=Elmt(*T,i);
                i--;
            }
            Elmt(*T,i+1) = X;
            Neff(*T)++;
        }
    }
}

void Del1Urut (TabInt * T, ElType X){
    // Kamus Lokal
    IdxType i,start;
    //Algoritma
    start= SearchUrut(*T, X);
    if(start!=IdxUndef && !IsEmpty(*T)){
        for(i=start;i<GetLastIdx(*T);i++){
            Elmt(*T, i)=Elmt(*T, i+1);
        }
        Neff(*T)--;
    }
}
