#include <iostream>
#include <vector>
using namespace std;

int inOrder[100001];
int position[100001];
int postOrder[100001];
int n;
void solve(int is, int ie, int ps, int pe){
    if(is > ie || ps > pe || pe == 0)
        return;
    int root = postOrder[pe];
    int ir = position[root];
    int l = ir - is;

    printf("%d ", root);

    //left
    solve(is, ir-1, ps, ps+l-1);

    //right
    solve(ir+1, ie, ps+l, pe-1);
}

int main(){
    cin>>n;

    for(int i=1; i<=n; ++i){
        scanf("%d", &inOrder[i]);
        position[inOrder[i]] = i;
    }
    for(int i=1; i<=n; ++i)
        scanf("%d", &postOrder[i]);

    solve(0, n, 0, n);
    printf("\n");
    return 0;
}