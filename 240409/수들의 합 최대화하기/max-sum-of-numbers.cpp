#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int arr[11][11];
int ans;
bool check[11];
void func(int k, int now){
    if(k==n){
        if(now>ans){
            ans = now;
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(!check[i]){
            check[i]=1;
            func(k+1, now+arr[k][i]);
            check[i]=0;
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    func(0, 0);

    cout<<ans;
}