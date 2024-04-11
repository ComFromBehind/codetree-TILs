#include <iostream>
#include <vector>
using namespace std;

int ans;
int n,m;

int arr[1001][1001];
bool check[1001];


void dfs(int k){
    for(int i=1;i<=n;i++){
        if(arr[k][i]==1&&!check[i]){
            ans++;
            check[i] = 1;
            dfs(i);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m;i++ ){
        int tmp1, tmp2;
        cin>>tmp1>>tmp2;

        arr[tmp1][tmp2] = 1;
        arr[tmp2][tmp1] = 1;      
    }
    check[1]  =1;
    dfs(1);
    
    cout<<ans;
}