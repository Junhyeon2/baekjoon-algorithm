#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    cin>>input;

    int num, cnt = 0;
    for(int i=0; i<input.size(); ++i){
        num = (int)(input[i] - 64);
        if(num >= 1 && num <= 3)
            cnt += 3;
        else if(num >= 4 && num <= 6)
            cnt += 4;
        else if(num >= 7 && num <= 9)
            cnt += 5;
        else if(num >= 10 && num <= 12)
            cnt += 6;
        else if(num >= 13 && num <= 15)
            cnt += 7;
        else if(num >= 16 && num <= 19)
            cnt += 8;
        else if(num >= 20 && num <= 22)
            cnt += 9;
        else if(num >= 23 && num <= 26)
            cnt += 10;
    }
    cout<<cnt<<endl;
    return 0;
}