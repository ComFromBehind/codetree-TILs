#include <iostream>
using namespace std;

int ans;

int n,m;
int arr[201][201];

void l_block(int i, int j){
    if(i+1>=n||j+1>=m) return;

    int param = arr[i][j]+arr[i+1][j]+arr[i][j+1]+arr[i+1][j+1];
    
    int a1 = param-arr[i][j];
    ans = max(ans, a1);
    int a2 = param-arr[i+1][j];
    ans = max(ans, a2);
    int a3 = param-arr[i][j+1];
    ans = max(ans, a3);
    int a4 = param-arr[i+1][j+1];
    ans = max(ans,a4);

}

void sero(int i,int j){
    if(i+2>=n) return;
    int a1 = arr[i][j]+arr[i+1][j]+arr[i+2][j];
    ans = max(a1, ans);
}

void garo(int i, int j){
    if(j+2>=m) return;
    int a1 = arr[i][j]+arr[i][j+1]+arr[i][j+2];
    ans = max(a1, ans);
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            garo(i,j);
            sero(i,j);
            l_block(i,j);
        }
    }
    
    cout<<ans;


}