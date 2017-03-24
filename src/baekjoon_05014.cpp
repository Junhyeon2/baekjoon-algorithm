/* 문제 번호: 05014
 * 문제 이름: 스타트 링크
 * 알고리즘 분류: BFS
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;

int solve(int start){
    vector<bool> discovered(F+1, false);

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
            if(order[i] == G)
                ret = count;
        }
        if(order.size() == 0)
            break;

        for(int i=0; i<order.size(); ++i){
            int up = order[i] + U;
            int down = order[i] - D;
            if(up < F+1 && !discovered[up]){
                q.push(up);
                discovered[up] = true;
            }
            if(down > 0 && !discovered[down]){
                q.push(down);
                discovered[down] = true;
            }
        }
        order.clear();
        count++;
    }
    return ret;
}

int main(void){
    cin>>F>>S>>G>>U>>D;

    if(U == 0 && S < G || D == 0 && S > G){
        cout<<"use the stairs"<<endl;
    }else if(S == G){
        cout<<"0"<<endl;
    }else{
        int ret = solve(S);
        if(ret != -1)
            cout<<ret<<endl;
        else
            cout<<"use the stairs"<<endl;
    }
    return 0;
}