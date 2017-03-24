/* 문제 번호: 1726
 * 문제 이름: 로봇
 * 알고리즘 분류: BFS
 */
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <limits>
using namespace std;

const int MAX = 101;
const int INF = numeric_limits<int>::max();

class Robot{
public:
    int x;
    int y;
    int dir;
    bool checkDir[5];
    Robot(){}
    Robot(int x, int y, int dir){
        this->x = x;
        this->y = y;
        this->dir = dir;
        for(int i=1; i<=4; ++i){
            checkDir[i] = false;
        }
        checkDir[dir] = true;
    }
};
int track[MAX][MAX];
int M, N;
Robot sLoc, eLoc;

int solve(){
    queue<pair<Robot, int> > q;
    vector<pair<Robot, int> > v;
    //시작지점 큐에 삽입
    q.push(make_pair(sLoc, 0));
    track[sLoc.x][sLoc.y] = 1;
    //반복문 안에서 사용될 로봇의 위치와 방향 변수
    int curX, curY, curD, cnt;

    //갈수 있는지 없는지 판단.
    bool isPossible[4], checkMove;

    Robot curR;
    int ret = INF;
    while(true){
        //큐의 값을 벡터에 옮기고 큐를 비운다.
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }

        // for(int i=1; i<=M; ++i){
        //     for(int j=1; j<=N; ++j){
        //         cout<<track[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;


        for(int i=0; i<v.size(); ++i){
            //cout<<v[i].first.x<<" "<<v[i].first.y<<" "<<v[i].second<<endl;
            if(v[i].first.x == eLoc.x && v[i].first.y == eLoc.y && v[i].first.dir == eLoc.dir){
                //cout<<v[i].second<<endl;
                ret = min(ret, v[i].second);
            }
        }

        
        if(v.size() == 0)
            break;

        for(int i=0; i<v.size(); ++i){
            curR = v[i].first;
            //현재 로봇의 위치
            curX = v[i].first.x;
            curY = v[i].first.y;
            curD = v[i].first.dir;
            cnt = v[i].second;
            track[curX][curY] = 1;

            for(int k=1; k<=3; ++k)
                isPossible[k] = false;
            //방향을 확인하여 앞에 갈 수 있는 것을 확인
            //dir 값 > 1 - 동, 2 - 서, 3 - 남, 4 - 북
            if(curD == 1){ //동: x 증가 값
                //오른쪽
                if(curR.checkDir[3] == false){
                    curR.checkDir[3] = true;
                    curR.dir = 3;
                    q.push(make_pair(curR, cnt+1));
                }
                //왼쪽
                if(curR.checkDir[4] == false){
                    curR.checkDir[4] = true;
                    curR.dir = 4;
                    q.push(make_pair(curR, cnt+1));
                }
                if(curR.checkDir[2] == false){
                    curR.checkDir[2] = true;
                    curR.dir = 2;
                    q.push(make_pair(curR, cnt+2));
                }
                
                //방향에서 갈 수있는 길이 있는지 찾는다.
                for(int j=1; j<=3; ++j){
                    if(curY+j <= N){ //다음 진행 위치가 범위를 벗어나지 않고
                        //방문한적이 없을 때
                        checkMove = true;
                        for(int k=curY+1; k<=curY+j; ++k){
                            if(track[curX][k] == 1){
                                checkMove = false;
                            }
                        }
                        if(checkMove)
                            isPossible[j] = true;
                    }
                }

                for(int j=3; j>=1; --j){
                    //이동
                    if(isPossible[j]){
                        q.push(make_pair(Robot(curX, curY+j, curD), cnt+1));
                        //track[curX][curY+j] = 1;
                    }
                }
            }else if(curD == 2){ //서: x 감소 값
                //오른쪽
                if(curR.checkDir[3] == false){
                    curR.checkDir[3] = true;
                    curR.dir = 3;
                    q.push(make_pair(curR, cnt+1));
                }
                //왼쪽
                if(curR.checkDir[4] == false){
                    curR.checkDir[4] = true;
                    curR.dir = 4;
                    q.push(make_pair(curR, cnt+1));
                }
                if(curR.checkDir[1] == false){
                    curR.checkDir[1] = true;
                    curR.dir = 1;
                    q.push(make_pair(curR, cnt+2));
                }
                //방향에서 갈 수있는 길이 있는지 찾는다.
                for(int j=1; j<=3; ++j){
                    if(curY-j >= 1){ //다음 진행 위치가 범위를 벗어나지 않고
                        checkMove = true;
                        for(int k=curY-1; k>=curY-j; --k){
                            if(track[curX][k] == 1)
                                checkMove = false;
                        }
                        if(checkMove)
                            isPossible[j] = true;
                    }
                }
                for(int j=3; j>=1; --j){
                    //이동
                    if(isPossible[j]){
                        q.push(make_pair(Robot(curX, curY-j, curD), cnt+1));
                        //track[curX][curY-j] = 1;
                    }
                }
            }else if(curD == 3){ //남: y 증가 값
                //왼쪽
                if(curR.checkDir[1] == false){
                    curR.checkDir[1] = true;
                    curR.dir = 1;
                    q.push(make_pair(curR, cnt+1));
                }
                //오른쪽
                if(curR.checkDir[2] == false){
                    curR.checkDir[2] = true;
                    curR.dir = 2;
                    q.push(make_pair(curR, cnt+1));
                }
                if(curR.checkDir[4] == false){
                    curR.checkDir[4] = true;
                    curR.dir = 4;
                    q.push(make_pair(curR, cnt+2));
                }
                //방향에서 갈 수있는 길이 있는지 찾는다.
                for(int j=1; j<=3; ++j){
                    if(curX+j <= M){ //다음 진행 위치가 범위를 벗어나지 않고
                        checkMove = true;
                        for(int k=curX+1; k<=curX+j; ++k){
                            //cout<<k<<" "<<curY<<" "<<cnt+1<<endl;
                            if(track[k][curY] == 1){
                                checkMove = false;
                            }
                        }
                        if(checkMove){
                            isPossible[j] = true;
                        }
                    }
                }
                for(int j=3; j>=1; --j){
                    //이동
                    if(isPossible[j]){
                        q.push(make_pair(Robot(curX+j, curY, curD), cnt+1));
                        //track[curX+j][curY] = 1;
                    }
                }
            }else if(curD == 4){ //북: y 감소 값
                //오른쪽
                if(curR.checkDir[1] == false){
                    curR.checkDir[1] = true;
                    curR.dir = 1;
                    q.push(make_pair(curR, cnt+1));
                }
                //왼쪽
                if(curR.checkDir[2] == false){
                    curR.checkDir[2] = true;
                    curR.dir = 2;
                    q.push(make_pair(curR, cnt+1));
                }
                if(curR.checkDir[3] == false){
                    curR.checkDir[3] = true;
                    curR.dir = 3;
                    q.push(make_pair(curR, cnt+2));
                }
                //방향에서 갈 수있는 길이 있는지 찾는다.
                for(int j=1; j<=3; ++j){
                    if(curX-j >= 1){ //다음 진행 위치가 범위를 벗어나지 않고
                        checkMove = true;
                        for(int k=curX-1; k>=curX-j; --k){
                            if(track[k][curY] == 1){
                                checkMove = false;
                            }
                        }
                        if(checkMove){
                            isPossible[j] = true;
                        }
                    }
                }
                for(int j=3; j>=1; --j){
                    //이동
                    if(isPossible[j]){
                        q.push(make_pair(Robot(curX-j, curY, curD), cnt+1));
                        //track[curX-j][curY] = 1;
                    }
                }
            }
            // if(isPossible[1] || isPossible[2] || isPossible[3])
                
        }
        v.clear();
    }
    return ret;
}

int main(void){
    memset(track, -1, sizeof(track));
    int x, y, dir;
    cin>>M>>N;
    for(int i=1; i<=M; ++i){
        for(int j=1; j<=N; ++j){
            cin>>track[i][j];
        }
    }
    cin>>x>>y>>dir;
    sLoc = Robot(x, y, dir);
    cin>>x>>y>>dir;
    eLoc = Robot(x, y, dir);

    int ret = solve();

    cout<<ret<<endl;

    return 0;
}