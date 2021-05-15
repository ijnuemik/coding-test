#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;

	transform(str1.begin(), str1.end(), str1.begin(), (int(*)(int))tolower);
	transform(str2.begin(), str2.end(), str2.begin(), (int(*)(int))tolower);

	//2글자씩 나누기
	vector<string> vec1;
	for (int i = 0; i < str1.size() - 1; i++) {
		string tmp = str1.substr(i, 2);
		char ch1 = tmp[0];
		char ch2 = tmp[1];
		if (ch1 < 'a' || ch1 > 'z' || ch2 < 'a' || ch2 > 'z') {
			continue;
		}
		vec1.push_back(tmp);
	}
	vector<string> vec2;
	for (int i = 0; i < str2.size() - 1; i++) {
		string tmp = str2.substr(i, 2);
		char ch1 = tmp[0];
		char ch2 = tmp[1];
		if (ch1 < 'a' || ch1 > 'z' || ch2 < 'a' || ch2 > 'z') {
			continue;
		}
		vec2.push_back(tmp);
	}

	int intersections = 0;
	int unions = 0;
	for (int i = 0; i < vec1.size(); i++) {
		for (int j = 0; j < vec2.size(); j++) {
			if (vec1[i] == vec2[j]) {
				vec2.erase(vec2.begin() + j);
				intersections++;
				break;
			}
		}
	}

	unions = vec1.size() + vec2.size();

	cout << intersections << " " << unions << endl;
	if (unions == 0) answer = 65536;
	else {
		float ans = (float)intersections / (float)unions;
		answer = ans * 65536;
	}
	cout << answer << endl;

	return answer;
}