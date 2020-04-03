#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second < b.second;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<pair<string, int>> cache; //city 이름, 접근 시간 == cache
	int time = 1;
	for (int i = 0; i < cities.size(); i++) {
		//모두 소문자로 변환하기
		string str = cities[i];
		transform(str.begin(), str.end(), str.begin(), (int(*)(int))tolower);
		cities[i] = str;
		//cout << str << endl;
		int find = 0;
		for (int j = 0; j < cache.size(); j++) {
			if (cache[j].first == cities[i]) {
				answer++;
				cache[j] = make_pair(cities[i], time);
				find = 1;
				break;
			}
		}

		if (cacheSize == 0) {
			answer += 5;
			continue;
		}

		//sort
		sort(cache.begin(), cache.end(), cmp);

		if (find == 0) {
			if (cache.size() == cacheSize) cache[0] = make_pair(cities[i], time);
			else if (cache.size() < cacheSize) cache.push_back(make_pair(cities[i], time));
			answer += 5;
		}

		time++;

		//sort
		sort(cache.begin(), cache.end(), cmp);

		//for(int j=0; j<cache.size(); j++){
		//    cout << cache[j].first << " " << cache[j].second;
		//}//
		//cout << endl;

	}


	//cout << answer << endl;
	return answer;
}