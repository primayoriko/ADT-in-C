/* Nama : Naufal Prima Yoriko
 *  NIM : 13518146
 *  Tanggal : 28 Aug 2019 */

#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
    //Kamus Lokal
    POINT P;
    //Algoritma
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
    // Kamus Lokal
    float x, y;
    // Algoritma
    scanf("%f %f", &x, &y);
    *P = MakePOINT(x, y);
}

void TulisPOINT (POINT P){
    // Algoritma
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
    return (Absis(P1)==Absis(P2) && Ordinat(P1)==Ordinat(P2));
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

boolean NEQ (POINT P1, POINT P2){
    return (Absis(P1)!=Absis(P2) || Ordinat(P1)!=Ordinat(P2));
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
    return (Absis(P)==0 && Ordinat(P)==0);
}
/* Menghasilkan true jika P adalah titik origin */

boolean IsOnSbX (POINT P){
    return (Ordinat(P)==0);
}
/* Menghasilkan true jika P terletak Pada sumbu X */

boolean IsOnSbY (POINT P){
    return (Absis(P)==0);
}
/* Menghasilkan true jika P terletak pada sumbu Y */

int Kuadran (POINT P){
    //Kamus Lokal
    int kuadran;
    //Algoritma
    if(Ordinat(P)>0){
        if(Absis(P)>0){
            kuadran = 1;
        }
        else {
            kuadran = 2;
        }
    }
    else{
        if(Absis(P)>0){
            kuadran = 4;
        }
        else {
            kuadran = 3;
        }
    }
    return kuadran;
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P){
    //Algoritma
    return MakePOINT(Absis(P)+1, Ordinat(P));
}
/* Mengirim salinan P dengan absis ditambah satu */

POINT NextY (POINT P){
    //Algoritma
    return MakePOINT(Absis(P), Ordinat(P)+1);
}
/* Mengirim salinan P dengan ordinat ditambah satu */

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    //Algoritma
    return MakePOINT(Absis(P)+deltaX, Ordinat(P)+deltaY);
}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */

POINT MirrorOf (POINT P, boolean SbX){
    //Algoritma
    if(SbX){
        P = MakePOINT(Absis(P), -(Ordinat(P)));
    }
    else{
        P = MakePOINT(-(Absis(P)), Ordinat(P));
    }
    return P;
}
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */

float Jarak0 (POINT P){
    // Algoritma
    return sqrtf(powf(Absis(P), 2) + powf(Ordinat(P), 2));
}
/* Menghitung jarak P ke (0,0) */

float Panjang (POINT P1, POINT P2){
    // Algoritma
    return sqrtf(powf(Absis(P1)-Absis(P2), 2) + powf(Ordinat(P1)-Ordinat(P2), 2));
}
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */

void Geser (POINT *P, float deltaX, float deltaY){
    // Algoritma
    *P = MakePOINT((Absis(*P))+deltaX, (Ordinat(*P))+deltaY);
}
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

void GeserKeSbX (POINT *P){
    // Algoritma
    *P = MakePOINT(Absis(*P), 0);
}
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */

void GeserKeSbY (POINT *P){
    // Algoritma
    *P = MakePOINT(0, Ordinat(*P));
}
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */

void Mirror (POINT *P, boolean SbX){
    //Algoritma
    if(SbX){
        *P = MakePOINT(Absis(*P), -(Ordinat(*P)));
    }
    else{
        *P = MakePOINT(-(Absis(*P)), Ordinat(*P));
    }
}
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */

void Putar (POINT *P, float Sudut){
    //Algoritma
    Sudut = (-Sudut) * (3.14159) /180;
    *P = MakePOINT((cosf(Sudut)*Absis(*P)-sinf(Sudut)*Ordinat(*P)), (cosf(Sudut)*Ordinat(*P)+sinf(Sudut)*Absis(*P)));
}
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/
