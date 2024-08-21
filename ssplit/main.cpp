#include <iostream>
using namespace std;
int n;
long long v[200004], s[200004];
int vmin = 2000000000;
int vmini, vminj;
int cb(int i){
    int j = n - 1, mij, p1 = i, p2 = n - 1, dif = 2000000000, s1, s2;
    while (p1 <= p2){
        mij = (p1 + p2) / 2;
        s1 = s[mij] - s[i-1];
        s2 = s[n] - s[mij];
        if (s1 < s2){
            if (dif > s2 - s1){
                dif = s2 - s1, j = mij;
            }
            p1 = mij + 1;
        }
        else{
            if (dif > s1 - s2){
                dif = s1 - s2, j = mij;
            }
            p2 = mij - 1;
        }
    }
    return j;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        s[i] = s[i-1]+v[i];
    }
    for(int i = 1; i <= n-1; i++){
        int p1 = i, p2 = n;
        int x = s[i];
        int j = cb(i+1);
        int y = s[j]-s[i];
        int z = s[n]-s[j];
        int sm = max(max(x,y), z)-min(min(x, y), z);
        if(sm < vmin){
            vmin = sm;
            vmini = i;
            vminj = j;
        }
    }
    cout << vmini << ' ' << vminj;
    return 0;
}
