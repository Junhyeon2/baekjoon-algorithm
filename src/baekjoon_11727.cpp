/* 문제 번호: 11727
 * 문제 이름: 2XN 타일링 2
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
using namespace std;

const int MOD = 10007;

unsigned long long d[1001];

int solve(int n){
	for(int i=3; i<=n; ++i)
		d[i] = d[i-1]%MOD+d[i-2]*2%MOD;

	return d[n];
}

int main(void){
	int n;
	cin>>n;
	d[1] = 1;
	d[2] = 3;
	cout<<solve(n)%MOD<<endl;
	return 0;
}