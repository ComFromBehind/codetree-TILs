#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[51][51];
int brr[51][51]; //임시 저장공간
int ans;

void print() {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cout << brr[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "\n";
}

void copy_array() {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            brr[i][j] = arr[i][j];
        }
    }
}

void falling() {

    vector<int> v;
    for (int i = 0;i < n;i++) {
        v.clear();
        for (int j = n - 1;j >= 0;j--) {
            if (brr[j][i] != 0) v.push_back(brr[j][i]);
        }
        for (int j = 0;j < v.size();j++) {
            brr[n - 1 - j][i] = v[j];
        }
        for (int j = v.size();j < n;j++) {
            brr[n - 1 - j][i] = 0;
        }
    }
}

void counting() {
    int cnt = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 1;j < n;j++) {
            if (brr[i][j] == brr[i][j - 1] && brr[i][j] != 0) cnt++;
            if (brr[j][i] == brr[j - 1][i] && brr[j][i] != 0) cnt++;
        }
    }
    ans = max(cnt, ans);
}

void bomb(int row, int col) {

    copy_array();

    int bomb_sz = arr[row][col];

    int st = col - (bomb_sz - 1);
    if (st < 0) st = 0;
    int en = col + (bomb_sz - 1);
    if (en > n - 1) en = n - 1;

    int row_st = row - (bomb_sz - 1);
    if (row_st < 0) row_st = 0;
    int row_en = row + (bomb_sz - 1);
    if (row_en > n - 1) row_en = n - 1;

    for (int i = st;i <= en;i++) {
        if (i == col) {
            for (int j = row_st;j <= row_en;j++) {
                brr[j][i] = 0;
            }
        }
        else {
            brr[row][i] = 0;
        }
    }

    falling();
    counting();
    
}

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            bomb(i, j);
        }
    }

    cout << ans;

}