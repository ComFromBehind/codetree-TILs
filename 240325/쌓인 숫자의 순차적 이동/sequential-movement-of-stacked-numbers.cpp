#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;

string arr[21][21];
int brr[21][21]; 

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

int row;
int col;
int height;

void find(int k) { 
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			for (int t = 0;t < arr[i][j].size();t++) {
				if (arr[i][j][t] - '0' == k) {
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
		
		
		if (arr[nx][ny].empty()) {
			continue;
		}


		for (int j = 0;j < arr[nx][ny].size();j++) {
			if ((arr[nx][ny][j] - '0') > max_val) {
				max_idx = i;
				max_val = arr[nx][ny][j] - '0';
			}
		}
	}

	return max_idx;
}


void move() {
	string temp;
	temp.clear();
	for (int i = 0;i <= height; i++){
		temp += arr[row][col][i];
	}
	for (int i = 0;i <= height;i++) {
		arr[row][col].erase(arr[row][col].begin());
	}

	if (temp.size() == 0) return;

	int dir = find_max_loc(row, col);

	if (dir != -1) {
		for (int i = temp.size()-1;i >= 0;i--) {
			arr[row + dx[dir]][col + dy[dir]].insert(arr[row + dx[dir]][col + dy[dir]].begin(), temp[i]);
		}
	}
	else {
		if (temp.size() == 0) return;
		for (int i = temp.size() - 1;i >= 0;i--) {
			arr[row][col].insert(arr[row][col].begin(), temp[i]);
		}
	}
}

void print() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j].empty()) {
				cout << "None" << "\n";
			}
			else {
				for (int k = 0;k < arr[i][j].size();k++) {
					cout << arr[i][j][k] << " ";
				}
				cout << "\n";
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
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