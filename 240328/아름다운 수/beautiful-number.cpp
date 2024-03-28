#include <iostream>
using namespace std;

int n;int ans;
string s;

int calc(string t){
    int sz = t.size();
    int flag=0;
    int cnt = 0;
    while(cnt!=sz){
        char now = t[cnt];
        int howmany = t[cnt]-'0';
        
        for(int i=0;i<howmany-1;i++){
            cnt++;
            if(t[cnt]!=now) flag=1;
            if(cnt>=sz) flag=1;
        }
        
    }
    if(flag==0) return 1;
    else return 0;
}

void func(int k){
    if(k==n){
        ans+=calc(s);
        return;
    }

    for(int i=1;i<=4;i++){
        s.push_back(i);
        func(k+1);
        s.pop_back();
    }
}

int main(){
    cin>>n;

    func(0);
    cout<<ans;
}