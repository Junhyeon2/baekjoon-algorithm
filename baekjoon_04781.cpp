/* 문제 번호: 04781
 * 문제 이름: 사탕 가게
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Candy{
public:
    int cal;
    int money;
    Candy(){}
    Candy(int cal, int money){
        this->cal = cal;
        this->money = money;
    }
};

int cache[10001];
Candy candy[5001];
int num;
double totalMoney;

int solve(int money){
    int& ret = cache[money];
    if(ret != -1)
        return ret;
    ret = 0;

    for(int i=0 ; i<num; ++i){
        if(money - candy[i].money >= 0){
            int sumCal = candy[i].cal + solve(money - candy[i].money);
            ret = max(ret, sumCal);
        }
    }
    return ret;
}

int main(void){
    while(true){
        memset(cache, -1, sizeof(cache));
        cin>>num>>totalMoney;
        if(num == 0 && totalMoney == 0.00)
            break;
        for(int i=0; i<num; ++i){
            int cal;
            double money;
            cin>>cal>>money;
            Candy temp(cal, (int)(money*100));
            candy[i] = temp;
        }
        cout<<solve((int)(totalMoney*100))<<endl;
    }

    return 0;
}