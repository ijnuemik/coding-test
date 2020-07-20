#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
vector<string> vec;
vector<pair<int, string>> rec;
map<string, string> m;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	int index = 0;
	for (int i = 0; i < record.size(); i++) {
		vector<string> v;
		while (true) {
			int tmp = record[i].find(' ', index);
			v.push_back(record[i].substr(index, tmp - index));
			index = tmp + 1;
			if (tmp == -1) {
				break;
			}
		}
		if (v[0] == "Enter") {
			//map�� ����
			m[v[1]] = v[2];

			//�迭�� ����
			rec.push_back(make_pair(1, v[1]));
		}
		else if (v[0] == "Leave") {
			//�迭�� ����
			rec.push_back(make_pair(2, v[1]));
		}
		else if (v[0] == "Change") {
			//map�� ����
			m[v[1]] = v[2];
		}
	}

	for (int i = 0; i < rec.size(); i++) {
		int command = rec[i].first;
		string id = rec[i].second;
		if (command == 1) {
			answer.push_back(m[id] + "���� ���Խ��ϴ�.");
		}
		else if (command == 2) {
			answer.push_back(m[id] + "���� �������ϴ�.");
		}
	}

	return answer;
}