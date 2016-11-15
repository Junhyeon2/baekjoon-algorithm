#include <iostream>
#include <string>
#include <stack>
#include <utility>
using namespace std;

bool checkBomb[1000001];

int main(){
    string input, bomb;
    stack<pair<int, int> > s;
    cin>>input>>bomb;

    int idx = 0;
    int inputSize = input.size();
    int bombSize = bomb.size();
    pair<int, int> temp;

    if(bombSize == 1){
        for(int i=0; i<inputSize; ++i){
            if(input[i] == bomb[0])
                checkBomb[i] = true;
        }
    }else{
        for(int i=0; i<inputSize; ++i){
            if(input[i] == bomb[0]){
                s.push(make_pair(i, 0));
                idx++;
            }else{
                if(!s.empty()){
                    temp = s.top();
                    if(input[i] == bomb[temp.second+1]){
                        s.push(make_pair(i, temp.second+1));
                        if(temp.second+1 == bombSize-1){
                            for(int j=0; j<bombSize; ++j){
                                temp = s.top();
                                s.pop();
                                checkBomb[temp.first] = true;
                            }
                        }
                    }else{
                        while(!s.empty()){
                            s.pop();
                        }
                    }
                }
            }
        }
    }
    bool isAllBomb = true;
    for(int i=0; i<inputSize; ++i){
        if(checkBomb[i] == false){
            isAllBomb = false;
            break;
        }
    }
    if(isAllBomb)
        cout<<"FRULA"<<endl;
    else{
        for(int i=0; i<inputSize; ++i){
            if(checkBomb[i] == false)
                cout<<input[i];
        }
        cout<<endl;
    }

    return 0;
}