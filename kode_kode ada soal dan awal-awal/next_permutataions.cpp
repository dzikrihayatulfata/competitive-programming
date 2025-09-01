#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s = "ABCDEFGHIJ";  // 10 letters
    int count = 0;

    do {
        cout << s << endl;
        count++;
       
        if (count == 1000) break;
    } while (next_permutation(s.begin(), s.end()));

    cout << "Total permutations: " << count << endl;
    return 0;
}
