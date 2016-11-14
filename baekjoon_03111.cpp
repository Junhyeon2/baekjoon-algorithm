#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string A, T;
    stack<char> left, right;
    cin>>A>>T;

    int start=0, end=T.size()-1, cnt=0;
    int leftIdx=0, rightIdx=A.size()-1;
    int aSize = A.size(), tSize = T.size();
    int leftCnt=0, rightCnt=0;
    while(start <= end){
        cout<<start<<" "<<end<<endl;
        if(cnt%2==0){ //left
            left.push(T[start]);
            if(T[start] == A[leftIdx])
                leftIdx++;
            start++;
            cout<<"L I:"<<leftIdx<<endl;
            if(leftIdx == aSize){
                for(int i=0; i<aSize; ++i){
                    cout<<"L: "<<left.top()<<endl;
                    left.pop();
                }
                leftIdx = 0;
                leftCnt++;
                //find idx
                cout<<start-aSize<<endl;
                for(int i=0; i<start-aSize*leftCnt; ++i){
                    if(T[i] == A[leftIdx])
                        leftIdx++;
                    else{
                        if(T[i] == A[0])
                            leftIdx = 1;
                        else
                            leftIdx = 0;
                    }
                }
                cnt++;
            }
        }else{ //right
            right.push(T[end]);
            if(T[end] == A[rightIdx])
                rightIdx--;
            end--;
            if(rightIdx == -1){
                for(int i=0; i<aSize; ++i){
                    cout<<"R: "<<right.top()<<endl;
                    right.pop();
                }
                rightIdx = aSize-1;
                rightCnt++;
                for(int i=tSize-1; i>=end+aSize*rightCnt; --i){
                    if(T[i] == A[rightIdx])
                        rightIdx--;
                    else{
                        if(T[i] ==A[aSize-1])
                            rightIdx = aSize-2;
                        else
                            rightIdx = aSize-1;
                    }
                }
                cnt++;
            }
        }
    }
    cout<<endl;
    cout<<leftIdx<<" "<<rightIdx<<endl;
    while(!left.empty()){
        cout<<left.top()<<endl;
        right.push(left.top());
        if(left.top() == A[rightIdx])
            rightIdx--;
        left.pop();
        if(rightIdx == -1){
            for(int i=0; i<aSize; ++i){
                cout<<"R: "<<right.top()<<endl;
                right.pop();
            }
            rightIdx = aSize-1;
        }
    }
    cout<<endl;
    while(!right.empty()){
        cout<<right.top();
        right.pop();
    }

    // while(!left.empty()){
    //     right.push(left.top());
    //     left.pop();
    // }

    // while(!right.empty()){
    //     cout<<right.top()<<endl;
    //     right.pop();
    // }

    return 0;
}