#include <iostream>
using namespace std;

const int MAX = 1000000;

int A[MAX];
int B[MAX];
int C[MAX*2];

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; ++i)
        scanf("%d", &A[i]);

    for(int i=0; i<M; ++i)
        scanf("%d", &B[i]);

    int aIdx=0, bIdx=0, count=0;
    while(aIdx < N && bIdx < M){
        if(A[aIdx] < B[bIdx])
            C[count++] = A[aIdx++];
        else
            C[count++] = B[bIdx++];
    }

    for(int i=aIdx; i<N; ++i)
        C[count++] = A[i];

    for(int i=bIdx; i<M; ++i)
        C[count++] = B[i];

    for(int i=0; i<count; ++i)
        printf("%d ", C[i]);
    printf("\n");

    return 0;
}