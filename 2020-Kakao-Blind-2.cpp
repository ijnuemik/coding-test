#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

string go(string str) {
	//1�ܰ�
	if (str == "") {
		return "";
	}

	//2�ܰ� u, v�� �и�
	int a = 0;
	int b = 0;
	int index = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			a++;
		}
		else if (str[i] == ')') {
			b++;
		}
		if (a == b) {
			index = i;
			break;
		}
	}
	string u = str.substr(0, index + 1);
	string v = str.substr(index + 1, str.size());
	//3�ܰ� U�� �ùٸ� ��ȣ���� Ȯ��
	stack<char> st;
	int problem = 0;
	for (int i = 0; i < u.size(); i++) {
		if (u[i] == '(') st.push(u[i]);
		else {
			if (st.empty()) {
				problem = 1;
				break;
			}
			else {
				int top = st.top();
				if (top == ')') {
					problem = 1;
					break;
				}
				else if (top == '(') {
					st.pop();
				}
			}

		}
	}
	if (problem == 0) {
		//U�� �ùٸ� ��ȣ�϶�
		string tmp = go(v);
		u += tmp;
		return u;
	}
	else {
		//U�� �ùٸ��� ���� ��ȣ�϶�
		string tmp = "(";
		tmp += go(v);
		tmp += ")";
		for (int i = 1; i < u.size() - 1; i++) {
			if (u[i] == '(') tmp += ")";
			else tmp += "(";
		}
		return tmp;
	}
}

int main() {

	cout << go(")(") << endl;;

}