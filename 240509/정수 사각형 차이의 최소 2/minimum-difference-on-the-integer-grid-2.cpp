#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;

int arr[101][101];
pair<int,int> dp[101][101];

int main() {
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    dp[0][0] = {arr[0][0],arr[0][0]};
    
    for(int i=1;i<n;i++){
        dp[0][i] = {max(dp[0][i-1].first,arr[0][i]),min(dp[0][i-1].second,arr[0][i])};
        dp[i][0] = {max(dp[i-1][0].first,arr[i-1][0]),min(dp[i-1][0].second,arr[i-1][0])};

    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = {max(min(dp[i-1][j].first,dp[i][j-1].first),arr[i][j]),min(max(dp[i-1][j].second,dp[i][j-1].second),arr[i][j])};
        
        }

    }
    
    cout<<dp[n-1][n-1].first-dp[n-1][n-1].second;
    return 0;
}