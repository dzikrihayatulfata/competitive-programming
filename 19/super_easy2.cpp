#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while(getline(cin,line)){
        auto l = line.find_first_not_of(" \t\r\n");
        auto r = line.find_last_not_of(" \t\r\n");
        if(l == string::npos)continue;
        line = line.substr(l,r-l+1);

        cout << line << '\n';
    }
    return 0;
}

