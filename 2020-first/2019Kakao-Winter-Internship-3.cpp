#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
vector<string> banned_id = { "fr*d*", "*rodo", "******", "******" };

set<set<string>> s;
bool check[100];

void go(int index, vector<string> vec, int usrsize, int bansize) {

	if (index == bansize) {
		set<string> tmp;
		int problem = 0;
		for (int i = 0; i < vec.size(); i++) {
			string banstr = banned_id[i];
			string usrstr = vec[i];
			if (banstr.length() == usrstr.length()) {
				for (int j = 0; j < banstr.length(); j++) {
					if (banstr[j] != '*') {
						if (banstr[j] != usrstr[j]) {
							problem = 1;
							break;
						}
					}
				}
			}
			else {
				problem = 1;
				break;
			}
			if (problem == 1) break;
		}
		if (problem == 0) {
			for (int i = 0; i < vec.size(); i++) {
				tmp.insert(vec[i]);
				cout << vec[i] << " ";
			}
			cout << endl;
			s.insert(tmp);
		}
		return;
	}

	for (int i = 0; i < usrsize; i++) {
		if (check[i] != true) {
			check[i] = true;
			vector<string> ttmp = vec;
			ttmp.push_back(user_id[i]);
			go(index + 1, ttmp, usrsize, bansize);
			check[i] = false;
		}
	}

}

int main() {

	int usrsize = user_id.size();
	int bansize = banned_id.size();
	vector<string> vec;
	go(0, vec, usrsize, bansize);
	cout << s.size() << endl;
}