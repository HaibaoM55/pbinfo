#include <bits/stdc++.h>
#define NMAX 100004
#define DIM 10000
using namespace std;

ofstream fout("aecmmdci.out");

int N,M,T,A,B,i,j,r,st,dr,poz,cmmdc,v[NMAX],sq[1002],d[1002];

char buff[DIM];
int _poz=0;

void citeste(int &numar)
{
     numar = 0;
     char semn='+';
     while (buff[_poz] < '0' || buff[_poz] > '9')
     {
          semn = buff[_poz];
          if (++_poz == DIM)
               fread(buff,1,DIM,stdin),_poz=0;
     }
     while ('0'<=buff[_poz] && buff[_poz]<='9')
     {
          numar = numar*10 + buff[_poz] - '0';
          if (++_poz == DIM)
               fread(buff,1,DIM,stdin),_poz=0;
     }
     if (semn == '-')
          numar = -numar;
}



int euclid(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }

    return a;
}

void citire()
{
    citeste(N);

    ///r=(int)sqrt(N);
    r=100;

    for(i=1; i<=N; i++)
    {
        poz=i/r;
        citeste(v[i]);
        if(sq[poz]==0)
        {
            sq[poz]=v[i];
        }
        else
        {
            sq[poz]=euclid(sq[poz],v[i]);
        }
    }

    citeste(M);
}

int main()
{
    freopen ("aecmmdci.in","rt",stdin);
    citire();

    for(i=1; i<=M; i++)
    {
        citeste(T);
        citeste(A);
        citeste(B);

        if(T==1)
        {
            cmmdc=v[A];
            st=A;
            dr=B;

            while(cmmdc>1 && st<=dr && st%r!=0)
            {
                cmmdc=euclid(cmmdc,v[st]);
                st++;
            }

            while(cmmdc>1 && st+r<=dr)
            {
                if(d[st/r]==1){
                    int cmmdc1=v[st];
                    for(j=st+1; j<st+r && cmmdc1>1; j++)
                    {
                        cmmdc1=euclid(cmmdc1,v[j]);
                    }
                    sq[st/r]=cmmdc1;
                    d[st/r]=0;
                }
                cmmdc=euclid(cmmdc,sq[st/r]);
                st+=r;
            }

            while(cmmdc>1 && st<=dr)
            {
                cmmdc=euclid(cmmdc,v[st]);
                st++;
            }

            fout<< cmmdc<< "\n";
        }
        else
        {
            v[A]=B;
            d[A/r]=1;
        }
    }

    return 0;
}
