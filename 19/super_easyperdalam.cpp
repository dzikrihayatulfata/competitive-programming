#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (getline(cin, s)) { // baca sampai EOF
        size_t l = s.find_first_not_of(" \t\r\n#");
        size_t r = s.find_last_not_of(" \t\r\n");

        if (l == string::npos) {
            // Kalau baris kosong / hanya berisi karakter yang dihapus
            cout << "(kosong)" << '\n';
            continue;
        }

        cout << "Index pertama bukan spasi: " << l << '\n';
        cout << "Index terakhir bukan spasi: " << r << '\n';
        cout << "Hasil trimming: '" << s.substr(l, r - l + 1) << "'" << '\n';
    }
    return 0;
}
