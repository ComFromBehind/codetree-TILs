#include <iostream>
using namespace std;
int n, m, r,c;

int arr[101][101];
int ans;

int garo[4] = {1,3,6,4};  //위 오른쪽, 아래, 왼쪽 순
int sero[4] = {1,2,6,5}; //위 앞 아래 뒤 순

int temp[4] = {0,0,0,0};


char mov;

int left(){
    int temp = garo[0];
    for(int i=0;i<3;i++){
        garo[i] = garo[i+1];
    }
    garo[3] = temp;
    sero[0] = garo[0];
    sero[2] = garo[2];
    //sero도 바뀜..1->3, 6->4
    return garo[2]; 
}

int right(){
    int temp = garo[3];
    for(int i=3;i>=1;i--){
        garo[i] = garo[i-1];
    }
    garo[0] = temp;

    sero[0] = garo[0];
    sero[2] = garo[2];
    return garo[2];

}

int up(){
    int temp = sero[0];
    for(int i=0;i<=2;i++){
        sero[i] = sero[i+1];
    }
    sero[3] = temp;
    garo[0] = sero[0];
    garo[2] = sero[2];
    return sero[2];
}

int down(){
    int temp = sero[3];
    for(int i=3;i>=1;i--){
        sero[i] = sero[i-1];
    }
    sero[0] = temp;
    garo[0] = sero[0];

    garo[2] = sero[2];
    
    return sero[2];
}


int main() {
    
    cin>>n>>m>>r>>c;
    r = r-1;
    c = c-1;

    arr[r][c] = garo[2];


    for(int i=0;i<m;i++){
        cin>>mov;

        if(mov=='L'){
            if(c-1<0) continue;
            c = c-1;
            arr[r][c] = left();
        }
        else if(mov=='R')
        {
            if(c+1>=n) continue;
            c = c+1;
            arr[r][c]= right();
        }
        else if(mov=='U'){
            if(r-1<0) continue;
            r = r-1;
            arr[r][c] = up();
        }
        else if(mov=='D'){
            if(r+1>=n) continue;
            r = r+1;
            arr[r][c] = down();
        }
        
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+=arr[i][j];
        }
    }
    cout<<ans;

    return 0;
}