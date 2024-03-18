#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[201][201];
vector<int> v;
int brr[201][201];
void boom(int col) {
	int row = -1;
	for (int i = 0;i < n;i++) {
		if (arr[i][col] != 0){
			row = i;
			break;
		}
	}

	if (row == -1) return;

	int bomb_sz = arr[row][col];
    
	int st = col - bomb_sz + 1;
	if (st < 0) st = 0;
	int en = col + bomb_sz - 1;
	if (en >= n-1) en = n - 1;


	int center_st = row - bomb_sz + 1;
	if (center_st < 0) center_st = 0;
	int center_en = row + bomb_sz - 1;
	if (center_en >= n-1) center_en = n-1;

	for (int i = st;i <= en;i++) {
		
        if (i == col) {
			for (int j = center_st;j <= center_en;j++) {
				arr[j][i] = 0;
			}
		}
		else {
			arr[row][i] = 0;
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = n - 1;j >= 0;j--) {
			if (arr[j][i] != 0)
				v.push_back(arr[j][i]);
		}

		for (int j = 0;j < v.size();j++) {
			arr[n - 1 - j][i] = v[j];
		}
		for (int j = v.size();j < n;j++) {
			arr[n - 1 - j][i] = 0;
		}
        v.clear();
	}
	
}

int main() {
	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}

	while (m--) {
		int bomb_row = 0;
		cin >> bomb_row;

		boom(bomb_row - 1);
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}