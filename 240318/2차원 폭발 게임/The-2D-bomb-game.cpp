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
    for (int i = 0;i < n;i++) {

        vector<pair<int, int>> v;

        for (int j = 0;j < n;j++) {
            if (arr[j][i] == 0) continue;
            if (v.empty()) {
                v.push_back({ arr[j][i],1 });
            }
            else if (arr[j][i] == v[v.size() - 1].first) {
                v[v.size() - 1].second++;
                if (j == n - 1) {
                    if (v[v.size() - 1].second >= m)
                        v.pop_back();
                }
            }
            else if (arr[j][i] != v[v.size() - 1].first) {

                if (v.back().second >= m)
                    v.pop_back();
                if (v.empty()) {
                    v.push_back({ arr[j][i],1 });
                }
                else if (arr[j][i] == v[v.size() - 1].first) {
                    v[v.size() - 1].second++;
                    if (j == n - 1) {
                        if (v[v.size() - 1].second >= m)
                            v.pop_back();
                    }
                }
                else {
                    v.push_back({ arr[j][i],1 });
                }
            }


        }

        int st = 0;
        for (int j = 0;j < v.size();j++) {
            for (int t = 0;t < v[j].second;t++) {
                arr[st][i] = v[j].first;
                st++;
            }
        }
        for (int j = st;j < n;j++) {
            arr[st][i] = 0;
            st++;
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