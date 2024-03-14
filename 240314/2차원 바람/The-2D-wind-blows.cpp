#include <iostream>

int n,m,q;
int r1,c1,r2,c2;

int arr[101][101];
int brr[101][101];

void rotate(int r1, int c1, int r2, int c2){
    
    int temp0 = arr[r1][c1];
    int temp1 = arr[r1][c2];
    int temp2 = arr[r2][c2];
    int temp3 = arr[r2][c1];

    for(int i=c2;i>c1;i--){
        brr[r1][i] = arr[r1][i-1];
    }
    
    for(int i=r2;i>r1;i--){
        brr[i][c2]=arr[i-1][c2];
    }
    
    for(int i=c1;i<c2-1;i++){
        brr[r2][i] = arr[r2][i+1];
    }
    
    for(int i=r1;i<r2-1;i++){
        brr[i][c1] = arr[i+1][c1];
    }

}

int main(){
    cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cin>>r1>>c1>>r2>>c2;
    r1 = r1-1; c1-=1;
    r2 = r2-1; c2-=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<brr[i][j]<<" ";
        }
        cout<<"\n";
    }
}