#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX_N 100
#define DIR_NUM 4

using namespace std;

// 전역 변수 선언:
int n, k;

int a[MAX_N][MAX_N];

int r1, c1, r2, c2;

vector<pair<int, int> > stone_pos;

// bfs에 필요한 변수들 입니다.
queue<pair<int, int> > q;
bool visited[MAX_N][MAX_N];
int step[MAX_N][MAX_N]; // step[i][j] : 시작점으로부터 
                        // (i, j) 지점에 도달하기 위한 
                        // 최단거리를 기록합니다.

int ans = INT_MAX;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

// 격자를 벗어나지 않으면서, 벽도 없고, 아직 방문한 적이 없는 곳이라면
// 지금 이동하는 것이 최단거리임을 보장할 수 있으므로 가야만 합니다. 
bool CanGo(int x, int y) {
    return InRange(x, y) && !a[x][y] && !visited[x][y];
}

// queue에 새로운 위치를 추가하고
// 방문 여부를 표시해줍니다.
// 시작점으로 부터의 최단거리 값도 갱신해줍니다.
void Push(int nx, int ny, int new_step) {
    q.push(make_pair(nx, ny));
    visited[nx][ny] = true;
    step[nx][ny] = new_step;
}

// bfs를 통해 최소 이동 횟수를 구합니다.
int bfs() {
    // queue에 남은 것이 없을때까지 반복합니다.
    while(!q.empty()) {
        // queue에서 가장 먼저 들어온 원소를 뺍니다.
        pair<int, int> curr_pos = q.front();
        int x = curr_pos.first, y = curr_pos.second;
        q.pop();

        int dx[DIR_NUM] = {-1, 1, 0, 0};
        int dy[DIR_NUM] = {0, 0, -1, 1};

        // queue에서 뺀 원소의 위치를 기준으로 4방향을 확인해봅니다.
        for(int dir = 0; dir < DIR_NUM; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            // 아직 방문한 적이 없으면서 갈 수 있는 곳이라면
            // 새로 queue에 넣어줍니다.
            if(CanGo(nx, ny))
                // 최단 거리는 이전 최단거리에 1이 증가하게 됩니다. 
                Push(nx, ny, step[x][y] + 1);
        }
    }

    // 도착점에 가는 것이 가능할때만
    // 답을 갱신해줍니다.
    if(visited[r2][c2])
		return step[r2][c2];
	else
		return INT_MAX;
}

void FindMin(int idx, int cnt) {
	if(idx == (int) stone_pos.size()) {
		if(cnt == k) {
            // visited, step 값을 초기화 해줍니다.
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++) 
					visited[i][j] = step[i][j] = 0;
            
		    // bfs를 이용해 최소 이동 횟수를 구합니다.
		    // 시작점을 queue에 넣고 시작합니다.
		    Push(r1, c1, 0);
		    int min_dist = bfs();
			ans = min(min_dist, ans);
		}
		return;
	}
	
	a[stone_pos[idx].first][stone_pos[idx].second] = 0;
	FindMin(idx + 1, cnt + 1);
	a[stone_pos[idx].first][stone_pos[idx].second] = 1;
	
	FindMin(idx + 1, cnt);
}

int main() {
    // 입력:
    cin >> n >> k;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			if(a[i][j])
				stone_pos.push_back(make_pair(i, j));
		}
	
	cin >> r1 >> c1; r1--; c1--;
	cin >> r2 >> c2; r2--; c2--;
	
	FindMin(0, 0);

    // 출력:
    if(ans == INT_MAX)  // 불가능한 경우라면
        ans = -1;       // -1을 답으로 넣어줍니다.
    
    cout << ans;

    return 0;
}