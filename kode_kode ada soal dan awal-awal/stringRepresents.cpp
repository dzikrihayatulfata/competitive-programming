#include <bits/stdc++.h>
using namespace std;

// Convert character to its numeric value (0-35)
int charToValue(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10; // Optional for lowercase
    return -1;
}

// Convert numeric value (0-35) to corresponding character
char valueToChar(int val) {
    if (val < 10) return '0' + val;
    return 'A' + (val - 10);
}

// Convert from base X to decimal
long long toDecimal(string num, int baseX) {
    long long value = 0;
    for (char c : num) {
        int digit = charToValue(c);
        value = value * baseX + digit;
    }
    return value;
}

// Convert from decimal to base Y
string fromDecimal(long long decimalValue, int baseY) {
    if (decimalValue == 0) return "0";
    string result;
    while (decimalValue > 0) {
        int remainder = decimalValue % baseY;
        result.push_back(valueToChar(remainder));
        decimalValue /= baseY;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string num;
    int baseX, baseY;
    
    cout << "Enter number: ";
    cin >> num;
    cout << "Enter base X: ";
    cin >> baseX;
    cout << "Enter base Y: ";
    cin >> baseY;

    long long decimalValue = toDecimal(num, baseX);
    string converted = fromDecimal(decimalValue, baseY);

    cout << "In base " << baseY << ": " << converted << endl;
}
