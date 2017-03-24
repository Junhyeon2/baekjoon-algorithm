#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string left, right;
    cin>>left>>right;

    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());
    int a = stoi(left);
    int b = stoi(right);

    if(a>b)
        cout<<a<<endl;
    else
        cout<<b<<endl;

    return 0;
}