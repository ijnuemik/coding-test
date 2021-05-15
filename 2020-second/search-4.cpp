#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int a = 0;
    int b = 0;
    for(int i=1; i<=yellow/2; i++){
        if(yellow % i == 0){
            a = i;
            b = yellow / i;
            if(2*a + 2*b + 4 == brown){
                answer.push_back(b+2);
                answer.push_back(a+2);
                break;
            }
        }
    }

    if(yellow == 1){
        answer.push_back(3);
        answer.push_back(3);
    }
    return answer;
}
