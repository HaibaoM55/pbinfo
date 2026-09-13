#include <iostream>
using namespace std;
int f, v, m, x, y;
int main(){
    while(cin >> x >> y){
        m++;
        v = max(v, max(x, y));
    }
    f = 2-v+m;
    cout << f;
    return 0;
}
