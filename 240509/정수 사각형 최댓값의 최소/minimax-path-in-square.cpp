#include <iostream>
using namespace std;

int n;

int arr[101][101];
int dp[101][101];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];
    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][0], arr[i][0]);
        dp[0][i] = max(dp[0][i-1],arr[0][i]);
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = max(min(dp[i-1][j],dp[i][j-1]),arr[i][j]);
        }
    }
    cout<<dp[n-1][n-1];
}