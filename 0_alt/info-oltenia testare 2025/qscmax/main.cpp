#include <fstream>
#define DIM 100010
using namespace std;
int d[DIM], v[DIM], n, m, i, p, x, a, b, t;
int scmax(int a, int b) {
    int maxim, p, i, j, sol;
    sol = 1;
    d[a] = 1;
    for (i=a+1;i<=b;i++) {
        maxim = 0;
        for (j=a;j<i;j++)
            if (v[j] <= v[i] && d[j] > maxim) {
                maxim = d[j];
            }
        d[i] = maxim + 1;

        if (d[i] > sol) {
            sol = d[i];
        }
    }
    return sol;
}


int main () {
    ifstream fin ("qscmax.in");
    ofstream fout("qscmax.out");
    fin>>n;
    for (i=1;i<=n;i++)
        fin>>v[i];
    fin>>m;
    for (i=1;i<=m;i++) {
        fin>>t;
        if (t == 1) {
            fin>>p>>x;
            v[p] = x;
        } else {
            fin>>a>>b;
            fout<<scmax(a, b)<<" ";
        }
    }
    return 0;
}
