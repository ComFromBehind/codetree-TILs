#include <iostream>
#include <queue>

using namespace std;

int n,k;
int arr[101][101];
int a, b;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool check[101][101];
queue<pair<int, int>> q;
int ans;
void bfs() {
	
	
	while (!q.empty()) {
		
		
		auto c = q.front();
		int x = c.first;
		int y = c.second;
		q.pop();
		if (check[x][y]||arr[x][y]!=0) continue;
		check[x][y] = 1;
		ans++;
		
		for (int i = 0;i < 4;i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (check[nx][ny] != 0 || arr[nx][ny] == 1) continue;
			
			q.push({ nx,ny });
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0;i < k;i++) {
		cin >> a >> b;
		q.push({ a,b });
		bfs();
	}
	cout << ans;
	

}