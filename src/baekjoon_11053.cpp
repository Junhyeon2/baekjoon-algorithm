#include <iostream>

using namespace std;

int seq[1001];
int d[1001];

int main(){
    int n;
    cin>>n;

    for(int i=1; i<=n; ++i)
        cin>>seq[i];

    for(int i=1; i<=n; ++i){
        d[i] = 1;
        for(int j=1; j<=i; ++j){
            if(seq[j] < seq[i] && d[j]+1 > d[i]){
                d[i] = d[j] + 1;
            }
        }
        // for(int j=1; j<=n; ++j)
        //     cout<<d[j]<<" ";
        // cout<<endl;
    }

    int maxVal = 0;
    for(int i=1; i<=n; i++){
        if(d[i] > maxVal)
            maxVal = d[i];
    }
    cout<<maxVal<<endl;
    return 0;
}