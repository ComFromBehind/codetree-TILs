#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int arr[5][5];
int brr[5][5];

int r,c;
int ans;

vector<pair<int,int>>  v;

void search(int row, int col){
    int dir = brr[row][col];
    int x_dir = dx[dir-1];
    int y_dir = dy[dir-1];

    int temp_row = row;
    int temp_col = col;


    while(temp_row+x_dir>=0&&temp_row+x_dir<n&&temp_col+y_dir>=0&&temp_col+y_dir<n){
        if(arr[row][col]<arr[temp_row+x_dir][temp_col+y_dir]){
            v.push_back({temp_row+x_dir, temp_col+y_dir});
        }
        temp_row = temp_row+x_dir;
        temp_col = temp_col+y_dir;
    }
    
}

void func(int cnt, int row, int col){
    //종료 조건
    
    v.clear();
    search(row, col); //갈 수 있는 리스트 셋업..
    vector<pair<int,int>> w = v;
    
    if(v.empty()){

        ans = max(ans, cnt);
        return;
    }
    for(int i=0;i<w.size();i++){
        func(cnt+1, w[i].first, w[i].second);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>brr[i][j];
    }

    cin>>r>>c; // start point;

    func(0, r-1, c-1);

    cout<<ans;

}