#include <iostream>
using namespace std;

const int MAX = 2187;

int paper[MAX][MAX];
int zero, plusOne, minusOne;

void check(int x, int y, int size){
    int checkVal = paper[x][y];
    for(int i=x; i<x+size; ++i){
        for(int j=y; j<y+size; ++j){
            if(checkVal != paper[i][j]){
                check(x, y, size/3);
                check(x+size/3, y, size/3);
                check(x+2*size/3, y, size/3);
                check(x, y+size/3, size/3);
                check(x, y+2*size/3, size/3);
                check(x+size/3, y+size/3, size/3);
                check(x+2*size/3, y+size/3, size/3);
                check(x+size/3, y+2*size/3, size/3);
                check(x+2*size/3, y+2*size/3, size/3);
                return;
            }
        }
    }
    if(checkVal == 0)
        zero++;
    else if(checkVal == 1)
        plusOne++;
    else if(checkVal == -1)
        minusOne++;
}

int main(){
    int N;
    cin>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>paper[i][j];
        }
    }
    check(0, 0, N);
    cout<<minusOne<<endl;
    cout<<zero<<endl;
    cout<<plusOne<<endl;
}