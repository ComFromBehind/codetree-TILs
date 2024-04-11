#include <iostream>
#include <vector>
using namespace std;

int k, ans;

int n, m;

int arr[51][51];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int cnt;
bool check[51][51];



void lowering_setting(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if(arr[i][j]!=0) arr[i][j]--;
            check[i][j] = 0;
        }
    }
    cnt = 0;
}


void dfs(int a, int b){
    for(int i=0;i<4;i++){
        int nx = dx[i] + a;
        int ny = dy[i] + b;
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        if(arr[nx][ny]!=0&&!check[nx][ny]){
            check[nx][ny] = 1;
            dfs(nx,ny);
        }
    }
}

void all_dfs(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!check[i][j]&&arr[i][j]!=0){
                cnt++;
                dfs(i,j);
            }
        }
    }
}

int main(){
    
    int max_height = 0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin>>arr[i][j]; 
            if(arr[i][j]>max_height) max_height = arr[i][j];
        } 
    }
    k=1;
    int ans_k = 1;
    while(max_height--){
        
        lowering_setting();
        
        all_dfs();
        
        if(cnt>ans){
            ans = cnt;
            ans_k = k;
        }
        k++;
    }
    cout<<ans_k<<" "<<ans;

    
    

}