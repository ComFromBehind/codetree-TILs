#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> inputv;
vector<int> list;
int ans = 1e9;
int sum; 

void func(int k){
    if(k==2*n+1){
        
        int temp=0;
        for(int i=0;i<list.size();i++){
            temp+=list[i];
        }
        ans = min(abs(sum-temp-temp),ans);
        return;
    }
    int temp=0;
    for(int i=0;i<list.size();i++){
        temp+=list[i];;
    }
    
    ans = min(abs(sum-temp-temp),ans);
   

    list.push_back(inputv[k]);
    func(k+1);
    list.pop_back();
    func(k+1);

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

    func(0);

    cout<<ans;
}