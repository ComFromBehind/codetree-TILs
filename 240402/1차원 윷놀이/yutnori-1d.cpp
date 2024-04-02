#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <tuple>

int n, m, k;

using namespace std;

int mvlist[13];

int check[5]; //이 값이 m이상인지 아닌지로 판단!

vector<int> waitlist;
int ans = 0;

void func(int a){
    if(a==n){

        int tmp = 0;
        
        for(int i=1;i<=k;i++){
            if(check[i]>=m) tmp++;
        }
        
        ans = max(ans, tmp);
        return;
    }
    
    for(int i=1;i<=k;i++){
        if(check[i]>=m) continue;
        check[i]+=mvlist[a];
        func(a+1);
        check[i]-=mvlist[a];
    }
    int flag=0;
    for(int i=1;i<=k;i++){
        if(check[i]<m) flag=1;
    }
    if(flag==0){
        cout<<k;
        exit(0);
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>mvlist[i];
    }

    func(0);
    cout<<ans;
}