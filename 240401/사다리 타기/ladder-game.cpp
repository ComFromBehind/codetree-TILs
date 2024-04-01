#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, m;
int x, y;  //x는 가로, y는 세로 줄

pair<int, int > arr[18][18];
pair<int, int> brr[18][18];
vector<pair<int, int>> v;
vector<int> anslist;
vector<int> hubolist;

int ans = 1e9;

bool check_vec(vector<int> s, vector<int> t) {
    int s_sz = s.size();
    int t_sz = t.size();
    if (s_sz != t_sz) return false;

    for (int i = 0;i < s_sz;i++) {
        if (s[i] != t[i]) return false;
    }
    return true;
}

vector<int> ans_fill2() {
    vector<int> s;
    for (int i = 1;i <= n;i++) {
        int row = 0;
        int j = i;
        while (row <= 16){
            if (brr[row + 1][j] == make_pair(0,0)) {
                row++;
            }
            else {
                if (j <= n - 1 && brr[row + 1][j + 1].second != 0 && brr[row + 1][j].second == brr[row + 1][j + 1].second + 1) {
                    row++; j += 1;
                }
                else  {
                    row++; j -= 1;
                }
            }
            
        }
        
        s.push_back(j);
    }
    return s;
}

vector<int> ans_fill() {
    vector<int> s;
    
    for (int i = 1;i <= n;i++) {
        int row = 0;
        int j = i;
        while (row <= 16) {
            if (arr[row + 1][j] == make_pair(0, 0)) {
                row++;    
            }
            else {
                if (j<=n-1&&arr[row+1][j+1].second!=0&&arr[row + 1][j].second == arr[row+1][j+1].second+1) {
                    row++;
                    j++;
                }
                else {
                    row++;
                    j--;
                }
            }
            
        }
        
        s.push_back(j);
    }

    return s;
}

int count_brr() {
    int cnt = 0;
    for (int i = 0;i <= 17;i++) {
        for (int j = 0;j <= 17;j++) {
            if (brr[i][j] != make_pair(0, 0)) {
                cnt++;
            }
        }
    }
    return cnt / 2;
}

void func(int k) {
    
    if (k == m) {
        vector<int> temp = ans_fill2();
        
        if (check_vec(temp, anslist)) {
            int temphubo = count_brr();
            ans = min(ans, temphubo);
        }
        return;
    }

    brr[v[k].first][v[k].second] = { v[k].first, v[k].second + 1 };
    brr[v[k].first][v[k].second + 1] = { v[k].first, v[k].second };
    func(k + 1);
    brr[v[k].first][v[k].second] = { 0,0};
    brr[v[k].first][v[k].second + 1] = { 0,0 };
    func(k + 1);


}

int main() {

    cin >> n >> m;

    for (int i = 0;i < m;i++) {
        cin >> x >> y;

        v.push_back({ y,x });
        arr[y][x] = { y, x + 1 };
        arr[y][x + 1] = { y, x };
 
    }
    anslist = ans_fill();
    
    func(0);

    cout << ans;
}