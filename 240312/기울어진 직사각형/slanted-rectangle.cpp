#include <iostream>
using namespace std;

int n;
int arr[21][21];
int ans;

void func(int r, int c, int left, int right){
    if(c+right>=n) return;
    if(c-left<0) return;
    if(r+left+right>=n) return;

    int temp = 0;
    
    for(int i=1;i<=left;i++){
        temp+=arr[r+i][c-i];
        temp+=arr[r+right+left-i][c-left+right+i];
    }
    for(int i=1;i<=right;i++){
        temp+=arr[r+i+left][c-left+i];
        temp+=arr[r+right-i][c+right-i];
    }

    ans = max(ans, temp);
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];

        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=1;k<n;k++){
                for(int l=1;l<n;l++){
                    func(i,j,k,l);
                }
            }
        }
    }

    cout<<ans;
    

}