#include <iostream>
#include <vector>
using namespace std;

int n, m;

int dx[2] ={1,0};
int dy[2] ={0,1};
bool check[101][101];

int arr[101][101];
int flag=0;

void dfs(int a, int b){
    if(a==n-1&&b==m-1){
        flag=1;
        cout<<1;
        exit(0);
    }
    
    for(int i=0;i<2;i++){
        int nx = a+dx[i];
        int ny = b+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        if(check[nx][ny]==0&&arr[nx][ny]==1){
            
            check[nx][ny] = 1;
            dfs(nx,ny);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    dfs(0,0);

    cout<<0;

}