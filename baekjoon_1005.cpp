#include <iostream>
#include <vector>
using namespace std;

/*
void slove(int s, int w, int n, vector<int> adj[], vector<int> &d, vector<int> &lev){
    for(int i=1; i<=n; ++i){
        for(int j=0; j<adj[i].size(); ++j){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
*/
int main(void){
    int tc;

    cin>>tc;

    for(int test_case=0; test_case<tc; ++test_case){
        int n, k, w, ret = 0, lev = 1;
        cin>>n>>k;
        vector<int> d, adj[n+1], levVector;

        d.assign(n+1, 0);
        levVector.assign(n+1, 0);
        for(int i=1; i<=n; ++i)
            cin>>d[i];

        for(int i=0; i<k; ++i){
            int x, y;
            cin>>x>>y;
            adj[x].push_back(y);
        }
        cin>>w;

        levVector[1] = 1;
        for(int i=1; i<=n; ++i){
            for(int j=0; j<adj[i].size(); ++j){
                levVector[adj[i][j]] = levVector[i]+1;
            }
        }
        //알고리즘
        for(int i=1; i<d.size();){
            d[levVector[i]];
        }
        cout<<endl;

        d.clear();
        levVector.clear();
        for(int i=0; i<=n; ++i)
            adj[i].clear();

    }
    return 0;
}