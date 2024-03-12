#include <iostream>
using namespace std;

int n,m;
int ans=-10000000;
bool check[6][6];
int arr[6][6];

void reset(int a,int b,int c,int d){
    for(int i=0;i<c;i++){
        for(int j=0;j<d;j++)
            check[a+i][b+j]=0;
    }
}

int func(int a,int b, int c, int d){
    if(a+c>=n||b+d>=m) return -100000;
    int temp = 0;
    for(int i=0;i<=c;i++){
        for(int j=0;j<=d;j++){
            if(check[i+a][b+j]) return -100000;
            check[i+a][b+j] = 1;
            temp+=arr[i+a][b+j];
            
        }
    }
    
    return temp;
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
            for(int k=0;k<n;k++){
                for(int l=0;l<m;l++){
                    int pre = func(i,j,k,l);
                    for(int t=0;t<n;t++){
                        for(int p=0;p<m;p++){
                            for(int q=0;q<n;q++){
                                for(int r=0;r<m;r++){
                                    int now = func(t,p,q,r);
                                    
                                    if(now==-100000) continue;
                                    else{
                                        ans= max(ans, pre+now);
                                        
                                        reset(t,p,q,r);
                                    }
                                    
                                }
                            }
                        }
                    }
                    reset(i,j,k,l);
                }
            }
        }
    }
    cout<<ans;
}