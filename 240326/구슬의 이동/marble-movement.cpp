#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
int m, t, k;

typedef tuple <int, int, int, int, int> ball;
vector<ball> v;

int brr[51][51];

int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };

bool ops(tuple<int, int, int, int, int> a, tuple<int, int, int, int, int> b) {
	
	if (get<1>(a) < get<1>(b))  return true; 
	if (get<1>(a) > get<1>(b)) return false; 
	if (get<2>(a) < get<2>(b)) 	return true;
	if (get<2>(a) > get<2>(b))  return false; 
	if (get<4>(a) > get<4>(b))  return true;
	if (get<4>(a) < get<4>(b))  return false;
	return get<0>(a) > get<0>(b);

}

void clear() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++)
			brr[i][j] = 0;
	}
}

int dir_trans(char a) {
	if (a == 'L') return 0;
	else if (a == 'R') return 3;
	else if (a == 'U') return 1;
	else if (a == 'D') return 2;
}

int main() {
	cin >> n >> m >> t >> k;

	int row = 0;
	int col = 0;
	char dir = ' ';
	int spd = 0;
	for (int i = 0;i < m;i++) {

		cin >> row >> col >> dir >> spd;
		int intdir = dir_trans(dir);
		v.push_back(make_tuple(i, row - 1, col - 1, intdir, spd));
	}
		//옮기고
	int sz = v.size();
	
	while (t--) {
		sz = v.size();
		int intdir = 0; int idx = 0;
		for (int i = 0;i < sz;i++) {
			idx = get<0>(v[i]);
			row = get<1>(v[i]);
			col = get<2>(v[i]);
			intdir = get<3>(v[i]);
			spd = get<4>(v[i]);
			for (int j = 0;j < spd;j++) {
				int nx = dx[intdir] + row;
				int ny = dy[intdir] + col;
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
					intdir = 3 - intdir;
					nx = dx[intdir] + row;
					ny = dy[intdir] + col;
				}
				row = nx; col = ny;
			}
			v[i] = make_tuple(idx, row, col, intdir, spd);
		}
		sort(v.begin(), v.end(), ops);

		int cnt = 1;
		vector<int> eraser; //지울 idx 저장..
		for (int i = 1;i < sz;i++) {
			if (get<1>(v[i]) == get<1>(v[i - 1]) && get<2>(v[i]) == get<2>(v[i - 1])) {
				cnt++;
				if (cnt > k) {
					eraser.push_back(i);
				}
			}
			else {
				cnt = 1;
			}
		}

		for (int i = eraser.size() - 1;i >= 0;i--) {
			v.erase(v.begin()+eraser[i]);
		}

		
	}

	cout << v.size();
}