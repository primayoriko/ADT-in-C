/* Nama : Naufal Prima Yoriko
 *  NIM : 13518146
 *  Tanggal : 28 Aug 2019 */

#include <stdio.h>
#include "point.h"

int main(){
    POINT P1,P2;
    BacaPOINT(&P1);
    TulisPOINT(P1);
    BacaPOINT(&P2);
    TulisPOINT(P2);
    printf("Jarak kedua titik nya adalah : %.2f", Panjang(P1, P2))
    printf("P1 setelah dirotasi 30 deg posisinya adalah ");
    Putar(&P1, 30);
    TulisPOINT(P1);
    printf("P2 setelah di translasi 3 sat di absis dan -2 sat di ordinat, posisinya adalah ");
    Geser(&P2, 3, -2);
    TulisPOINT(P2);
    printf("maka sekarang P1 ada di kuadran %d dan P2 ada di kuadran %d", Kuadran(P1), Kuadran(P2));
    return 0;
}