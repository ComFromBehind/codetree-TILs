#include <iostream>
using namespace std;

int n,m,t;
int arr[21][21];
int brr[21][21];
int crr[21][21];
int r,c;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            crr[i][j] = 0;
    }
}

void move(int row,int col){
    int max_idx = 0;
    int max_val = 0;
    
    for(int i=0;i<4;i++){
        int nx = dx[i]+row;
        int ny = dy[i]+col;
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        if(max_val<arr[nx][ny]){
            max_idx = i;
            max_val = arr[nx][ny];
        }
    }

    crr[row+dx[max_idx]][col+dy[max_idx]]++;
}

void crash_check(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){           
            if(crr[i][j]>1) crr[i][j] = 0;
        }
    }
}

void copy(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            brr[i][j] = crr[i][j];
        }
    }
}

int main(){
    cin>>n>>m>>t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    
    while(m--){
        cin>>r>>c;
        
        brr[r-1][c-1] = 1;
    }
    while(t--){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(brr[i][j]!=0){
                    move(i,j);

                }
            }
        }

        crash_check();
        copy();
        reset();

        
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(brr[i][j]==1) ans++; 
        }
    }
    cout<<ans;
}