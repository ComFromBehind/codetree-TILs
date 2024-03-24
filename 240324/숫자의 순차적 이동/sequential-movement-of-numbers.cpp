#include <iostream>
using namespace std;


int n,m;
int arr[101][101];

int dx[8] = {-1,-1,-1,0,1,1,1,0}; //좌상 부터 시작해서 시계방향으로 돔.
int dy[8] = {-1,0,1,1,1,0,-1,-1};

int search(int row, int col){
    int max_idx = -1;
    int max_val = 0;
    
    for(int i=0;i<8;i++){
        int nx = dx[i]+row;
        int ny = dy[i]+col;
        
        
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        if(max_val < arr[nx][ny]){
            max_idx = i;
            max_val = arr[nx][ny];
        }
        
    }

    
    return max_idx;
}

void change(int row, int col, int k){
    int temp = arr[row][col];

    arr[row][col] = arr[dx[k]+row][dy[k]+col];
    arr[dx[k]+row][dy[k]+col] = temp;
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main() {
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    while(m--){
        int t = 1;
        while(t<=n*n){
            int find_x = 0;
            int find_y = 0;

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(arr[i][j] == t)
                    {
                        find_x = i;
                        find_y = j;
                        i = n; j=n;
                    }
                }
            }

            int k =search(find_x, find_y);
            change(find_x, find_y,k);
            

            t++;
        }
        

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}