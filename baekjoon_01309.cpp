/* 문제 번호: 1309
 * 문제 이름: 동물원
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
using namespace std;

const int MOD = 9901;

int d[100001];

int main(){
    int n;
    cin>>n;

    d[0] = 1;
    d[1] = 3;
    for(int i=2; i<=n; ++i)
        d[i] = ((2*(d[i-1]-1))%MOD+((d[i-2]-1)+2+1)%MOD)%MOD;
    cout<<d[n]<<endl;
    return 0;
}