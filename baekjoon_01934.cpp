#include <iostream>
using namespace std;
int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

int main(){
    int T, a, b, G, L;

    cin>>T;

    while(T-->0){
        cin>>a>>b;
        if(a>b)
            G = gcd(a,b);
        else
            G = gcd(b,a);
        L = a*b/G;
        cout<<L<<endl;
    }
    return 0;
}