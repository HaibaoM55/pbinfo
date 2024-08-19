#include <fstream>
using namespace std;
int n, v[1000004], nr = 0;
long long p,prod=1;
int k = 0, st=1, lc=0;
ifstream fin("produs2.in");
ofstream fout("produs2.out");
int main()
{
    fin >> n >> p;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for (int i=1; i<=n; i++)
    {
        prod=1LL*prod*v[i];
        lc++;
        if (prod<p)
        {
            nr+=lc;
        }
        else
        {
            while(prod>p && st<i)
            {
                prod=prod/v[st];
                st++;
                lc--;
            }
            nr+=lc;
        }
    }
    fout << nr;
    return 0;
}
