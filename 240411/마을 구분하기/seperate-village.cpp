#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[30][30];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<int> ans;
bool check[30][30];
int now;

void dfs(int a, int b){
    now++;
    for(int i=0;i<4;i++){
        int nx = dx[i]+a;
        int ny = dy[i]+b;
        
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        if(arr[nx][ny]==1&&!check[nx][ny]){
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
            if(arr[i][j]==1&&!check[i][j]){
                now = 0;
                check[i][j] = 1;
                dfs(i,j);
                ans.push_back(now);
                
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout<<ans.size()<<"\n";

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}