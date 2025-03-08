#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;
ifstream  fin("cubprim.in");
ofstream fout("cubprim.out");
int N,p;
unsigned long long a,x;
struct pereche
{
     int valoare,pozitie;
}v[200002];
char ciur[4000002];
int comp(pereche a, pereche b)
{
     if(a.valoare>b.valoare) return 1;
     if(a.valoare==b.valoare && a.pozitie<b.pozitie)return 1;
     return 0;
}
int main()
{
    ciur[0]=1; ciur[1]=1;///0 si 1 nu sunt prime
    for(int i=2;i<=4000000;i++)
    {
        if(ciur[i]==0)
        {
              ///i este numar prim
              ////marcam acum toti multipli lui i cu 1
              for(int j=2*i;j<=4000000;j=j+i)
              {
                    ciur[j]=1;
              }
        }
    }
    fin>>N;
    p=0;
    for(int i=1;i<=N;i++)
    {
       fin>>a;
       x=cbrt(a)+0.0000001;
       if(x*x*x==a && ciur[x]==0)
       {
             p++;
             v[p].valoare=x;
             v[p].pozitie=i;
       }
    }
    sort(v+1,v+1+p,comp);
    fout<<p<<"\n";
    for(int i=1;i<=p;i++)
    {
        a=v[i].valoare;
        fout<<v[i].pozitie<<" "<<a<<" "<<a*a*a<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
