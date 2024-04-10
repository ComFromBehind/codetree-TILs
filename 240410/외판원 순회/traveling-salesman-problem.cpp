#include <iostream>
using namespace std;

int n;
int arr[11][11];

bool check[11];

int ans= 1e9;

void func(int k, int cnt){
    if(k==n){
        if(cnt < ans) ans = cnt;
        return;
    }
    for(int i=0;i<n;i++){
        if(k!=i&&!check[i]){
            check[i] = 1;
            func(k+1, cnt+arr[k][i]);
            check[i] = 0;
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>> arr[i][j];
        }
    }
    
    func(0,0);
    cout<<ans;
}