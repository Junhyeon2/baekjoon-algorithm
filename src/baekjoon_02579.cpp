/* 문제 번호: 2579
 * 문제 이름: 계단 오르기
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <limits>

using namespace std;

const int MAX = 305;
const int INF = numeric_limits<int>::min();

int input[MAX];
int dpTable[MAX][3];

int main(void){
	int N;
	cin>>N;

	memset(input, 0, sizeof(MAX));
	memset(dpTable, 0, sizeof(dpTable));

	for(int i=0; i<N; ++i)
		cin>>input[i];

	dpTable[0][1] = input[0];
	dpTable[1][0] = input[0];
	dpTable[1][1] = input[1];
	dpTable[1][2] = dpTable[0][0] +input[1];
	int cnt = 0;
	for(int i=1; i<N; ++i){
		dpTable[i][0] = max(dpTable[i-1][1], dpTable[i-1][2]);
		dpTable[i][1] = dpTable[i-1][0] + input[i];
		dpTable[i][2] = dpTable[i-1][1] + input[i];
	}
	cout <<max(dpTable[N-1][1], dpTable[N-1][2])<<endl;

	return 0;
}