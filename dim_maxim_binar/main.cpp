#include <iostream>
#include <string.h>
using namespace std;
char x[105];
int b[105][10];
int s[105][10];
int main()
{
    cin >> x;
    int l = strlen(x);
    for(int i = 0; i < l; i++){
        int v = x[i];
        b[i][1] = 0;
        int p = 8;
        while(v > 0){
            b[i][p] = v % 2;
            p--;
            v = v/2;
        }
        for(int j = 1; j <= 8; j++){
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+b[i][j];
        }
    }
    for(int lg = 8; lg >= 0; lg--){
        for(int i = 0; i+lg-1 < l; i++){
            for(int j = 1; j+lg-1 <= 8; j++){
                //(i, j), (i+lg-1, j+lg-1);
                int suma = s[i+lg-1][j+lg-1]-s[i-1][j+lg-1]-s[i+lg-1][j-1]+s[i-1][j-1];
                if(suma == lg*lg || suma == 0){
                    cout << lg;
                    return 0;
                }
            }
        }
    }
    return 0;
}
