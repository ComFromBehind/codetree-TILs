#include <iostream>
#include <vector>
using namespace std;

int r, c, k;

int check[71][71];
int col;
int dir;
int row = 0;
bool block_check = 0;
vector<pair<int, int>> v;
vector<int> v2;
int dir_4[4] = { 0,1,2,3 };
int ans;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void reset_board() {
	for (int i = 0;i <= r;i++) {
		for (int j = 0;j <= c;j++) {
			check[i][j] = 0;
		}
	}
}

void print_board() {
	for (int i = 1;i <= r;i++) {
		for (int j = 1;j <= c;j++) {
			cout << check[i][j];
		}
		cout << "\n";
	}
}

void paint_board(int num) {
	check[row][col] = num;
	check[row - 1][col] = num;
	check[row - 2][col] = num;
	check[row - 1][col + 1] = num;
	check[row - 1][col - 1] = num;
}

void move_to_south() {
	block_check = 0;
	while (block_check == 0) {

		if (row + 1 > r) {
			block_check = 1; continue;
		}
		if (check[row + 1][col] != 0) block_check = 1;
		if (check[row][col - 1] != 0) block_check = 1;
		if (check[row][col + 1] != 0) block_check = 1;
		if (block_check != 1) {
			row++;

		}
	}
}

void possible_move() {
	row = 0;
	
	move_to_south();

	block_check = 0;
	while (block_check == 0) {
		if (col <= 2) {
			block_check = 1; continue;
		}
		if (row + 1 > r) {
			block_check = 1; continue;
		}
		
		if (check[row][col - 1] != 0) block_check = 1;
		if (check[row + 1][col - 1] != 0) block_check = 1;
		if (check[row ][col - 2] != 0) block_check = 1;
		
		if (row>=1&&check[row - 1][col - 2] != 0) block_check = 1;
		if (row>=2&&check[row - 2][col - 1] != 0) block_check = 1;
		if (block_check != 1) {
			row++; col--; dir = (dir + 3) % 4;
			
		}
	}

	move_to_south();

	block_check = 0;
	while (block_check == 0) {
		if (col >= c - 1) {
			block_check = 1; continue;
		}
		if (row + 1 > r) {
			block_check = 1;
			continue;
		}
		if (check[row][col + 1] != 0) block_check = 1;
		if (check[row + 1][col + 1] != 0) block_check = 1;
		if (check[row][col + 2] != 0) block_check = 1;
		if (row>=1&&check[row - 1][col + 2] != 0) block_check = 1;
		if (row>=2&&check[row - 2][col + 1] != 0)block_check = 1;
		if (block_check != 1) {
			row++; col++; dir = (dir + 1) % 4;
			
		}
	}

	move_to_south();

	if (row <= 2) reset_board();
	else {
		
		int max = 0;
		paint_board(row);

		int r1, c1;
		if (dir == 0) {
			r1 = row - 2;
			c1 = col;
		}
		else if (dir == 1) {
			r1 = row - 1;
			c1 = col + 1;
		}
		else if (dir == 2) {
			r1 = row;
			c1 = col;
		}
		else if (dir == 3) {
			r1 = row - 1;
			c1 = col - 1;
		}

		for (int i = 0;i < 4;i++) {
			if (r1 + dx[i] <= 0 || r1 + dx[i] > r || c1 + dy[i] <= 0 || c1 + dy[i] > c) continue;

			if (max < check[r1 + dx[i]][c1 + dy[i]]) {
				max = check[r1 + dx[i]][c1 + dy[i]];

			}
		}
		paint_board(max);

		ans += max;
	}
}

int main() {

	cin >> r >> c >> k;

	for (int i = 0;i < k;i++) {
		cin >> col;
		cin >> dir;
		possible_move();
		//print_board(); 
	}

	
	cout << ans;
	
	

}