/* 문제 번호: 1513
 * 문제 이름: 경로찾기
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
using namespace std;

typedef unsigned long long ull;

const int MOD = 1000007;

int d[51][51][51][51];
int game[51][51];
int ans[51];

int N, M, C;

int main(void){
	cin>>N>>M>>C;
	for(int i=0; i<C; ++i){
		int x;
		int y;
		cin>>x>>y;
		game[x][y] = i;
	}

	d[1][0][0][0] = 1;


}