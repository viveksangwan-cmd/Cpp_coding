#include <bits/stdc++.h>
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}
bool check(vector<vector<int>> &sudoku, int row, int col, int no) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[row][i] == no) return false;
	}

	for (int i = 0; i < 9; i++) {
		if (sudoku[i][col] == no) return false;
	}

	int tri = (row / 3) * 3;
	int trj = (col / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (sudoku[tri + i][trj + j] == no) return false;
		}
	}
	return true;
}

void display(vector<vector<int>> sudoku) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void solveSodoku(vector<vector<int>> &sudoku, int i, int j) {
	if (i == 9) {
		display(sudoku);
		return;
	}
	int ni = 0;
	int nj = 0;

	if (j == sudoku[0].size() - 1) {
		ni = i + 1;
		nj = 0;
	} else {
		ni = i;
		nj = 1 + j;
	}

	if (sudoku[i][j] != 0) {
		solveSodoku(sudoku, ni, nj);
	} else {
		for (int c = 1; c <= 9; c++) {
			if (check(sudoku, i, j, c) == true) {
				sudoku[i][j] = c;
				solveSodoku(sudoku, ni, nj);
				sudoku[i][j] = 0;

			}
		}
	}

}

int main() {
	sublime();
	vector<vector<int>> sudoku(9, vector<int> (9, 0));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
		}
	}
	solveSodoku(sudoku, 0, 0);
}



// 3 0 6 5 0 8 4 0 0
// 5 2 0 0 0 0 0 0 0
// 0 8 7 0 0 0 0 3 1
// 0 0 3 0 1 0 0 8 0
// 9 0 0 8 6 3 0 0 5
// 0 5 0 0 9 0 6 0 0
// 1 3 0 0 0 0 2 5 0
// 0 0 0 0 0 0 0 7 4
// 0 0 5 2 0 6 3 0 0


// 3 1 6 5 7 8 4 9 2
// 5 2 9 1 3 4 7 6 8
// 4 8 7 6 2 9 5 3 1
// 2 6 3 4 1 5 9 8 7
// 9 7 4 8 6 3 1 2 5
// 8 5 1 7 9 2 6 4 3
// 1 3 8 9 4 7 2 5 6
// 6 9 2 3 5 1 8 7 4
// 7 4 5 2 8 6 3 1 9

