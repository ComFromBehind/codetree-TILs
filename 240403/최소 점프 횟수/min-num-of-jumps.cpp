#include <iostream>
#include <vector>
using namespace std;

int n;

int arr[11];
int ans=1e9;

void func(int k, int cnt){
    if(k>=n-1){
        ans = min(ans, cnt );
        return;
    }
    int c = arr[k];
    if(c==0) return;
    for(int i=1;i<=c;i++){
        func(k+i, cnt+1);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];

    func(0, 0);

    if(ans==1e9) cout<<-1;
    else cout<<ans;
}