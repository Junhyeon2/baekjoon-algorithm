#include <iostream>
using namespace std;

int seq[500001];
int tmp[500001];
long long cntSwap = 0;

void merge(int l, int m, int r){
    int i, j, idx;
    i = idx = l;
    j = m+1;

    while(i <= m && j <= r){
        if(seq[i] < seq[j]){
            tmp[idx++] = seq[i++];
        }else{
            //오른쪽에서 왼쪽으로 이동될 때 왼쪽에 이동이 안된 원소 수 만큼 SWAP
            cntSwap += m-i+1;
            tmp[idx++] = seq[j++];
        }
    }

    if(i > m){
        for(int k=j; k<=r; ++k)
            tmp[idx++] = seq[k];
    }else{
        for(int k=i; k<=m; ++k)
            tmp[idx++] = seq[k];
    }

    for(int k=l; k<=r; ++k)
        seq[k] = tmp[k];
}

void mergeSort(int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(l, m);
        mergeSort(m+1, r);

        merge(l, m, r);
    }
}

int main(){
    int n;
    cin>>n;

    for(int i=1; i<=n; ++i)
        cin>>seq[i];

    mergeSort(1, n);

    cout<<cntSwap<<endl;
    return 0;
}