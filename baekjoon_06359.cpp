/* 문제 번호: 6359
 * 문제 이름: 만취한 상범
 * 알고리즘 분류: 동적 계획법(DP)
 */

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 101;
bool jail[MAX];

int solve(int n){
    int ret = 0;
    memset(jail, 0, sizeof(jail));

    for(int i=2; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(j%i == 0)
                jail[j] = !jail[j];
        }
    }

    for(int i=1; i<=n; ++i)
        if(!jail[i])
            ret++;

    return ret;
}

int main(void){

    int tc, n;
    cin>>tc;
    for(int i=0; i<tc; ++i){
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}