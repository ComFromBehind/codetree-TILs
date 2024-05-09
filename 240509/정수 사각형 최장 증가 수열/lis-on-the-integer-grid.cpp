#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int n;

int max_val = 1;

int arr[501][501];
int dp[501][501];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void setup(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            dp[i][j] = -1;
    }
}

int getdp(int i,int j){
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    vector<pair<int,int>> v;
    int cnt = 0;
    for(int k=0;k<4;k++){
        int nx = dx[k]+i;
        int ny = dy[k]+j;
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        if(arr[nx][ny]<=arr[i][j]) continue;
        cnt++;
        v.push_back({nx,ny});
    }
    if(cnt==0) {
        dp[i][j] = 1;
        return dp[i][j];
    }
    int temp_max = -2;
    for(int k=0;k<v.size();k++){
        int a = getdp(v[k].first,v[k].second);
        if(temp_max<a) temp_max = a;

    }
    
    dp[i][j] = temp_max+1;
    if(dp[i][j]>max_val) max_val = dp[i][j];
    return dp[i][j];

}

int main(){
    cin>>n;
    setup();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            getdp(i,j);
        }
    }

    cout<<max_val;
}