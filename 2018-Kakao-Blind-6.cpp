#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char arr[50][50];

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = board[i][j];
		}
	}
	
	while (true) {
		vector<pair<int, int>> vec;

		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				char a = arr[i][j];
				char b = arr[i][j + 1];
				char c = arr[i + 1][j];
				char d = arr[i + 1][j + 1];
				if (a == b && b == c && c == d && d == a) {
					if(a != '0') vec.push_back(make_pair(i, j));
				}
			}
		}

		if (vec.size() == 0) {
			break;
		}

		for (int i = 0; i < vec.size(); i++) {
			int row = vec[i].first;
			int col = vec[i].second;
			arr[row][col] = '1';
			arr[row][col + 1] = '1';
			arr[row + 1][col] = '1';
			arr[row + 1][col + 1] = '1';
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == '1') {
					answer++;
					arr[i][j] = '0';
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		//빈공간 채우기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[j][i] == '0') {
					for (int k = j; k > 0; k--) {
						arr[k][i] = arr[k - 1][i];
					}
					arr[0][i] = '0';
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;


	}
	cout << answer << endl;
	return answer;
}

int main() {
	//vector<string> vec = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
	vector<string> vec = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
	solution(6, 6, vec);
}