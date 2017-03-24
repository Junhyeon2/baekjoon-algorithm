#include <iostream>
#include <string>
using namespace std;

char decode[1000];

int main(){
    string caesar;
    cin>>caesar;

    char c;
    for(int i=0; i<caesar.size(); ++i){
        c = caesar[i] - 3;
        if(c < 'A')
            c += 26;
        decode[i] = c;
    }

    cout<<decode<<endl;
    return 0;
}