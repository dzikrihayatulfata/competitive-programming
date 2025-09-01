#include<iostream>

using namespace std;

int main(){
    int t;
    int m;
    int y;
    int j;
    int k;
    int h;
    const char* bulan[12] = {
        "januari","febuari","maret", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    cout<<"Masukkan tanggal";
    cin>>t;
    cout<<"Masukkan bulan";
    cin>>m;
    cout<<"Masukkan tahun";
    cin>>y;

    k = y%100;
    j = y/100;

    h = (t+(13 *(m+1))/5+k+(k/4)+(j/4)+5*j)%7;

    switch(h){
        case 0: cout<<"senin";
        break;
        case 1: cout<<"selasa";
        break;
        case 2: cout<<"rabu";
        break;
        case 3: cout<<"kamis";
        break;
        case 4: cout<<"jumat";
        break;
        case 5: cout<<"saptu";
        break;
        case 6: cout<<"minggu";
        break;
    };
}