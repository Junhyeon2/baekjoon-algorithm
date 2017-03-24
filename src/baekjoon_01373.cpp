#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string binNum;
    stack<int> s;
    cin>>binNum;

    int chiper = 0, oct = 0;
    for(int i=binNum.size()-1; i>=0; --i){
        oct += ((binNum[i]-48)<<chiper);
        chiper++;
        if(chiper == 3){
            s.push(oct);
            chiper = 0;
            oct = 0;
        }
    }

    if(chiper != 0)
        s.push(oct);

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    return 0;
}