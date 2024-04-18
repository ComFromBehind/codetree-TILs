#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n,m;

int arr[101][101];
int check[101][101];

int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1};

queue<pair<int,int>> q;

void bfs(){
    
    while(!q.empty()){
        auto c = q.front();
        q.pop();
        int x = c.first;
        int y = c.second;
    
        for(int i=0;i<4;i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(check[nx][ny]!=-1||arr[nx][ny]!=1) continue;
            check[nx][ny] = check[x][y]+1;
            q.push({nx,ny});
        }
    }

}

int main(){
    
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){            
            cin>>arr[i][j];
            check[i][j] = -1;
        }
    }

    check[0][0] = 0;
    q.push({0,0});
    bfs();

    cout<<check[n-1][m-1];

}