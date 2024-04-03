#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n,m;

void func(int idx, int k){
    //종료조건
    if(idx==n+1){
        if(k!=m) return;
    }
    
    if(k==m){
        for(int i=0;i<m;i++) cout<<v[i]<<" ";
        cout<<"\n";
        return;
    }
    v.push_back(idx);
    func(idx+1, k+1);
    v.pop_back();
    func(idx+1, k);

    
}

int main(){
    cin>>n>>m;


    func(1,0);


}