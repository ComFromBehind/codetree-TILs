#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int n, m, k;

int arr[101][101];
int brr[101][101];

void print() {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void bomb() {
    
    int flag = 0;
    while (flag == 0) {
        int cnt = 0;
        flag = 1;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
               
                int t = j;
                cnt = 0;
                int nx = arr[j][i];
                if (nx == 0) continue;
                while (t<n&&nx == arr[t][i]||arr[t][i]==0) {
                    
                    if (arr[t][i] == 0) {t++;continue;}
                    cnt++;
                    t++;
                    if (t == n) break;
                }
                if (cnt >= m) {
                    flag = 0;
                    int k = 0;
                    int cnt2 = 0;
                    while (j+k<n&&cnt2 != cnt) {

                        if (arr[j + k][i] == 0) {
                            k++;continue;
                        }
                        arr[j + k][i] = 0;
                        cnt2++;

                    }
                }
            }
        }
        
    }
}


void rotate() { // 시계방향으로 회전.. 
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            brr[i][j] = arr[n - 1 - j][i];
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            arr[i][j] = brr[i][j];
        }
    }

}

void fall() {
    for (int i = 0;i < n;i++) {
        vector<int> v;
        for (int j = n - 1;j >= 0;j--) {
            if (arr[j][i] != 0)
                v.push_back(arr[j][i]);
        }

        int sz = v.size();
        for (int j = 0;j < sz;j++) {
            arr[n - 1 - j][i] = v[j];
        }
        for (int j = sz;j < n;j++) {
            arr[n - 1 - j][i] = 0;
        }
    }
}


int main() {

    cin >> n >> m >> k;

    if (m == 1) {
        cout << 0;
        exit(0);
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++)
            cin >> arr[i][j];
    }
    

    while (k--) {
        bomb();
        fall();
        rotate();
        fall();
        
    }
    bomb();
    fall();

    int ans = 0;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {


            if (arr[i][j] != 0)
                ans++;
        }


    }


    cout << ans;
}