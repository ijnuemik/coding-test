#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

int check[] = { 0,0,0,0,0,0,0,0,0,0 };
int p[10000000];


void check_string(string numbers) {
	for (int i = 0; i < numbers.size(); i++) {
		char ch = numbers[i];
		int num = ch - '0';
		check[num]++;
	}
}

bool make(int number) {
	int tmp[10];
	for (int i = 0; i < 10; i++) {
		tmp[i] = check[i];
	}
	string str = to_string(number);
	for (int i = 0; i < str.size(); i++) {
		if (tmp[str[i] - '0'] < 1) return false;
		tmp[str[i] - '0']--;
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;
    check_string(numbers);

	sort(numbers.begin(), numbers.end(), greater<char>());

	for (int i = 2; i < sqrt(stoi(numbers)); i++) {    //에라토스테네스의 체
		if (!p[i]) {
			for (int j = i * i; j <= stoi(numbers); j += i) {
				p[j] = 1;
			}
		}
	}

	for (int i = 2; i <= stoi(numbers); i++) {
		if (p[i] == 0) {
			if (make(i) == true) {
				answer++;
			}
		}
	}

	return answer;
}
