#include <iostream>
using namespace std;

int n, m, q;
int r;
char wind;

int dir;
int arr[101][101];

void left_move(int row, int dir) {

    int temp = arr[row][m - 1];
    for (int i = m - 1;i > 0;i--) {
        arr[row][i] = arr[row][i - 1];
    }
    arr[row][0] = temp;
}

void right_move(int row, int dir) {

    int temp = arr[row][0];
    for (int i = 0;i < m - 1;i++) {
        arr[row][i] = arr[row][i + 1];
    }
    arr[row][m - 1] = temp;
}


void dir_check(int dir, int row) {
    if (dir == 0) {
        left_move(row, dir);
    }
    else if (dir == 1) {
        right_move(row, dir);
    }
}




bool up_check(int row) {
    if (row == 0) return false;

    int flag = 1;

    for (int i = 0;i < m;i++) {
        if (arr[row][i] == arr[row - 1][i])
            flag = 0;
    }

    if (flag == 0) return true;
    else return false;
}

bool down_check(int row) {
    if (row == n - 1) return false;

    int flag = 1;

    for (int i = 0;i < m;i++) {
        if (arr[row][i] == arr[row + 1][i])
            flag = 0;
    }

    if (flag == 0) return true;
    else return false;
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> arr[i][j];
        }
    }

  

    while (q--) {
        cin >> r >> wind;
        r = r - 1;
        if (wind == 'L') dir = 0;
        else dir = 1;

        dir_check(dir, r); //dir_check하고 이후 움직임까지 가져감

        int temp_dir = dir;
        int r1 = r;
        while (up_check(r1)) {
            if (temp_dir == 0) temp_dir = 1;
            else temp_dir = 0;
            dir_check(temp_dir, r1 - 1);
            r1--;
        }

        int temp_dir2 = dir;
        int r2 = r;
        while (down_check(r2)) {
            if (temp_dir2 == 0) temp_dir2 = 1;
            else temp_dir2 = 0;
            dir_check(temp_dir2, r2 + 1);
            r2++;
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

}