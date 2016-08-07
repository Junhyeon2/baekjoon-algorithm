#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int tc;

	cin>>tc;

    for(int test_case=0; test_case<tc; ++test_case){
        int x1, y1, x2, y2, num, ret=0;
        cin>>x1>>y1>>x2>>y2;
        cin>>num;

        for(int i=0; i<num; ++i){
        	int cx, cy, r;
        	cin>>cx>>cy>>r;

        	double d1 = sqrt(pow(cx- x1, 2) + pow(cy - y1, 2));
        	double d2 = sqrt(pow(cx- x2, 2) + pow(cy - y2, 2));
        	if((d1 < r || d2 < r) && !(d1 < r && d2 < r))
        		ret++;
        }
        cout<<ret<<endl;
    }
    return 0;
}