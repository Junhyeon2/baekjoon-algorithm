#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

const int MAX_V = 101;
const int INF = numeric_limits<int>::max();

unsigned int adj[MAX_V][MAX_V];
int via[MAX_V][MAX_V];

void floyd(int numOfV){
	for(int i=1; i<numOfV; ++i)
		adj[i][i] = 0;
	memset(via, -1, sizeof(via));
	for(int k=1; k<numOfV; ++k)
		for(int i=1; i<numOfV; ++i)
			for(int j=1; j<numOfV; ++j){
				if(adj[i][j] > adj[i][k] + adj[k][j]){
					via[i][j] = k;
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
}
int main(void){
	int numOfV, numOfE;
	cin>>numOfV>>numOfE;
	
	for(int i=1; i<=numOfV; ++i)
		for(int j=1; j<=numOfV; ++j)
			adj[i][j]=INF-1;

	for(int i=0; i<numOfE; ++i){
		int startV, endV;
		cin>>startV>>endV;
		adj[startV][endV] = 1;
		adj[endV][startV] = 1;
	}

	floyd(numOfV+1);

	vector<pair<int, int> > sum;
	
	for(int i=0; i<=numOfV; ++i){
		sum.push_back(make_pair(0, i));
	}

	for(int i=1; i<=numOfV; ++i)
		for(int j=1; j<=numOfV; ++j)
			sum[i].first += adj[i][j];

	sort(sum.begin(), sum.end());

	int result = sum[1].second;

	cout<<result<<endl;

	return 0;
}