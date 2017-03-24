#include <iostream>
using namespace std;

char star[6532][6532];

void solve(int x, int y, int size){
    if(size > 3){
        solve(x, y, size/3);
        solve(x+size/3, y, size/3);
        solve(x+2*size/3, y, size/3);
        solve(x, y+size/3, size/3);
        //solve(x+size/3, y+size/3, size/3);
        solve(x+2*size/3, y+size/3, size/3);
        solve(x, y+2*size/3, size/3);
        solve(x+size/3, y+2*size/3, size/3);
        solve(x+2*size/3, y+2*size/3, size/3);
    }
    //cout<<x<<" "<<y<<" "<<size<<endl;
    for(int i=x; i<x+size; ++i){
        for(int j=y; j<y+size; ++j){
            if(i == x || i == x+size-1){
                star[i][j] = '*';
            }else if(j == y || j == y+size-1){
                star[i][j] = '*';
            }
            //cout<<star[i][j];
        }
        //cout<<endl;
    }

}

int main(){
    int N;
    cin>>N;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j)
            star[i][j] = ' ';
    }

    solve(1, 1, N);
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j)
            printf("%c", star[i][j]);
        printf("\n");
    }
    return 0;
}