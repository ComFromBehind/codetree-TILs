#include <iostream>

using namespace std;

int n;

int arr[1001];
int dp[1001];

int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    dp[0] = 1;

    for(int i=1;i<n;i++){
        dp[i] = -1e8;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }
    int ans=1;
    for(int i=0;i<=n;i++){
        ans = max(dp[i], ans);
    }
    cout<<ans;
}