#include <iostream>
using namespace std;

int n;
int arr[201][201];

int r,c;

void bomb(int row, int col){
    
    int size = arr[row][col];

    for(int i=0;i<size;i++){
        if(col-i>=0)
            arr[row][col-i] = 0;
        if(col+i<n)
            arr[row][col+i] = 0;
        if(row+i<n)
            arr[row+i][col] = 0;
        if(row-i>=0)
            arr[row-i][col] = 0;

    }

    for(int i=0;i<n;i++){
        if(i<col-(size-1)||i>col+(size-1)) continue;
    
        for(int j=n-1;j>0;j--){
            int k=j;
            int temp=0;
            if(arr[k][i]==0){
                while(k!=0&&arr[k][i]==0){
                    if(arr[k-1][i]!=0) {temp = arr[k-1][i]; arr[k-1][i]=0; break;}
                    else k--;
                }
                arr[k][i] = temp;
            }
        }
    }

}

int main(){
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    cin>>r>>c;

    bomb(r-1,c-1);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }


}