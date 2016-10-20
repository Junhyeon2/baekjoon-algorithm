/* 문제 번호: 2133
 * 문제 이름: 타일 채우기
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
using namespace std;

int d[31][8];

int solve(int n){
	d[0][7] = 1;

	for(int i=1; i<=n; ++i){
		d[i][0] = d[i-1][7];
		d[i][1] = d[i-1][6];
		d[i][2] = d[i-1][5];
		d[i][3] = d[i-1][4];
		d[i][4] = d[i-1][7] + d[i-1][3];
		d[i][5] = d[i-1][2];
		d[i][6] = d[i-1][1] + d[i-1][7];
		d[i][7] = d[i-1][0] + d[i-1][4] + d[i-1][6];
	}
	return d[n][7];
}

int main(){
	int n;
	cin>>n;

	cout<<solve(n)<<endl;

	return 0;
}