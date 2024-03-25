#include <iostream>
#include <vector>

using namespace std;

int t, n, m;
int arr[51][51];
string brr[51][51];
string crr[51][51];
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };

int dir_trans(char dir) {
	if (dir == 'L') return 0;
	else if (dir == 'R') return 3;
	else if (dir == 'U') return 1;
	else if (dir == 'D') return 2;
}

char dir_reverse(char dir) {
	if (dir == 'L') return 'R';
	else if (dir == 'R') return 'L';
	else if (dir == 'U') return 'D';
	else if (dir == 'D') return 'U';
}

void clear() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			brr[i][j].clear();
			crr[i][j].clear();
		}
	}
}

void print() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << brr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

int main() {
	cin >> t;

	while (t--) {
		cin >> n >> m;

		clear();

		
		for (int i = 0;i < m;i++) {
			int row = 0;
			int col = 0;
			char dir = '\0';
			
			cin >> row >> col >> dir;
			
			brr[row - 1][col - 1] += dir;
	
		}

		int cycle = 2 * n + 1;
		while (cycle--) {
			
			for (int i = 0;i < n;i++) {
				for (int j = 0;j < n;j++) crr[i][j].clear();
			}
			for (int i = 0;i < n;i++) {
				for (int j = 0;j < n;j++) {
					if (!brr[i][j].empty()) {
						for (int k = 0;k < brr[i][j].size();k++) {
							
							int go_x = dx[dir_trans(brr[i][j][k])]+i;
							int go_y = dy[dir_trans(brr[i][j][k])] + j;
							
							if (go_x < 0 || go_x >= n || go_y < 0 || go_y >= n) {
								crr[i][j] += dir_reverse(brr[i][j][k]);
							}

							else {
								crr[go_x][go_y] += brr[i][j][k];
							}
								//go_x와 go_y가 범위를 넘어서면 방향전환후 c에게 넘겨줌
								//아니면 그대로 이동시켜서 c에다가 넘겨줌
								//모든 과정 진행후, c에 겹치는 곳이 있으면 그부분 폭파
								//이후 c를 b로 넘겨주고 c 초기화.
						}
					}
				}
			}
			for (int i = 0;i < n;i++) {
				for (int j = 0;j < n;j++) {
					if (crr[i][j].size() > 1) {
						crr[i][j].clear();
					}
				}
			}

			for (int i = 0;i < n;i++) {
				for (int j = 0;j < n;j++) {
					brr[i][j] = crr[i][j];
				}
			}

		}
		int ans = 0;

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (!brr[i][j].empty()) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}