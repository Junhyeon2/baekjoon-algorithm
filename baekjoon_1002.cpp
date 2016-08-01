#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int tc;

    cin>>tc;

    for(int test_case=0; test_case<tc; ++test_case){
        int x1, x2, y1, y2, r1, r2, ret;
        cin>>x1>>y1>>r1;
        cin>>x2>>y2>>r2;

        double dist = sqrt(pow(x2- x1, 2) + pow(y2 - y1, 2));

        if(dist == 0.0){
            if(r1 == r2)
                ret = -1;
            else
                ret = 0;
        }else{
            if(r1+r2 > dist){
                if(abs(abs(r1)-abs(r2)) == dist)
                    ret = 1;
                else
                    ret = 2;
            }
            else if(r1+r2 == dist)
                ret = 1;
            else
                ret = 0;
        }
        cout<<ret<<endl;
    }
}