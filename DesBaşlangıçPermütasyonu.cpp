/*1. Parametre olarak giri� ve ��k�� bit dizisinin boyutlar�, (m,n), m bitten olu�an giri� dizisi (Dizi_g(m)), n bitten olu�an ��k�� dizisi (Dizi_cHay�r) ve n indis de�erinden 
olu�an perm�tasyon tablosu (P_tHay�r) verilecektir. Fonksiyonda perm�tasyon tablosundaki indis de�erlerine g�re bo� gelen Dizi_c ��k�� bit dizisi �retilecektir.
void permute(int m, int n, int Dizi_g[m], int Dizi_c[n], const int P_tHay�r) �eklinde fonksiyonun isim c�mlesi verilebilir. */

void permute(int m, int n, int Dizi_g[], int Dizi_c[], const int P_t[]) {
  for (int i = 0; i < n; i++) {
    Dizi_c[i] = Dizi_g[P_t[i]];
  }
}


/*
2. split (ay�rma) fonksiyonu: parametre olarak giri� ve ��k�� bit dizisinin boyutlar�, (m,n), m bitten olu�an giri� dizisi (Dizi_g(m)), n bitten olu�an iki ��k�� dizisi
(Dizi_lHay�r, Dizi_rHay�r) verilecektir. Giri� dizisinin sol ve sa� bitleri iki par�aya b�l�nerek Dizi_lHay�r ve Dizi_rHay�r ye aktar�lacakt�r.
void split(int m, int n, int Dizi_g[m], int Dizi_l[n], int Dizi_r[n]) �eklinde fonksiyonun isim c�mlesi tan�mlanabilir. */

void split(int m, int n, int Dizi_g[], int Dizi_l[], int Dizi_r[]) {
  int mid = m / 2;
  for (int i = 0; i < mid; i++) {
    Dizi_l[i] = Dizi_g[i];
  }
  for (int i = mid; i < m; i++) {
    Dizi_r[i - mid] = Dizi_g[i];
  }
}

