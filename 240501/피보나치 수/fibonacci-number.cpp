#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int n;
int arr[46];

int fibo(int m){
    if(arr[m]!=-1)
        return arr[m];
    if(m<=2) return 1;
    else{
        arr[m] = fibo(m-1)+fibo(m-2);
    }
    return arr[m]; 
}

int main(){
    
    cin>>n;
    
    for(int i=0;i<=n;i++){
        arr[i] = -1;
    }

    cout<<fibo(n);


}