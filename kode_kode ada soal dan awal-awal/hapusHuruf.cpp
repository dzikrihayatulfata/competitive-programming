#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "line: a70 and z72 will be replaced, aa24 and a872 will not";

    regex pattern("([a-z][0-9]{2})");

    string result = regex_replace(s,pattern,"***");

    cout<<result<<endl;

}