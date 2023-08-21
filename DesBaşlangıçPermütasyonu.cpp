/*1. Parametre olarak giriþ ve çýkýþ bit dizisinin boyutlarý, (m,n), m bitten oluþan giriþ dizisi (Dizi_g(m)), n bitten oluþan çýkýþ dizisi (Dizi_cHayýr) ve n indis deðerinden 
oluþan permütasyon tablosu (P_tHayýr) verilecektir. Fonksiyonda permütasyon tablosundaki indis deðerlerine göre boþ gelen Dizi_c çýkýþ bit dizisi üretilecektir.
void permute(int m, int n, int Dizi_g[m], int Dizi_c[n], const int P_tHayýr) þeklinde fonksiyonun isim cümlesi verilebilir. */

void permute(int m, int n, int Dizi_g[], int Dizi_c[], const int P_t[]) {
  for (int i = 0; i < n; i++) {
    Dizi_c[i] = Dizi_g[P_t[i]];
  }
}


/*
2. split (ayýrma) fonksiyonu: parametre olarak giriþ ve çýkýþ bit dizisinin boyutlarý, (m,n), m bitten oluþan giriþ dizisi (Dizi_g(m)), n bitten oluþan iki çýkýþ dizisi
(Dizi_lHayýr, Dizi_rHayýr) verilecektir. Giriþ dizisinin sol ve sað bitleri iki parçaya bölünerek Dizi_lHayýr ve Dizi_rHayýr ye aktarýlacaktýr.
void split(int m, int n, int Dizi_g[m], int Dizi_l[n], int Dizi_r[n]) þeklinde fonksiyonun isim cümlesi tanýmlanabilir. */

void split(int m, int n, int Dizi_g[], int Dizi_l[], int Dizi_r[]) {
  int mid = m / 2;
  for (int i = 0; i < mid; i++) {
    Dizi_l[i] = Dizi_g[i];
  }
  for (int i = mid; i < m; i++) {
    Dizi_r[i - mid] = Dizi_g[i];
  }
}

