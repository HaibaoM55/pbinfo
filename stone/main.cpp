#include <iostream>
using namespace std;
int n, m;
int k, q;
bool lin[5];
bool col[5];
int main()
{
    cin >> n >> m >> k >> q;
    for(int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        lin[x] = true;
        col[y] = true;
    }
    int s = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(lin[i] == false && col[j] == false){
                s++;
            }
        }
    }
    /*
    s!      1*2*3*...*(s-q)*(s-q+1)...*s
    ----- = ---------------------------- = (s-q+1)*(s-q+2)*...*s
    (s-q)!      1*2*...*(s-q)
    */
    long long p = 1;
    for(int i = s-q+1; i <= s; i++){
        p = p*i;
    }
    if(s-q+1 > s){
        cout << 0;
    }
    else{
        cout << p;
    }
    return 0;
}
