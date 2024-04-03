#include <iostream>
#include <vector>
using namespace std;

int n;

int arr[11];
int ans=1e9;

void func(int k, int cnt){
    if(k<0){
        ans = min(ans, cnt );
        return;
    }

    int c = arr[k];
    if(c==0) return;
    for(int i=1;i<=c;i++){
        func(k-c, cnt+1);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];

    func(n-1, 0);

    if(ans==1e9) cout<<-1;
    else cout<<ans;
}