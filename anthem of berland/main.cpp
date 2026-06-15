#include <iostream>
#include <string.h>
using namespace std;
char cps[100004];
char s[100004];
char x[100004];
int nrmax = 0;
int main(){
    cin >> s;
    cin >> x;
    strcpy(cps, s);
    int l = strlen(s);
    int lx = strlen(x);
    for(int k = 0; k < lx; k++){
        int nr = 0;
        for(int i = k; i < l-lx+1; i++){
            bool ok = true;
            for(int j = i; j <= i+lx-1; j++){
                if(s[j] != '?' && s[j] != x[j-i]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                for(int j = i; j <= i+lx-1; j++){
                    s[j] = x[j-i];
                }
                nr++;
            }
        }
        nrmax = max(nrmax, nr);
        strcpy(s, cps);
    }
    cout << nrmax;
    return 0;
}
