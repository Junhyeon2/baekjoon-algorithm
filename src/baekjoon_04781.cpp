/* 문제 번호: 04781
 * 문제 이름: 사탕 가게
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

ull d[100001];

int main(void){
    int n, c;
    float m, p;

    do{
        cin>>n>>m;
        memset(d, 0, sizeof(d));
        cin>>c>>p;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m*100; ++j){
                if(j+p <= m){
                    if(d[j+(int)(p*100)] != 0){

                    }
                }
                d[i] = max(cal[i], d[i-1]+cal[i]);
            }
        }

    }while(c != 0 && p != 0.00f);


    for(int i=1; i<=m*100; ++i){
        cout<<d[i]<<" ";
    }
    cout<<endl;

    return 0;
}