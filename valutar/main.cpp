#include <fstream>
using namespace std;
ifstream  fin("valutar.in");
ofstream fout("valutar.out");
int nr[102] = {0};
int ls = 1;
char cod[10002];
int c[10002];
int v[10002];
int e[102] = {0};
int euro[102] = {0};
int lei[102] = {0};
int poz[102] = {1};
int a, b, n, n0;
int m,l,E,x;
int t;
int nrj(int v0)
{
    return (a * v0 + b) % n + 1;
}
int main()
{
    fin >> t;
    fin >> a >> b >> n0;
    fin >> n >> m >> l >> E >> x;
    for(int i = 1; i <= n; i++)
    {
        fin >> cod[i];
        fin >> c[i];
        fin >> v[i];
    }
    for(int i = 1; i <= m; i++)
    {
        poz[i] = 1;
        euro[i] = E;
        lei[i] = l;
    }
    int k=0;
    while(k<x)
    {
        for(int i = 1; i <= m && k<x; i++)
        {
            if(e[i] == 0)
            {
                k++;
                n0 = nrj(n0);
                poz[i] = poz[i] + n0;
                if(poz[i] > n)
                {
                    poz[i] = poz[i] - n;
                }
                if(cod[poz[i]] == 'R')
                {
                    nr[i]++;
                }
                else if(cod[poz[i]] == 'G')
                {
                    if(c[poz[i]]*poz[i] > lei[i])
                    {
                        if(nr[i] > 0)
                        {
                            nr[i]--;
                            continue; // cartonas pas
                        }
                        else
                        {
                            e[i] = 1;//eliminat
                        }
                    }
                    else
                    {
                        euro[i] = euro[i] + poz[i];
                        lei[i] = lei[i] - (c[poz[i]]*poz[i]);
                    }
                }
                else if(cod[poz[i]] == 'V')
                {
                    if(euro[i] < poz[i])
                    {
                        if(nr[i] > 0)
                        {
                            nr[i]--;
                            continue;
                        }
                        else
                        {
                            e[i] = 1;//eliminat
                        }
                    }
                    else
                    {
                        euro[i] = euro[i] - poz[i];
                        lei[i] = lei[i] + (v[poz[i]]*poz[i]);
                    }
                }
            }
        }
    }
    if(t == 1)
    {
        int s = 0;
        for(int i = 1; i <= m; i++)
        {
            if(e[i] == 0)
            {
                s++;
            }
        }
        fout << s;
    }
    return 0;
}
