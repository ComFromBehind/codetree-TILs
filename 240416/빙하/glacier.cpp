#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[201][201];
bool check[201][201];
bool check2[201][201];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<pair<int,int>> next_ice;

int count;
int n,m;
queue<pair<int,int>> q;
queue<pair<int,int>> q2;
int now = 0;

int next_x;
int next_y;

void bfs(){
    while(!q.empty()){
        auto c = q.front();
        int x = c.first;
        int y = c.second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(check[nx][ny]!=0) continue;
            if(arr[nx][ny]!=0&&check2[nx][ny]==0) {
                q2.push({nx,ny}); 
          
                check2[nx][ny] =1;
                continue;
            } 
            if(arr[nx][ny]!=0&&check2[nx][ny]!=0) continue;
            check[nx][ny] = 1;
            q.push({nx,ny});
            
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }
    check[0][0]= 1;
    q.push({0,0});
    while(1){
      
        bfs();
        now++;
        if(q2.empty()) break;
        count = 0;
        while(!q2.empty()){
            auto c = q2.front();
            int x = c.first;
            int y = c.second;
            next_x = x;
            next_y = y;
            q2.pop();
            
            count++;
            arr[x][y] = 0;
        }
        q.push({next_x,next_y});
        
    }
    cout<<now-1<<" "<<count;

}