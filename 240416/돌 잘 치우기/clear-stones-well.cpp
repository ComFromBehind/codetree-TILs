#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n;
queue<pair<int,int>> q;

int k, m;
vector<pair<int,int>> start;
int a,b;
vector<pair<int,int>> block;

bool check[101][101];
bool check2[10];
int arr[101][101];
int brr[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ans;
vector<int> blocklist;

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) check[i][j]=0;
    }
}

void copy(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) brr[i][j] = arr[i][j];
    }
}

int bfs(){
    int cnt = 0;
    for(int i=0;i<k;i++){
        int s_x = start[i].first;
        int s_y = start[i].second;
        check[s_x][s_y]=1;
        q.push({s_x,s_y});
        cnt++;
    }
    while(!q.empty()){
        auto c = q.front();
        int x = c.first;
        int y = c.second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(check[nx][ny]!=0||brr[nx][ny]!=0) continue;
            check[nx][ny]=1;
            cnt++;
            q.push({nx,ny});
        }
    }
    return cnt;
}

void func(int t){
    if(t==m){
        reset();
        copy();
        for(int i=0;i<m;i++){
            int x = block[blocklist[i]].first;
            int y = block[blocklist[i]].second;
            brr[x][y] = 0;
        }
        int temp = bfs();
        ans = max(temp, ans);
        return;
    }
    for(int i=0;i<block.size();i++){
        if(!check2[i]){
            check2[i]=1;
            blocklist.push_back(i);
            func(t+1);
            check2[i]=0;
            blocklist.pop_back();
        }
    }
}

int main(){
    cin>>n>>k>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            brr[i][j] = arr[i][j];
            if(arr[i][j]==1){
                block.push_back({i,j});
            }
        }
    }

    for(int i=0;i<k;i++){
        cin>>a>>b;
        start.push_back({a-1,b-1});
    }
   
    func(0);
    cout<<ans;
}