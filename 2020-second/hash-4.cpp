#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

bool cmp2(const pair<string, int> &a, const pair<string, int> &b){
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> m1;
    map<string, vector<pair<int,int>>> m2;
    vector<pair<string, int>> vec;

    for(int i=0; i<genres.size(); i++){
        m1[genres[i]] += plays[i];
        m2[genres[i]].push_back(make_pair(i, plays[i]));
    }

    for(auto it = m1.begin(); it != m1.end(); it++){
        vec.push_back(make_pair(it->first, it->second));
    }
    sort(vec.begin(), vec.end(), cmp2);

    for(auto it = m2.begin(); it != m2.end(); it++){
        sort(it->second.begin(), it->second.end(), cmp);
    }

    for(int i=0; i<vec.size(); i++){
        string genre = vec[i].first;
        vector<pair<int, int>> elements = m2[genre];
        for(int j=0; j< elements.size(); j++){
            if(j==2) break;
            answer.push_back(elements[j].first);
        }
    }

    return answer;
}
