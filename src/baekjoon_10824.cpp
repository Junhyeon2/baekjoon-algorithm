#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;
typedef unsigned long long ull;

int main(){
    ull num, temp, left, right;
    vector<pair<ull, ull> > input;
    int chiper = 1;

    for(int i=0; i<4; ++i){
        cin>>num;
        temp = num;
        while(temp >=10){
            temp /= 10;
            chiper++;
        }
        input.push_back(make_pair(num, chiper));
        chiper = 1;
    }

    left = input[0].first*pow(10, input[1].second)+input[1].first;
    right = input[2].first*pow(10, input[3].second)+input[3].first;

    cout<<left+right<<endl;
    return 0;
}