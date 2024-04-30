#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int n;
int h,m;

int arr[101][101];
int check[101][101];
int ans[101][101];
int dx[4] = { 1,0,-1,0};
int dy[4] ={0,1,0,-1};

vector<pair<int,int>> v;
queue<pair<int,int>> q;
void clear(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            check[i][j] = -1;
        }
    }
}

int main(){
    cin>>n>>h>>m;
    clear();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==3){
                check[i][j] = 0;
                q.push({i,j});
            }
        }
    }   
    
    while(!q.empty()){
        auto cur = q.front();
        int x = cur.first;
        int y = cur.second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+ dx[i];
            int ny = y + dy[i];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(check[nx][ny]!=-1) continue;
            if(arr[nx][ny]==1) continue;
            q.push({nx,ny});
            check[nx][ny] = check[x][y] + 1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==2) {
                if(check[i][j]!=0) cout<<check[i][j]<<" ";
                else cout<<-1<<" ";
            }
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }

    

}