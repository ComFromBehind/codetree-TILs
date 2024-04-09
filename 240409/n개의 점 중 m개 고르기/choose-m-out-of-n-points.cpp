#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int n, m;

int x, y;
vector<pair<int, int>> v;
vector<int> list;
int realans = 1e9;

int dist[21][21];

map<pair<int, int>, int> mm;

void func(int k, int cnt) {
    if (k == n) {
        if (cnt != m) return;
    }
    if (cnt == m) {
        int temp = 0;
        int max_d = 0;
        for (int i = 0;i < list.size();i++) {
            for (int j = i + 1;j < list.size();j++) {
                map<pair<int, int>, int> ::iterator it = mm.begin();
                it = mm.find({ v[list[i]].first, v[list[i]].second });
                int a = it->second;
                it = mm.find({ v[list[j]].first, v[list[j]].second });
                int b = it->second;
                if (max_d < dist[a][b]) {
                    max_d = dist[a][b];
                }
            }
        }
        realans = min(max_d, realans);
        return;
    }

    list.push_back(k);
    func(k + 1, cnt + 1);
    list.pop_back();
    func(k + 1, cnt);

}

int main() {
    cin >> n >> m;

    for (int i = 0;i < n;i++) {
        cin >> x >> y;
        v.push_back({ x,y });
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            int x_2 = (v[i].first - v[j].first) * (v[i].first - v[j].first);
            int y_2 = (v[i].second - v[j].second) * (v[i].second - v[j].second);
            dist[i][j] = x_2 + y_2;
            mm[{v[i].first, v[i].second}] = i;
            mm[{v[j].first, v[j].second}] = j;
        }
    }

    func(0, 0);

    cout << realans;
}