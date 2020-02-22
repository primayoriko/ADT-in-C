/* Nama : Naufal Prima Yoriko
 * NIM : 13518146
 * Tanggal : 2 Sept 2019 */
 
 //Program Mjam
 
 #include <stdio.h>
 #include "jam.h"
 
 int main(){
	 //Kamus Global
	 int n, res;
	 JAM J1, Jint, J2, Jawal, Jakhir;
	 //Algoritma
	 Jawal = MakeJAM(23,59,59);
	 Jakhir = MakeJAM(0,0,0);
	 scanf("%d", &n);
	 for (int i=1;i<=n;i++){
		 printf("[%d]\n", i);
		 BacaJAM(&J1);
		 BacaJAM(&J2);
		 if (JLT(J2, J1)){
			Jint = J2;
			J2 = J1;
			J1 = Jint;
		}
		res = (JAMToDetik(J2)-JAMToDetik(J1)+86400)%86400;
		printf("%d\n", res);
		if(JLT(J1, Jawal)){
			Jawal = J1;
		}
		if(JLT(Jakhir, J2)){
			Jakhir = J2;
		}

	 }
	 TulisJAM(Jawal);
	 printf("\n");
	 TulisJAM(Jakhir);
	 printf("\n");
	 return 0;
}
