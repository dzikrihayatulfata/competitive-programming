#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s = "abcd";
    int count = 0;

    do{
        cout<<s<<endl;
        count++;
    }while(next_permutation(s.begin(),s.end()));

    cout<<"Total permutation :"<<count<<endl;
    return 0;
}