#include <iostream>
using namespace std;

long long d[301];

int main(){
    int N, M;
    cin>>N>>M;
    for(int i=1; i<=M; ++i){
        d[i] = i - 1;
    }

    for(int i=2; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            d[j] = d[j]+j;
        }
    }
    cout<<d[M]<<endl;
    return 0;
}