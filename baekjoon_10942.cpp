#include <iostream>
using namespace std;

int question[2001];
bool d[2001][2001];

int main(){
    int N, M;
    scanf("%d", &N);
    for(int i=1; i<=N; ++i)
        cin>>question[i];

    for(int i=1; i<=N; ++i)
        d[i][i] = true;
    for(int i=1; i<=N-1; ++i)
        if(question[i] == question[i+1])
            d[i][i+1] = true;
    for(int k=3; k<=N; ++k){
        for(int i=1; i<=N-k+1; ++i){
            int j = i+k-1;
            if(question[i] == question[j]  && d[i+1][j-1] == true)
                d[i][j] = true;
        }
    }
    scanf("%d", &M);
    int x, y;
    for(int i=1; i<=M; ++i){
        scanf("%d %d", &x, &y);
        printf("%d\n",d[x][y]);
    }
    return 0;
}