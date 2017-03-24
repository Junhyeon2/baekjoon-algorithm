/* 문제 번호: 10844
 * 문제 이름: 쉬운 계단수
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
using namespace std;

typedef unsigned long long ull;

const ull MOD = 1000000000;

ull d[101][10];

ull solve(int n){
	for(int i=1; i<10; ++i)
		d[1][i] = 1;

	for(int i=2; i<=n; ++i){
		for(int l=0; l<10; ++l)
			if(l == 0)
				d[i][l] = d[i-1][l+1]%MOD;
			else if(l == 9)
				d[i][l] = d[i-1][l-1]%MOD;
			else
				d[i][l] = d[i-1][l-1]%MOD + d[i-1][l+1]%MOD;
	}
	ull sum = 0;

	for(int i=0; i<10; ++i)
		sum = sum%MOD + d[n][i]%MOD;
	return sum;
}

int main(void){
	int n;
	cin>>n;
	cout<<solve(n)%MOD<<endl;
	return 0;
}