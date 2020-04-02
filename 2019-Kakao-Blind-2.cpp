#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;
int arr[501];
vector<pair<float, int>> vec;
bool cmp(const pair<float, int>& a, const pair<float, int>& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	for (int i = 0; i < stages.size(); i++) {
		arr[stages[i]]++;
	}
	int count = 0;
	int number = stages.size();
	for (int i = 1; i <= N; i++) {
		int low = number - count;
		if (low == 0) {
			float fault = 0;
			vec.push_back(make_pair(fault, i));

		}
		else {
			float fault = float(arr[i]) / float(low);
			vec.push_back(make_pair(fault, i));
		}

		count += arr[i];
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < vec.size(); i++) {
		answer.push_back(vec[i].second);
	}

	return answer;
}