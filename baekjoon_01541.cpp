#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    string equation;
    int sign = 1, bracketCount = 0;
    vector<int> val;
    vector<int> oper;

    cin>>equation;

    int end;
    oper.push_back(0); //dummy
    while(true){
        end = min(equation.find('+'), equation.find('-'));
        if(end == -1){
            val.push_back(stoi(equation));
            break;
        }

        if(equation[end] == '+'){
            oper.push_back(1);
        }else if(equation[end] == '-'){
            oper.push_back(-1);
        }
        val.push_back(stoi(equation.substr(0, end)));
        equation = equation.substr(end+1, equation.size());

    }

    int plusSum = val[0], minusSum = 0;
    for(int i=1; i<val.size(); ++i){
        if(oper[i] == -1)
            bracketCount++;

        if(bracketCount % 2 == 0){
            if(oper[i] == 1){
                plusSum += val[i];
            }else{
                bracketCount++;
                minusSum += val[i];
            }

        }else if(bracketCount % 2 == 1){
            minusSum += val[i];
        }
    }
    cout<<plusSum-minusSum<<endl;
    return 0;
}