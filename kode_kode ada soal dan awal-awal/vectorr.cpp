#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(const vector<int>& L,int v){
    int left = 0;
    int right = L.size() - 1;
    int comparisons = 0;

    while(left <= right && comparisons < 20){
        int mid = left + (right - left)/2;
        comparisons++;

        if(L[mid] == v){
            return true;
        }else if(L[mid]<v){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return false;
}

int main(){
    int n,v;
    cout<<"Masukkan ukuran array (max 1.000.000):";
    cin>>n;

    vector<int> L(n);
    cout<<"Masukkan "<<n<<" angka terurut :\n";
    for(int i = 0;i<n;i++){
        cin>>L[i];
    }

    cout<<"Masukkan nilai yang ingin dicari:";
    cin>>v;

    if(binarySearch(L,v)){
        cout<<"Nilai ditemukan.\n";
    }else{
        cout<<"Nilai tidak ditemukan (atau melebihi 20 perbadingan.) \n";
    }

    return 0;
}
