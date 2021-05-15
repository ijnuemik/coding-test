#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 0;

	int start = 0;
	int end = 200000000;
	int max = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		vector<int> temp;
		temp = stones;
		for (int i = 0; i < temp.size(); i++) {
			temp[i] = temp[i] - (mid - 1);
		}

		int cnt = 0;
		int pro = 0;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] <= 0) {
				cnt++;
				if (cnt == k) {
					pro = 1; // �������� ����!
					break;
				}
			}
			else {
				cnt = 0;
			}
		}
		//�������� 0���� ���� ��
		if (pro == 1) {
			end = mid - 1;
		}

		//�������� 0���� ���� ��        
		else {
			answer = mid;
			start = mid + 1;
		}
	}

	return answer;
}