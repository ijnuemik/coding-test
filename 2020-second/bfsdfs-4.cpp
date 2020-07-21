#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>

using namespace std;
vector<string> answer;
map<string, vector<string>> m;
map<string, int> city;
int a = 0;

void go(string start, int num, vector<string> vec, int limit){
    if(num == limit){
        if(a == 0){
            a = 1;
            answer = vec;
            return;
        }
        else return;
    }

    if(num>limit) return;

    for(int i=0; i<m[start].size(); i++){
        string next = m[start][i];
        if(city[start+next] > 0){
            city[start+next]--;
            vec.push_back(next);
            go(next, num+1, vec, limit);
            vec.pop_back();
            city[start+next]++;
        }
    }

}

vector<string> solution(vector<vector<string>> tickets) {

    for(int i=0; i<tickets.size(); i++){
        string start = tickets[i][0];
        string end = tickets[i][1];
        m[start].push_back(end);
        city[start+end]++;
    }

    for(auto it = m.begin(); it != m.end(); it++){
        sort(it->second.begin(), it->second.end());
    }

    vector<string> tmp;
    tmp.push_back("ICN");

    go("ICN", 1, tmp, tickets.size()+1);

    return answer;
}
