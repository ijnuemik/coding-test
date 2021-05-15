#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <tuple>
#include <bitset>

using namespace std;
int location[10001]; 
int weightarr[10001];
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int current = 0;
	
	queue<int> wait;
	queue<int> road;
	vector<int> vec;
	for (int i = 0; i < truck_weights.size(); i++) {
		wait.push(i);
		weightarr[i] = truck_weights[i];
	}

	while (true) {
		
		if (wait.size() == 0 && vec.size() == 0) {
			break;
		}


		answer++;
		
		//거리 앞으로 전진
		for (int i = 0; i < vec.size(); i++) {
			location[vec[i]]++;
		}

		if (vec.size() != 0) {
			//제일 앞의 애가 나가면 weight 변경, vec에서 빼기
			if (location[vec[0]] > bridge_length) {
				current -= weightarr[vec[0]];
				vec.erase(vec.begin());
			}
		}

		//weight에 따라 wait 배열에서 나가거나 안나가거나
		if (wait.size() != 0) {
			int tmp = wait.front();
			if (current + weightarr[tmp] <= weight) {
				wait.pop();
				vec.push_back(tmp);
				location[tmp] = 1;
				current += weightarr[tmp];
			}
		}

		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
		cout << endl;
	}

	cout << answer << endl;
	return answer;
}

int main() {
	int bridge_length = 100;
	int weight = 100;
	vector<int> wieghts = { 10,10,10,10,10,10,10,10,10,10 };
	solution(bridge_length, weight, wieghts);
}
