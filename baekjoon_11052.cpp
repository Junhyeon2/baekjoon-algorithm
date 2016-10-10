/* 문제 번호: 11052
 * 문제 이름: 붕어빵 판매하기
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000;
int price[MAX+1];
int setPrice[MAX+1];

int main(void){
    int N;
    cin>>N;

    memset(setPrice, 0, (MAX*1)*sizeof(int));
    memset(price, 0, (MAX*1)*sizeof(int));
    for(int i=1; i<=N; ++i){
        cin>>price[i];
    }

    for(int i=0; i<=N; ++i){
        if(setPrice[i] < price[i]){
            setPrice[i] = price[i];
            for(int j=i+1; j<=N; ++j){
                int target = j-i;
                if(setPrice[j] < setPrice[i]+setPrice[target]){
                    setPrice[j] = setPrice[i]+setPrice[target];
                }

            }
        }
    }

    int ret = 0;
    for(int i=0; i<=N; ++i){
        if(ret < setPrice[i])
            ret = setPrice[i];
    }
    cout<<ret<<endl;

    return 0;
}