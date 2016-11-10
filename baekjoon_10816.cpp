#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 500000;

int card[MAX], output[MAX];
int m[20000001];
int main(){
    int N, M, num;
    vector<int> input;

    cin>>N;
    for(int i=0; i<N; ++i){
        cin>>num;
        m[num+10000000]++;
        input.push_back(num);
    }
    cin>>M;
    for(int i=0; i<M; ++i){
        cin>>card[i];
    }

    sort(input.begin(), input.end());

    int left, right, mid;
    for(int i=0; i<M; ++i){
        left = 0;
        right = N-1;
        while(left <= right){
            mid = (left+right)/2;
            if(card[i] == input[mid])
                break;
            else if(card[i] > input[mid])
                left = mid+1;
            else if(card[i] < input[mid])
                right = mid-1;
        }
        if(left <= right)
            output[i] = m[card[i]+10000000];
    }

    for(int i=0; i<M; ++i)
        cout<<output[i]<<" ";
    cout<<endl;
    return 0;
}