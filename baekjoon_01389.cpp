#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
int result[100][100] = {0,};

void dfs(int here){
	visited[here] = true;
	for(int i=0; i<adj[here].size(); ++i){
		int there = adj[here][i];
		if(!visited[there]){
			cout<<here<<" "<<there<<endl;
			result[here][there]++;
			result[there][here]++;
			dfs(there);
		}
	}
	cout<<endl;
}

void dfsAll(){
	for(int i=1; i<adj.size(); ++i){
		visited = vector<bool>(adj.size(), false);
		if(!visited[i])
			dfs(i);
		
	}
}

int main(void){
	int numOfV, numOfE;
	cin>>numOfV>>numOfE;

	vector<int> temp;
	adj = vector<vector<int> >(numOfV+1, temp);
	
	for(int i=0; i<numOfE; ++i){
		int startV, endV;
		cin>>startV>>endV;
		adj[startV].push_back(endV);
		adj[endV].push_back(startV);
	}

	dfsAll();

	for(int i=1; i<=numOfV; ++i){
		for(int j=1; j<=numOfV; ++j){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}