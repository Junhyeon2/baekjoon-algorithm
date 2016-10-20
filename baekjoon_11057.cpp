/* 문제 번호: 11057
 * 문제 이름: 오르막수
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
using namespace std;

typedef unsigned long long ull;
const int MOD = 10007;

ull d[1001][10];

ull solve(int n){
	for(int i=0; i<=9; ++i)
		d[1][i] = 1;

	ull sum;
	for(int i=2; i<=n; ++i){
		for(int j=0; j<=9; ++j){
			sum = 0;
			for(int k=0; k<=j; ++k){
				sum = sum%MOD + d[i-1][k]%MOD;
			}
			d[i][j] = sum%MOD;
		}
	}

	ull ret = 0;

	for(int i=0; i<=9; ++i)
		ret = ret%MOD + d[n][i]%MOD;

	return ret;
}

int main(void){
	int n;
	cin>>n;

	cout<<solve(n)%MOD<<endl;

	return 0;
}