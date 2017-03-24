#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int isSelect[26];

int main(){
    string input;
    cin>>input;

    memset(isSelect, -1, sizeof(isSelect));

    for(int i=0; i<input.size(); ++i){
        if(isSelect[input[i]-'a'] == -1){
            isSelect[input[i]-'a'] = i;
        }
    }
    for(int i=0; i<26; ++i)
        cout<<isSelect[i]<<" ";
    cout<<endl;
    return 0;
}