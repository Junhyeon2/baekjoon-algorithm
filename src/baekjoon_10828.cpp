#include <iostream>
#include <string>
using namespace std;

const int MAX = 10000;
int stack[MAX];

int main(){
    int N, top = -1;
    string comm;
    cin>>N;

    for(int i=0; i<N; ++i){
        cin>>comm;
        if(comm.compare("push") == 0){
            cin>>stack[++top];
        }else if(comm.compare("top") == 0){
            if(top != -1)
                cout<<stack[top]<<endl;
            else
                cout<<top<<endl;
        }else if(comm.compare("size") == 0){
            cout<<top+1<<endl;
        }else if(comm.compare("pop") == 0){
            if(top != -1){
                cout<<stack[top--]<<endl;
            }else{
                cout<<top<<endl;
            }
        }else if(comm.compare("empty") == 0){
            if(top != -1)
                cout<<"0"<<endl;
            else
                cout<<"1"<<endl;
        }
    }

    return 0;
}