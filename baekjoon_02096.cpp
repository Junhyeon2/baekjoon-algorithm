/* 문제 번호: 2096
 * 문제 이름: 내려가기
 * 알고리즘 분류: 동적 계획법(DP)
 */
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

const int MAX = 100000;
const int INF = numeric_limits<int>::max();

int input[MAX][3];
int maxArr[3];
int minArr[3];
int N;

int main(void){
    cin>>N;

    for(int i=0; i<N; ++i)
        for(int j=0; j<3; ++j)
            cin>>input[i][j];

    for(int i=0; i<3; ++i)
        maxArr[i] = minArr[i] = input[0][i];

    int maxTemp[3], minTemp[3];

    for(int i=1; i<N; ++i){
        for(int j=0; j<3; ++j)
            maxTemp[j] = -1;
        for(int j=0; j<3; ++j){
            if(j == 0){
                maxTemp[j] = max(maxTemp[j], maxArr[j]+input[i][j]);
                maxTemp[j+1] = max(maxTemp[j+1], maxArr[j]+input[i][j+1]);
            }else if(j == 1){
                maxTemp[j-1] = max(maxTemp[j-1], maxArr[j]+input[i][j-1]);
                maxTemp[j] = max(maxTemp[j], maxArr[j]+input[i][j]);
                maxTemp[j+1] = max(maxTemp[j+1], maxArr[j]+input[i][j+1]);
            }else{
                maxTemp[j-1] = max(maxTemp[j-1], maxArr[j]+input[i][j-1]);
                maxTemp[j] = max(maxTemp[j], maxArr[j]+input[i][j]);
            }
        }
        for(int j=0; j<3; ++j)
            maxArr[j] = maxTemp[j];
    }

    for(int i=1; i<N; ++i){
        for(int j=0; j<3; ++j)
            minTemp[j] = INF;
        for(int j=0; j<3; ++j){
            if(j == 0){
                minTemp[j] = min(minTemp[j], minArr[j]+input[i][j]);
                minTemp[j+1] = min(minTemp[j+1], minArr[j]+input[i][j+1]);
            }else if(j == 1){
                minTemp[j-1] = min(minTemp[j-1], minArr[j]+input[i][j-1]);
                minTemp[j] = min(minTemp[j], minArr[j]+input[i][j]);
                minTemp[j+1] = min(minTemp[j+1], minArr[j]+input[i][j+1]);
            }else{
                minTemp[j-1] = min(minTemp[j-1], minArr[j]+input[i][j-1]);
                minTemp[j] = min(minTemp[j], minArr[j]+input[i][j]);
            }
        }
        for(int j=0; j<3; ++j)
            minArr[j] = minTemp[j];
    }

    int maxVal = -1;
    int minVal = INF;
    for(int i=0; i<3; ++i){
        if(maxArr[i] > maxVal)
            maxVal = maxArr[i];
        if(minArr[i] < minVal)
            minVal = minArr[i];
    }
    cout<<maxVal<<" "<<minVal<<endl;

    return 0;
}
