#include <iostream>
using namespace std;



int n,t;
int arr[2][201];

void rotate(){
    int temp = arr[0][n-1];
    for(int i=n-1;i>0;i--){
        arr[0][i] = arr[0][i-1];
    }
    int temp2 = arr[1][n-1];
    for(int i=n-1;i>0;i--){
        arr[1][i] = arr[1][i-1];
    }
    arr[1][0] = temp;
    arr[0][0] = temp2;
}


int main(){
    cin>>n>>t;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<t;i++){
        rotate();
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}