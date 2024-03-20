#include <iostream>
using namespace std;

int n, m, k;

int arr[101][101];
int brr[101][101];

void setting(int row, int m, int k){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            brr[i][j] = arr[i][j];
        }
    }
    
    for(int i=k-1;i<k-1+m;i++){
        brr[row][i] = 1;
    }
}

int falling(){
    int t = 0;
    for(int i=0;i<n;i++){
        for(int j=k-1;j<k-1+m;j++){
            if(i==n-1 || brr[i+1][j]!=0){
                t = i;
                j = n;
                i = n;
            }
        }
    }
    return t;    
}

int main() {
    
    cin>>n>>m>>k;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            brr[i][j] = arr[i][j];
        }
    }

    setting(0,m,k);
    
    
    int row = falling();
    setting(row, m,k);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<brr[i][j]<<" ";
        }
        cout<<"\n";
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}