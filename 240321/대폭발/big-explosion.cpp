#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;

int n;
int m;
int r,c;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<pair<int,int>> v;
vector<pair<int,int>> w;

int flag=0; //v가 폭탄 근원지일 경우 flag=0, w가 근원지이면 flag=1;

int arr[101][101];


void bomb(int t, int r, int c, int now){
    if(now==t+1) return;
    
    if(flag==0){
        
        if(now==0) {
            arr[r][c] = 1;
            w.push_back({r,c});
            flag=1;
            
            
        }
        else{
        for(int i=0;i<v.size();i++){
            for(int j=0;j<4;j++){
                

                
                int nx = v[i].first+pow(2,now-1)*dx[j];
                int ny = v[i].second+pow(2,now-1)*dy[j];

                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if(arr[nx][ny]!=0) continue;
                arr[nx][ny] = 1;
                w.push_back({nx,ny});
            }
        }
        flag=1;
        }
    }
    else{
        
        for(int i=0;i<w.size();i++){
            for(int j=0;j<4;j++){
                int nx = w[i].first+pow(2,now-1)*dx[j];
                int ny = w[i].second+pow(2,now-1)*dy[j];

                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if(arr[nx][ny]!=0) continue;
                arr[nx][ny] = 1;
                v.push_back({nx,ny});
            }
        }
        flag=0;
    }

    
    
    bomb(t,r,c,now+1);
    
}

int main() {
    
    cin>>n;
    cin>>m>>r>>c;

    r = r-1;
    c = c-1;

    v.push_back({r,c});
    bomb(m,r,c,0);
    
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0) ans++;
        }
    }
    cout<<ans;
}