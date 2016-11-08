#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(b.second > a.second)
        return true;
    else if(b.second == a.second){
        return a.first < b.first;
    }else
        return false;
}

int main(){
    int n, start, end, count=1;
    vector<pair<int, int> > v;
    cin>>n;

    for(int i=0; i<n; ++i){
        cin>>start>>end;
        v.push_back(make_pair(start, end));
    }
    sort(v.begin(), v.end(), cmp);

    end = v[0].second;

    for(int i=1; i<n; ++i){
        if(end <= v[i].first){
            end = v[i].second;
            count++;
        }
    }

    cout<<count<<endl;
    return 0;
}