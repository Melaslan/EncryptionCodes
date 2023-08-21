// Matris satýr, sütun iþlemleri kullanarak þifreleme örneði (anahtarsýz),

#include <iostream>
#include <string>

using namespace std;

int main() {
    string mesaj = "kriptoloji";
    int satir = 5, sutun = 3;

    char matrix[satir][sutun];
    int k = 0;
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            if (k < mesaj.length()) {
                matrix[i][j] = mesaj[k];
                k++;
            }
            else {
                matrix[i][j] = ' ';
            }
        }
    }

    string sifrelenmis_satir = "";
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            sifrelenmis_satir+= matrix[i][j];
        }
    }
    cout << "Mesaj = " << sifrelenmis_satir << endl;

    string sifrelenmis_sutun = "";
    for (int j = 0; j < sutun; j++) {
        for (int i = 0; i < satir; i++) {
            sifrelenmis_sutun += matrix[i][j];
        }
    }
    cout << "Sifreli mesaj = " << sifrelenmis_sutun << endl;

    return 0;
}
