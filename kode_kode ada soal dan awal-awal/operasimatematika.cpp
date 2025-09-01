#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

// Prioritas operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Konversi infix ke postfix (Reverse Polish Notation)
vector<string> infixToPostfix(string expr) {
    stack<char> ops;
    vector<string> output;
    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == ' ') continue;

        // Jika angka (bisa lebih dari 1 digit / desimal)
        if (isdigit(expr[i]) || expr[i] == '.') {
            string num;
            while (i < expr.size() && (isdigit(expr[i]) || expr[i] == '.')) {
                num += expr[i++];
            }
            output.push_back(num);
            i--;
        }
        // Jika '('
        else if (expr[i] == '(') {
            ops.push(expr[i]);
        }
        // Jika ')'
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.pop(); // hapus '('
        }
        // Jika operator
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(expr[i]);
        }
    }

    // Ambil sisa operator
    while (!ops.empty()) {
        output.push_back(string(1, ops.top()));
        ops.pop();
    }
    return output;
}

// Evaluasi postfix
double evaluatePostfix(vector<string> postfix) {
    stack<double> st;
    for (string token : postfix) {
        if (token.size() > 1 || isdigit(token[0])) {
            st.push(stod(token)); // angka
        } else {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            switch (token[0]) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

int main() {
    string expr = "3 + (8 - 7.5) * 10 / 5 - (2 + 5 * 7)";
    
    vector<string> postfix = infixToPostfix(expr);
    double hasil = evaluatePostfix(postfix);

    cout << fixed << setprecision(1) << hasil << endl; // format desimal 1 digit
}
