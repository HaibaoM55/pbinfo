#include <fstream>
#include <cstdio>
#include <bitset>
using namespace std;
#define DIM 10000
char buff[DIM];
int poz=0;

///ifstream  fin("masterpiece001.in");
FILE *fin=freopen("masterpiece001.in","r",stdin);
ofstream fout("masterpiece001.out");

int n,nrp,x,pri[1004],divmax,z;
char ciur[1004];
bitset <400001> mybitset;
int nrdiv(int x){
    int p=1,d=1,e=0;
    while(pri[d]*pri[d]<=x){
        e=0;
        while(x%pri[d]==0){
            e++;
            x=x/pri[d];
        }
        p=p*(1+e);
        d++;
    }
    if(x>1){
        p=p*2;
    }
    return p;
}

void citeste(int &numar)
{
     numar = 0;
     //cat timp caracterul din buffer nu e cifra ignor
     while (buff[poz] < '0' || buff[poz] > '9')
          //daca am "golit" bufferul atunci il umplu
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     //cat timp dau de o cifra recalculez numarul
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     }
}
int main()
{
    ciur[0]=1;ciur[1] = 1;
    for(int i = 2; i <= 1000; i++){
        if(ciur[i]==0){
            pri[++nrp]=i;
            for(int j = i*i; j <= 1000; j += i){
                ciur[j]=1;
            }
        }
    }
    mybitset.reset();
    divmax=0;
    ///fin >> n;
    citeste(n);
    for(int i = 1; i <= n; i++){
        ///fin >> x;
        citeste(x);
        z=nrdiv(x);
        if(z>divmax){
            mybitset.reset();
            mybitset.set(x,1);
            divmax=z;
        }
        else{
            if(z==divmax){
                mybitset.set(x,1);
            }
        }
    }
    for(int i = 1; i <= 400000; i++){
        if(mybitset.test(i)==1){
            fout << i << ' ';
        }
    }
    return 0;
}
