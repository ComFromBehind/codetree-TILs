#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[101][101][101];
int arr[101][101];

void initialize(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=1;k<=100;k++){
                dp[i][j][k] = 1e9;
            }
        }
    }
    dp[0][0][arr[0][0]] = arr[0][0];

    for(int i=1;i<n;i++){
        for(int k=1;k<=100;k++){
            dp[i][0][min(k,arr[i][0])] = min(
                dp[i][0][min(k, arr[i][0])],
                max(dp[i-1][0][k], arr[i][0])
            );
            
        }
    }
    for(int i=1;i<n;i++){
        for(int k=1;k<=100;k++){
            dp[0][i][min(k,arr[0][i])]= min(
                dp[0][i][min(k,arr[0][i])],
                max(dp[0][i-1][k], arr[0][i])
            );
        }
    }
}

void solve(){
    initialize();

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            for(int k=1;k<=100;k++){
                dp[i][j][min(k,arr[i][j])] = min(
                    dp[i][j][min(k, arr[i][j])],
                    max(min(dp[i-1][j][k],dp[i][j-1][k]), arr[i][j])
                );
            }
        }
    }
}


int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    solve();

    int ans = 1e9;
    for(int k=1;k<=100;k++){
        if(dp[n-1][n-1][k]!=1e9)
            ans = min(ans, dp[n-1][n-1][k]-k);
    }
    cout<<ans;
}