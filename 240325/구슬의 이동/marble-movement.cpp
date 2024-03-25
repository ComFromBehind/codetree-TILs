#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m, t, k;

int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };

bool ops(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	
	return get<3>(a) > get<3>(b);
	if (get<3>(a) == get<3>(b)) {
		return a > b;
	}
}

int dir_translate(char a) {
	if (a == 'L') return 0;
	else if (a == 'R') return 3;
	else if (a == 'U') return 1;
	else if (a == 'D') return 2;
}

typedef tuple<int, int, int, int> ball;

vector<ball> v;

int main() {
	cin >> n >> m >> t >> k;


	int row = 0;
	int col = 0;
	char dir = ' ';
	int spd = 0;
	for (int i = 0;i < m;i++) {
		cin >> row >> col >> dir >> spd;
		v.push_back(make_tuple(row - 1, col - 1, dir_translate(dir), spd));
	}

	while (t--) {
		int sz = v.size();

		int intdir = 0;
		for (int i = 0;i < sz;i++) { //v[i] 이동!
			row = get<0>(v[i]);
			col = get<1>(v[i]);
			intdir = get<2>(v[i]);
			spd = get<3>(v[i]);

			int x_dir = dx[intdir];
			int y_dir = dy[intdir];

			for (int j = 0;j < spd;j++) {
				int nrow = row + x_dir;
				int ncol = col + y_dir;
				if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n) {
					intdir = 3 - intdir;
					x_dir = dx[intdir];
					y_dir = dy[intdir];
					nrow = row + x_dir;
					ncol = col + y_dir;

				}
				row = nrow; col = ncol;
			}

			v[i] = make_tuple(row, col, intdir, spd);
		}

		sort(v.begin(), v.end(), ops);

		int cnt = 1;
		vector<int> eraser;
		for (int i = 1;i < v.size();i++) {
			if (get<0>(v[i]) == get<0>(v[i - 1]) && get<1>(v[i]) == get<1>(v[1])){
				cnt++;
				if (cnt > k) {
					eraser.push_back(i);
				}
			}
			else {
				cnt = 1;
			}
		}

		for (int i = eraser.size()-1;i >=0 ;i--) {
			v.erase(v.begin() + eraser[i]);
		}

		//중복된거 정렬 후 우선순위 넘어선거 부터 제거!
	}

	cout << v.size();
}