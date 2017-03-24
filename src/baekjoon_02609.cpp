#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

int main(){
    int a, b, G, L;
    cin>>a>>b;

    if(a>b)
        G = gcd(a,b);
    else
        G = gcd(b,a);

    L = a*b/G;

    cout<<G<<endl<<L<<endl;
    return 0;
}