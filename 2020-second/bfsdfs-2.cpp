#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> a[200];
int check[200];

void bfs(int start){
    queue<int> q;
    q.push(start);
    check[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0; i<a[node].size(); i++){
            int next = a[node][i];
            if(check[next] == false){
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j && computers[i][j] == 1 ){
                a[i].push_back(j);
                a[j].push_back(i);
            }
        }
    }

    for(int i=0; i<n; i++){
        if(check[i] == false){
            bfs(i);
            answer ++;
        }
    }


    return answer;
}
