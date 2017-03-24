#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int N, K, L, appX, appY, time, X=1, Y=1, dir;
    char chDir;
    vector<pair<int, int> > apples;
    vector<pair<int, char> > infos;
    vector<pair<int, int> > snake;
    cin>>N>>K;

    for(int i=0; i<K; ++i){
        cin>>appX>>appY;
        apples.push_back(make_pair(appX, appY));
    }
    cin>>L;
    for(int i=0; i<L; ++i){
        cin>>time>>chDir;
        infos.push_back(make_pair(time, chDir));
    }

    //D dir = 0
    //L dir = 1

    time = 0;
    dir = 3;
    snake.push_back(make_pair(X, Y));
    bool eatApple, isCollison;

    while(true){
        //change direct
        for(int i=0; i<infos.size(); ++i){
            if(infos[i].first == time){
                if(infos[i].second == 'D'){
                    if(dir == 0){
                        dir = 3;
                    }else if(dir == 1){
                        dir = 2;
                    }else if(dir == 2){
                        dir = 0;
                    }else if(dir == 3){
                        dir = 1;
                    }
                }else if(infos[i].second == 'L'){
                    if(dir == 0){
                        dir = 2;
                    }else if(dir == 1){
                        dir = 3;
                    }else if(dir == 2){
                        dir = 1;
                    }else if(dir == 3){
                        dir = 0;
                    }
                }
            }
        }
         //go - > X, Y change
        if(dir == 0){ //UP
            X -= 1;
        }else if(dir == 1){ //DOWN
            X += 1;
        }else if(dir == 2){ //LEFT
            Y -= 1;
        }else if(dir == 3){ //RIGHT
            Y += 1;
        }
        time++;

        //check eat apple -> add tails
        eatApple = false;
        int eraseTaget;
        for(int i=0; i<apples.size(); ++i){
            if(apples[i].first == X && apples[i].second == Y){
                snake.push_back(make_pair(X, Y));
                eatApple = true;
                eraseTaget = i;
                break;
            }
        }

        if(!eatApple){

            snake.push_back(make_pair(X, Y));
            //check collision
            isCollison = false;
            for(int i=0; i<snake.size()-1; ++i){
                for(int j=i+1; j<snake.size(); ++j){
                    if(snake[i].first == snake[j].first && snake[i].second == snake[j].second){
                        isCollison = true;
                        break;
                    }
                }
                if(isCollison)
                    break;
            }
            if(isCollison){
                cout<<time<<endl;
                return 0;
            }

            snake.erase(snake.begin());
        }else{
            apples.erase(apples.begin()+eraseTaget);
        }
        // output test
        // cout<<"direction : "<<dir<<endl;
        // cout<<"apples num: "<<apples.size()<<endl;
        // cout<<"time: "<<time<<endl;
        // for(int k=0; k<snake.size(); ++k){
        //     cout<<snake[k].first<<" "<<snake[k].second<<endl;
        // }
        // cout<<endl;

        //check range
        if((X < 1 || X > N) || (Y < 1 || Y > N)){
            cout<<time<<endl;
            return 0;
        }

    }
}