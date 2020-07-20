#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
vector<int> ans;
void go(int index, int count, string s, string str, int num, string prev) {

	//재귀 멈추는 부분
	if (index >= s.size()) {
		if (count == 1) {
			str += prev;
		}
		else {
			str += to_string(count);
			str += prev;
		}
		ans.push_back(str.size());
		return;
	}

	string tmp = s.substr(index, num);
	if (prev == tmp) { //이전이랑 같은 string일 때
		count++;
		go(index + num, count, s, str, num, tmp);
	}
	else { //이전이랑 다른 string일 때
		if (count == 1) {
			str += prev;
			go(index + num, 1, s, str, num, tmp);
		}
		else {
			str += to_string(count);
			str += prev;
			go(index + num, 1, s, str, num, tmp);
		}
	}

}

int solution(string s) {
	int answer = 0;
	for (int i = 1; i <= s.size(); i++) {
		string tmp = s.substr(0, i);
		go(i, 1, s, "", i, tmp);
	}
	cout << *min_element(ans.begin(), ans.end()) << endl;
	answer = *min_element(ans.begin(), ans.end());
	return answer;
}
int main() {

	solution("abcabcabcabcdededededede");

}