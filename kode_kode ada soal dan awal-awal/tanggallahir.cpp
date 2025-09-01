#include <iostream>

using namespace std;

int main(){
    int d;
    int m;
    int y;
    int arr[100][3],u[100];
    int p;
    cout<<"banyak orang";
    cin>>p;

    for(int i = 0;i<p;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    
    for(int i = 0;i<p;i++){
        if(arr[i][2]<2025){
            if((arr[i][0] < 8 && arr[i][1] < 8) || arr[i][1] < 8 ){
                u[i]=2025 - arr[i][2]-1;
                }else{
                u[i]=2025 - arr[i][2];
            }
        }
    }

    for(int i = 0;i<p;i++){
        for(int j =0;j<p-i-1;j++){
            if(u[j] > u[j+1]){
                    int temp = u[j];
                    u[j] = u[j+1];
                    u[j+1] = temp;  
            }
        }
    }

    for(int i = 0;i<p;i++){
        for(int j =0;j<p-i-1;j++){
            if(u[j] > u[j+1]){
                    int temp = arr[j][0];
                    arr[j][0] =arr[j+1][0];
                    u[j+1] = arr[j][0];  
            }
        }
    }

    for(int i = 0;i<p;i++){
        for(int j =0;j<p-i-1;j++){
            if(u[j] > u[j+1]){
                    int temp = arr[j][1];
                    arr[j][0] =arr[j+1][1];
                    u[j+1] = arr[j][1];   
            }
        }
    }

    for(int i = 0;i<p;i++){
        cout<<u[i]<<endl;
    }
    cout<<"---"<<endl;;
    for(int i = 0;i<p;i++){
        cout<<arr[i][0]<<endl;
    }
    cout<<"---"<<endl;;
    for(int i = 0;i<p;i++){
        cout<<arr[i][1]<<endl;
    }
}
