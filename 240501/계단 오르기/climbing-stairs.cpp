#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n;
int arr[1001];

int main(){
    
    cin>>n;
    arr[2] = 1;
    arr[3] = 1;

    for(int i=4;i<=n;i++){
        arr[n] = ((arr[n-2])%10007+ (arr[n-3])%10007)%10007;
    }
    
    cout<<arr[n];
}