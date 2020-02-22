/* Modul lain yang digunakan : */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bintree.h"

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R){
    BinTree a = AlokNode(Akar);
    if(a!=Nil){
        Left(a) = L;
        Right(a) = R;
    }
    return a;
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P){
    *P = Tree(Akar, L, R);
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
   jika alokasi berhasil. P = Nil jika alokasi gagal. */
BinTree BuildBalanceTree(int n){
    /*if (n==0) return Nil;
    else{
        infotype X;
        scanf("%d", &X);
        return Tree(X, BuildBalanceTree(n/2 + (n%2)),BuildBalanceTree(n/2));
    }*/
    addrNode P;
	int nL, nR;
	infotype X;
	BinTree R, L;
	//Algoritma
	if (n==0) return Nil;
	else {
		scanf("%d", &X);
		P = AlokNode(X);
		if (P!=Nil) {
			nL = n/2; nR = n-nL-1;
			L = BuildBalanceTree(nL);
			R = BuildBalanceTree(nR);
			Left(P) = L; 
			Right(P) = R;
		}
		return P;
	}
}
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
/* Jika n == 0, kembalikan Nil.
   Mula-mula, baca nilai dari root dari stdin, lalu bangun pohon biner di kiri
   (dengan membaca dari stdin) lalu di tree kanan (dengan membaca dari stdin). 
   misal dari stdin: 1, 2, 3, 4, 5, 6, 7, hasilnya:
       1
     2   5
    3 4 6 7
  */

/* Manajemen Memory */
addrNode AlokNode(infotype X){
    addrNode a = (Node*)malloc(sizeof(Node));
    if(a!=Nil){
        Akar(a) = X;
        Left(a) = Nil;
        Right(a) = Nil;
    }
    return a;
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode(addrNode P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P){
    return P==Nil;
}
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P){
    return !IsTreeEmpty(P) && Right(P)==Nil && Left(P) == Nil;
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P){
    return Left(P)!= Nil && Right(P) == Nil;
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P){
    return Right(P)!= Nil && Left(P) == Nil;
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P){
    return Left(P)!= Nil && Right(P)!= Nil;
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

/* *** Traversal *** */
void PrintTreeHelper(BinTree P, int h, int hc)
{
	//Algoritma
	if (!IsTreeEmpty(P)) {
        for(int i=0;i<hc;i++)printf(" ");
		printf("%d\n", Akar(P));
		if (!IsTreeEmpty(Left(P))) {
			PrintTreeHelper(Left(P), h, hc+h);
		}
		if (!IsTreeEmpty(Right(P))) {
			PrintTreeHelper(Right(P), h, hc+h);
		}
	}
}
void PrintPreorder(BinTree P){
    printf("(");
    if(!IsTreeEmpty(P)){
        printf("%d", Akar(P));
        PrintPreorder(Left(P));
        PrintPreorder(Right(P));
    }
    printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
void PrintInorder(BinTree P){
    printf("(");
    if(!IsTreeEmpty(P)){
        PrintInorder(Left(P));
        printf("%d", Akar(P));
        PrintInorder(Right(P));
    }
    printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
void PrintPostorder(BinTree P){
    printf("(");
    if(!IsTreeEmpty(P)){
        PrintPostorder(Left(P));
        PrintPostorder(Right(P));
        printf("%d", Akar(P));
    }
    printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
void PrintTree(BinTree P, int h){
    PrintTreeHelper(P, h, 0);
}
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X){
    if(!IsTreeEmpty(P)){
        if(Akar(P)==X) return true;
        return SearchTree(Left(P), X) || SearchTree(Right(P), X);
    }
    return false;
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P){
    int n=0;
    if(!IsTreeEmpty(P)){
        n++;
        n+= (NbElmt(Left(P)) + NbElmt(Right(P)));
    }
    return n;
}
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun(BinTree P){
    if(IsTreeEmpty(P)) return 0;
    if(IsTreeOneElmt(P)) return 1;
    return NbDaun(Left(P)) + NbDaun(Right(P));
}
/* Mengirimkan banyaknya daun (node) pohon biner P *y/
/* Prekondisi: P tidak kosong */
boolean IsSkewLeft(BinTree P){
    if(IsTreeEmpty(P) || IsTreeOneElmt(P)) return true;
    return IsUnerLeft(P) && IsSkewLeft(Left(P));
}
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight(BinTree P){
    if(IsTreeEmpty(P) || IsTreeOneElmt(P)) return true;
    return IsUnerRight(P) && IsSkewRight(Right(P));
}
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
int Level(BinTree P, infotype X){
    if (X==Akar(P)){
		return 1;
	}
	else 
		if (SearchTree(Left(P), X)) {
			return 1+Level(Left(P), X);
		}
		else {
			return 1+Level(Right(P), X);
		}
}
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
int Tinggi(BinTree P){
    int n=0;
    if(!IsTreeEmpty(P)){
        int a = Tinggi(Right(P));
        int b = Tinggi(Left(P));
        b = (a>b)? a:b;
        n += (1+b);
    }
    return n;
}
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotype X){
    if(IsTreeEmpty(*P)) (*P) = AlokNode(X);
    else if(IsTreeEmpty(Left(*P))) Left(*P) = AlokNode(X);
    else AddDaunTerkiri(&(Left(*P)), X);
}
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri){
    if(!(IsTreeOneElmt(*P) && Akar(*P) != X)){
        if(IsTreeOneElmt(*P) && Akar(*P)==X){
            if(Kiri) Left(*P) = AlokNode(Y);
            else Right(*P) = AlokNode(Y);
        }
        else{
            if(SearchTree(Left(*P), X)) AddDaun(&Left(*P), X, Y, Kiri);
            else AddDaun(&Right(*P), X, Y, Kiri);
        }
    }
}
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*      Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void DelDaunTerkiri(BinTree *P, infotype *X){
    if (Left(*P)==Nil) {
		if (Right(*P)==Nil) {
			(*X) = Akar(*P);
			(*P) = Nil;
			free(*P);
		}
		else {
			DelDaunTerkiri(&Right(*P), X);
		}
	}
	else {
		DelDaunTerkiri(&Left(*P), X);
	}
}
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
void DelDaun(BinTree *P, infotype X){
    if(IsTreeOneElmt(*P) && Akar(*P)==X){
        addrNode X = *P;
        DealokNode(X);
        *P = Nil;
    }
    /*if(IsTreeOneElmt(Left(*P)) && Akar(Left(*P))==X){
        DealokNode(Left(*P));
        Left(*P) = Nil;
    }
    if(IsTreeOneElmt(Right(*P)) && Akar(Right(*P))==X){
        DealokNode(Right(*P));
        Right(*P) = Nil;
    }*/
    if(!IsTreeEmpty(*P) && !IsTreeOneElmt(*P)){
        if(Left(*P)!=Nil) DelDaun(&Left(*P), X);
        if(Right(*P)!=Nil) DelDaun(&Right(*P), X);
    }
}
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
List MakeListDaun(BinTree P){
    if(IsTreeEmpty(P)) return Nil;
    if(IsTreeOneElmt(P)) return Alokasi(Akar(P));
    return Concat(MakeListDaun(Left(P)), MakeListDaun(Right(P)));
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
List MakeListPreorder(BinTree P){
    if(IsTreeEmpty(P)) return Nil;
    if(IsTreeOneElmt(P)) return Alokasi(Akar(P));
    return Konso(Akar(P), Concat(MakeListPreorder(Left(P)), MakeListPreorder(Right(P))));
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   dengan urutan preorder, jika semua alokasi berhasil.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
List MakeListLevel(BinTree P, int N){
    if(IsTreeEmpty(P)) return Nil;
    if(N==1) return Alokasi(Akar(P));
    return Concat(MakeListLevel(Left(P),N-1),MakeListLevel(Right(P),N-1));
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   yang levelnya=N, jika semua alokasi berhasil.
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotype X){
    if(IsTreeEmpty(P)) return false;
    else if(Akar(P)==X) return true;
    else if(X>Akar(P)) return BSearch(Right(P), X);
    else return BSearch(Left(P), X);
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

void InsSearch(BinTree *P, infotype X){
    if(IsTreeEmpty(*P)) *P = AlokNode(X);
    else if(X > Akar(*P)){
        if(Right(*P) == Nil) Right(*P) = AlokNode(X);
        else InsSearch(&Right(*P), X);
    }
    else{
        if (Left(*P) == Nil) Left(*P) = AlokNode(X);
        else InsSearch(&Left(*P), X);
    }
}
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */

void DelBtree(BinTree *P, infotype X){
    addrNode t;
    if(IsTreeOneElmt(*P) && Akar(*P) == X){
        t = *P;
        DealokNode(t);
        *P = Nil;
    }
    else{
        if(X<Akar(*P)){
            DelBtree(&Left(*P), X);
        }
        else DelBtree(&Right(*P), X);
    }
}
/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */

