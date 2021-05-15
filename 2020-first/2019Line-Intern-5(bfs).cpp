#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;
vector<int> vec;
vector<int> ans;
bool check[200001][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ifstream cin;
	cin.open("input.txt");

	int c, b;
	cin >> c >> b;

	//브라운의 위치에 대해 BFS 탐색
	queue<pair<int, int>> q; //위치랑 시간
	check[b][0] = true;
	q.push(make_pair(b, 0));

	while (!q.empty()) {

		int location = q.front().first;
		int time = q.front().second;
		q.pop();
		int cony_location = c + (time + 1) * time / 2;
		if (cony_location == location) {
			cout << time << endl;
			break;
		}
		if (0 <= location - 1 && location - 1 <= 200000) {
			if (check[location - 1][(time + 1) % 2] == false) {
				check[location - 1][(time + 1) % 2] = true;
				q.push(make_pair(location - 1, time + 1));
			}
		}

		if (0 <= location + 1 && location - 1 <= 200000) {
			if (check[location + 1][(time + 1) % 2] == false) {
				check[location + 1][(time + 1) % 2] = true;
				q.push(make_pair(location + 1, time + 1));
			}
		}

		if (0 <= location * 2 && location * 2 <= 200000) {
			if (check[location * 2][(time + 1) % 2] == false) {
				check[location * 2][(time + 1) % 2] = true;
				q.push(make_pair(location * 2, time + 1));
			}
		}

	}


}