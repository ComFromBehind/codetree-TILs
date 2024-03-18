#include <iostream>
#include <vector>
using namespace std;

int n, m,k;

int arr[101][101];
int brr[101][101];


void bomb(){
    for(int i=0;i<n;i++){
        vector<int> v;
        
        v.push_back(0);
        for(int j=1;j<n;j++){
            if(arr[j][i]!=arr[j-1][i]&&arr[j-1][i]!=0)
                v.push_back(j-1);
        }
        v.push_back(n-1);

        for(int j=1;j<v.size();j++){
            if(v[j]-v[j-1]>=m-1){
                
                for(int k=v[j-1]+1;k<=v[j];k++){
                    arr[k][i] =0;
                }
            }
            
        }
        
    }
}

void rotate(){ // 시계방향으로 회전.. 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            brr[i][j] = arr[n-1-j][i];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = brr[i][j];
        }
    }

}

void fall(){
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=n-1;j>=0;j--){
            if(arr[j][i]!=0)
                v.push_back(arr[j][i]);
        }

        int sz = v.size();
        for(int j=0;j<sz;j++){
            arr[n-1-j][i] = v[j];
        }
        for(int j=sz;j<n;j++){
            arr[n-1-j][i] = 0;
        }
    }
}

int main(){
    cin>>n>>m>>k;
    
    if(m==1){
        cout<<0;
        exit(0);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }

    while(k--){
        
        bomb();
        fall();
        rotate();
        fall();
        
    }
    
    int ans = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0)
                ans++;
        }
    }
    cout<<ans;
}