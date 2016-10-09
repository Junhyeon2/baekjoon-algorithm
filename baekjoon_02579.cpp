#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 300;
int N;
int stairs[MAX];

vector<pair<int,int> > bfs(int start){
	vector<pair<int,int> > order;
	queue<pair<int,int> > q;
	q.push(make_pair(0, 1));
	q.push(make_pair(1, 1));

	while(true){
		while(!q.empty()){
			order.push_back(q.front());
			q.pop();
		}

		for(int i=0; i<order.size(); ++i){
			cout<<order[i].first<<" ";//<<" seq("<<order[i].second<<")";
		}
		cout<<endl;

		if(order.size() == 0)
			break;

		for(int i=0; i<order.size(); ++i){
			int oneStep = order[i].first+1;
			int twoStep = order[i].first+2;
			int sequence = order[i].second;

			if(sequence < 2 && oneStep <N){
				q.push(make_pair(oneStep, sequence+1));
			}
			if(twoStep<N){
				q.push(make_pair(twoStep, 1));
			}
		}
		order.clear();
	}
	return order;
}


int main(void){
	N=6;
	bfs(0);

	return 0;
}