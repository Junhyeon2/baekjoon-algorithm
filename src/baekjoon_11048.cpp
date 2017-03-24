/* 문제 번호: 11048
 * 문제 이름: 이동하기
 * 알고리즘 분류: 동적 계획법(DP)
 */

#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

const int MAX = 1001;

int maze[MAX][MAX];
int d[MAX][MAX];
int N, M;

int main(void){
    cin>>N>>M;

    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            cin>>maze[i][j];
        }
    }
    d[1][1] = maze[1][1];

    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            int curSum = d[i][j];
            pair<int, int> right(make_pair(i+1, j));
            pair<int, int> down(make_pair(i, j+1));
            pair<int, int> rightDown(make_pair(i+1, j+1));
            if(right.first <= N && right.second <= M){
                int x = right.first;
                int y = right.second;
                int nextSum = curSum + maze[x][y];
                d[x][y] = max(d[x][y], nextSum);
            }
            if(down.first <= N && down.second <= M){
                int x = down.first;
                int y = down.second;
                int nextSum = curSum + maze[x][y];
                d[x][y] = max(d[x][y], nextSum);
            }
            if(rightDown.first <= N && rightDown.second <= M){
                int x = rightDown.first;
                int y = rightDown.second;
                int nextSum = curSum + maze[x][y];
                d[x][y] = max(d[x][y], nextSum);
            }
        }
    }
    cout<<d[N][M]<<endl;

    return 0;
}