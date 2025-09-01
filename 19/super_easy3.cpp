#include <iostream>
using namespace std;
int main() {
    int p, a, b, c;
    while (cin >> p >> a >> b >> c) {
        if (p == 0 && a == 0 && b == 0 && c == 0) {
            break;
        }
        int dist1 = (p - a + 40) % 40;
        int ticks1 = 80 + dist1;
        int dist2 = (b - a + 40) % 40;
        int ticks2 = 40 + dist2;
        int dist3 = (b - c + 40) % 40;
        int total_ticks = ticks1 + ticks2 + dist3;
        int degrees = total_ticks * 9;
        std::cout << degrees << std::endl;
    }
    return 0;
}