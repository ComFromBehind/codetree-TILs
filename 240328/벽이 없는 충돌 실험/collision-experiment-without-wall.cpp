#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

int t, n;

int row;
int col;
char dir;
int weight;
int intdir;
int row2, col2, weight2;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

typedef tuple<int, int, int> ball;

map<pair<int, int>, pair<int, int>> m;


pair<int, int> vlist[101];
pair<int, int> wlist[101];
int dir_arr[101];
int wei_arr[101];

int trans_dir(char a) {
    if (a == 'L') return 2;
    if (a == 'R') return 0;
    if (a == 'D') return 3;
    if (a == 'U') return 1;
}

void vlist_clear() {
    for (int i = 0;i <= 100;i++) {
        vlist[i] = { -1,-1 };
        dir_arr[i] = -1;
    }
}

//void print() {
//    for (int i = 0;i < n;i++) {
//        (dir_arr[i] == -1) ? cout << "0" : cout << "1";
//        cout << "\n";
//        cout << vlist[i].first << " " << vlist[i].second << " " << "\n";
//    }
//}

int flag = 0;
int ans = 0;

int main() {

    cin >> t;
    while (t--) {
        cin >> n;

        ans = 0;
        flag = 0;

        //초기화 공부해볼것..
        vlist_clear();

        for (int i = 0;i < n;i++) { //ball 등록과정
            cin >> row >> col >> weight >> dir;
            row += 1001;
            col += 1001;
            vlist[i] = { row - 1,col - 1 };
            wei_arr[i] = weight;

            wlist[i] = vlist[i];
            intdir = trans_dir(dir);
            dir_arr[i] = intdir;
        }

        int max_t = 3;
        //int max_t = 2002;
        int timer = 1;

        while (max_t--) {
            flag = 0;


            for (int i = 0;i <= n;i++) {
                wlist[i] = vlist[i];
            }

            for (int i = 0;i < n;i++) {

                if (dir_arr[i] == -1) continue;
                row = vlist[i].first;
                col = vlist[i].second;

                if (row < 0 || row>2000 || col < 0 || col>2000) {
                    dir_arr[i] = -1;
                    continue;
                }

                intdir = dir_arr[i];
                weight = wei_arr[i];
                vlist[i] = { row + dx[intdir], col + dy[intdir] };



            }

            for (int i = 0;i < n;i++) {
                if (dir_arr[i] == -1) continue;
                row = vlist[i].first;  //v는 지금 리스트 //wlist는 과거..
                col = vlist[i].second;

                int bef_row = wlist[i].first;
                int bef_col = wlist[i].second;



                for (int j = 0;j < n;j++) {
                    if (j == i || dir_arr[j] == -1) continue;
                    if (wlist[j] == vlist[i]) {
                        if (wlist[i] == vlist[j]) {
                            if (wei_arr[i] > wei_arr[j]) dir_arr[j] = -1;
                            else if (wei_arr[i] < wei_arr[j]) dir_arr[i] = -1;
                            else {
                                if (i < j) dir_arr[i] = -1;
                                else dir_arr[j] = -1;
                            }
                            flag = 1;

                            ans = timer;
                        }
                    }
                }
            }
            flag = 0;
            timer++;
            m.clear();
            for (int i = 0;i < n;i++) {
                if (dir_arr[i] == -1) continue;
                row = vlist[i].first;
                col = vlist[i].second;

                intdir = dir_arr[i];
                auto it = m.find({ row,col });
                if (it == m.end()) {
                    m.insert({ {row,col},{wei_arr[i],i} });
                }
                else {
                    if (it->second.first > wei_arr[i]) {
                        dir_arr[i] = -1;
                    }
                    else {
                        dir_arr[it->second.second] = -1;
                        m[{row, col}] = { wei_arr[i],i };

                    }
                    flag = 1;

                }
            }


            if (flag == 1) {
                ans = timer;
            }
            timer++;

        }

        if (ans == 0) {
            cout << -1 << "\n";
        }
        else cout << ans << "\n";
    }
}