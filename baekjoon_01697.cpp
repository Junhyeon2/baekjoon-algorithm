#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100000;
int N, K;


int solve(int start){
	vector<bool> discovered(MAX+1, false);
	queue<int> q;

	vector<int> order;
	discovered[start] = true;
	q.push(start);

	int count = 0;
	int ret = -1;
	while(true){
		while(!q.empty()){
			order.push_back(q.front());
			q.pop();
		}

		for(int i=0; i<order.size(); ++i){
            if(order[i] == K)
                ret = count;
        }
		if(order.size() == 0 || ret != -1)
			break;

		for(int i=0; i<order.size(); ++i){
			int prev = order[i] - 1;
			int next = order[i] + 1;
			int tele = order[i] * 2;
			
			if(prev >= 0 && !discovered[prev]){
				q.push(prev);
				discovered[prev] = true;
			}

			if(next <= MAX && !discovered[next]){
				q.push(next);
				discovered[next] = true;
			}

			if(tele <= MAX && !discovered[tele]){
				q.push(tele);
				discovered[tele] = true;
			}
		}
		order.clear();
		count++;
	}
	return ret;
}

int main(void){
	cin>>N>>K;
	int result = solve(N);

	cout<<result<<endl;
	return 0;
}