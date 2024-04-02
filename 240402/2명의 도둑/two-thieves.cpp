#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n,m,c;
int arr[11][11];
int ans;
int smallans;
bool check[11][11];
vector<int> tmp;
vector<pair<int,int>> v;

bool checking(int i, int j){
    for(int t = j; t<j+m; t++){
        if(check[i][t]!=0) return false;
    }
    for(int t = j;t<j+m;t++){
        check[i][t] = 1; 
    }
    return true;
}

bool unchecking(int i, int j){
    for(int t = j; t<j+m; t++){
        if(check[i][t]!=1) return false;
    }
    for(int t = j;t<j+m;t++){
        check[i][t] = 0; 
    }
    return true;
}

vector<pair<int,int>> w;

void func2(int k){

    if(k==m){
        int sum=0;
        for(int i=0;i<tmp.size();i++){
            sum+=arr[w[tmp[i]].first][w[tmp[i]].second];
        }
        if(sum>c) {return;}

        int temp_weight = 0;
        for(int i=0;i<tmp.size();i++){
            temp_weight += arr[w[tmp[i]].first][w[tmp[i]].second]*arr[w[tmp[i]].first][w[tmp[i]].second];
        }
        smallans = max(smallans, temp_weight);
        return;
    }
    
    tmp.push_back(k);
    func2(k+1);
    tmp.pop_back();
    func2(k+1);
    
}

void calc(){
    int temp_w=0;

    for(int i=0;i<2;i++){
        w.clear();
        
        int row = v[i].first;
        int col = v[i].second;
        
        for(int j=0;j<m;j++){
            w.push_back({row,col+j});
        }
        tmp.clear();
        smallans=0;
        func2(0);
        temp_w += smallans;
    }
    
    ans = max(temp_w, ans);
}



void func(int k){
    if(k==2){
        
        calc();
        return;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-m+1;j++){
            if(checking(i,j)){
                v.push_back({i,j});
                func(k+1);
                v.pop_back();
                unchecking(i,j);
            }
        }
    }
    //최적화 풀이는 아니다!


}



int main(){
    cin>>n>>m>>c;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    func(0);

    cout<<ans;
}