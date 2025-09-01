#include <bits/stdc++.h>
using namespace std;

int main() {
    string T, fullText;
    while (getline(cin, T)) {
        fullText += T + "\n"; // simpan semua input + newline
    }

    string hasil;
    int hitungan = 0;
    for (char c : fullText) {
        if (c == '"') {
            if (hitungan % 2 == 0)
                hasil += "``";
            else
                hasil += "''";
            hitungan++;
        } else {
            hasil += c;
        }
    }

    cout << hasil;
    return 0;
}
