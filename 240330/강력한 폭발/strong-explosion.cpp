#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
int arr[21][21];
int brr[21][21];
vector<pair<int,int>> v;
vector<int> bomb_num;
int ans;

int dx[3][5]={
    {-2,-1,0,1,2}, {-1,0,0,0,1},{-1,-1,0,1,1}
};
int dy[3][5]={
    {0,0,0,0,0},{0,-1,0,1,0},{-1,1,0,-1,1}
};

void brr_reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            brr[i][j] = 0;
    }
}

void bomb_counting(){
    brr_reset();
    int temp = 0;
    for(int i=0;i<bomb_num.size();i++){
        int row = v[i].first;
        int col = v[i].second;
        int num = bomb_num[i];

        for(int j=0;j<5;j++){
            int nx = row+dx[num][j];
            int ny = col+dy[num][j];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(brr[nx][ny]!=0) continue;
            brr[nx][ny]=1;
            temp++;
        }
    }
    ans = max(temp, ans);   
}

void func(int k){
    if(k==v.size()){
        bomb_counting();
       
        return;
    }
    for(int i=0;i<3;i++){
        bomb_num.push_back(i);
        func(k+1);
        bomb_num.pop_back();
    }
}

int main() {
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1)
                v.push_back({i,j});
        }
    }

    func(0);

    cout<<ans;
    return 0;
}