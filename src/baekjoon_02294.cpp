/* 문제 번호: 2294
 * 문제 이름: 동전 2
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
using namespace std;

int d[101][10001];
int coin[101];

int N, K;

int main(){
	cin>>N>>K;
	for(int i=1; i<=N; ++i)
		cin>>coin[i];

	for(int i=0; i<=K; ++i){
		if(i%coin[1] == 0)
			d[1][i] = i/coin[1];
	}
	
	for(int i=2; i<=N; ++i){
		for(int j=0; j<=K; ++j){
			if(j-coin[i] < 0)
				d[i][j] = d[i-1][j];
			else
				d[i][j] = d[i][j-coin[i]] + d[i-1][j];
		}
	}

	for(int i=1; i<=N; ++i){
		for(int j=1; j<=K; ++j)
			cout<<d[i][j]<<" ";
		cout<<endl;
	}
	cout<<d[N][K]<<endl;
	return 0;
}

