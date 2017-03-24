#include <iostream>

using namespace std;

int seq[1001];
int d1[1001];
int d2[1001];

int main(){
    int n;
    cin>>n;

    for(int i=1; i<=n; ++i)
        cin>>seq[i];

    for(int i=1; i<=n; ++i){
        d1[i] = 1;
        for(int j=1; j<=i; ++j){
            if(seq[j] < seq[i] && d1[j]+1 > d1[i]){
                d1[i] = d1[j] + 1;
            }
        }
    }
    for(int i=n; i>=1; --i){
        d2[i] = 1;
        for(int j=n; j>=i; --j){
            if(seq[j] < seq[i] && d2[j]+1 > d2[i]){
                d2[i] = d2[j] + 1;
            }
        }
    }
    int maxVal = 0;
    for(int i=1; i<=n; i++){
        if(d1[i]+d2[i] > maxVal)
            maxVal = d1[i]+d2[i];
    }
    cout<<maxVal-1<<endl;
    return 0;
}