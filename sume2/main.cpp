#include <fstream>
using namespace std;
ifstream fin("sume2.in");
ofstream fout("sume2.out");
int n;
int q;
long long s[100004];
int main()
{
    fin >> n;
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        fin >> s[i];
        s[i] = s[i-1]+s[i];
    }
    fin >> q;
    for(int i = 1; i <= q; i++){
        int x, y;
        fin >> x >> y;
        fout << s[y]-s[x-1] << '\n';
    }
    return 0;
}
