#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int n;
int m; // 사과 개수
int k; // 뱀 방향 전환 수
char dir;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[101][101];
int ans = 0;
int row = 0;
int col = 0;
vector<pair<int, int>> v;
vector<pair<char, int>> w;
int p;

int dir_translate () {
    if (dir == 'L') return 3;
    else if (dir == 'R') return 1;
    else if (dir == 'U') return 2;
    else if (dir == 'D') return 0;
}

int main() {
    cin >> n >> m >> k;

    while (m--) {
        int r = 0; int c = 0;
        cin >> r >> c;
        arr[r - 1][c - 1] = -1;
    }
    
    v.push_back({ row,col });
    int tmp = k;
    while (k--) {
        cin >> dir;
        cin >> p;
        w.push_back({ dir,p });
    }
    k = tmp;
    tmp = 0;
    while (tmp!=k) {
        dir = w[tmp].first;
        p = w[tmp].second;
        int tail_flag = 0;
        while (p--) {
            ans++;
            tail_flag = 1;
            int tail_row = v.back().first;
            int tail_col = v.back().second;

          
            
            
            int head_row = v.front().first;
            int head_col = v.front().second;
            
            int new_dir = dir_translate();
            
            int nx = head_row + dx[new_dir];
            int ny = head_col + dy[new_dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                cout << ans;
                exit(0); // 벽과 부딪혀서 끝남. 여기서 종료
            }

            if (arr[nx][ny] > 0 || (nx==tail_row&&ny==tail_col)) {
                cout << ans;
                exit(0); // 자기 몸뚱아리에 부딪혀서 끝남. 여기서 종료
            }
            
            if (arr[nx][ny] = -1) {
                v.push_back({ tail_row,tail_col }); //꼬리 붙여주기
                arr[tail_row][tail_col] = 1;
           
                tail_flag = 0;
            }

            arr[nx][ny] = 1;
            v.insert(v.begin(), { nx,ny });

            if (tail_flag == 1) {
                arr[tail_row][tail_col] = 0;
                v.pop_back(); //꼬리를 잘라준다. 
            }
        }
        tmp++;
    }

    cout << ans; //뱀이 전부 움직여서 끝남.

}