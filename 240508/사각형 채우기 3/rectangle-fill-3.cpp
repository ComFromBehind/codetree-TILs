#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;

int arr[1001];


int main(){
    cin>>n;
    
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 7;
    arr[3] = 22;
    for(int i=4;i<=n;i++){
        int sum = 0;
        for(int j=i-3;j>=0;j--){
            sum+=2*(arr[j]);
        }
        sum+=2*arr[i-1];
        sum+=3*arr[i-2];
        arr[i] = sum;
    }
    cout<< arr[n];  
}