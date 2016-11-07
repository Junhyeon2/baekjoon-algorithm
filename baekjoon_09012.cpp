#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool solve(string str){
    char open = '(';
    char close = ')';
    stack<char> s;
    stack<char> res;
    for(int i=0; i<str.size(); ++i){
        if(open == str[i])
            s.push(str[i]);
        if(close == str[i]){
            if(s.empty())
                res.push(str[i]);
            else
                s.pop();
        }
    }
    if(s.empty() && res.empty())
        return true;
    else
        return false;
}

int main(){
    int T;
    string str;
    cin>>T;
    for(int i=0; i<T; ++i){
        cin>>str;
        if(solve(str))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}