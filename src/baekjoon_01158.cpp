#include <iostream>
#include <queue>
using namespace std;


int main(){
    int N, M, temp, curIdx=0;
    queue<int> input;
    queue<int> output;

    cin>>N>>M;
    for(int i=1; i<=N; ++i){
        input.push(i);
    }

    while(output.size() != N){
        curIdx++;
        if(curIdx % M == 0){
            curIdx = 0;
            output.push(input.front());
        }else{
            input.push(input.front());
        }
        input.pop();
    }
    cout<<"<";
    while(!output.empty()){
        cout<<output.front();
        output.pop();
        if(output.size() != 0)
            cout<<", ";
    }
    cout<<">"<<endl;
    return 0;
}