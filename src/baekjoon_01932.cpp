/* 문제 번호: 1932
 * 문제 이름: 숫자 삼각형
 * 알고리즘 분류: 동적 계획법(DP)
 */

#include <iostream>
#include <vector>
#include <limits>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX = 500;
const int INF = numeric_limits<int>::min();

int triangle[MAX][MAX];
int dpTable[MAX][MAX];

int main(void){
    int N;
    cin>>N;

    memset(triangle, 0, sizeof(triangle));
    memset(dpTable, 0, sizeof(dpTable));

    for(int i=0; i<N; ++i){
        for(int j=0; j<=i; ++j){
            int num;
            cin>>num;
            triangle[i][j] = num;
        }
    }
    dpTable[0][0] = triangle[0][0];

    for(int i=1; i<N; ++i){
        for(int j=0; j<i; ++j){
            dpTable[i][j] = max(dpTable[i][j], triangle[i][j] + dpTable[i-1][j]);
            dpTable[i][j+1] = max(dpTable[i][j+1], triangle[i][j+1] + dpTable[i-1][j]);
        }
    }

    int max = INF;
    for(int i=0; i<N; ++i){
        if(max < dpTable[N-1][i])
            max = dpTable[N-1][i];
    }

    cout<<max<<endl;

    return 0;
}