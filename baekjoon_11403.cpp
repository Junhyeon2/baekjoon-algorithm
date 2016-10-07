#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;

int input[MAX][MAX];
int output[MAX][MAX];
int N;

void solve(){
    //1. 무한 루프 시작
    //2. 시작 정점이 모두 방문되었을 때 while문 탈출
    //3. 시작 정점을 변수 s에 저장 true로 변경, while 시작
    //4. 정점 s 에서 모든 정점에 대해 간선이 있는지 없는지 확인.
    //5. 간선이 있다면 다음 정점으로 이동.
    //6. output 그래프에 입력
    //7. 간선이 없거나 사이클을 형성할 때 반복문 탈출
    //8. 방문하지 않은 시작정점으로 이동
    //9. 0부터 N까지 모든 정점을 방문하면 while 탈출
    int curV = 0;
    while(true){
        if(curV > N)
            break;

        int i = 0;
        int startV = curV;
        while(true){
            int prevV;
            if(i>N)
                break;

            if(input[startV][i] == 0){
                i++;
                continue;
            }
            prevV = startV;
            startV = i;
            output[curV][startV] = 1;
            cout<<prevV<<"      :"<<curV<<", "<<startV<<endl;
            i=0;
            if(startV == curV){
                break;
            }
        }
        curV++;
    }
}

int main(void){
    cin>>N;

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>input[i][j];
        }
    }

    solve();

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}