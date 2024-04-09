#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> inputv;
vector<int> list;
int ans = 1e9;
int sum; 

void func(int k, int cnt){
    if(k==2*n+1){
        if(cnt!=n) return;
    }
    if(cnt==n){
        int temp =0;
        for(int i=0;i<list.size();i++){
            temp+=list[i];
            //cout<<list[i]<<" ";
        }
        
        ans = min(abs(sum-temp-temp),ans);
        //cout<<ans<<"\n";
        return;
    }
    if(k==0)
        func(k+1, cnt);
    
    else{
    list.push_back(inputv[k-1]);
    func(k+1 , cnt+1);
    list.pop_back();
    func(k+1, cnt);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=2*n;i++){
        
        int temp;
        cin>>temp;
        inputv.push_back(temp);
        sum += temp;
    }

    sort(inputv.begin(),inputv.end());

    func(0,0);

    cout<<ans;
}