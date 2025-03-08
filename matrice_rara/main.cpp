#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("matrice_rara.in");
ofstream fout("matrice_rara.out");
long long n,m,N1,N2,i,j,c,s,k,z;
struct trip
{
    int i;
    int j;
    long long v;
};
trip l[600009],a[600009];
int main()
{
    fin>>n>>m>>N1>>N2;
    for(k=1;k<=N1+N2;k=k+1)
    {
        fin>>l[k].i;
        fin>>l[k].j;
        fin>>l[k].v;
    }
    c=0;
    k=1;
    z=N1+1;
    while(k<=N1 && z<=N1+N2)
    {
        if(l[k].i==l[z].i && l[k].j==l[z].j)
        {
            if(l[k].v+l[z].v!=0)
            {
                c=c+1;
                a[c]=l[k];
                a[c].v=l[k].v+l[z].v;
            }
            k=k+1;
            z=z+1;
        }
        else
        {
            if((l[k].i<l[z].i) || (l[k].i==l[z].i && l[k].j<l[z].j))
            {
                c=c+1;
                a[c]=l[k];
                k=k+1;
            }
            else
            {
                c=c+1;
                a[c]=l[z];
                z=z+1;
            }
        }
    }
    while(k<=N1)
    {
        c=c+1;
        a[c]=l[k];
        k=k+1;
    }
    while(z<=N1+N2)
    {
        c=c+1;
        a[c]=l[z];
        z=z+1;
    }
    fout<<c<<"\n";
    for(k=1;k<=c;k=k+1)
    {
        fout<<a[k].i<<" "<<a[k].j<<" "<<a[k].v<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}

