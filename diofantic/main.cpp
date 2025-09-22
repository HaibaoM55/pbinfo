#include <iostream>
#include <math.h>
using namespace std;
int diofantic(int n, int s[],  int a, int b, int c){
    int f[65537];
    for(int i = 1; i <= n; i++){
        f[s[i]]++;
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        long long p = c-1LL*a*s[i]*s[i];
        if(p < 0){
            continue;
        }
        if(p % b == 0){
            long long pb = p/b;
            long long sq = sqrt(pb);
            if(sq*sq == pb){
                nr += f[sq];
            }
        }
    }
    return nr;
}
