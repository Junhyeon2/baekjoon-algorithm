#include <iostream>
using namespace std;

int main(){
    string plain, crypt;
    getline(cin, plain);
    cin>>crypt;

    char c;
    for(int i=0; i<plain.size(); ++i){
        if(plain[i] == ' '){
            cout<<' ';
        }else{
            c = plain[i] - crypt[i%crypt.size()];
            if(c > 0)
                cout<<(char)(c+96);
            else
                cout<<(char)(c+122);
        }
    }
    cout<<endl;

    return 0;
}