#include <iostream>
using namespace std;

int zeroCount;
int oneCount;

int fibo(int n){
    if(n==0){
        zeroCount++;
        return 0;
    }else if(n==1){
        oneCount++;
        return 1;
    }else{
        return fibo(n-1) + fibo(n-2);
    }
}
int main(void){
    int tc;
    cin>>tc;

    for(int test_case=0; test_case<tc; ++test_case){
        zeroCount = 0;
        oneCount = 0;
        int num;
        cin>>num;
        fibo(num);

        cout<<zeroCount<<" "<<oneCount<<endl;
    }
    return 0;
}
