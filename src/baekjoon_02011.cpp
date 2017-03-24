#include <iostream>
#include <string>
using namespace std;

const int MOD = 1000000;

long long d[5001];

int main(){
    string code;
    cin>>code;

    d[0] = 1;
    d[1] = 1;

    int left, right;
    for(int i=2; i<=code.size(); ++i){
        right = code[i-1] - 48;
        left = code[i-2]- 48;

        if(left*10+right <= 26 && left != 0 && right != 0)
            d[i] = (d[i-1]%MOD + d[i-2]%MOD)%MOD;
        else if(left*10+right > 26)
            d[i] = d[i-1];
        else if(right == 0)
            d[i] = d[i-2];
        else if(left == 0)
            d[i] = d[i-1];
    }
    cout<<d[code.size()]<<endl;
    return 0;
}