/* File: garis.c */
/* Tanggal: 29 Agustus 2019 */
/* Implementasi ADT GARIS */

#include <stdio.h>
#include "boolean.h"
#include "garis.h"
#include "point.h"

// Nama : Muhammad Rizky Ismail Faizal
// NIM  : 13518148

void MakeGARIS (POINT P1, POINT P2, GARIS * L)
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */
{
	PAwal(*L) = P1;
	PAkhir(*L) = P2;
}

void BacaGARIS (GARIS * L)
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
{
	boolean check = false;
	POINT a, b;
	while (!check) {
		BacaPOINT(&a);
		BacaPOINT(&b);
		check = NEQ(a, b);
		if (!check) {
			printf("Garis tidak valid\n");
		}
	}
	MakeGARIS(a, b, L);
}
void TulisGARIS (GARIS L)
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
{
	printf("(");
	TulisPOINT(PAwal(L));
	printf(",");
	TulisPOINT(PAkhir(L));
	printf(")");
}

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L)
/* Menghitung panjang garis L : berikan rumusnya */
{
	return Panjang(PAwal(L), PAkhir(L));
	// Rumus: ((x2-x1)^2 + (y2-y1)^2)^0.5
}
float Gradien (GARIS L)
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
{
	return (Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))-Absis(PAwal(L)));
}
void GeserGARIS (GARIS * L, float deltaX, float deltaY)
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */
{
	PAwal(*L) = PlusDelta(PAwal(*L), deltaX, deltaY);
	PAkhir(*L) = PlusDelta(PAkhir(*L), deltaX, deltaY);
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2)
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
{
	return ((Gradien(L1)*Gradien(L2)) == -1);
}
boolean IsSejajar (GARIS L1, GARIS L2)
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
{
	return (Gradien(L1) == Gradien(L2));
}
