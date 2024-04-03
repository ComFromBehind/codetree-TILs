#include <iostream>
#include <vector>

using namespace std;

int n;

string s;

bool check_func(){
    
    int t = 1;
    string temp;
    string temp2;
    temp.push_back(s.back());
    while(t<=n/2){
        
        temp2.clear();
        temp.clear();
        for(int i=0;i<t;i++){
            temp.push_back(s[s.size()-1-i]);
        }
        for(int i=0;i<t;i++){
            temp2.push_back(s[s.size()-t-1-i]);
        }
        if(temp==temp2){
            
            return false;
        }
        t++;
    }
    
    return true;
}

void func(int k){
    if(k==n){
        if(check_func())
        {   cout<<s;
            exit(0);}
        return;
    }

    if(k!=0&&!check_func()){
        return;
    }

    for(int i=4;i<=6;i++){
        s.push_back(i+'0');
        func(k+1);
        s.pop_back();
    }
}

int main(){
    cin>>n;

    func(0);
}