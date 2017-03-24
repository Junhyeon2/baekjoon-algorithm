#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    char open = '(', close = ')';
    string stick;
    stack<char> s;
    int numOfStick = -1, sum = 0;

    cin>>stick;
    for(int i=0; i<stick.size(); ++i){
        if(stick[i] == open){
            s.push(stick[i]);
            numOfStick++;
        }else if(stick[i] == close){
            if(s.top() == open){
                //laser
                if(numOfStick >= 1){
                    sum += numOfStick;
                }
            }else if(s.top() == close){
                sum += 1;
            }
            numOfStick--;
            s.push(stick[i]);
        }
    }

    cout<<sum<<endl;
    return 0;
}