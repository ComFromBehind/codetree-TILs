#include <iostream>
using namespace std;

int n;
int arr[101][101];
int brr[101][101];
int ans=0;
int dir = 0;

int dx[4] = {1,0,-1,0}; //아래, 왼쪽, 위, 오른쪽 
                        //1을 만나면 0<=>1, 2<=>3이 각각 자기네 집합애들끼리로 대응 
int dy[4] = {0,-1,0,1}; // 2는 3-i 관계

void rotate(){ //n개의 열에 대해 수행 후 시계방향으로 90도 회전시켜 다시 n개의 열에 대해 수행할 예정..
    //1과 2가 어떻게 바뀌는지 알아놓아야 함.
    //회전 시 1은 2가 되고 2는 1이 됨!

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = brr[n-j-1][i];
            if(arr[i][j]==1) arr[i][j] = 2;
            else if(arr[i][j]==2) arr[i][j] = 1; 
        }
    }

}

void copy(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            brr[i][j]= arr[i][j];
        }
    }
}

void dir_translate(int num){ // 1을 만낫냐 2를 만낫냐에 따라 방향을 바꿔줌..
    if(num==1){
        if(dir==0) dir=1;
        else if(dir==1) dir=0;
        else if(dir==2) dir=3;
        else if(dir==3) dir=2;
    }
    else if(num==2){
        dir = 3-dir;
    }
    else
        return;

}

void falling(){
    int tmp= 0;
    for(int i=0;i<n;i++){
        tmp = 0;
        int col = i;
        int row = 0;
        dir = 0;
        while(col>=0&&col<n&&row>=0&&row<n){
            
            tmp++;
            dir_translate(arr[row][col]);

            int nx = row+dx[dir];
            int ny = col+dy[dir];   
            
            row = nx;
            col = ny;
            
        }
        ans = max(ans, tmp+1);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    
    
    for(int i=0;i<4;i++){
        copy();
        falling();
        rotate();
    }
    
    cout<<ans;

}