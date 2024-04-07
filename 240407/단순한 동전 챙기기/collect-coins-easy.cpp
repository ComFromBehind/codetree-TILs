#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int n;

char arr[21][21];

pair<int,int> brr[10];

int st_r, st_c;
int en_r, en_c;

vector<int> ans;
int realans = 1e9;

bool check[10];

int calc(){
    int sum = 0;
    int temp_r = st_r;
    int temp_c = st_c;
    for(int i=0;i<3;i++){
        int new_r = brr[ans[i]].first;
        int new_c = brr[ans[i]].second;

        sum+=abs(new_r - temp_r);
        sum+=abs(new_c - temp_c);
        temp_r = new_r;
        temp_c = new_c;
    }
    sum+= abs(en_r-temp_r);
    sum+=abs(en_c-temp_c);
    return sum;
}

void func(int k){
    if(k==3){
        
        int cnt = calc();
        realans = min(realans,cnt);

        return;
    }
    for(int i=1;i<10;i++){
        if(brr[i]!=make_pair(-1,-1)&&check[i]!=1){
            check[i] = 1;
            ans.push_back(i);
            func(k+1);
            ans.pop_back();
            check[i] = 0;
        }
    }
}

int main(){
    cin>>n;
    
    for(int i=0;i<10;i++){
        brr[i] = {-1,-1};
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]>='1'&&arr[i][j]<='9'){
                int a = arr[i][j]-'0';
                brr[a] = {i,j};
            }
            else if(arr[i][j]=='S'){
                st_r = i; st_c = j;
            }
            else if(arr[i][j]=='E'){
                en_r = i; en_c = j;
            }
        }

    }

    func(0);

    cout<<realans;
    


}