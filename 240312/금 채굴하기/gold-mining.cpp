#include <iostream>
using namespace std;

int n,m;
int payoff; // 순간 들어가는 비용
int ans; //금의 개수
int arr[21][21];

void searching(int k,int a, int b){
    int temp=0;
    
    while(k!=-1){
        int temp = 0;
        for(int i=-k;i<=k;i++){
            for(int j=-k;j<=k;j++){
                if(a+i<0||a+i>=n||b+j<0||b+j>=n) continue;
                if(i+j<=k&&i+j>=-k&&i-j<=k&&i-j>=-k) temp+=arr[a+i][b+j];

            }
        }
        payoff = k*k+(k+1)*(k+1);
        if(payoff< m*temp){
            ans = max(ans, temp);
        }
        k--;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            searching(n,i,j);
        }
    }

    cout<<ans;



    

}