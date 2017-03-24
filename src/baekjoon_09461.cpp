/* 문제 번호: 9461
 * 문제 이름: 파도반 수열
 * 알고리즘 분류: DP
 */

#include <iostream>
using namespace std;

typedef unsigned long long ull;

const int MAX = 101;
ull P[MAX] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };
void solve(){
    for(int i=11; i<=100; ++i)
        P[i] = P[i-1] + P[i-5];
}

int main(void){
    solve();

    int tc;
    cin>>tc;

    for(int i=0; i<tc; ++i){
        int n;
        cin>>n;
        cout<<P[n]<<endl;
    }
    return 0;
}