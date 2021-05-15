#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


bool cmp (const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<pair<int,int>> vec;
    bool check = false;
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] != 0) check = true;
        string str = to_string(numbers[i]);
        int start = 0;
        while(true){
            if(str.size() == 4) break;
            str += str[start];
            start++;
        }
        vec.push_back(make_pair(numbers[i],stoi(str)));
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i=0; i<vec.size(); i++){
        string str = to_string(vec[i].first);
        answer += str;
    }
    if(check == false ) answer = "0";
    return answer;
}
