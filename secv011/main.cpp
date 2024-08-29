#include <fstream>
using namespace std;
ifstream fin("secv011.in");
ofstream fout("secv011.out");
int n = 0;
long long nr = 0;
long f[3000005];
int main()
{
    fin >> n;
    f[n] = 1;
    int p = 0;
    for(int i = 1; i <= n; i++){
        int x;
        fin >> x;
        p += x;
        nr += f[2*i-3*p+n]++;
    }
    fout << nr;
    return 0;
}
