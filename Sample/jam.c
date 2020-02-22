/* Nama : Naufal Prima Yoriko
 *  NIM : 13518146
 *  Tanggal : 28 Aug 2019 */

#include <stdio.h>
#include "jam.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S){
    // Algoritma
    return !(H>23 || H<0 || M<0 || M>59 || S<0 || S>59);
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS){
    //Kamus Lokal
    JAM J;
    //Algoritma
    Hour(J) = HH;
    Minute(J) = MM;
    Second(J) = SS;
    return J;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J){
    // Kamus Lokal
    int H, M, S;
    // Algoritma
    do{
        scanf("%d %d %d", &H, &M, &S);
        if(!IsJAMValid (H, M, S)){
            printf("Jam tidak valid\n");
        }
    } while (!IsJAMValid (H, M, S));

    *J = MakeJAM (H, M, S);
}

void TulisJAM (JAM J){
    //Algoritma
    printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J){
    //Algoritma
    return Hour(J)*3600 + Minute(J)*60 + Second(J);
}

JAM DetikToJAM (long N){
    //Kamus Lokal
    JAM J;
    //Algoritma
    N = N + 86400;
    J = MakeJAM ((N%86400)/3600, (N%3600)/60, N%60);
    return J;
}


/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2){
    //Algoritma
    return JAMToDetik(J1) == JAMToDetik(J2);
}

boolean JNEQ (JAM J1, JAM J2){
    //Algoritma
    return JAMToDetik(J1) != JAMToDetik(J2);
}
boolean JLT (JAM J1, JAM J2){
    //Algoritma
    return JAMToDetik(J1) < JAMToDetik(J2);
}

boolean JGT (JAM J1, JAM J2){
    //Algoritma
    return JAMToDetik(J1) > JAMToDetik(J2);
}

/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J){
    //Algoritma
    return DetikToJAM(JAMToDetik(J) + 1);
}

JAM NextNDetik (JAM J, int N){
    //Algoritma
    return DetikToJAM(JAMToDetik(J) + N);
}

JAM PrevDetik (JAM J){
    //Algoritma
    return DetikToJAM(JAMToDetik(J) - 1);
}

JAM PrevNDetik (JAM J, int N){
    //Algoritma
    return DetikToJAM(JAMToDetik(J) - N);
}
/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh){
    //Algoritma
    return (JAMToDetik(JAkh)-JAMToDetik(JAw)+86400)%86400;
}
