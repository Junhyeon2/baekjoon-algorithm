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