#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    string n;
    int b;
    cin>>n>>b;
    int ret = 0, chiper;
    for(int i=n.size()-1; i>=0; --i){
        chiper = n.size()-1 - i;
        if(n[i] >= 48 && n[i] <= 57)
            ret += pow(b, chiper)*(n[i]-48);
        else
            ret += pow(b, chiper)*(n[i]-55);
    }
    cout<<ret<<endl;
    return 0;
}