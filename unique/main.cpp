#include <bits/stdc++.h>
using namespace std;
bitset<200003> a, b;
int main()
{
    int x;
    int nr = 0;
    while (cin >> x){
        if(a[x] == 0){
            nr++;
            a[x] = 1;
        }
        else{
            if(b[x] == 0){
                nr--;
            }
            b[x] = 1;
        }
    }
    cout << nr;
    return 0;
}
