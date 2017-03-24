/* 문제 번호: 1149
 * 문제 이름: RGB 거리
 * 알고리즘 분류: 동적 계획법(DP)
 */

#include <iostream>
#include <limits>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int RED = 0;
const int GREEN = 1;
const int BLUE = 2;
const int MAX = 1000;
const int INF = numeric_limits<int>::max();

int N;
int input[MAX][3];
int dpTable[MAX][3];
int main(void){
    memset(input, 0, sizeof(input));
    memset(dpTable, 0, sizeof(dpTable));
    cin>>N;

    for(int i=0; i<N; ++i){
        int r, g, b;
        cin>>r>>g>>b;
        input[i][RED] = r;
        input[i][GREEN] = g;
        input[i][BLUE] = b;
    }

    dpTable[0][RED] = input[0][RED];
    dpTable[0][GREEN] = input[0][GREEN];
    dpTable[0][BLUE] = input[0][BLUE];

    for(int i=1; i<N; ++i){
        dpTable[i][RED] = min(dpTable[i-1][BLUE], dpTable[i-1][GREEN]) + input[i][RED];
        dpTable[i][GREEN] = min(dpTable[i-1][RED], dpTable[i-1][BLUE]) + input[i][GREEN];
        dpTable[i][BLUE] = min(dpTable[i-1][RED], dpTable[i-1][GREEN]) + input[i][BLUE];
    }

    int min = INF;
    for(int i=0; i<3; ++i){
        if(dpTable[N-1][i] < min)
            min = dpTable[N-1][i];
    }

    cout<<min<<endl;

    return 0;
}