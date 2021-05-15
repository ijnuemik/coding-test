#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int i=0; i<commands.size(); i++){
        int start = commands[i][0];
        int end = commands[i][1];
        int num = commands[i][2];
        vector<int> vec;
        for(int j=start-1; j<end; j++){
            vec.push_back(array[j]);
        }
        sort(vec.begin(), vec.end());
        answer.push_back(vec[num-1]);
    }
    return answer;
}
