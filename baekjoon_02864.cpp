/* 문제 번호: 2864
 * 문제 이름: 5와 6의 차이
 * 알고리즘 분류: 수학, 문자열 처리
 */
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(void){
    string str1, str2, maxStr1, maxStr2, minStr1, minStr2;

    cin>>str1>>str2;
    maxStr1.assign(str1);
    maxStr2.assign(str2);
    minStr1.assign(str1);
    minStr2.assign(str2);

    for(int i=0; i<maxStr1.size(); ++i){
        if(maxStr1[i] == '5')
            maxStr1[i] = '6';
    }

    for(int i=0; i<maxStr2.size(); ++i){
        if(maxStr2[i] == '5')
            maxStr2[i] = '6';
    }

    for(int i=0; i<minStr1.size(); ++i){
        if(minStr1[i] == '6')
            minStr1[i] = '5';
    }

    for(int i=0; i<minStr2.size(); ++i){
        if(minStr2[i] == '6')
            minStr2[i] = '5';
    }

    int max = atoi(maxStr1.c_str()) + atoi(maxStr2.c_str());
    int min = atoi(minStr1.c_str()) + atoi(minStr2.c_str());

    cout<<min<<" "<<max<<endl;

    return 0;
}