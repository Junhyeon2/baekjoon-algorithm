//1. 무한 루프 시작
//2. 시작 정점이 모두 방문되었을 때 while문 탈출
//3. 시작 정점을 변수 s에 저장 true로 변경, while 시작
//4. 정점 s 에서 모든 정점에 대해 간선이 있는지 없는지 확인.
//5. 간선이 있다면 다음 정점으로 이동.
//6. output 그래프에 입력
//7. 간선이 없거나 사이클을 형성할 때 반복문 탈출
//8. 방문하지 않은 시작정점으로 이동
//9. 0부터 N까지 모든 정점을 방문하면 while 탈출
#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 100;

vector<vector<int> > inputAdj;
vector<vector<int> > resultAdj;
vector<bool> visited;

void solve(int startV){
    vector<int> temp;
    for(int i=0; i<visited.size(); ++i){
        if(visited[i])
            temp.push_back(1);
        else
            temp.push_back(0);
    }
    resultAdj.push_back(temp);
}

void dfs(int here){
    for(int i=0; i<inputAdj[here].size(); ++i){
        if(inputAdj[here][i] == 0)
            continue;
        int there = i;
        if(!visited[there]){
            visited[there] = true;
            dfs(there);
        }
    }
}
void dfsAll(){
    for(int i=0; i<inputAdj.size(); ++i){
        visited = vector<bool>(inputAdj.size(), false);
        if(!visited[i])
            dfs(i);
        solve(i);
    }
}

int main(void){
    int n;
    cin>>n;
    
    for(int i=0; i<n; ++i){
        vector<int> temp;
        for(int j=0; j<n; ++j){
            int input;
            cin>>input;
            temp.push_back(input);
        }
        inputAdj.push_back(temp);
    }
    dfsAll();
    for(int i=0; i<resultAdj.size(); ++i){
        for(int j=0; j<resultAdj[i].size(); ++j)
            cout<<resultAdj[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}