/* 문제 번호: 1912
 * 문제 이름: 연속합
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MIN_INF = numeric_limits<ll>::min();

ll d[100001];
ll num[100001];
int n;

int main(){
	cin>>n;

	for(int i=1; i<=n; ++i)
		cin>>num[i];

	d[1] = num[1];

	for(int i=2; i<=n; ++i){
		d[i] = max(num[i], d[i-1]+num[i]);
	}
	
	ll maxVal = MIN_INF;
	for(int i=1; i<=n; ++i){
		if(maxVal < d[i])
			maxVal = d[i];
	}
	cout<<maxVal<<endl;
	
	return 0;
}