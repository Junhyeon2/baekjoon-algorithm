#include <iostream>
#include <string>
using namespace std;

int quad[65][65];

void solve(int x, int y, int size){
    int checkVal = quad[x][y];
    for(int i=x; i<x+size; ++i){
        for(int j=y; j<y+size; ++j){
            if(quad[i][j] != checkVal){
                cout<<"(";
                solve(x, y, size/2);
                solve(x, y+size/2, size/2);
                solve(x+size/2, y, size/2);
                solve(x+size/2, y+size/2, size/2);
                cout<<")";
                return;
            }
        }
    }
    cout<<checkVal;
}

int main(){
    int N;
    string input;
    cin>>N;
    for(int i=1; i<=N; ++i){
        cin>>input;
        for(int j=0; j<=input.size(); ++j){
            quad[i][j+1] = input[j] -'0';
        }
    }
    solve(1, 1, N);
    cout<<endl;
    return 0;
}