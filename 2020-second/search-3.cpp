#include <string>
#include <vector>
#include <set>

using namespace std;

bool check[10];
vector<string> vec;

bool check_success(int original, int num, int strike, int ball){
    set<char> s;
    for(int i=0; i<3; i++){
        s.insert(to_string(original)[i]);
        s.insert(to_string(num)[i]);
    }
    int check_ball = 6 - s.size();
    int check_strike = 0;
    for(int i=0; i<3; i++){
        if(to_string(original)[i] == to_string(num)[i]){
            check_strike++;
            check_ball--;
        }
    }

    if(check_strike == strike && check_ball == ball){
        return true;
    }
    else return false;
}

void go(int index, int limit, string str){
    if(index == limit){
        vec.push_back(str);
        return;
    }
    for(int i=1; i<=9; i++){
        if(check[i] == false){
            check[i] = true;
            go(index+1, limit, str+to_string(i));
            check[i] = false;
        }
    }
}


int solution(vector<vector<int>> baseball) {
    int answer = 0;
    go(0,3,"");
    for(int i=0; i<vec.size(); i++){
        int success = 1;
        for(int j=0; j<baseball.size(); j++){
            int num = baseball[j][0];
            int strike = baseball[j][1];
            int ball = baseball[j][2];
            if(check_success(stoi(vec[i]),num,strike,ball)==false) {
                success = 0;
                break;
            }
        }
        if(success == 1) answer++;

    }

    return answer;
}
