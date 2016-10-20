/* 문제 번호: 2156
 * 문제 이름: 포도주 시식
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

ull cost[10001];
ull d[10001][3];

ull solve(int n){
	d[1][0] = 0;
	d[1][1] = cost[1];
	d[1][2] = 0;

	for(int i=2; i<=n; ++i){
		d[i][0] = max(d[i-1][0], max(d[i-1][1], d[i-1][2]));
		d[i][1] = d[i-1][0]+cost[i];
		d[i][2] = d[i-1][1]+cost[i];
	}
	// for(int i=1; i<=n; ++i){
	// 	for(int j=0; j<=2; ++j)
	// 		cout<<d[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;
	return max(d[n][0], max(d[n][1], d[n][2]));
}

int main(){
	int n;
	cin>>n;

	for(int i=1; i<=n; ++i)
		cin>>cost[i];

	cout<<solve(n)<<endl;

	return 0;
}