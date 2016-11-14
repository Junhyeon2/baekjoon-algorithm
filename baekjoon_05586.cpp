#include <iostream>
#include <string>
using namespace std;

int main(){
    string input, temp;
    cin>>input;
    int cntJoi=0, cntIoi=0;
    for(int i=0; i<input.size()-2; ++i){
        temp = input.substr(i, 3);
        if(temp.compare("JOI")==0)
            cntJoi++;
        else if(temp.compare("IOI")==0)
            cntIoi++;
    }
    cout<<cntJoi<<endl;
    cout<<cntIoi<<endl;
    return 0;
}