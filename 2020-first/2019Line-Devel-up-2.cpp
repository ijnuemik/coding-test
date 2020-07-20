#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;
vector<int> vec;
bool check[1000001];
int cnt;
void go(int index, int k, string str){

	if (index == vec.size()){
		cnt ++;
		if(cnt == k) cout << str;
		return;
	}

	for(int i=0; i<vec.size(); i++){
		if(check[i] == false){
			check[i] = true;
			go(index+1, k, str + to_string(vec[i]));
			check[i] = false;
		}


	}

}

int main(){
		//ios_base :: sync_with_stdio(false); 
		//cin.tie(NULL); 
		//cout.tie(NULL);
		//ifstream cin;
		//cin.open("input.txt");


		do{
			int n;
			cin >> n;
			vec.push_back(n);
		}while (getc(stdin) == ' ');

		int k;
		cin >> k;
		
		sort(vec.begin(), vec.end());

		go(0, k , "");

		cout << "end";
}   