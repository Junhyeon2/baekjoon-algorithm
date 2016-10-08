#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;

vector<int> solve(vector<int> start){
    vector<bool> discovered(F+1, false);
    vector<int> order;
    discovered[start.front()] = true;

    for(int i=0; i<start.size(); ++i){
        int up = start[i] + U;
        int down = start[i] - D;
        if(up > F+D)
            return NULL;
        if(up <= F+1){
            if(!discovered[up]){
                discovered[up] = true;
                order.push_back(up);
            }
        }
        if(down >= 1){
            if(!discovered[down]){
                discovered[down] = true;
                order.push_back(down);
            }
        }
    }
    return order;
}

int checkResult(vector<int> result){
    for(int i=0; i<result.size(); ++i){
        if(result[i] == G)
            return 0;
        if(result[i] - D > F)
            return 1;
    }
    return -1;
}
int main(void){
    cin>>F>>S>>G>>U>>D;
    vector<int> result;
    result.push_back(S);

    int count = 0;
    int isPossible = -1;
    while(true){
        isPossible = checkResult(result);
        if(isPossible != -1)
            break;
        result = solve(result);
        count++;
    }
    if(isPossible == 0){
        cout<<count<<endl;
    }else if(isPossible == 1){
        cout<<"use the stairs"<<endl;
    }

    return 0;
}