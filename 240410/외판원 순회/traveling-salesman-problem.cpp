#include <iostream>
using namespace std;

int n;
int arr[11][11];

bool check[11];

int ans= 1e9;

void func(int k,int prev,int cnt){
    if(k==n-1){
        if((cnt+arr[prev][0]) < ans) ans = (cnt+arr[prev][0]);
        return;
    }

    for(int i=1;i<n;i++){
        
        if(!check[i]&&arr[prev][i]!=0){
            check[i] = 1;
            
            func(k+1, i ,cnt+arr[prev][i]);
            
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
    check[0] = 1;
    func(0,0,0);
    cout<<ans;
}