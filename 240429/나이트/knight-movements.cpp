#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n;
int r1,c1,r2,c2;

int check[101][101];

queue<pair<int,int>> q;

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            check[i][j]=-1;
    }
}

int main(){
    cin>>n;
    cin>>r1>>c1>>r2>>c2;
    q.push({r1,c1});
    while(!q.empty()){
        auto cur = q.front();
        int x = cur.first;
        int y = cur.second;
        q.pop();
        if(x==r2&&y==c2) {
            cout<<check[x][y];
            exit(0);
        }
        for(int i=0;i<8;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<1||nx>=n||ny<1||ny>=n) continue;
            if(check[nx][ny]!=0) continue;
            q.push({nx,ny});
            check[nx][ny] = check[x][y]+1;
        }
    }
    cout<<-1;
}