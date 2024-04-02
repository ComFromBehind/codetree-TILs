#include <iostream>
#include <vector>
using namespace std;
int n;
string s;

char list[6] = {'a','b','c','d','e','f'};
int check[6] = {-1,-1,-1,-1,-1,-1}; 

vector<int> alpha;
int m;

int ans=-2147483648;
int arr[6]; //숫자 매핑

vector<int> mapping;

void calc(){
    int cnt = 0;
    
    char op2 = ' ';
    for(int i=0;i<s.length();i++){
        if(s[i]>='a'&&s[i]<='f'){
            if(cnt==0){
                cnt = arr[s[i]-'a'];
            }
            else{
                if(op2=='+')
                    cnt+=arr[s[i]-'a'];
                else if(op2=='-')
                    cnt-=arr[s[i]-'a'];
                else if(op2=='*')
                    cnt*=arr[s[i]-'a'];
            }
        }
        else if(s[i]=='+'){
            op2 = '+';
        }
        else if(s[i]=='-'){
            op2 = '-';
        }
        else if(s[i]=='*'){
            op2 = '*';
        }
    }
    ans = max(cnt, ans);
}

void func(int k ){
    if(k==m){
        
        for(int i=0;i<mapping.size();i++){
            arr[alpha[i]] = mapping[i]; 
        }
        calc();

        return;
    }
    for(int i=1;i<=4;i++){
        mapping.push_back(i);
        func(k+1);
        mapping.pop_back();
    }
}
 //짝수번째에 무조건 연산자가 오게 되어있다!

int main(){
    cin>>s;
    
    for(int i=0; i<s.length();i++ ){
        if(s[i] >= 'a' && s[i]<='f') {
            if(check[s[i]-'a']==-1){
                check[s[i]-'a']=0;
                alpha.push_back(s[i]-'a'); //alpha에는 스트링에 들어잇는 문자대표 1개씩 들어잇음.

            }
        }
    }
    m = alpha.size();
    func(0);

    cout<<ans;

}