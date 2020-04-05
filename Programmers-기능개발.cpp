#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> vec;
	for (int i = 0; i < progresses.size(); i++) {
		int time = (100 - progresses[i]) / speeds[i];
		vec.push_back(time);
	}

	int maxnum = vec[0];
	int count = 1;
	for (int i = 1; i < vec.size(); i++) {
		if (maxnum < vec[i]) {
			answer.push_back(count);
			maxnum = vec[i];
			count = 1;
		}
		else if (maxnum > vec[i]) {
			count++;
		}
		else if (maxnum == vec[i]) {
			count++;
		}
	}

	answer.push_back(count);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
	return answer;
}