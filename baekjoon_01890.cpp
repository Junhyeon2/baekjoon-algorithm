#include <iostream>
using namespace std;

int board[101][101];
unsigned long long d[102][102];

int main(){
    int N;
    cin>>N;

    for(int i=1; i<=N; ++i)
        for(int j=1; j<=N; ++j)
            cin>>board[i][j];

    d[1][1] = 1;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            if(board[i][j] == 0)
                continue;
            if(board[i][j]+j <= N)
                d[i][board[i][j]+j] += d[i][j];
            if(board[i][j]+i <= N)
                d[board[i][j]+i][j] += d[i][j];
        }
    }
    cout<<d[N][N]<<endl;
    return 0;
}