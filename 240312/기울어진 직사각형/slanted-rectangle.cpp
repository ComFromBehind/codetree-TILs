#include <iostream>
using namespace std;
int n;
int arr[21][21];

int ans;

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int k=1;k<n-1;k++){
        //st = arr[0][i];
        int temp = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i-j)==k||(i-j)==-k||(i+j)==k||(i+j)==-k){
                    temp +=arr[i][j];
                }
            }
        }
        ans = max(ans, temp);
    }
    
    cout<<ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}