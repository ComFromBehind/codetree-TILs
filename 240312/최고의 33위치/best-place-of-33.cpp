#include <iostream>
#include <algorithm>
using namespace std;

int arr[21][21];
int big;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp = 0;
            if(i+2>n) continue;
            if(j+2>n) continue;
            for(int k=0;k<3;k++){
                for(int m=0;m<3;m++){
                    if(arr[i+k][j+m]==1)
                        temp++;
                }
            }
            big = max(temp,big);
        }
    }
    cout<<big;
}