/* 문제 번호: 1436
 * 문제 이름: 1로 만들기
 * 알고리즘 분류: 동적 계획법(DP)
 */

#include <iostream>
using namespace std;

int d[1000001];

int solve(int n){
	for(int i=2; i<=n; ++i){
		d[i] = d[i-1] + 1;
		if(i%3 == 0 && d[i] > d[i/3]+1){
			d[i] = d[i/3]+1;
		}else if(i%2 == 0 && d[i] > d[i/2]+1){
			d[i] = d[i/2]+1;
		}
	}
	return d[n];
}

int main(void){
	int n;
	cin>>n;

	int ret = solve(n);

	cout<<ret<<endl;

	return 0;
} 