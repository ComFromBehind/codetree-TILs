#include <iostream>
#include <vector>
using namespace std;

int k,n;

using namespace std;

vector<int> ans;

void func(int a){
    if(a==n){
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<"\n";
        return;
    }

    for(int i=1;i<=k;i++){
        if(a>=2&&i==ans[ans.size()-1]&&ans[ans.size()-2]==i){
            continue;
        }
        ans.push_back(i);
        func(a+1);
        ans.pop_back();

    }
}

int main(){
    cin>>k>>n;

    func(0);
}