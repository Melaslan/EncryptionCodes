// Caesar þifreleme örneði yapýlacaktýr.

#include <iostream>
#include <string>

using namespace std;

string caesar_sifreleme(string mesaj, int shift) {
    string result = "";

    for (int i = 0; i < mesaj.length(); i++) {
        if (isupper(mesaj[i])) {
            result += char(int(mesaj[i] + shift - 65) % 26 + 65);
        }
        else {
            result += char(int(mesaj[i] + shift - 97) % 26 + 97);
        }
    }

    return result;
}

int main() {
    string mesaj = "TryHackMe";
    int shift = 4;

    cout << "Mesaj = " << mesaj << endl;
    string sifrele = caesar_sifreleme(mesaj, shift);
    cout << "Sifrelenmis Mesaj " << sifrele << endl;

    return 0;
}
