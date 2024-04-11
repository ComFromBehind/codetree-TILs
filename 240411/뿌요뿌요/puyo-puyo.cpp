#include <iostream>
using namespace std;

int n;

int ans_cnt;
int ans_max;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool check[101][101];
int arr[101][101];

int param;
int temp = 0;
void dfs(int a, int b){
    temp++;
    for(int i=0;i<4;i++){
        int nx = dx[i]+a;
        int ny = dy[i]+b;
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        if(arr[nx][ny]==param&&check[nx][ny]==0){
            check[nx][ny] = 1;
            dfs(nx,ny);
        }
    }
}

int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!check[i][j]){
                temp = 0;
                check[i][j]=1;
                param = arr[i][j];
                dfs(i,j);
                if(temp>=4) ans_cnt++;
                ans_max = max(ans_max, temp);
            }
        }
    }

    cout<<ans_cnt<<" "<<ans_max;
}