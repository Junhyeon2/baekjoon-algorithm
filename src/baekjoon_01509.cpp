#include <iostream>
#include <string>
using namespace std;

bool isPalin[2501][2501];
int d[2501];

int main(){
    string input;
    cin>>input;
    int len = input.size();
    input = " " + input;

    for(int i=1; i<=len; ++i)
        isPalin[i][i] = true;

    for(int i=1; i<=len-1; ++i){
        if(input[i] == input[i+1])
            isPalin[i][i+1] = true;
    }
    for(int k=2; k<len; ++k){
        for(int i=1; i<=len-k; ++i){
            int j = i+k;
            if(input[i] == input[j] && isPalin[i+1][j-1] == true)
                isPalin[i][j] = true;
        }
    }
    d[0] = 0;
    for(int i=1; i<=len; ++i){
        d[i] = -1;
        for(int j=1; j<=i; ++j){
            if(isPalin[j][i]){
                if(d[i] == -1 || d[i] > d[j-1]+1)
                    d[i] = d[j-1]+1;
            }
        }
    }
    cout<<d[len]<<endl;
    return 0;
}