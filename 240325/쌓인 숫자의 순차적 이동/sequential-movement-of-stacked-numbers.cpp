#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;

vector<vector<vector<int>>> v(21,vector<vector<int>>(21));

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

int row;
int col;
int height;

void find(int k) { 
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			for (int t = 0;t < v[i][j].size();t++) {
				if (v[i][j][t]== k) {
					row = i;
					col = j;
					height = t;
				}
			}
		}
	}
}

int find_max_loc(int r, int c) {

	int max_idx = -1;
	int max_val = -1;
	for (int i = 0;i < 8;i++) {
		int nx = r + dx[i];
		int ny = c + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		
		
		if (v[nx][ny].empty()) {
			continue;
		}


		for (int j = 0;j < v[nx][ny].size();j++) {
			if (v[nx][ny][j] > max_val) {
				max_idx = i;
				max_val = v[nx][ny][j];
			}
		}
	}

	return max_idx;
}


void move() {
	vector<int> temp;
	temp.clear();

	for (int i = 0;i <= height; i++){
		temp.push_back(v[row][col][i]);
	}
	
	for (int i = 0;i <= height;i++) {
		v[row][col].erase(v[row][col].begin());
	}

	if (temp.size() == 0) return;

	int dir = find_max_loc(row, col);

	if (dir != -1) {
		for (int i = temp.size()-1;i >= 0;i--) {
			v[row + dx[dir]][col + dy[dir]].insert(v[row + dx[dir]][col + dy[dir]].begin(), temp[i]);
		}
	}
	else {
		if (temp.size() == 0) return;
		for (int i = temp.size() - 1;i >= 0;i--) {
			v[row][col].insert(v[row][col].begin(), temp[i]);
		}
	}
}

void print() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (v[i][j].empty()) {
				cout << "None" << "\n";
			}
			else {
				for (int k = 0;k < v[i][j].size();k++) {
					cout << v[i][j][k] << " ";
				}
				cout << "\n";
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int temp=0;
			cin >> temp;
			v[i][j].push_back(temp);
		}
	}

	int temp = 0;
	for (int i = 0;i < m;i++) {
		cin >> temp;
		find(temp);
		move();
	}
	print();

}