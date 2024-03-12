#include <iostream>
using namespace std;

int n,m;
int arr[21][21];

int ans=-1;

int func(int a, int b,int c, int d){
   if(a+c>n||b+d>m) return -1;
   for(int i=0;i<c;i++){
        for(int j=0;j<d;j++){
            if(arr[a+i][b+j]<0) return -1;
        }
   }
   return c*d;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=m;l++){
                    ans = max(ans, func(i,j,k,l));
                }
            }
        }
    }
    cout<<ans;
}