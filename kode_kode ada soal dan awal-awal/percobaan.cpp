#include <iostream>
#include <iomanip>
using namespace std;

double pi = 3.141592653589793;
int N;
int main(){
    cin>>N;
    cout<<fixed<<setprecision(N)<<pi<<endl;
}