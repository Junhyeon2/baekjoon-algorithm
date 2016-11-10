#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int N, M, num;
    vector<int> input, card, output;

    cin>>N;
    for(int i=0; i<N; ++i){
        cin>>num;
        input.push_back(num);
    }
    cin>>M;
    for(int i=0; i<M; ++i){
        cin>>num;
        card.push_back(num);
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
            output.push_back(1);
        else
            output.push_back(0);
    }

    for(int i=0; i<output.size(); ++i)
        cout<<output[i]<<" ";
    cout<<endl;
    return 0;
}