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

int main(){
      ios_base :: sync_with_stdio(false); 
      cin.tie(NULL); 
      cout.tie(NULL);
      ifstream cin;
      cin.open("input.txt");

      int n;
			cin >> n;
			stack<pair<int,int>> s;

			int first;
			cin >> first;
			s.push(make_pair(first,1));
			vec.push_back(0);

			for(int i=2; i<n+1; i++){

				int tmp;
				cin >> tmp;
				int solve = 0;
				while(true){
					if(!s.empty()){
						int top = s.top().first;
						int top_ind = s.top().second;
						if(top < tmp){ //더 높은 것이 들어왔을 때
							s.pop();
						}
						else if(top > tmp){ //더 낮은 것이 들어왔을 때
							vec.push_back(top_ind);
							s.push(make_pair(tmp, i));
							break;
						}
					}
					else if (s.empty()){
						vec.push_back(0);
						s.push(make_pair(tmp,i));
						break;
					}
				}
			}

			for(int i=0; i<n; i++){
				cout << vec[i] << " ";
			}
}   