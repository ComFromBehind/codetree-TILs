#include <iostream>
#include <vector>
using namespace std;

int ans;
int n,m;

bool check[1001];

vector<int> node[1001];

void dfs(int k){
    for(int i=0;i<node[k].size();i++){
        if(!check[node[k][i]]){
            ans++;
            check[node[k][i]] = 1;
            dfs(node[k][i]);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m;i++ ){
        int tmp1, tmp2;
        cin>>tmp1>>tmp2;
        node[tmp1].push_back(tmp2);
        node[tmp2].push_back(tmp1);
    }
    check[1] =1;
    dfs(1);
    
    cout<<ans;
}