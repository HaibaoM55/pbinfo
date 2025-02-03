#include <iostream>
#include <string.h>
using namespace std;
char x[21];
int l = 0;
int f[27];
long long fact[21];
int main()
{
    cin >> x;
    l = strlen(x);
    for(int i = 0; i < l; i++){
        f[(x[i]-'a')+1]++;
    }
    fact[1] = 1;
    for(int i = 2; i <= 20; i++){
        fact[i] = fact[i-1]*i;
    }
    long long rasp = fact[l];
    long long imp = 1;
    for(int i = 1; i <= 26; i++){
        if(f[i] > 0){
            imp = imp*fact[f[i]];
        }
    }
    rasp = rasp/imp;
    cout << rasp;
    return 0;
}
