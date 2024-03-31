#include <iostream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

int n,m,t;
int r,c,w;
char d;
int intd;
int idx;
int ans;
//idx, row, col, dir, weight 순
typedef tuple<int,int,int,int,int> ball;

ball b;
vector<ball> v;


int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

map<pair<int,int>,tuple<int,int,int>> mm;

int dir_trans(char a){
    if(a=='L') return 3;
    if(a=='D') return 1;
    if(a=='U') return 2;
    if(a=='R') return 0;
}

void simul(){
    int sz = v.size();
    mm.clear();
    
    map<pair<int,int>,tuple<int,int,int>>::iterator it= mm.begin();
    for(int i=0;i<sz;i++){
        tie(idx, r, c, intd, w) = v[i];
        
        int nx = r+dx[intd];
        int ny = c+dy[intd];
        
        if(nx<0||nx>=n||ny<0||ny>=n){
            intd = 3-intd;
            nx = r+dx[intd];
            ny = c+dy[intd];
        }

        r = nx;
        c = ny;

        it=mm.find({r,c});

        if(it==mm.end()){
            mm[{r,c}] = {idx, intd, w};  
        }
        else{
            int e,f,g;
            tie(e,f,g) = it->second;

            int nweight, nidx, ndir;
            
            nweight = w+g; //무게 합치기

            if(idx<e) {nidx = e; ndir = f;}
            else {nidx = idx; ndir = intd;}

            mm[{r,c}] = {nidx, ndir, nweight}; 
            ans = max(ans, nweight);   
        }
    }
}

void v_store(){
    int sz= mm.size();
    auto it = mm.begin();
    v.clear();
    int idx;
    for(it=mm.begin();it!=mm.end();it++){
        int tmp1,tmp2,tmp3,tmp4,tmp5;
        
        tie(tmp1,tmp2) = it->first;
    

        tie(tmp3,tmp4,tmp5) = it->second;
        tie(idx, r, c,intd, w) = tie(tmp1,tmp2,tmp3,tmp4,tmp5);
        b = tie(idx,r,c,intd,w);
        v.push_back(b);
       
    }
}

int main(){
    cin>>n>>m>>t;
    for(int i=1;i<=m;i++){
        cin>>r>>c>>d>>w;
        intd = dir_trans(d);
        b = make_tuple(i, r-1,c-1,intd,w);
        v.push_back(b);
        ans = max(ans, w);
    }

    while(t--){
        simul();
        v_store();
    }

    cout<<v.size()<<" "<<ans; // 남아있는 구슬의 개수와 가장 무거운 구슬무게
}