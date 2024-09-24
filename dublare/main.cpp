#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
char x[260];
int main()
{
    cin >> x;
    int l = strlen(x);
    int vmax = 0;
    for(int i = 0; i < l; i++){
        int nr = 0;
        for(int j = i+1; j <= l; j++){
            //verificam daca x[i],x[i+1],...,x[j] este dublat
            int lg = j-i+1;
            if(lg % 2 == 0){
                int olp = j;
                bool ok = true;
                for(int p = i; p <= j; p++){
                    if(x[p] != x[olp]){
                        ok = false;
                    }
                    olp--;
                }
                if(ok){
                    nr++;
                }
            }
        }
        nr = log2(nr)+1;
        vmax = max(nr, vmax);
    }
    cout << vmax;
    return 0;
}
