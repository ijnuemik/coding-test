#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	vector<int> vec1({ 0,1,2,3,4,4,5,6,7,8 });
	vector<int> vec2({ 0,1,2,3,4,9 });

	//부분집합
	if (includes(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()))
	{
		cout << "vec1 include vec2" << endl;
	}
	else {
		cout << "vec1 don't include vec2" << endl;
	}

	//합집합
	vector<int> result;
	result.resize(vec1.size() + vec2.size());//공간확보
	auto itr = set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), result.begin());//합집합
	result.erase(itr, result.end());//남은공간 제거
	for_each(result.begin(), result.end(), [](int i) {cout << i << " "; });//출력
	cout << endl;

	//교집합 vec1 intersection vec2
	result.clear();
	result.resize(vec1.size() + vec2.size());//공간확보
	itr = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), result.begin());//교집합
	result.erase(itr, result.end());//남은공간 제거
	for_each(result.begin(), result.end(), [](int i) {cout << i << " "; });//출력
	cout << endl;

	//차집합 vec1 - vec2
	result.clear();
	result.resize(vec1.size() + vec2.size());//공간확보
	itr = set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), result.begin());//차집합
	result.erase(itr, result.end());//남은공간 제거
	for_each(result.begin(), result.end(), [](int i) {cout << i << " "; });//출력
	cout << endl;

	//대칭차집합 vec1 EX_OR vec2
	result.clear();
	result.resize(vec1.size() + vec2.size());//공간확보
	itr = set_symmetric_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), result.begin());//교집합
	result.erase(itr, result.end());//남은공간 제거
	for_each(result.begin(), result.end(), [](int i) {cout << i << " "; });//출력
	cout << endl;
}