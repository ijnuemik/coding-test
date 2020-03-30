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

int main(){
      ios_base :: sync_with_stdio(false); 
      cin.tie(NULL); 
      cout.tie(NULL);
      ifstream cin;
      cin.open("input.txt");

      int n,m;

      cin >> n >> m;

      for(int i=0; i<m; i++){
         int tmp;
         cin >> tmp;
         vec.push_back(tmp);
      }   

      for(int i=0; i<n-m; i++){
         int tmp;
         cin >> tmp;
         int min_index = min_element(vec.begin(), vec.end()) - vec.begin();
         vec[min_index] += tmp;
      }   


      cout << *max_element(vec.begin(), vec.end());
}   