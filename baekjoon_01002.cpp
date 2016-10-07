#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//r'이 r보다 크거나 같다 가정.
/* 두점에서 만날 때
 * r'-r<d<r'+r
 */
/* 한점에서 만날 때
 * 외접: r+r' = d
 * 내접: r'-r = d
 */
 /* 만나지 않을 때
  * 외부: r+r' < d
  * 내부: d < r'-r
  * 동심원: d = 0
  */
int main(void){
    int tc;

    cin>>tc;

    for(int test_case=0; test_case<tc; ++test_case){
        int x1, x2, y1, y2, r1, r2, ret;
        cin>>x1>>y1>>r1;
        cin>>x2>>y2>>r2;

        double d = sqrt(pow(x2- x1, 2) + pow(y2 - y1, 2));
        int big = max(r1, r2);
        int small = min(r1, r2);

        if(d == 0.0){
            if(big == small)
                ret = -1;
            else
                ret = 0;
        }else{
            if(big-small < d && big+small > d)
                ret = 2;
            else if(big+small == d || big-small == d)
                ret = 1;
            else
                ret = 0;
        }
        cout<<ret<<endl;
    }
}