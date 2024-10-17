#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

int n, m;
int s_r, s_c, e_r, e_c;
vector<pair<int, int>> v;

int board[51][51];
int board2[51][51]; // 전사들 여기다가 넣어 놓는다. 
int check[51][51];
int mem[51][51];

queue<pair<int, int>> q;

int dx[4] = { -1,1, 0, 0 };
int dy[4] = { 0,0, -1, 1 };

vector<pair<int, int>> dup_mem;
vector<pair< int, int>> member;
vector<pair< int, int>> ice;

int move_dist;
int stone;
int attacks;

void clear() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			check[i][j] = -1;
		}
	}
}

void clear_memboard() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			mem[i][j] = 0;
		}
	}
}

void print_memboard() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << mem[i][j]<<" ";
		}
		cout << "\n";
	}
}

void bfs() {
	
	q.push({ e_r,e_c });
	check[e_r][e_c] = 0;
	while (!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
	

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (check[nx][ny]>=0 || board[nx][ny]) continue;
			q.push( {nx,ny} );
			check[nx][ny] = check[x][y] + 1;
		}
	}
}

void bfs_warrior(int r, int c) { //r,c는 마녀의 위치
	
	clear();
	q.push({ r,c });
	check[r][c] = 0;
	
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (check[nx][ny] != -1) continue;
			check[nx][ny] = check[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}

pair<int,int> move_medusa(int m_r, int m_s) {
	//move
	
		//전사 체크 후 있다면 삭제
	int now = check[m_r][m_s];
	
	for (int i = 0;i < 4;i++) {
		if (m_r + dx[i] < 0 || m_r + dx[i] >= n || m_s + dy[i] < 0 || m_s + dy[i] >= n) continue;
		if (check[m_r + dx[i]][m_s + dy[i]] == -1) continue;
		if (check[m_r + dx[i]][m_s + dy[i]] < now)
			return { m_r + dx[i], m_s + dy[i] };
	}
	
	
	
}

void erase_possible(int dir, int r, int c, int erase_dir) {
	
	int flag = 0;
	int st_r, st_c;
	int en_r, en_c;
	st_r = r;
	st_c = c;
	en_r = r;
	en_c = c;

	int cnt = 0;

	while (flag == 0) {
		flag = 1;
		if (dir == 0 || dir == 1) {
			if (erase_dir == 1) {
				st_r = st_r + dx[dir]; 
				st_c = st_c - 1;

				en_r = st_r;
				en_c = st_c;
			}
			else if (erase_dir == 3) {
				st_r = st_r + dx[dir];
				st_c = st_c;

				en_r = st_r;
				en_c = st_c;
			}
			else if (erase_dir == 5) {
				st_r = st_r + dx[dir];
				st_c = st_c + 1;

				en_r = st_r;
				en_c = st_c;
			}
			else if (erase_dir == 2) {
				st_r = st_r + dx[dir];
				st_c = st_c - 1;

				en_r = st_r;
				en_c = c;
			}
			else if (erase_dir == 4) {
				st_r = st_r + dx[dir];
				st_c = c;

				en_r = st_r;
				en_c = en_c + 1;

			}
			for (int i = st_c;i <= en_c;i++) {
				if (st_r < 0 || st_r >= n) continue;
				if (i < 0 || i >= n) continue;
				flag = 0;
				mem[st_r][i] = 1;
			}
		}
		else if (dir == 2 || dir == 3) {
			if (erase_dir == 1) {
				st_r = st_r - 1;
				st_c = st_c + dy[dir];

				en_r = st_r;
				en_c = st_c;
			}
			else if (erase_dir == 3) {
				st_r = st_r;
				st_c = st_c + dy[dir];

				en_r = st_r;
				en_c = st_c;
			}
			else if (erase_dir == 5) {
				st_r = st_r + 1;
				st_c = st_c + dy[dir];

				en_r = st_r;
				en_c = st_c;
			}
			else if (erase_dir == 2) {
				st_r = st_r - 1;
				st_c = st_c + dy[dir];

				en_r = r;
				en_c = st_c;
			}
			else if (erase_dir == 4) {
				st_r = r;
				st_c = st_c + dy[dir];

				en_r = en_r + 1;
				en_c = st_c;
			}
			for (int i = st_r;i <= en_r;i++) {
				if (st_c < 0 || st_c >= n) continue;
				if (i < 0 || i >= n) continue;
				flag = 0;
				mem[i][st_c] = 1;
			}
		}
		

	}
	
	
}

int coloring_direction( int dir , int r, int c) {
	//해당 방향 기준 몇 명이 서있는지 확인 후 return
	
	int flag = 0;
	int st_r, st_c;
	int en_r, en_c;
	st_r = r; st_c = c; en_r = r; en_c = c;
	
	int cnt = 0;

	while (flag == 0) {
		flag = 1;
		if (dir == 0 || dir == 1) {
			st_r = st_r + dx[dir]; en_r = en_r + dx[dir]; //st_r == en_r 이다.
			st_c = st_c + dy[2]; en_c = en_c + dy[3];
			

			for (int i = st_c;i <= en_c;i++) {
				if (st_r < 0 || st_r >= n) continue;
				if (i < 0 || i >= n) continue;
				if (mem[st_r][i] >= 1) continue;
				
				flag = 0;
				mem[st_r][i] = -1;
				
				
				if (board2[st_r][i] > 0) {
					cnt += board2[st_r][i];
					
					int erase_dir;
					
					if (i == st_c) erase_dir = 1;
					else if (i == en_c) erase_dir = 5;
					else if (i == c) erase_dir = 3;
					else if (i > st_c && i < c) erase_dir = 2;
					else if (i > c && i < en_c) erase_dir = 4;

					erase_possible(dir, st_r, i, erase_dir ); //mem 에서 불가능하도록 영역을 0보다 낮게 바꾸줌.
				}
			}
		}
		else {
			st_r = st_r + dx[0]; en_r = en_r + dx[1];
			st_c = st_c + dy[dir]; en_c = en_c + dy[dir]; //st_c == en_c 이다.
		
			for (int i = st_r;i <= en_r;i++) {
				if (st_c < 0 || st_c >= n) continue;
				if (i < 0 || i >= n) continue;
				if (mem[i][st_c] >= 1) continue;
				flag = 0;
				mem[i][st_c] = -1;
				if (board2[i][st_c] > 0) {
					cnt += board2[i][st_c];
					int erase_dir;

					if (i == st_r) erase_dir = 1;
					else if (i == en_r) erase_dir = 5;
					else if (i == r) erase_dir = 3;
					else if (i > st_r && i < r) erase_dir = 2;
					else if (i > r && i < en_r) erase_dir = 4;

					erase_possible(dir, i, st_c, erase_dir);
				}
			}
		}	
	}

	return cnt;
}

void locking_soldier() {
	//전사들이 얼음.
}

void dir_check_medusa() {
	//eye_of_medusa를 4방향 모두 체크해보고 가장 높은 결과가 나온 방향으로 쳐다봄.
	//이에따라 해당방향에 있는 전사들 얼음.
}

void move_soldier() {
	//move

	//움직일 수 있는 지 체크 후 이동.
}

void attack_from_soldier() {

}

int main() {
	
	cin >> n >> m;
	cin >> s_r >> s_c >> e_r >> e_c;

	

	for (int i = 0;i < m;i++) {
		int temp_r;
		int temp_c;
		cin >> temp_r >> temp_c;
		
				
;		board2[temp_r][temp_c]++;
		v.push_back({ temp_r, temp_c });

	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> board[i][j];
		}
	}
	

	//check 확인용
	//for (int i = 0;i < n;i++) {
	//	for (int j = 0;j < n;j++) {
	//		cout << check[i][j]<<" ";
	//	}
	//	cout << "\n";
	//}

	if (check[s_r][s_c] == -1) {
		cout << "-1";
		exit(0);
	}

	int now_r = s_r;
	int now_c = s_c;

	pair<int, int> temp_pair;

	//print_memboard();

	while (1) { //medusa가 공원에 도착해서 종료되기까지.. (미완)
		

		move_dist = 0;
		attacks = 0;
		stone = 0;
		
		clear();
		bfs();
		
		temp_pair = move_medusa(now_r, now_c);		

		now_r = temp_pair.first;
		now_c = temp_pair.second;

		for (auto it = v.begin(); it != v.end();) {
			pair<int, int>& t = *it;
			if (t.first == now_r && t.second == now_c) {
				board2[t.first][t.second]--;
				it=v.erase(it);
			}
			else it++;

		}

		if (now_r == e_r && now_c == e_c) {
			cout << 0;
			break;
		}


		int maxdir = -1;
		int maxcnt = -1;
		int tempcnt = 0;
		
		for (int i = 0;i < 4;i++) {
			
			clear_memboard();
			tempcnt = coloring_direction(i, now_r, now_c);
			
			if (tempcnt > maxcnt) {
				maxcnt = tempcnt;
				maxdir = i;
			}
			
		}

		clear_memboard();
		stone = coloring_direction(maxdir, now_r, now_c);

		clear();
		bfs_warrior(now_r, now_c);
		
		
		
		int times = 2;
		
		int flag2 = 0;
		while (times--) {
			
			
			for (auto it = v.begin(); it != v.end();) {
				flag2 = 0;
				pair<int, int>& t = *it;
				if (mem[t.first][t.second] <= -1) {
					
					it++;
					
				}
				else {
					

					int param = check[t.first][t.second];
					int idx = -1;
					for (int i = 0;i < 4;i++) {
						if (t.first + dx[i] < 0 || t.first + dx[i] >= n || t.second + dy[i] < 0 || t.second + dy[i] >= n) {
							continue;
						}
						if (mem[t.first + dx[i]][t.second + dy[i]] == -1) {
							continue;
						}
						
						if (check[t.first + dx[i]][t.second + dy[i]] < param) {
							param = check[t.first + dx[i]][t.second + dy[i]];
							idx = i;
						}
					}
					if (idx!=-1) {
						if (mem[t.first + dx[idx]][t.second + dy[idx]] >= 0) {
							board2[t.first][t.second]--;
							t.first = t.first + dx[idx];
							t.second = t.second + dy[idx];
							move_dist++;
							board2[t.first][t.second]++;
							if (t.first == now_r && t.second == now_c) {
								attacks++;

								flag2 = 1;
								board2[t.first][t.second]--;
								it = v.erase(it);
							}

						}
						

					}
					if (flag2 == 0) it++;
				}
				
			}
		}

		cout << move_dist << " " << stone << " " << attacks << "\n";
		
		
	}

	
}