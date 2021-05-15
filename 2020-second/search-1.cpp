#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {2,1,2,3,2,4,2,5};
    vector<int> v3 = {3,3,1,1,2,2,4,4,5,5};

    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    for(int i=0; i<answers.size(); i++){
        int n1 = i % 5;
        int n2 = i % 8;
        int n3 = i % 10;

        int ans = answers[i];

        if(ans == v1[n1]) sum1++;
        if(ans == v2[n2]) sum2++;
        if(ans == v3[n3]) sum3++;

    }

    vector<int> sum;
    sum.push_back(sum1);
    sum.push_back(sum2);
    sum.push_back(sum3);

    for(int i=0; i<sum.size(); i++){
        if(*max_element(sum.begin(), sum.end()) == sum[i]){
            answer.push_back(i+1);
        }
    }

    return answer;
}
