#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int counter[9] = {7, 7, 7, 7, 7, 7, 14 ,7 ,7};

int main(){
    string input;
    cin>> input;

    for(int i=0; i<input.size(); ++i){
        if(input[i] == '9'){
            counter[6]--;
        }else
            counter[input[i]-48]--;
    }
    counter[6] /= 2;
    sort(counter, counter+9);

    cout<<7-counter[0]<<endl;

    return 0;
}