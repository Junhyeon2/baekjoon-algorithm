#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

vector<int> adj[10001];
bool isVisited[10001];
int count[10001];
int cnt, maxNum;

void dfs(int s){
    isVisited[s] = true;
    int nv;
    for(int i=0; i<adj[s].size(); ++i){
        nv = adj[s][i];
        if(isVisited[nv] == false){
            cnt++;
            dfs(nv);
        }
    }
}

void dfsAll(int n){
    for(int i=1; i<=n; ++i){
        memset(isVisited, false, sizeof(isVisited));
        cnt = 0;
        dfs(i);
        if(cnt > maxNum)
            maxNum = cnt;
        count[i] = cnt;
    }
}

int main(){
    int N, M, sv, ev;
    cin>>N>>M;

    for(int i=0; i<M; ++i){
        cin>>ev>>sv;
        adj[sv].push_back(ev);
    }
    dfsAll(N);
    for(int i=1; i<=N; ++i){
        if(maxNum == count[i])
            cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}