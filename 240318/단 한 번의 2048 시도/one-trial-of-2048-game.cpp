#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int arr[4][4];
vector<pair<int,int>> v;
char dir[4] = { 'L','R','U','D' };

void func(int dir) {


    if (dir == 0) {
        for (int i = 0;i < 4;i++) {
            v.resize(0);
            int sz = 0;
            for (int j = 0;j < 4;j++) {
                if (arr[i][j] != 0) {
                    v.push_back({arr[i][j],0});
                }
                sz = v.size();
                if (sz > 1) {

                    if (v[sz - 1].first == v[sz - 2].first && v[sz - 2].second == 0) {
                        v[sz - 2].first = 2 * v[sz - 2].first;
                        v[sz - 2].second = 1;
                        v.pop_back();
                    }
                }
            }
            sz = v.size();
            for (int j = 0;j < sz;j++) {
                arr[i][j] = v[j].first;
            }
            for (int j = sz;j < 4;j++) {
                arr[i][j] = 0;
            }
        }
    }
    else if (dir == 1) {
        for (int i = 0;i < 4;i++) {
            v.resize(0);
            int sz = 0;
            for (int j = 3;j >= 0;j--) {
                if (arr[i][j] != 0) {
                    v.push_back({ arr[i][j],0 });
                }
                sz = v.size();
                if (sz > 1) {
                    if (v[sz - 1].first == v[sz - 2].first && v[sz - 2].second == 0) {
                        v[sz - 2].first = 2 * v[sz - 2].first;
                        v[sz - 2].second = 1;
                        v.pop_back();
                    }
                }
            }
            sz = v.size();
            for (int j = 0;j < sz;j++) {
                arr[i][3 - j] = v[j].first;
            }
            for (int j = sz;j < 4;j++) {
                arr[i][3 - j] = 0;
            }
        }
    }
    else if (dir == 2) {
        for (int i = 0;i < 4;i++) {
            v.resize(0);
            int sz = 0;
            for (int j = 0;j < 4;j++) {
                if (arr[j][i] != 0) {
                    v.push_back({ arr[j][i],0 });
                }
                sz = v.size();
                if (sz > 1) {
                    if (v[sz - 1].first == v[sz - 2].first && v[sz - 2].second == 0) {
                        v[sz - 2].first = 2 * v[sz - 2].first;
                        v[sz - 2].second = 1;
                        v.pop_back();
                    }
                }
            }
            sz = v.size();
            for (int j = 0;j < sz;j++) {
                arr[j][i] = v[j].first;
            }
            for (int j = sz;j < 4;j++) {
                arr[j][i] = 0;
            }
        }
    }
    else if (dir == 3) {
        for (int i = 0; i < 4;i++) {
            v.resize(0);
            int sz = 0;
            for (int j = 3;j >= 0;j--) {
                if (arr[j][i] != 0) {
                    v.push_back({ arr[j][i],0 });
                }
                sz = v.size();
                if (sz > 1) {
                    if (v[sz - 1].first == v[sz - 2].first && v[sz - 2].second == 0) {
                        v[sz - 2].first = 2 * v[sz - 2].first;
                        v[sz - 2].second = 1;
                        v.pop_back();
                    }
                }
            }
            sz = v.size();
            for (int j = 0;j < sz;j++) {
                arr[3 - j][i] = v[j].first;
            }
            for (int j = sz; j < 4;j++) {
                arr[3 - j][i] = 0;
            }
        }
    }
}

int main() {
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            cin >> arr[i][j];
        }
    }



    char temp = ' ';
    cin >> temp;

    int idx = 0;
    for (int i = 0;i < 4;i++) {
        if (temp == dir[i]) {
            idx = i;
            break;
        }
    }


    func(idx);

    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }


}