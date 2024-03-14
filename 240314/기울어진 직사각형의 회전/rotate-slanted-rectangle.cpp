#include <iostream>
using namespace std;

int n;

int arr[101][101];

int r, c, m1, m2, m3, m4, dir;

void rotate_clockwise() { //dir  = 1


	int temp1 = arr[r - m2][c - m2];
	for (int i = 0;i < m2;i++) {
		arr[r - m2 + i][c - m2 + i] = arr[r - m2 + i + 1][c - m2 + i + 1];

	}

	int temp2 = arr[r - m1 - m2][c - m2 + m1];
	for (int i = 0;i < m1 - 1;i++) {
		arr[r - m1 - m2 + i][c - m2 + m1 - i] = arr[r - m1 - m2 + i + 1][c - m2 + m1 - i - 1];

	}
	arr[r - m2 - 1][c - m2 + 1] = temp1;



	int temp3 = arr[r - m1][c + m1];
	for (int i = 0;i < m2 - 1;i++) {
		arr[r - m1 - i][c + m1 - i] = arr[r - m1 - i - 1][c + m1 - i - 1];
	}
	arr[r - m1 - m2 + 1][c - m2 + m1 + 1] = temp2;


	for (int i = 0;i < m1 - 1;i++) {
		arr[r - i][c + i] = arr[r - i - 1][c + i + 1];
	}
	arr[r - m1 + 1][c + m1 - 1] = temp3;
}

void rotate_anticlockwise() { //dir = 0
	int temp1 = arr[r - m1][c + m1];
	for (int i = 0;i < m1;i++) {
		arr[r - m1 + i][c + m1 - i] = arr[r - m1 + i + 1][c + m1 - i - 1];

	}

	int temp2 = arr[r - m1 - m2][c + m1 - m2];
	for (int i = 0;i < m2 - 1;i++) {
		arr[r - m1 - m2 + i][c + m1 - m2 + i] = arr[r - m1 - m2 + i + 1][c + m1 - m2 + i + 1];
	}
	arr[r - m1 - 1][c + m1 - 1] = temp1;

	int temp3 = arr[r - m4][c - m4];
	for (int i = 0;i < m3 - 1;i++) {
		arr[r - m4 - i][c - m4 + i] = arr[r - m4 - i - 1][c - m4 + i + 1];

	}
	arr[r - m2 - m1 + 1][c + m1 - m2 - 1] = temp2;

	for (int i = 0; i < m4 - 1;i++) {
		arr[r - i][c - i] = arr[r - i - 1][c - i - 1];
	}
	arr[r - m4 + 1][c - m4 + 1] = temp3;
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}

	cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

	r = r - 1; c = c - 1;

	if (dir == 0)
		rotate_anticlockwise();
	else
		rotate_clockwise();

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

}