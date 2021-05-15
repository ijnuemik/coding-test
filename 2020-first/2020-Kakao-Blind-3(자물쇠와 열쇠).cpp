#include <string>
#include <vector>
#include <iostream>

using namespace std;
int n, k;
vector<vector<int>> tmp;

void rotate(vector<vector<int>> arr, int k) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			tmp[i][j] = arr[k - 1 - j][i];
		}
	}
}

bool possible(vector<vector<int>> lock, vector<vector<int>> key, int row, int col) {
	int aa = 0;
	for (int i = row; i < row + k; i++) {
		int bb = 0;
		for (int j = col; j < col + k; j++) {
			int keytype = key[aa][bb];
			bb++;
			int locktype = lock[i][j];
			if (locktype == 0) {
				if (keytype == 1) {
					lock[i][j] = 1;
				}
			}
			else if (locktype == 1) {
				if (keytype == 1) {
					return false;
				}
			}
		}
		aa++;
	}

	for (int i = 0; i < n + 2 * (k - 1); i++) {
		for (int j = 0; j < n + 2 * (k - 1); j++) {
			if (lock[i][j] == 0) {
				return false;
			}
		}
	}

	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	n = lock.size();
	k = key.size();
	for (int i = 0; i < n; i++) {
		vector<int> vec;
		for (int j = 0; j < n; j++) {
			vec.push_back(0);
		}
		tmp.push_back(vec);
	}
	//커진 배열 만들기
	vector<vector<int>> lock2;
	for (int i = 0; i < n + 2 * (k - 1); i++) {
		vector<int> t;
		for (int j = 0; j < n + 2 * (k - 1); j++) {
			t.push_back(2);
		}
		lock2.push_back(t);
	}

	int aa = 0;
	for (int i = k - 1; i < k - 1 + n; i++) {
		int bb = 0;
		for (int j = k - 1; j < k - 1 + n; j++) {
			lock2[i][j] = lock[aa][bb];
			bb++;
		}
		aa++;
	}

	//0도 회전
	for (int i = 0; i < k - 1 + n; i++) {
		for (int j = 0; j < k - 1 + n; j++) {
			if (possible(lock2, key, i, j) == true) {
				cout << "TRUE" << endl;
				return true;
			}
		}
	}
	//90도회전
	rotate(key, k);
	for (int i = 0; i < k - 1 + n; i++) {
		for (int j = 0; j < k - 1 + n; j++) {
			if (possible(lock2, tmp, i, j) == true) {
				cout << "TRUE" << endl;
				return true;
			}
		}
	}

	//180도 회전
	rotate(tmp, k);
	for (int i = 0; i < k - 1 + n; i++) {
		for (int j = 0; j < k - 1 + n; j++) {
			if (possible(lock2, tmp, i, j) == true) {
				cout << "TRUE" << endl;
				return true;
			}
		}
	}

	//270도 회전
	rotate(tmp, k);
	for (int i = 0; i < k - 1 + n; i++) {
		for (int j = 0; j < k - 1 + n; j++) {
			if (possible(lock2, tmp, i, j) == true) {
				cout << "TRUE" << endl;
				return true;
			}
		}
	}

	return false;
}