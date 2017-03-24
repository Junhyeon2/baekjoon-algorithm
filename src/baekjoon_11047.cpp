#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K, val, count = 0;
    vector<int> coin;
    cin>>N>>K;

    for(int i=0; i<N; ++i){
        cin>>val;
        coin.push_back(val);
    }

    while(K>0){
        for(int i=coin.size()-1; i>=0; --i){
            if(K - coin[i] >= 0){
                K -= coin[i];
                count++;
                break;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}