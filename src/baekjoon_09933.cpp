#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<string> input;
    int N;
    cin>>N;

    string temp;
    for(int i=0; i<N; ++i){
        cin>>temp;
        input.push_back(temp);
    }

    for(int i=0; i<input.size(); ++i){
        temp = input[i];
        reverse(temp.begin(), temp.end());
        for(int j=i; j<input.size(); ++j){
            if(temp.compare(input[j]) == 0){
                cout<<temp.size()<<" "<<temp[temp.size()/2]<<endl;
            }
        }
    }

    return 0;
}