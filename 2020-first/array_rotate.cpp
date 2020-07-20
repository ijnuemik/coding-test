#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;
int n, m, k;
int arr[100][100];
bool check[100][100];

bool possible(int arrayy[20][20], int a, int b, int rotate, int row, int col) {
	int tmp[20][20] = { 0, };
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			tmp[i][j] = 0;
		}
	}
	if (rotate == 0) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (arrayy[i][j] == 1) {
					if (a + i >= n || b + j >= m) {
						return false;
					}
					if (arr[a + i][b + j] == 1) {
						return false;
					}
				}
			}
		}
	}

	else if (rotate == 90) {

		//돌린 배열
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				tmp[i][j] = arrayy[row - 1 - j][i];
			}
		}
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				//cout << "a " << a << " b " << b << endl;
				//cout << "i " << i << "j " << j << " a + i" << a + i << " b + j" << b + j << endl;
				if (tmp[i][j] == 1) {
					if (a + i >= n || b + j >= m) {
						return false;
					}
					if (arr[a + i][b + j] == 1) {
						return false;
					}
				}
			}
		}
	}

	else if (rotate == 180) {

		//돌린 배열
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				tmp[i][j] = arrayy[row - 1 - i][col - 1 - j];
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (tmp[i][j] == 1) {
					if (a + i >= n || b + j >= m) {
						return false;
					}
					if (arr[a + i][b + j] == 1) {
						return false;
					}
				}
			}
		}
	}

	else if (rotate == 270) {

		//돌린 배열
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				tmp[i][j] = arrayy[j][col - 1 - i];
			}
		}

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				if (tmp[i][j] == 1) {
					if (a + i >= n || b + j >= m) {
						return false;
					}
					if (arr[a + i][b + j] == 1) {
						return false;
					}
				}
			}
		}
	}

	return true;
}

void makeone(int arrayy[20][20], int a, int b, int rotate, int row, int col) {
	int tmp[20][20] = { 0, };
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			tmp[i][j] = 0;
		}
	}
	if (rotate == 0) {

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (arrayy[i][j] == 1) {
					arr[a + i][b + j] = 1;
				}
			}
		}
	}

	else if (rotate == 90) {
		//돌린 배열
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				tmp[i][j] = arrayy[row - 1 - j][i];
				//cout << tmp[i][j] << " ";
			}
			//cout << endl;
		}


		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				if (tmp[i][j] == 1) {
					//cout << "i " << i << "j " << j << " a + i" << a+i << " b + j" << b+j << endl;
					arr[a + i][b + j] = 1;
				}
			}
		}
	}

	else if (rotate == 180) {
		//돌린 배열
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				tmp[i][j] = arrayy[row - 1 - i][col - 1 - j];
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (tmp[i][j] == 1) {
					arr[a + i][b + j] = 1;
				}
			}
		}
	}

	else if (rotate == 270) {
		//돌린 배열
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				tmp[i][j] = arrayy[j][col - 1 - i];
			}
		}

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				if (tmp[i][j] == 1) {
					arr[a + i][b + j] = 1;
				}
			}
		}
	}

}



int main() {
	//os_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m >> k;



	for (int i = 0; i < k; i++) {
		int a = 0; //(0,0) 부터 탐색
		int b = 0;
		int r = 0, c = 0;
		int sticker[20][20] = { 0, };
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				sticker[i][j] = 0;
			}
		}
		cin >> r >> c;
		for (int j = 0; j < r; j++) {
			for (int mm = 0; mm < c; mm++) {
				int tmp = 0;
				cin >> tmp;
				sticker[j][mm] = tmp;
			}
		}

		int br = 0;
		int rot = 0;
		for (int j = 0; j < 4; j++) {
			for (int a = 0; a < n; a++) {
				if (br == 1) break;
				for (int b = 0; b < m; b++) {
					if (br == 1) break;
					//if (arr[a][b] == 0) {
					if (br == 1) break;
					if (possible(sticker, a, b, rot, r, c) == true) {
						//가능하면 arr배열 1로 만들기
						//cout << "sticker " << i << " a " << a << " b " << b << " rotate " << rot << endl;
						makeone(sticker, a, b, rot, r, c);
						br = 1;
					}
					if (br == 1) break;

					if (br == 1) break;
					//}
					//else {  }
				}
				if (br == 1) break;
			}
			rot += 90;
			if (br == 1) break;
		}


	}


	//모든 스티커 끝내고 나서


	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cout << arr[i][j] << " ";
			if (arr[i][j] == 1) {
				ans++;
			}
		}
		//cout << endl;
	}

	cout << ans;
	return 0;
}