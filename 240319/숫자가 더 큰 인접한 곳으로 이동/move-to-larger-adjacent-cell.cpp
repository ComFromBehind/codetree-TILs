#include <iostream>
using namespace std;

int n, r, c;
int arr[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
    cin>>n>>r>>c;
    
    r = r-1;
    c = c-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    int flag = 0;
    int row = r;
    int col = c;
    cout<<arr[row][col]<<" ";
    while(flag==0){
        flag=1;
        for(int i=0;i<4;i++){
            int nx = dx[i]+row;
            int ny = dy[i]+col;
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(arr[nx][ny]>arr[row][col]){
                cout<<arr[nx][ny]<<" ";
                row = nx;
                col = ny;
                flag=0;
                break;
            }
        }
    }
}