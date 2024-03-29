#include <iostream>
using namespace std;

int n;

int x, y;
char arr[101][101];

int check[101][101][4];



int dx[4] = { 0,1,0,-1 }; //오른쪽, 아래, 왼쪽, 위 순서
int dy[4] = { 1,0,-1,0 };

int ans;
int now_dir;
int move_flag; //이미 벽이없는 상태에서 회전을 했을 때, 그대로 전진함.
int double_check; // 중복된 체크 두번 발생하면 fail;
bool right_check(int x, int y, int nowdir) {
    int wall_loc = (nowdir + 1) % 4;

    int nx = dx[wall_loc] + x;
    int ny = dy[wall_loc] + y;


    if (nx < 0 || nx >= n || ny < 0 || ny >= n) return false; //벽이 없음

    if (arr[nx][ny] == '#') return true;
    else {
        return false;
    }
}

void move_dir() {
    now_dir = (now_dir + 1) % 4;
}

void going() {
    int nx = dx[now_dir] + x;
    int ny = dy[now_dir] + y;

    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
    {
        x = nx;
        y = ny;
        ans++;
        return;
    }
    if (arr[nx][ny] == '#') {
        now_dir = (now_dir + 3) % 4;
    }
    else {
        x = nx;
        y = ny;
        ans++;
    }

}

int main() {

    cin >> n >> x >> y;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
        }
    }

    x = x - 1; y = y - 1;
    now_dir = 0;



    while (1) {
        if (double_check == 1 && check[x][y][now_dir] != 0) {
            cout << -1;
            exit(0);
        }
        else if (check[x][y][now_dir] != 0) double_check = 1;
        
        else {
            double_check = 0;
            check[x][y][now_dir] = 1;
        }
        if (right_check(x, y, now_dir)) {
            going();
            move_flag = 0;
        }

        else {

            if (move_flag == 0) {
                move_flag = 1;move_dir();
            }
            else {
                move_flag = 0; going();
            }


        }
        if (x < 0 || x >= n || y < 0 || y >= n) {
            cout << ans;
            exit(0);
        }

        
        

    }

    cout << -1; //실패시 -1 출력

    return 0;
}