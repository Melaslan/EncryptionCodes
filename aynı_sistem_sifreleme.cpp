// Ayný sistem anahtar kullanarak þifreleme sistemi oluþturulacaktýr

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string mesaj = "Melisa Irem Aslan";
    string anahtar = "2143";

    int satir = mesaj.length() / anahtar.length();
    int sutun = anahtar.length();

    char matrix[satir][sutun];
    int k = 0;
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            matrix[i][j] = mesaj[k];
            k++;
        }
    }

    string sifreleme = "";
    for (int j = 1; j <= sutun; j++) {
        int index = find(anahtar.begin(), anahtar.end(), '0' + j) - anahtar.begin();
        for (int i = 0; i < satir; i++) {
            sifreleme += matrix[i][index];
        }
    }
    cout << "Sifreli Mesaj = " << sifreleme << endl;

    return 0;
}
