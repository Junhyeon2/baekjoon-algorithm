/* 문제 번호: 2146
 * 문제 이름: 다리만들기
 * 알고리즘 분류: DFS
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[101];
bool visited[101];
int map[101][101];
int n;
int numOfArea = 1;
void dfs(int here){
	cout<<"DFS visits "<<here<<endl;
	visited[here] = true;
	for(int i=0; i<adj[here].size(); ++i){
		int there = adj[here][i];
		map[here][there] = numOfArea;
		if(!visited[there]){
			dfs(there);
		}
	}
	numOfArea++;
}

void dfsAll(){
	memset(visited, false, sizeof(visited));
	for(int i=1; i<=n; ++i){
		//memset(visited, false, sizeof(visited));
		if(!visited[i])
			dfs(i);
	}
}

int main(){
	cin>>n;
	int input;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin>>input;
			if(input == 1)
				adj[i].push_back(j);
		}
	}
	dfsAll();

	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}