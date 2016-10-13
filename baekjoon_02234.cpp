/* 문제 번호: 2234
 * 문제 이름: 성곽
 * 알고리즘 분류: BFS
 */
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

const int MAX = 51;

class Coord{
public:
    int x;
    int y;
    Coord(){}
    Coord(int x, int y){
        this->x = x;
        this->y = y;
    }
};
int M, N;
int wall[MAX][MAX];
int isVisited[MAX][MAX];

pair<int, int> nextVisit(){
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            if(!isVisited[i][j]){
                return make_pair(i, j);
            }
        }
    }
    return make_pair(0, 0);
}

void solve(){
    queue<pair<Coord, int> > q;
    q.push(make_pair(Coord(1, 1), 1));
    isVisited[1][1] = 1;

    vector<pair<Coord, int> > v;
    vector<int> roomSize;
    roomSize.push_back(0); //dummy value
    bool isWall[4], isNextWall[4], isAllVisited;
    int idxWall, curWall, nextWall, curX, curY, size, numOfRoom = 1, maxSize = 0, mergeSize = 0;
    pair<int, int> nextPos;

    while(true){

        isAllVisited = true;
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }
        for(int i=1; i<=N; ++i){
            for(int j=1; j<=M; ++j)
                cout<<isVisited[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;

        if(v.size() == 0){
            nextPos = nextVisit();

            if(nextPos.first == 0 && nextPos.second == 0){
                break;
            }else{
                numOfRoom++;
                // cout<<"next: "<<nextPos.first<<" "<<nextPos.second<<endl;
                v.push_back(make_pair(Coord(nextPos.first, nextPos.second), 1));
                isVisited[nextPos.first][nextPos.second] = numOfRoom;
            }
        }

        for(int i=0; i<v.size(); ++i){
            //벽이 있는지 확인하는 변수 모두 false로 초기화
            for(int j=0; j<4; ++j)
                isWall[j] = false;

            //현재 위치의 벽의 상태 값을 받는다.
            curX = v[i].first.x;
            curY = v[i].first.y;
            size = v[i].second;
            curWall = wall[curX][curY];

            //cout<<curWall<<endl;


            //현재 위치의 값으로 4방향에 벽이 있는지 확인하고 isWall 배열에 true/false로 초기화
            idxWall = 0; //0: 서, 1: 북, 2:동, 3: 남
            while(curWall > 0){
                //벽이 있으면
                if(curWall%2 == 1)
                    isWall[idxWall] = true;
                //서 -> 북 -> 동 -> 남 순으로 확인. (2진수의 최하위 비트의 값으로 확인)
                curWall /= 2;
                idxWall++;
            }
            // for(int j=3; j>=0; --j)
            //     cout<<isWall[j]<<" ";
            // cout<<endl<<endl;
            // 다음으로 이동할 좌표가 범위 밖으로 넘어가지 않을 경우만 계산
            for(int j=0; j<4; ++j){
                for(int k=0; k<4; ++k)
                    isNextWall[k] = false;

                if(isWall[j] == false){
                    if(j == 0){ //서쪽
                        if(curY- 1 >= 1)
                            if(isVisited[curX][curY-1] == 0){
                                //이 방향의 wall값으로 넘어갈 수 있는지 확인
                                idxWall = 0; //0: 서, 1: 북, 2:동, 3: 남
                                nextWall = wall[curX][curY-1];
                                while(nextWall > 0){
                                    if(nextWall%2 == 1)
                                        isNextWall[idxWall] = true;
                                    nextWall /= 2;
                                    idxWall++;
                                }
                                if(isNextWall[2] == false){
                                    isVisited[curX][curY-1] = numOfRoom;
                                    q.push(make_pair(Coord(curX, curY-1), size + 1));
                                }
                            }
                    }else if(j == 1){ //북쪽
                        if(curX - 1 >= 1)
                            if(isVisited[curX-1][curY] == 0){
                                //이 방향의 wall값으로 넘어갈 수 있는지 확인
                                idxWall = 0; //0: 서, 1: 북, 2:동, 3: 남
                                nextWall = wall[curX-1][curY];
                                while(nextWall > 0){
                                    if(nextWall%2 == 1)
                                        isNextWall[idxWall] = true;
                                    nextWall /= 2;
                                    idxWall++;
                                }
                                if(isNextWall[3] == false){
                                    isVisited[curX-1][curY] = numOfRoom;
                                    q.push(make_pair(Coord(curX-1, curY), size + 1));
                                }
                            }
                    }else if(j == 2){ //동쪽
                        //cout<<curY + 1<<" "<<M<<endl;
                        if(curY + 1 <= M)
                            if(isVisited[curX][curY+1] == 0){
                                idxWall = 0; //0: 서, 1: 북, 2:동, 3: 남
                                nextWall = wall[curX][curY+1];
                                while(nextWall > 0){
                                    if(nextWall%2 == 1)
                                        isNextWall[idxWall] = true;
                                    nextWall /= 2;
                                    idxWall++;
                                }
                                if(isNextWall[0] == false){
                                    isVisited[curX][curY+1] = numOfRoom;
                                    q.push(make_pair(Coord(curX, curY+1), size + 1));
                                }
                            }
                    }else if(j == 3){ //남쪽
                        if(curX + 1 <= N)
                            if(isVisited[curX+1][curY] == 0){
                                idxWall = 0; //0: 서, 1: 북, 2:동, 3: 남
                                nextWall = wall[curX+1][curY];
                                while(nextWall > 0){
                                    if(nextWall%2 == 1)
                                        isNextWall[idxWall] = true;
                                    nextWall /= 2;
                                    idxWall++;
                                }
                                if(isNextWall[1] == false){
                                    isVisited[curX+1][curY] = numOfRoom;
                                    q.push(make_pair(Coord(curX+1, curY), size + 1));
                                }
                            }
                    }
                }
            }
        }

        v.clear();
    }
    int numOfSize;
    for(int k=1; k<=numOfRoom; ++k){
        numOfSize = 0;
        for(int i=1; i<=N; ++i){
            for(int j=1; j<=M; ++j){
                if(k == isVisited[i][j])
                    numOfSize++;
            }
        }
        roomSize.push_back(numOfSize);
    }

    for(int i=1; i<roomSize.size(); ++i){
        maxSize = max(maxSize, roomSize[i]);
    }

    int prevRoom, nextRoom;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            if(i == 1 && j == 1)
                prevRoom = isVisited[i][j];
            if(prevRoom == -1)
                prevRoom =  isVisited[i][j];
            nextRoom = isVisited[i][j];
            if(prevRoom != nextRoom){
                //cout<<prevRoom<<" "<<nextRoom<<" 인접!"<<endl;
                //cout<<roomSize[prevRoom]<<" "<<roomSize[nextRoom]<<" "<<mergeSize<<endl;
                mergeSize = max(mergeSize, roomSize[prevRoom]+roomSize[nextRoom]);
                prevRoom = nextRoom;
            }
        }
        prevRoom = -1;
    }
    // for(int i=1; i<roomSize.size(); ++i){
    //     cout<<roomSize[i]<<" ";
    // }
    // cout<<endl;

    cout<<numOfRoom<<endl;
    cout<<maxSize<<endl;
    cout<<mergeSize<<endl;
/*
    bool isWall[4];

    int res;
    while(n > 0){
        res = n%2;
        cout<<res<<endl;
        n /= 2;
    }
*/
}

int main(void){
    memset(wall, -1, sizeof(wall));
    memset(isVisited, 0, sizeof(isVisited));

    cin>>M>>N;
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j)
            cin>>wall[i][j];

    solve();

    return 0;
}