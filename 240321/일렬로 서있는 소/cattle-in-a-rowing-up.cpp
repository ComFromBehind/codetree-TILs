#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
int x,y,z;
int ans;
int main(){
    cin>>n;
    int temp=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        x = v[i];
        for(int j=i+1;j<v.size();j++){
            y = v[j];
            for(int k=j+1;k<v.size();k++){
                z = v[k];
                
                if(((y-x)<=(z-y))&&((z-y)<=2*(y-x))){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
}