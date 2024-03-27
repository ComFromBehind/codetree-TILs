#include <iostream>
#include <vector>
using namespace std;

int k, n;

vector<int> v;
void func(int a, int b){
    
    if(b==n){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=a;i++){
        v.push_back(i);
        func(a,b+1);
        v.pop_back();
    }
    
}

int main(){
    cin>>k>>n;
    func(k,0);
}