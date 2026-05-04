#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;
ifstream  fin("bipatrat.in");
ofstream fout("bipatrat.out");
long long v[2002],N,i,j,x,a[20],na,r,b[200],nb,k,l;
int main()
{
    N=0;
    while(fin>>x)
    {
        N++;
        v[N]=x;
    }
    for(i=1;i<=N;i++)
    {
        r=sqrt(v[i]);
        if(r*r==v[i])
        {
            nb=0;
            //depozitam in a cifrele lui v[i]
            x=v[i];
            na=0;
            do
            {
                na++;
                a[na]=x%10;
                x=x/10;
            }
            while(x!=0);
            //inseram in fata primei cifre doar cifre nenule
            for(j=1;j<=9;j++)
            {
                x=j;
                for(k=na;k>=1;k--)
                {
                    x=x*10+a[k];
                }
                r=sqrt(x);
                if(r*r==x)
                {
                    nb++;
                    b[nb]=x;
                }
            }

            for(j=0;j<=9;j++)
            {
                //inseram intre cifrele din a[] cifra j
                for(l=na;l>=1;l--)
                {
                    ///la pozitia l
                    x=0;
                    for(k=na;k>=l;k--)
                    {
                        x=x*10+a[k];
                    }
                    x=x*10+j;
                    for(k=l-1;k>=1;k--)
                    {
                        x=x*10+a[k];
                    }
                    r=sqrt(x);
                    if(r*r==x)
                    {
                        nb++;
                        b[nb]=x;
                    }
                }
            }
            if(nb>0)
            {
                sort(b+1,b+nb+1);
                fout<<b[1]<<" ";
                for(j=2;j<=nb;j++)
                {
                    if(b[j-1]<b[j])
                    {
                    	fout<<b[j]<<" ";
                    }
                }
                fout<<"\n";
            }
            else
            {
                fout<<0<<"\n";
            }
        }else{
        	fout << 0 << '\n';
        }
    }
   return 0;
}
