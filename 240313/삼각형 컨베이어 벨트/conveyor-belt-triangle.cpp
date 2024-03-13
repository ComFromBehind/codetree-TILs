#include <iostream>
using namespace std;

int n,t;

int arr[3][201];
int temp[3];

void rotate(){
    
    for(int i=0;i<3;i++){
        temp[i] = arr[i][n-1];
    }

    for(int i=0;i<3;i++){
        for(int j=n-1;j>=0;j--){
            if(j==0) {
                if(i==0) arr[i][j]=temp[2];
                else arr[i][j] = temp[i-1];
            }
            else{
                arr[i][j] = arr[i][j-1];
            }
        }
    }

}

int main(){
    cin>>n>>t;
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }

    for(int i=0;i<t;i++){
        rotate();
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

}