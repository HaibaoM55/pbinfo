#include <fstream>
using namespace std;
ifstream fin("cochilie.in");
ofstream fout("cochilie.out");
struct pozitie{
    int l1,c1;
    int l2,c2;
} poz[33];
int c;
int n,p, r[900500];
long long fib[33];
int v[33][3];
int main()
{
    fin>>c;
    fin>>n;
    fib[1] = 1;
    fib[2] = 1;
    for(int i=1;i<=n;i++)
    {
        if(i > 1){
            fib[i+1] = fib[i]+fib[i-1];
        }
        if(i%2==0){
            v[i][1] = fib[i];
            v[i][2] = fib[i+1];
        }
        else{
            v[i][1] = fib[i+1];
            v[i][2] = fib[i];
        }
    }

    if(c==1)
    {
        fout<<v[n][1]<<" "<<v[n][2];
        return 0;
    }
    fin>>p;
    poz[1]={1,1,1,1};
    int a, b;
    a = 1;
    b = 1;
    for(int i = 2; i <= n; i++){
        if(i%4==1){
            poz[i].l1=poz[i-1].l1-v[i][2];
            poz[i].c1=poz[i-1].c1;
            poz[i].l2=poz[i-1].l1-1;
            poz[i].c2=poz[i-1].c1+v[i][2]-1;
        }else if(i%4==2){
            poz[i].l1=poz[i-1].l1;
            poz[i].c1=poz[i-1].c2+1;
            poz[i].l2=poz[i-1].l1+v[i][1]-1;
            poz[i].c2=poz[i-1].c2+v[i][1];
        }else if(i%4==3){
            poz[i].l1=poz[i-1].l2+1;
            poz[i].c1=poz[i-1].c2-v[i][2]+1;
            poz[i].l2=poz[i-1].l2+v[i][2];
            poz[i].c2=poz[i-1].c2;
        }else{
            poz[i].l1=poz[i-1].l2-v[i][1]+1;
            poz[i].c1=poz[i-1].c1-v[i][1];
            poz[i].l2=poz[i-1].l2;
            poz[i].c2=poz[i-1].c1-1;
        }
        a = min(a,poz[i].l1);
        a = min(a,poz[i].l2);
        b = min(b,poz[i].c1);
        b = min(b, poz[i].c2);
    }
    if(n>3)
        b=abs(b)+1;
    else b=0;
    p=p+a-1;
    for(int i=1;i<=n;++i)
        if(poz[i].l1<=p && p<=poz[i].l2)
        {
            for(int j=poz[i].c1+b;j<=poz[i].c2+b;++j)
                r[j]=i;
        }

    for(int i=1;i<=v[n][2];++i)
        fout<<r[i]<<" ";

    return 0;
}
