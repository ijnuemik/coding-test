#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	vector<int> ans;
	vector<int> col;
	bool check[11];
	int index = 0;
	for (int i = 0; i < dartResult.size(); i++) {
		char ch = dartResult[i];
		if (ch >= '0' && ch <= '9') {
			if (ch == '0') {
				if (ch - 1 >= 0) {
					if (dartResult[i - 1] != '1') {
						col.push_back(i);
					}
				}
			}
			else {
				col.push_back(i);
			}
		}
	}

	for (int i = 0; i < col.size()-1; i++) {
		string str = dartResult.substr(col[i], col[i+1] - col[i]);
		cout << str << endl;
		if (str[0] == '1' && str[1] == '0') { //10일 때
			int num = 10;
			if (str[2] == 'D') {
				num = num * num;
			}
			else if (str[2] == 'T') {
				num = num * num * num;
			}
			ans.push_back(num);
			if (str.size() == 4) {
				if (str[3] == '#') {
					ans.pop_back();
					ans.push_back(num * (-1));
				}
				else {
					if (ans.size() == 1) {
						ans[0] = ans[0] * 2;
					}
					else {
						for (int j = ans.size() - 2; j < ans.size(); j++) {
							ans[j] = ans[j] * 2;
						}
					}
				}
			}
		}
		else {
			int num = stoi(str.substr(0, 1));
			if (str[1] == 'D') {
				num = num * num;
			}
			else if (str[1] == 'T') {
				num = num * num * num;
			}
			ans.push_back(num);
			if (str.size() == 3) {
				if (str[2] == '#') {
					ans.pop_back();
					ans.push_back(num * (-1));
				}
				else {
					if (ans.size() == 1) {
						ans[0] = ans[0] * 2;
					}
					else {
						for (int j = ans.size() - 2; j < ans.size(); j++) {
							ans[j] = ans[j] * 2;
						}
					}
				}
			}
		}
	}
	//마지막 숫자하기 i = col.size()-1
	string str = dartResult.substr(col[col.size() - 1]);
	cout << str << endl;
	if (str[0] == '1' && str[1] == '0') { //10일 때
		int num = 10;
		if (str[2] == 'D') {
			num = num * num;
		}
		else if (str[2] == 'T') {
			num = num * num * num;
		}
		ans.push_back(num);
		if (str.size() == 4) {
			if (str[3] == '#') {
				ans.pop_back();
				ans.push_back(num * (-1));
			}
			else {
				if (ans.size() == 1) {
					ans[0] = ans[0] * 2;
				}
				else {
					for (int j = ans.size() - 2; j < ans.size(); j++) {
						ans[j] = ans[j] * 2;
					}
				}
			}
		}
	}
	else {
		int num = stoi(str.substr(0, 1));
		cout << num << endl;
		if (str[1] == 'D') {
			num = num * num;
		}
		else if (str[1] == 'T') {
			num = num * num * num;
		}
		ans.push_back(num);
		if (str.size() == 3) {
			if (str[2] == '#') {
				ans.pop_back();
				ans.push_back(num * (-1));
			}
			else {
				if (ans.size() == 1) {
					ans[0] = ans[0] * 2;
				}
				else {
					for (int j = ans.size() - 2; j < ans.size(); j++) {
						ans[j] = ans[j] * 2;
					}
				}
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		answer += ans[i];
		cout << ans[i] << endl;
	}
	cout << answer << endl;
	return answer;
}

int main() {
	string a = "1S*2T*3S";
	solution(a);
}