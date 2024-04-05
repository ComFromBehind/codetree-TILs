#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
bool check[9];

void func(int k){
    if(k==0){

        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<"\n";
        return;    
    }

    for(int i=n;i>=1;i--){
        if(!check[i]){
            check[i] =1;
            v.push_back(i);
            func(k-1);
            check[i] = 0;
            v.pop_back();
        }
    }
}

int main(){
    cin>>n;
    

    func(n);
}