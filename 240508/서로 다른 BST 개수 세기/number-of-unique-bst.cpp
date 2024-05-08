#include <iostream>
using namespace std;

int n;
int arr[21];
int main(){
    cin>>n;
    arr[0] = 1;
    arr[1] = 1;
    arr[2] =2;
    
    for(int i=3;i<=n;i++){
        arr[i] = 0;
        for(int j=0;j<n;j++){
            arr[i] += (arr[i-j-1]*arr[j]);
        }
    }
    cout<<arr[n];

}