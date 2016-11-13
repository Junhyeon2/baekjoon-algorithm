#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n, b;
    stack<int> s;
    cin>>n>>b;
    while(n>0){
        s.push(n%b);
        n /= b;
    }
    while(!s.empty()){
        int num = s.top();
        s.pop();
        if(num >= 10)
            cout<<(char)(num+55);
        else
            cout<<num;
    }
    cout<<endl;
    return 0;
}