#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
bool check[10];
vector<vector<int>> ans;

int solution(vector<vector<string>> relation) {
	int answer = 0;
	int rowsize = relation.size();
	int colsize = relation[0].size();

	for (int i = 1; i <= colsize; i++) { //col을 몇개씩 묶을지
		vector<int> vec;
		for (int j = 0; j < colsize - i; j++) {
			vec.push_back(0);
		}
		for (int j = 0; j < i; j++) {
			vec.push_back(1);
		}
		do {
			vector<int> tmp; //묶여진 col numbers
			for (int j = 0; j < colsize; j++) { //j는 col number
				if (vec[j] == 1) {
					tmp.push_back(j);
				}
			}

			set<string>::iterator iter;
			int problem = 0;
			set<string> s;
			for (int j = 0; j < rowsize; j++) {
				string str1;
				for (int k = 0; k < tmp.size(); k++) {
					str1 = str1 + relation[j][tmp[k]] + " ";
					//cout << relation[j][tmp[k]] << " ";
				}
				cout << str1 << endl;
				//cout << endl;
				iter = s.find(str1);
				if (iter == s.end()) {
					s.insert(str1);
				}
				else {
					//cout << "Problem" << endl;
					problem = 1;
					break;
				}
			}
			if (problem == 0) {
				vector<int> ttmp;
				int problem2 = 0;
				for (int j = 0; j < tmp.size(); j++) {
					ttmp.push_back(tmp[j]);
				}
				if (ans.size() == 0) {
					answer++;
					ans.push_back(ttmp);
				}
				else {
					for (int jj = 0; jj < ans.size(); jj++) {
						if (includes(ttmp.begin(), ttmp.end(), ans[jj].begin(), ans[jj].end())) {
							problem2 = 1;
							break;
						}
					}
					if (problem2 != 1) {
						answer++;
						ans.push_back(ttmp);
					}
				}

			}
		} while (next_permutation(vec.begin(), vec.end()));

	}

	return answer;
}