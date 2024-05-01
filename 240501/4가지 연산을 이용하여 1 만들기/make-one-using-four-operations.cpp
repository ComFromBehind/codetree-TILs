#include <iostream>
#include <queue>
using namespace std;

int arr[1000001];
bool check[1000001];

int n;
int main() {
    cin>>n;
    arr[1] = 0;
    
    queue<int> q;

    q.push(1);
    check[1] = 1;
    while(!q.empty()){
        int c = q.front();
        
        q.pop();
        
        int nc1 = c + 1;
        if(!check[nc1]&&nc1>=0&&nc1<1000001){
            arr[nc1] = arr[c] +1;
            q.push(nc1);
            check[nc1] = 1;
        }
        if(nc1 == n){
            cout<<arr[n];
            exit(0);
        }
        
        int nc2 = c - 1;
        if(!check[nc2]&&nc2>=0&&nc2<1000001){
            arr[nc2] = arr[c] + 1;
            q.push(nc2);
            check[nc2] = 1;
        }
        if(nc2 ==n) {
            cout<<arr[n];
            exit(0);
        }
        int nc3 = c * 2;
        if(!check[nc3]&&nc3>=0&&nc3<1000001){
            arr[nc3] = arr[c] + 1;
            q.push(nc3);
            check[nc3]=1;
        }
        if(nc3 ==n){
            cout<<arr[n];
            exit(0);
        }
        int nc4 = c*3;
        if(!check[nc4]&&nc4>=0&&nc4<1000001){
            arr[nc4] = arr[c]+1;
            q.push(nc4);
            check[nc4] = 1;
        }
        
    }



    return 0;
}