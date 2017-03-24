#include <iostream>
#include <vector>
using namespace std;

void octToBin(int oct, int n){
    if(n == 0)
        return;
    octToBin(oct/2, n-1);
    cout<<oct%2;
}

int main(){
    string input;
    int oct, bin;
    vector<char> v;
    cin>>input;

    oct = input[0];
    for(int i=0; i<3; ++i){
        bin = oct%2;
        if(bin == 0)
            v.push_back('0');
        else
            v.push_back('1');
        oct /= 2;
    }
    bool isOne = false;
    for(int i=v.size(); i>=0; --i){
        if(v[i] == '1')
            isOne = true;
        if(isOne == false)
            continue;
        cout<<v[i];
    }

    for(int i=1; i<input.size(); ++i){
        oct = input[i] - 48;
        octToBin(oct, 3);
    }
    cout<<endl;
    return 0;
}