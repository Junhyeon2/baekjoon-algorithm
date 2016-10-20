/* 문제 번호: 1062
 * 문제 이름: 가르침
 * 알고리즘 분류: DFS
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool solve(string word, int k){
	int cnt = k;
	string prefix = word.substr(0, 4);
	string suffix = word.substr(word.length()-4, word.length());

	//cout<<prefix<<" "<<suffix<<endl;
	if(prefix == "anta" && suffix == "tica"){
		//cout<<word<<endl;
		string newWord = word.substr(4, word.length()-8);
		vector<char> alpha;
		alpha.push_back('a');
		alpha.push_back('n');
		alpha.push_back('t');
		alpha.push_back('i');
		alpha.push_back('c');
		//cout<<newWord<<endl;
		
		for(int i=0; i<newWord.length(); ++i){
			bool isExisit = false;
			for(int j=0; j<alpha.size(); ++j){
				if(alpha[j] == newWord[i]){
					isExisit = true;
				}
			}
			if(!isExisit){
				alpha.push_back(newWord[i]);
				k--;
			}
		}
	}else{
		return false;
	}
	
	if(k >=0 || k == cnt){
		//cout<<word<<endl;
		return true;
	}
	else
		return false;
}

int main(void){
	int n, k;
	cin>>n>>k;
	vector<string> words;

	for(int i=0; i<n; ++i){
		string temp;
		cin>>temp;
		words.push_back(temp);
	}
	int cnt = 0;
	for(int i=0; i<words.size(); ++i){
		bool ret = solve(words[i], k-5);
		if(ret)
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}