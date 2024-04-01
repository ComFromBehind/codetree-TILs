#include <iostream>
#include <vector>
using namespace std;

int n;
int check[1001];
vector<pair<int,int>> v;
int a,b;

int ans;

vector<int> w;

void clear(){
    for(int i=0;i<1001;i++){
        check[i] = 0;
    }
}

void check_v(){
    int flag=0;
    int cnt = 0;
    clear();
    for(int i=0;i<w.size();i++){
        cnt++;
        for(int j=v[w[i]].first;j<=v[w[i]].second;j++){
            if(check[j]!=0) return;
            check[j] = 1;

        }
    }
    ans = max(ans, cnt);
}

void func(int k, int ok){
    
    if(k==n){
        check_v();
        return;
    }
    if(ok==1){
        w.push_back(k);
        check_v();
        func(k+1,0);
        func(k+1,1);
        w.pop_back();
    }
    else{
        func(k+1,0);
        func(k+1,1);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }

    func(0, 0);
    func(0, 1);

    cout<<ans;
}