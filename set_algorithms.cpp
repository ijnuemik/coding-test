#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	vector<int> vec1({ 0,1,2,3,4,4,5,6,7,8 });
	vector<int> vec2({ 0,1,2,3,4,9 });

	//�κ�����
	if (includes(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()))
	{
		cout << "vec1 include vec2" << endl;
	}
	else {
		cout << "vec1 don't include vec2" << endl;
	}

	//������
	vector<int> result;
	result.resize(vec1.size() + vec2.size());//����Ȯ��
	auto itr = set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), result.begin());//������
	result.erase(itr, result.end());//�������� ����
	for_each(result.begin(), result.end(), [](int i) {cout << i << " "; });//���
	cout << endl;

	//������ vec1 intersection vec2
	result.clear();
	result.resize(vec1.size() + vec2.size());//����Ȯ��
	itr = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), result.begin());//������
	result.erase(itr, result.end());//�������� ����
	for_each(result.begin(), result.end(), [](int i) {cout << i << " "; });//���
	cout << endl;

	//������ vec1 - vec2
	result.clear();
	result.resize(vec1.size() + vec2.size());//����Ȯ��
	itr = set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), result.begin());//������
	result.erase(itr, result.end());//�������� ����
	for_each(result.begin(), result.end(), [](int i) {cout << i << " "; });//���
	cout << endl;

	//��Ī������ vec1 EX_OR vec2
	result.clear();
	result.resize(vec1.size() + vec2.size());//����Ȯ��
	itr = set_symmetric_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), result.begin());//������
	result.erase(itr, result.end());//�������� ����
	for_each(result.begin(), result.end(), [](int i) {cout << i << " "; });//���
	cout << endl;
	//test commit
}