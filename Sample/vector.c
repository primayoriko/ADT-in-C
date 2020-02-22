/* Nama : Naufal Prima Yoriko
 *  NIM : 13518146
 *  Tanggal : 2 Sept 2019 */
/* File: vector.h */

#include <stdio.h>
#include "vector.h"


VECTOR MakeVector(float x, float y){
	VECTOR V;
	AbsisComponent(V)=x;
	OrdinatComponent(V)=y;
	return V;
}

void TulisVector(VECTOR v) {
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));

}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v){
	return Jarak0(MakePOINT(AbsisComponent(v), OrdinatComponent(v)));
}
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
VECTOR Add(VECTOR a, VECTOR b){
	OrdinatComponent(a) += OrdinatComponent(b);
	AbsisComponent(a) += AbsisComponent(b);
	return a;
}
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
VECTOR Substract(VECTOR a, VECTOR b){
	OrdinatComponent(a) -= OrdinatComponent(b);
	AbsisComponent(a) -= AbsisComponent(b);
	return a;
}
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
float Dot(VECTOR a, VECTOR b){
	return OrdinatComponent(b) * OrdinatComponent(a) + AbsisComponent(a) * AbsisComponent(b);
}
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
VECTOR Multiply(VECTOR v, float s){
	OrdinatComponent(v) *= s;
	AbsisComponent(v) *= s;
	return v;
}
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * a.x, s * a.y) */

