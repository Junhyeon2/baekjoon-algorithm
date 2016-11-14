#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    cin>>input;

    int count = 0;
    char c;
    for(int i=0; i<input.size(); ++i){
        c = input[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }

    cout<<count<<endl;

    return 0;
}