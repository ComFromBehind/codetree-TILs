#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int n,k;

int arr[101][101];
bool check[101][101];

int dx[4] ={1,0,-1,0};
int dy[4] ={0,1,0,-1};

int st_r, st_c;
int tmp;
queue<pair<int,int>> q;
int now;
int now_r, now_c;

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            check[i][j]=0;
    }
}

void bfs(){
    while(!q.empty()){
        auto c = q.front();
        int x = c.first;
        int y = c.second;
       
        if(arr[x][y]>tmp&&arr[x][y]!=now) {
            tmp = arr[x][y];
            now_r = x;
            now_c = y;
          
        }
        else if (arr[x][y]==tmp&&arr[x][y]!=now){
            if(x<now_r){
                now_r = x;
                now_c = y;
            }
            else if(x==now_r&&y<now_c){
                now_r = x;
                now_c = y;
            }
            
        }
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(arr[nx][ny]>=now||check[nx][ny]) continue;
            check[nx][ny] = 1;
            q.push({nx,ny});     
        }
    }
}

int main(){
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    cin>>st_r>>st_c;
    st_r = st_r -1;
    st_c = st_c -1;


    int flag=0; int fix_x=0; int fix_y = 0;
    while(k--&&flag==0 ){
        
        reset();
        tmp = 0;
        
        q.push({st_r, st_c});
        check[st_r][st_c]=1;
        now = arr[st_r][st_c];
       
        fix_x = st_r; fix_y = st_c;
        bfs();
        
        st_r = now_r;
        st_c = now_c;
        if(now_r ==fix_x&&now_c ==fix_y) flag=1;
        
      
    }
    cout<<st_r+1<<" "<<st_c+1;
}