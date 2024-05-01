#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pair<int,int>> q;

int n,k;

int arr[101][101];
int check[101][101];

int main(){
    cin>>n>>k;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            check[i][j]=-1;
            if(arr[i][j]==1){
                check[i][j] = -2;
            }
            if(arr[i][j]==2){
                q.push({i,j});
                check[i][j]=0;
            }
        }
    }
    
    while(!q.empty()){
        auto c = q.front();
        q.pop();
        int x = c.first;
        int y = c.second;
        for(int i=0;i<4;i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(check[nx][ny]>-1) continue;
            if(arr[nx][ny]==0||arr[nx][ny]==2) continue;
            check[nx][ny] = check[x][y]+1;
            q.push({nx,ny});
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<check[i][j]<<" ";
        }
        cout<<"\n";
    }
}