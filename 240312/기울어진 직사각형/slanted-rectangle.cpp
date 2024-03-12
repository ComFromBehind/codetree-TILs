#include <iostream>
using namespace std;
int n;
int arr[21][21];

int ans;

void func(int k, int a, int b){// k기준으로 왼쪽으로 a칸, 오른쪽으로 b칸
    int temp = 0;
    for(int i=0;i<=a;i++){
        temp+=arr[i][k-i];
        temp+=arr[b+i][k+b-i];
    }
    for(int i=1;i<b;i++){
        temp+=arr[i][k+i];
        temp+=arr[a+i][k-a+i];
    }
    ans = max(ans, temp);
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<n-1;k++){
                if(k-i<0||k+j>=n) continue;
                func(k, i,j);
            }
        }
    }
    
    cout<<ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}