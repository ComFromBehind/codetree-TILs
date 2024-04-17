#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

bool check[10][10];
bool check2[10][10];
int arr[10][10];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<pair<int,int>> citylist;
int ans;

int n, k , u, d;
queue<pair<int,int>> q;

void reset1(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++) check[i][j]=0;
    }
}

void reset2(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++) check2[i][j]=0;
    }
}

bool isitok(int aa, int bb, int cc, int dd){
    
    int cal = abs(arr[aa][bb]- arr[cc][dd]);

    if( cal <= u && cal >= d) {
        return true;
    }
    
    return false;

}

int bfs(){
    
    int temp = 0;
    
    while(!q.empty()){
        temp++;
        auto c = q.front();
        int x = c.first;
        int y = c.second;

        q.pop();

        for(int i=0;i<4;i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
    
            if(check[nx][ny]!=0) continue;
           
            if(!isitok(nx,ny,x,y)) continue;
            
            check[nx][ny] = 1;
           
            q.push({nx,ny});
        }
    }
    return temp;
}

void func(int t){
    
    if(t==k){
        
        reset1();
        
        for(int i=0;i<citylist.size();i++){
            q.push({citylist[i].first, citylist[i].second});
            check[citylist[i].first][citylist[i].second]=1;
        }
    
        int temp_ans = bfs();
        ans = max(ans , temp_ans);
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            check2[i][j] = 1;
            citylist.push_back({i,j});
            func(t+1);
            check2[i][j] = 0;
            citylist.pop_back();
        }

    }
}

int main(){
    
    cin>>n>>k>>d>>u;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    func(0);

    cout<<ans;

}