#include <iostream>
#include <cmath>
using namespace std;

long long d[16][16];

int main(){
    int N, M, K, col, row;
    cin>>N>>M>>K;

    if(K != 0){
        if(K%M == 0){
            col = K/M;
            row = M;
        }else{
            col = K/M+1;
            row = K%M;
        }
    }else{
        col = N+1;
        row = M+1;
    }

    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            if(i == 1 || j == 1){
                if(j > row && i < col || j < row && i > col)
                    d[i][j] = 0;
                else
                    d[i][j] = 1;
            }else{
                if(j > row && i < col || j < row && i > col)
                    d[i][j] = min(d[i][j-1], d[i-1][j]);
                else
                    d[i][j] = d[i][j-1] + d[i-1][j];
            }
        }
    }
   // for(int i=1; i<=N; ++i){
   //      for(int j=1; j<=M; ++j){
   //         cout<<d[i][j]<<" ";
   //      }
   //      cout<<endl;
   //  }
   //  cout<<col<<" "<<row<<endl;
    cout<<d[N][M]<<endl;

    return 0;
}