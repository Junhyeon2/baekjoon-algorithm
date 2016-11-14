#include <iostream>
#include <string>
using namespace std;

char result[100];

int main(){
    string input;
    cin>>input;

    int idx = 0;
    result[idx++] = input[0];
    for(int i=1; i<input.size()-1; ++i){
        if(input[i] == '-'){
            result[idx++] = input[i+1];
        }
    }
    cout<<result<<endl;
    return 0;
}