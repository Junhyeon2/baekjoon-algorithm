#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 100002;

int sticker[2][MAX];
int d[2][MAX];

int main(){
    int T, n;
    scanf("%d", &T);
    for(int i=0; i<T; ++i){
        scanf("%d", &n);
        for(int j=0; j<2; ++j){
            for(int k=2; k<=n+1; ++k){
                scanf("%d", &sticker[j][k]);
            }
        }

        for(int j=2; j<=n+1; ++j){
            d[0][j] = max(max(d[0][j-1], d[1][j-1] + sticker[0][j]), d[1][j-2]+sticker[0][j]);
            d[1][j] = max(max(d[1][j-1], d[0][j-1] + sticker[1][j]), d[0][j-2]+sticker[1][j]);
        }

        printf("%d\n", max(d[0][n+1], d[1][n+1]));
    }
    return 0;
}