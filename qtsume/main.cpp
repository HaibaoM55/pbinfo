#include <fstream>
using namespace std;
ifstream fin("qtsume.in");
ofstream fout("qtsume.out");
int n, q;
long long s1[100004];
long long s2[100004];
int main()
{
    fin >> n;
    s1[0] = 0;
    s2[0] = 0;
    for(int i = 1; i <= n; i++){
        long long x;
        fin >> x;
        s1[i] = s1[i-1]+x;
        s2[i] = s2[i-1]+x*i;
    }
    fin >> q;
    for(int i = 1; i <= q; i++){
        long long x, y;
        fin >> x >> y;
        long long p = s2[y]-s2[x-1]-(s1[y]-s1[x-1])*(x-1);
        fout << p << '\n';
    }
    return 0;
}
