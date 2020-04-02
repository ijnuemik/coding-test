#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	//arr1[i], arr2[i] or 비트 연산!
	for (int i = 0; i < n; i++) {
		int num1 = arr1[i];
		int num2 = arr2[i];
		int ornum = arr1[i] | arr2[i];
		int bi1 = 0;
		int tmp = 1;
		string str = "";
		for (int j = 0; j < n; j++) {
			if (ornum % 2 == 0) str += ' ';
			else str += '#';
			ornum = ornum / 2;
		}
		reverse(str.begin(), str.end());
		answer.push_back(str);
	}

	return answer;
}