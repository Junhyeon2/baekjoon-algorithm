#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, time;
    vector<int> v;
    cin>>n;

    for(int i=0; i<n; ++i){
        cin>>time;
        v.push_back(time);
    }

    sort(v.begin(), v.end());

    time = v[0];

    for(int i=1; i<v.size(); ++i){
        v[i] = v[i-1] + v[i];
        time += v[i];
    }

    cout<<time<<endl;
    return 0;
}