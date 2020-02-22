#include "matriks.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

boolean IsIdxValid (int i, int j){
    return (i>=BrsMin && i<=  BrsMax   && j>=KolMin && j<= KolMax );
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
    return BrsMin;
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M){
    return KolMin;
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M){
    return NBrsEff(M);
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M){
    return NKolEff(M);
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    return (i>=BrsMin && i<=  GetLastIdxBrs(M)   && j>=KolMin && j<= GetLastIdxKol(M) );
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MATRIKS M, indeks i){
    return Elmt(M,i,i);
}
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
    for(int i=GetFirstIdxBrs(MIn);i<=GetLastIdxBrs(MIn);i++){
        for(int j=GetFirstIdxKol(MIn);j<=GetLastIdxKol(MIn);j++){
            Elmt(*MHsl,i,j)=Elmt(MIn,i,j);
        }
    }
    NBrsEff(*MHsl)=NBrsEff(MIn);
    NKolEff(*MHsl)=NKolEff(MIn);
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
    MakeMATRIKS(NB, NK, M);
    for(int i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
        for(int j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
            scanf("%d", &Elmt(*M,i,j));
        }
    }
}
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void TulisMATRIKS (MATRIKS M){
    for(int i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
        for(int j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
            printf("%d", Elmt(M,i,j));
            if(j<GetLastIdxKol(M)) printf(" ");
            else if (i<GetLastIdxBrs(M)) printf("\n");
        }
    }
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
    for(int i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++){
        for(int j=GetFirstIdxKol(M2);j<=GetLastIdxKol(M2);j++){
            Elmt(M1,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
        }
    }
    return M1;
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
    for(int i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++){
        for(int j=GetFirstIdxKol(M2);j<=GetLastIdxKol(M2);j++){
            Elmt(M1,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
        }
    }
    return M1;
}
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
    MATRIKS M3;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M3);
    for(int i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++){
        for(int j=GetFirstIdxKol(M2);j<=GetLastIdxKol(M2);j++){
            Elmt(M3,i,j) = 0;
            for(int k=GetFirstIdxKol(M1);k<=GetLastIdxKol(M1);k++){
                Elmt(M3,i,j) += Elmt(M1,i,k) * Elmt(M2,k,j);
            }
        }
    }
    return M3;
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliKons (MATRIKS M, ElType X){
    for(int i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
        for(int j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
            Elmt(M,i,j) *= X;
        }
    }
    return M;
}
/* Mengirim hasil perkalian setiap elemen M dengan X */
void PKaliKons (MATRIKS * M, ElType K){
    for(int i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
        for(int j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
            Elmt(*M,i,j) *= K;
        }
    }
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
    boolean res;
    int i,j;
    if (!EQSize(M1,M2)){
        res = false;
    }
    else{
        res = true;
        i=GetFirstIdxBrs(M1)-1;   
        do{
            i++;
            j=GetFirstIdxKol(M1)-1;
            do{
                j++;
                if(Elmt(M1,i,j) != Elmt(M2,i,j)){
                    res = false;
                }
            } while (res && j<GetLastIdxKol(M1));
        } while (res && i<GetLastIdxBrs(M1));
    }
    return res;
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ (MATRIKS M1, MATRIKS M2){
    return !EQ(M1,M2);
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2){
    return NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2);
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
    return NBrsEff(M)*NKolEff(M);
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
    return NBrsEff(M)==NKolEff(M);
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri (MATRIKS M){
    boolean res;
    int i,j;
    if(!IsBujurSangkar(M)){
        res = false;
    }
    else{
        res = true;
        i=GetFirstIdxBrs(M)-1;       
        do{
            i++;
            j=GetFirstIdxKol(M)-1;
            do{
                j++;
                if(Elmt(M,i,j) != Elmt(M,j,i)){
                    res = false;
                }    
            } while (res && j<GetLastIdxKol(M));
        } while (res && i<GetLastIdxBrs(M));   
    }
    return res;
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
boolean IsSatuan (MATRIKS M){
    int i,j;
    boolean res;
    if(!IsBujurSangkar(M)){
        res = false;
    }
    else{
        res = true;
        i=GetFirstIdxBrs(M)-1;
        do{
            i++;
            j=GetFirstIdxKol(M)-1;
            do{
                j++;
                if(i==j){
                    if(Elmt(M,i,j)!=1) res = false;
                }
                else{
                    if(Elmt(M,i,j)!=0) res = false;
                }    
            } while (res && j<GetLastIdxKol(M));
        } while (res && i<GetLastIdxBrs(M));   
    }
    return res;
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean IsSparse (MATRIKS M){
    boolean res;
    int num,N,i,j;
    num=0;
    //float spars;
    N=NBElmt(M);
    res = true;
    i=GetFirstIdxBrs(M)-1;
    do{
        i++;
        j=GetFirstIdxKol(M)-1;
        do{
            j++;
            if(Elmt(M,i,j) != 0){
                num++;
                //spars = (float)(num/N)*100;
                //printf("\n%f %d", spars, num);
                if(num*20>N) res = false;
            }    
        } while (res && j<GetLastIdxKol(M));
    } while (res && i<GetLastIdxBrs(M));  
    return res; 
}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
MATRIKS Inverse1 (MATRIKS M){
    return KaliKons(M, -1);
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
float Determinan (MATRIKS M){
    float res;
    int i,j,k,cnt;
    if (NKolEff(M)==1){
        res = Elmt(M,GetFirstIdxBrs(M),GetFirstIdxBrs(M));
    }
    else{
        res = 0;
        MATRIKS Ma;
        MakeMATRIKS(NBrsEff(M)-1,NKolEff(M)-1,&Ma);
        for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
            for(j=GetFirstIdxBrs(M)+1;j<=GetLastIdxBrs(M);j++){
                cnt=0;
                for(k=GetFirstIdxBrs(M);k<=GetLastIdxBrs(M);k++){
                    if(k==i) cnt=-1;
                    else Elmt(Ma,j-1,k+cnt) = Elmt(M,j,k);
                }
            }
            if (Elmt(M,GetFirstIdxBrs(M),i)!=0) res += pow(-1,i+1) * Elmt(M,GetFirstIdxBrs(M),i) * Determinan(Ma);
        }
    }
    return res;
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void PInverse1 (MATRIKS * M){
    return PKaliKons(M, -1);
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void Transpose (MATRIKS * M){
    MATRIKS M2;
    CopyMATRIKS(*M, &M2);
    for(int i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
        for(int j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
            Elmt(*M,i,j)= Elmt(M2,j,i);
        }
    }
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
