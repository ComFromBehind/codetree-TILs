#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n;
int m;
int arr[101][101];


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool check[101][101];
queue<pair<int,int>> q;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }  
    check[0][0] = 1;
    q.push({0,0});

    while(!q.empty()){
        auto c = q.front();
        
        int x = c.first;
        int y = c.second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(check[nx][ny]!=0||arr[nx][ny]==0) continue;
            check[nx][ny] = 1;
            q.push({nx,ny});
            if(nx==n-1&&ny==m-1){
                cout<<1;
                exit(0);
            }
        }
    }
    cout<<0;
}