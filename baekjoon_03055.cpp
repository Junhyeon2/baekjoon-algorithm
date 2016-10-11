/* 문제 번호: 3055
 * 문제 이름: 탈출
 * 알고리즘 분류: BFS, 시뮬레이션
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

class Point{
public:
    int x;
    int y;
    Point(){}
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int R, C;
vector<vector<char> > forest;

int solve(Point s, Point e, vector<Point> w, vector<Point> r){
    int visit[R][C];
    memset(visit, -1, sizeof(visit));

    queue<Point> wq;
    queue<pair<Point, int> >sq;

    for(int i=0; i<w.size(); ++i){
        visit[w[i].x][w[i].y] = 2;
        wq.push(w[i]);
    }

    for(int i=0; i<r.size(); ++i)
        visit[r[i].x][r[i].y] = 1;

    visit[s.x][s.y] = 0;
    sq.push(make_pair(s, 0));
    int ret = -1;
    int visitVal;
    vector<Point> wv;
    vector<pair<Point, int> > sv;

    while(true){

        while(!wq.empty()){
            wv.push_back(wq.front());
            wq.pop();
        }
        while(!sq.empty()){
            sv.push_back(sq.front());
            sq.pop();
        }
/*
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                cout<<visit[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
*/
        for(int i=0; i<sv.size(); ++i){
            if(sv[i].first.x == e.x && sv[i].first.y == e.y){
                 ret = sv[i].second;
                 break;
             }
        }

        if(sv.size() == 0)
            break;

        for(int i=0; i<wv.size(); ++i){
            Point up(wv[i].x, wv[i].y-1);
            Point down(wv[i].x, wv[i].y+1);
            Point left(wv[i].x-1, wv[i].y);
            Point right(wv[i].x+1, wv[i].y);
            // cout<<"UP: "<<up.x<<", "<<up.y<<endl;
            // cout<<"DOWN: "<<down.x<<", "<<down.y<<endl;
            // cout<<"LEFT: "<<left.x<<", "<<left.y<<endl;
            // cout<<"RIGHT: "<<right.x<<", "<<right.y<<endl;

            if(up.y >= 0){
                visitVal = visit[up.x][up.y];
                if(((visitVal == -1 || visitVal == 0) && visitVal != 2) && !(up.x == e.x && up.y == e.y)){
                    visit[up.x][up.y] = 2;
                    wq.push(up);
                }
            }
            if(down.y < C){
                visitVal = visit[down.x][down.y];
                if(((visitVal == -1 || visitVal == 0) && visitVal != 2)&& !(down.x == e.x && down.y == e.y)){
                    visit[down.x][down.y] = 2;
                    wq.push(down);
                }
            }
            if(left.x >= 0){
                visitVal = visit[left.x][left.y];
                if(((visitVal == -1 || visitVal == 0) && visitVal != 2) && !(left.x == e.x && left.y == e.y)){
                    visit[left.x][left.y] = 2;
                    wq.push(left);
                }
            }
            if(right.x < R){
                visitVal = visit[right.x][right.y];
                if(((visitVal == -1 || visitVal == 0) && visitVal != 2) && !(right.x == e.x && right.y == e.y)){
                    visit[right.x][right.y] = 2;
                    wq.push(right);
                }
            }
        }
        wv.clear();

        for(int i=0; i<sv.size(); ++i){
            Point up(sv[i].first.x, sv[i].first.y-1);
            Point down(sv[i].first.x, sv[i].first.y+1);
            Point left(sv[i].first.x-1, sv[i].first.y);
            Point right(sv[i].first.x+1, sv[i].first.y);
            int cnt = sv[i].second;
            if(up.y >= 0){
                visitVal = visit[up.x][up.y];
                if(visitVal == -1){
                    visit[up.x][up.y] = 0;
                    sq.push(make_pair(up, cnt+1));
                }
            }
            if(down.y < C){
                visitVal = visit[down.x][down.y];
                if(visitVal == -1){
                    visit[down.x][down.y] = 0;
                    sq.push(make_pair(down, cnt+1));
                }
            }
            if(left.x >= 0){
                visitVal = visit[left.x][left.y];
                if(visitVal == -1){
                    visit[left.x][left.y] = 0;
                    sq.push(make_pair(left, cnt+1));
                }
            }
            if(right.x < R){
                visitVal = visit[right.x][right.y];
                if(visitVal == -1){
                    visit[right.x][right.y] = 0;
                    sq.push(make_pair(right, cnt+1));
                }
            }
        }
        sv.clear();
    }
    return ret;
}

int main(void){
    cin>>R>>C;
    Point start, end;
    vector<Point> waters;
    vector<Point> rocks;
    for(int i=0; i<R; ++i){
        vector<char> row;
        for(int j=0; j<C; ++j){
            char input;
            cin>>input;
            if(input == 'S'){
                start.x = i;
                start.y = j;
            }
            if(input == 'D'){
                end.x = i;
                end.y = j;
            }
            if(input == '*'){
                Point p(i, j);
                waters.push_back(p);
            }
            if(input == 'X'){
                Point p(i, j);
                rocks.push_back(p);
            }
            row.push_back(input);
        }
        forest.push_back(row);
    }
    int ret = solve(start, end, waters, rocks);
    if(ret == -1)
        cout<<"KAKTUS"<<endl;
    else
        cout<<ret<<endl;

    return 0;
}