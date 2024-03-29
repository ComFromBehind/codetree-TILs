#include <iostream>
using namespace std;

int n;
string s;

int ans;

int calc(){
    int sz = s.size();
    int cnt = 0;
    int flag=0;
    while(cnt<sz){
        char now = s[cnt];
        int trans_now = s[cnt]-'0';
        for(int i=0;i<=trans_now-1;i++){
            if(cnt+i>=sz) {flag=1; return 0;}
            if(s[cnt+i]!=now) {flag=1; return 0;}
        }
        cnt+=trans_now;
    }
    if(cnt!=sz) return 0;
    return 1;
}

void func(int k){
    if(k==n){
        int plus = calc();
        ans+=plus;
       
        return;
    }
    for(int i=1;i<=4;i++){
        s+=to_string(i);
        func(k+1);
        s.pop_back();
    }
}

int main(){
    cin>>n;
    func(0);
    cout<<ans;
}