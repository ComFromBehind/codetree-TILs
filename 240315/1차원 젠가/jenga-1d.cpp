#include <iostream>
using namespace std;

int n;

int arr[101];
int brr[101];

int s1, e1, s2, e2;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cin>>s1>>e1>>s2>>e2;

    for(int i=0;i<n;i++){
        if(i>=s1-1&&i<=e1-1) arr[i]=0;
    }

    for(int i=0;i<n;i++){
        brr[i]=arr[i];
    }
    
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>0) count++; 
        if(count>=(s2-1)&&count<=(e2-1)) brr[i] = 0;
    }

    count = count - (e2-s2+1);



    cout<<count<<"\n";

    if(count==0) 
        exit(0);

    for(int i=0;i<n;i++){
        if(brr[i]>0){

            cout<<brr[i]<<"\n";
        }
    }
   
    return 0;
}