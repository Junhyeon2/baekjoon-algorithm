/* 문제 번호: 1759
 * 문제 이름: 암호 만들기
 * 알고리즘 분류: DFS
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool check(string &password){
	int ja = 0;
	int mo = 0;
	for(int i=0; i<password.length(); ++i){
		if(password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u'){
			mo += 1;
		}else{
			ja += 1;
		}
	}
	return ja >= 2 && mo >= 1;
}

void go(int n, vector<char> &alpha, string password, int i){
	if(password.length() == n){
		if(check(password)){
			cout<<password<<endl;
		}
		return;
	}
	if(i >= alpha.size())
		return;
	go(n, alpha, password+alpha[i], i+1);
	go(n, alpha, password, i+1);
}

int main(){
	int n, m;
    cin>>n>>m;
    vector<char> a(m);
    for (int i=0; i<m; i++) {
        cin>>a[i];
    }

    sort(a.begin(), a.end());
    
    go(n, a, "", 0);

    return 0;
}