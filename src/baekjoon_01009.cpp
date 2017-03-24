#include <iostream>
using namespace std;

int repeat[10][4] ={
    {1, 1, 1, 1},
    {2, 4, 8, 6},
    {3, 9, 7, 1},
    {4, 6, 4, 6},
    {5, 5, 5, 5},
    {6, 6, 6, 6},
    {7, 9, 3, 1},
    {8, 4, 2, 6},
    {9, 1, 9, 1},
    {10, 10, 10, 10}
};

int main(){
    int T, a, b;
    cin>>T;
    while(T-- > 0){
        cin>>a>>b;
        if(a%10 == 0)
            a = 10;
        else
            a = a%10;

        if(b%4 == 0)
            b = 4;
        else
            b = b%4;

        cout<<repeat[a-1][b-1]<<endl;
    }
    return 0;
}