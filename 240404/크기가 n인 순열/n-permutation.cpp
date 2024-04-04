#include <iostream>
#include <vector>
using namespace std;

bool visited[9];

int n;
vector<int> v;
void func(int k){
    if(k==n){
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i]= 1;
            v.push_back(i);
            func(k+1);
            visited[i]= 0;
            v.pop_back();
        }
    }
}

int main() {
    cin>>n;
    
    func(0);    
}