#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;

    getline(cin, input);

    for(int i=0; i<input.size(); ++i){
        if('a' <= input[i] && 'z' >= input[i]){
            if(input[i] + 13 > 'z'){
                input[i] = (input[i]+13-'a')%26 + 'a';
            }else{
                input[i] = input[i] + 13;
            }

        }else if('A' <= input[i] && 'Z' >= input[i]){
            if(input[i] + 13 > 'Z'){
                input[i] = (input[i]+13-'A')%26 + 'A';
            }else{
                input[i] = input[i] + 13;
            }

        }
    }
    cout<<input<<endl;
    return 0;
}