
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    const int MAX = 10000;
    char T[MAX], P[MAX];
    int n, m;

    // Input Teks dan Pola
    cout << "Enter text T: ";
    cin.getline(T, MAX);
    cout << "Enter pattern P: ";
    cin.getline(P, MAX);

    n = strlen(T);
    m = strlen(P);

    for (int i = 0;i<n;i++){
        bool found = true;
        for(int j = 0;j<m && found;j++)
            if( i + j >= n || P[j] != T[i+j])found=false;
        if(found) printf("P is found at index %d in T\n",i);
    }
    return 0;
}