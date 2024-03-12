#include <iostream>
using namespace std;

int arr[101][101];
int n; int m;
int ans;
void func_row(int row) {
    int temp = 0;
    int cnt = 1;
    for (int i = 0;i <= n;i++) {
        if (i == 0) temp = arr[i][row];
        else if (arr[i][row] == temp) cnt++;
        else cnt = 1;
        temp = arr[i][row];
        if (cnt >= m) {
            ans++;
            break;
        }
    }
}

void func_col(int col) {
    int temp = 0;
    int cnt = 1;
    for (int i = 0;i <= n;i++) {
        if (i == 0) temp = arr[col][i];
        else if (arr[col][i] == temp) cnt++;
        else cnt = 1;
        temp = arr[col][i];
        if (cnt >= m) {
            ans++;
            break;
        }

    }
}

int main() {
    cin >> n;
    cin >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
        }
    }

    for (int t = 0;t < n;t++) {
        func_row(t);
        func_col(t);
    }

    cout << ans;
}