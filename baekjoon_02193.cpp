/* 문제 번호: 2193
 * 문제 이름: 이친수
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull d[91][2];

ull solve(int n){
	d[1][0] = 0;
	d[1][1] = 1;
	d[2][0] = 1;
	d[2][1] = 0;

	for(int i=3; i<=n; ++i){
		d[i][0] = d[i-1][0] + d[i-1][1];
		d[i][1] = d[i-1][0];
	}

	return d[n][0]+d[n][1];
}

int main(void){
	int n;
	cin>>n;

	cout<<solve(n)<<endl;
	return 0;
}