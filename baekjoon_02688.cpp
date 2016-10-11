/* 문제 번호: 2688
 * 문제 이름: 줄어들지 않아
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>

using namespace std;
typedef unsigned long long ull;
ull cache[65][10];

int main(void){
    int tc;
    cin>>tc;
    for(int i=0; i<10; ++i)
        cache[1][i] = 1;

    for(int i=2; i<65; ++i){
        ull prevSum = 0;
        for(int j=0; j<10; ++j)
            prevSum += cache[i-1][j];
        cache[i][0] = prevSum;
        for(int j=1; j<10; ++j)
            cache[i][j] = cache[i][j-1] - cache[i-1][j-1];
    }

    for(int i=0; i<tc; ++i){
        int n;
        cin>>n;
        ull ret = 0;
        for(int j=0; j<10; ++j)
            ret += cache[n][j];
        cout<<ret<<endl;
    }
}