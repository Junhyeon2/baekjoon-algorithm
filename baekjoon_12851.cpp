/* 문제 번호: 12851
 * 문제 이름: 숨바꼭질2 
 * 알고리즘 분류: BFS
 */
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 100000;
int N, K;


pair<int, int> solve(int start){
	vector<bool> discovered(MAX+1, false);
	queue<int> q;

	vector<int> order;
	vector<int> v;
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
			//cout<<order[i]<<endl;
            if(order[i] == K){
                ret = count;
               	v.push_back(ret);
            }
        }
		if(order.size() == 0 || ret != -1)
			break;

		for(int i=0; i<order.size(); ++i){
			int prev = order[i] - 1;
			int next = order[i] + 1;
			int tele = order[i] * 2;
			
			if(prev >= 0 && !discovered[prev]){
				q.push(prev);
				//discovered[prev] = true;
			}					

			if(next <= MAX && !discovered[next]){
				q.push(next);
				//discovered[next] = true;
			}

			if(tele <= MAX && !discovered[tele]){
				q.push(tele);
				//discovered[tele] = true;
			}
			discovered[order[i]] = true;
		}
		order.clear();
		count++;
	}
	return make_pair(ret, v.size());
}

int main(void){
	cin>>N>>K;
	pair<int, int> result = solve(N);
	if(N!=K)
		cout<<result.first<<endl<<result.second<<endl;
	else
		cout<<result.first<<endl<<"1"<<endl;
	return 0;
}