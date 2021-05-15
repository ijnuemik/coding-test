#include <string>
#include <vector>

using namespace std;
vector<int> nums;
int answer = 0;

void go(int index, int sum, int target){
    if(index == nums.size()) {
        if(sum == target){
            answer ++;
        }
        return;
    }
    go(index + 1, sum + nums[index], target);
    go(index + 1, sum - nums[index], target);
}


int solution(vector<int> numbers, int target) {
    nums = numbers;
    go(0, 0, target);
    return answer;
}
