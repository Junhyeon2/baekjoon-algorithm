#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, num;
    vector<long long> plus, minus, zero, one;
    cin>>N;

    for(int i=0; i<N; ++i){
        cin>>num;
        if(num > 1){
            plus.push_back(num);
        }else if(num < 0){
            minus.push_back(num);
        }else if(num == 0){
            zero.push_back(num);
        }else if(num == 1){
            one.push_back(num);
        }
    }

    //음수 양수 0, 1 따로 벡터에 삽입.

    //음수는 오름차순 정렬
    //양수는 내림차순 정렬
    sort(plus.begin(), plus.end());
    reverse(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    //양수 합치기
    long long sum = 0;
    int plusResIdx=0, minResIdx=0;
    if(plus.size() >= 2){
        for(int i=0; i<plus.size()-1; i+=2){
            sum += plus[i]*plus[i+1];
            plusResIdx = i;
        }
    }

    //음수 합치기
    if(minus.size() >= 2){
        for(int i=0; i<minus.size()-1; i+=2){
            sum += minus[i]*minus[i+1];
            minResIdx = i;
        }
    }

    //음수가 남아있고, 제로가 없을 경우 빼주기
    if(minus.size() % 2 == 1 && zero.size() == 0){
        if(minus.size() == 1)
            sum += minus[minResIdx];
        else
            sum += minus[minResIdx+2];
    }

    //남은 양수 덧셈
    if(plus.size() % 2 == 1){
        if(plus.size() == 1)
            sum += plus[plusResIdx];
        else
            sum += plus[plusResIdx+2];
    }

    //1 더해주기
    for(int i=0; i<one.size(); ++i){
        sum += one[i];
    }

    cout<<sum<<endl;
    return 0;
}