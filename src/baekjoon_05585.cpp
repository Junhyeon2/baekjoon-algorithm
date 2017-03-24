#include <iostream>
using namespace std;

int main(){
    int n, count=0;
    cin>>n;
    int res = 1000 - n;
    while(res>0){

        if(res-500 >= 0){
            res -= 500;
        }else if(res-100 >= 0){
            res -= 100;
        }else if(res-50 >= 0){
            res -= 50;
        }else if(res-10 >= 0){
            res -= 10;
        }else if(res-5 >= 0){
            res -= 5;
        }else if(res-1 >= 0){
            res -= 1;
        }
        count++;
    }

    cout<<count<<endl;

    return 0;
}