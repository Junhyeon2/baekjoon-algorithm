#include <iostream>
#include <string>
#include <stack>
using namespace std;


int findBomb(string &input, string &bomb, int s){
    bool isExist = false;
    int idx = -1;
    for(int i=s; i<input.size()-bomb.size()+1; ++i){
        for(int j=0; j<bomb.size(); ++j){
            if(input[i+j] == bomb[j]){
                isExist = true;
            }else{
                isExist = false;
                break;
            }
        }
        if(isExist){
            idx = i;
            break;
        }
    }
    return idx;
}

int main(){
    string input, bomb;
    stack<string> s;
    cin>>input>>bomb;

    int idx = 1;
    while(idx != -1){
        idx = findBomb(input, bomb, idx-1);
        if(idx != -1)
            input = input.substr(0, idx) + input.substr(idx+bomb.size(), input.size());
        //cout<<input<<endl;
    }

    if(input.size() == 0)
        cout<<"FRULA"<<endl;
    else
        cout<<input<<endl;
    return 0;
}