#include <iostream>
using namespace std;

int num[100];

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

int main(){
    int t, n, sumOfG;
    cin>>t;
    while(t-- > 0){
        cin>>n;
        for(int i=0; i<n; ++i)
            cin>>num[i];
        sumOfG = 0;
        for(int i=0; i<n-1; ++i){
            for(int j=i+1; j<n; ++j){
                if(num[i] < num[j])
                    sumOfG += gcd(num[j], num[i]);
                else
                    sumOfG += gcd(num[i], num[j]);
            }
        }
        cout<<sumOfG<<endl;
    }
    return 0;
}