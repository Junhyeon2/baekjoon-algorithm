#include <iostream>
using namespace std;

char star[6145][6145];
void solve(int x, int y, int size){
    if(size > 3){
        solve(x+size/2, y, size/2);
        solve(x, y+size/2, size/2);
        solve(x+size/2, y+2*size/2, size/2);
    }
    if(size%6 == 0)
        return;
    for(int i=x; i<x+size; ++i){
        for(int j=y; j<y+size*2-1; ++j){
            if(i == x && j == y+size-1){
                star[i][j] = '*';
            }else if(i==(x+1) && (j == (y+size-2) || j == (y+size))){
                star[i][j] = '*';
            }else if(i == x+size-1){
                star[i][j] = '*';
            }
        }
    }
}

int main(){
    int N;
    cin>>N;
    for(int i=0; i<=N; ++i){
        for(int j=0; j<N*2; ++j)
            star[i][j] = ' ';
    }
    solve(0, 0, N);
    for(int i=0; i<N; ++i){
        printf("%s\n", star[i]);

    }
    return 0;
}