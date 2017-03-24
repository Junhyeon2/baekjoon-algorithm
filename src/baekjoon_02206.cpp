#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <limits>
#include <cmath>
using namespace std;

class Pos{
public:
    int x, y;
    bool crack;
    Pos(){}
    Pos(int _y, int _x, bool _crack){
        x = _x;
        y = _y;
        crack = _crack;
    }
};
const int INF = numeric_limits<int>::max();
int adj[1001][1001];
int isVisited[1001][1001][2];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int N, int M){
    queue<Pos> q;
    queue<int> count;
    q.push(Pos(1, 1, false));

    Pos curPos;
    int nx, ny, cx, cy;
    bool nc, cc;
    isVisited[1][1][0] = 1;
    while(!q.empty()){
        curPos = q.front();
        q.pop();
        cx = curPos.x;
        cy = curPos.y;
        cc = curPos.crack;
        for(int i=0; i<4; ++i){
            nx = cx+dx[i];
            ny = cy+dy[i];

            if (nx<1 || nx>M || ny<1 || ny>N)
                continue;

            if(adj[ny][nx] == 0 && (isVisited[cy][cx][cc]+1 < isVisited[ny][nx][cc])){
                isVisited[ny][nx][cc] = isVisited[cy][cx][cc]+1;
                q.push(Pos(ny, nx, cc));
            }else if(adj[ny][nx] == 1 && cc == false && (isVisited[cy][cx][0]+1 < isVisited[ny][nx][1])){
                isVisited[ny][nx][1] = isVisited[cy][cx][0]+1;
                q.push(Pos(ny, nx, true));
            }
        }

    }
    if(isVisited[N][M][0] == INF && isVisited[N][M][1] == INF)
        return -1;
    else
        return min(isVisited[N][M][0], isVisited[N][M][1]);
}

int main(){
    int N, M;
    string input;
    cin>>N>>M;
    memset(adj, -1, sizeof(adj));

    for(int i=1; i<=N; ++i){
        cin>>input;
        for(int j=0; j<input.size(); ++j){
            adj[i][j+1] = input[j] -'0';
            isVisited[i][j+1][0] = INF;
            isVisited[i][j+1][1] = INF;
        }
    }
    cout<<bfs(N, M)<<endl;
    return 0;
}