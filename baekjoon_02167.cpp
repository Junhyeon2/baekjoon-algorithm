#include <iostream>
#include <cstring>
using namespace std;

int d[301][301];

int main(){
    int N, M, K;
    int arr[301][301];
    int range[10001][4];
    cin>>N>>M;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j)
            cin>>arr[i][j];
    }
    cin>>K;
    for(int i=1; i<=K; ++i){
        for(int j=0; j<4; ++j){
            cin>>range[i][j];
        }
    }

    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            d[i][j] = d[i-1][j] + d[i][j-1] + arr[i][j] - d[i-1][j-1];
        }
    }
    //  for(int i=0; i<=N; ++i){
    //     for(int j=0; j<=M; ++j){
    //         cout<<d[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    int sx, sy, ex, ey, sum=0;
    for(int k=1; k<=K; ++k){
        sx = range[k][0];
        sy = range[k][1];
        ex = range[k][2];
        ey = range[k][3];
        //방향 결정.
        if(sx == ex && sy == ey){
            cout<<arr[sx][sy]<<endl;
        }else if(sx <= ex && sy <= ey){
            //좌->우 대각선 아래 방향 진행
            cout<<d[ex][ey] - d[ex][sy-1] - d[sx-1][ey] + d[sx-1][sy-1]<<endl;
        }else if(sx >= ex && sy <= ey){
            //좌->우 대각선 위 방향 진행
            cout<<d[sx][ey] - d[sx][sy-1] - d[ex-1][ey] + d[ex-1][sy-1]<<endl;
        }else if(sx <= ex && sy >= ey){
            //우->좌 대각선 아래 방향으로 진행
            cout<<d[ex][sy] - d[ex][ey-1] - d[sx-1][sy] + d[sx-1][ey-1]<<endl;
        }else if(sx >= ex && sy >= ey){
            //우->좌 대각선 위 방향으로 진행
            cout<<d[sx][sy] - d[sx][ey-1] - d[ex-1][sy] + d[ex-1][ey-1]<<endl;
        }

    }
    return 0;
}