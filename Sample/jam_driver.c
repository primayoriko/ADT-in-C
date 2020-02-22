/* Nama : Naufal Prima Yoriko
 *  NIM : 13518146
 *  Tanggal : 28 Aug 2019 */

#include <stdio.h>
#include "jam.h"

int main(){
    JAM J1, J2;
    BacaJAM(&J1);
    TulisJAM(J1);
    BacaJAM(&J2);
    TulisJAM(J2);
    printf("Total detik jam J1 : %d", JAMToDetik(J1));
    printf("Total detik jam J2 : %d", JAMToDetik(J2));
    printf("Selisih jam  J1 dan J2 : %d", Durasi(J1, J2));

    return 0;
}