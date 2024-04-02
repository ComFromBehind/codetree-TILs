#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n,m,c;
int arr[11][11];
int ans;

bool check[11][11];

vector<pair<int,int>> v;

bool checking(int i, int j){
    int temp = arr[i][j];
    if(j<n-1&&temp+arr[i][j+1]<=c){
        if(check[i][j]!=0||check[i][j+1]!=0) return false;
        check[i][j]=1;
        check[i][j+1]=1;
    }
    else{
        if(check[i][j]!=0) return false;
        check[i][j] = 1;
    }
    return true;
}

bool unchecking(int i, int j){
    int temp = arr[i][j];
    if(j<n-1&&temp+arr[i][j+1]<=c){
        if(check[i][j]!=1||check[i][j+1]!=1) return false;
        check[i][j]=0;
        check[i][j+1] = 0;
    }
    else{
        if(check[i][j]!=1) return false;
        check[i][j] = 0;
    }
    return true;
}

void calc(){
    int temp_w=0;
    for(int i=0;i<2;i++){
        int st = arr[v[i].first][v[i].second];
        int st1 = st*st;
        if(v[i].second<n-1&&arr[v[i].first][v[i].second+1]+st<=c){
            int st2 =  arr[v[i].first][v[i].second+1]*arr[v[i].first][v[i].second+1];
            temp_w+=st2;
        }
        temp_w+=st1;
    }
    
    ans = max(temp_w, ans);
}

void func(int k){
    if(k==2){
        
        calc();
        return;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
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