/* 문제 번호: 9095
 * 문제 이름: 1,2,3 더하기
 * 알고리즘 분류: 동적 계획법(DP)
 */

#include <iostream>
using namespace std;

unsigned long long d[11];

void solve(int n){
	for(int i=4; i<=n; ++i)
		d[i] = d[i-1] + d[i-2] + d[i-3];
}

int main(void){
	int tc;
	int n;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	cin>>tc;
	solve(10);
	for(int i=0; i<tc; ++i){
		cin>>n;
		cout<<d[n]<<endl;
	}
	return 0;
}