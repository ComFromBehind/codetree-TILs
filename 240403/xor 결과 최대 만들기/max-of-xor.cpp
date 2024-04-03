#include <iostream>
#include <vector>

using namespace std;

int n,m;
int arr[21];
int ans;
vector<int> v;

void func(int k, int idx){

    //
    if(idx==n){
        if(k!=m) return;
    }

    if(k==m){
        int tmp = v[0];
        for(int i=1;i<v.size();i++){
            tmp = (tmp^v[i]);
        }
        ans = max(ans, tmp);
        return;
    }

    v.push_back(idx);
    func(k+1, idx+1);
    v.pop_back();
    func(k, idx+1);
}

int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    func(0,0);

    cout<<ans;

    return 0;
}