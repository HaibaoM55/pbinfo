#include <fstream>
#define nmax 1000009
using namespace std;

ifstream  fin("livada2.in");
ofstream fout("livada2.out");
char speciali[nmax];
int n,i,Q,q,c,x,y,z,m[nmax], Left[nmax], Right[nmax];
long long Sp[nmax],p;

int main()
{
    fin>>n;

    for(i=1; i<=n; i++)
    {
        fin>>m[i];
    }

    for(i=1; i<=n; i++)
    {
        fin>>z;
        speciali[i]=z;
    }
	z=0;
    for(i=1;i<=n;i++)
    {
        if(speciali[i]==1)
        {
            z=i;
        }
        Left[i]=z;
    }
    z=0;
    for(i=n;i>=1;i--)
    {
        if(speciali[i]==1)
        {
            z=i;
        }
        Right[i]=z;
    }

    fin>>Q;

    for(q=1; q<=Q; q++)
    {
        fin>>c>>x>>y>>p;
		if(x>y)swap(x,y);
        if(c==1)
        {
            if(Right[y]>0)
            {
                y=Right[y];
            }

            Sp[x]+=p;
            Sp[y+1]-=p;
        }

        if(c==2)
        {
            if(Left[x]>0)
            {
                x=Left[x];
            }

            Sp[x]-=p;
            Sp[y+1]+=p;
        }
    }

    for(i=1; i<=n; i++)
    {
        Sp[i]+=Sp[i-1];
    }

    for(i=1; i<=n; i++)
    {
        fout<< m[i]+Sp[i] << " ";
    }

    return 0;
}
