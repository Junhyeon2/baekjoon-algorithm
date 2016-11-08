#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string equation;
    int sign = 1; //1: + / -1: -
    vector<int> plus;
    vector<int> minus;

    cin>>equation;

    cout<<stoi(equation.substr(0, 2))<<endl;
    return 0;
}