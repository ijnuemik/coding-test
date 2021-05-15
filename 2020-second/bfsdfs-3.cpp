#include <string>
#include <vector>

using namespace std;
vector<string> vec;
bool check[50];
int answer = 100;
int s = 0;

bool check_diff(string a, string b){
    int tmp = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]) tmp++;
    }
    if(tmp == 1) return true;
    else return false;
}

void go(string start, string target, int num){
    if(target == start){
        if(answer > num) answer = num;
        return;
    }

    if(num > s) return;

    for(int i=0; i<vec.size(); i++){
        if(check_diff(start, vec[i]) == true && check[i] == false){
            check[i] = true;
            go(vec[i], target, num+1);
            check[i] = false;
        }
    }

}

int solution(string begin, string target, vector<string> words) {
    vec = words;
    s = vec.size();
    go(begin, target, 0);
    if(answer == 100) answer = 0;
    return answer;
}
