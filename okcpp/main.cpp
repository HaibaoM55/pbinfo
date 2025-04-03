#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("okcpp.in");
ofstream fout("okcpp.out");
int c;
int p, k;
long long a, b;
int nrcif;
int f[11];
int v[20],cif=0;
bool ok(long long n,int lft){
    for(int i = 0; i <= 9; i++){
        f[i]=0;
    }
    do{
        f[n%10]++;
        n/=10;
    }while(n > 0);
    sort(f,f+10);
    int z=9;
    for(int i = 0; i <= 4; i++){
        swap(f[i], f[z]);
        z--;
    }
    for(int i=0; i<lft; i++){
        int min1=0;
        for(int j=1; j<10; j++){
            if(f[j]<f[min1]){
                min1=j;
            }
        }
        f[min1]++;
    }
    int s=0,cnt=0;
    while(s<k && cnt<10){
        s=s+f[cnt];
        cnt++;
    }
    if(s >= k && cnt >= p){
        return true;
    }else{
        return false;
    }
}
bool ok1=false;
void sol(long long nr,int a){
    if(ok(nr,cif-a)==0 || ok1){
        return;
    }
    if(a==cif){
        fout<<nr;
        ok1=1;
        return;
    }
    for(int i=v[a]; i<10 && ok1==0; i++){
        sol(nr*10+i,a+1);
    }
}
int main()
{
    fin >> c;
    if(c == 1){
        fin >> k >> p >> a >> b;
        int nr = 0;
        for(long long j = a; j <= b; j++){
            long long x = j;
            int m = k;
            int f[12] = {0,0,0,0,0,0,0,0,0,0};
            do{
                f[x%10]++;
                x = x/10;
            }while(x > 0);
            sort(f+0, f+10);
            bool ok = true;
            for(int i = 9; i >= 9-p+2; i--){
                m = m-f[i];
                if(m < 1){
                    break;
                }
            }
            if(m >= 1){
                nr++;
            }
        }
        fout << nr;
    }else{
        fin >> k >> p >> a;
        long long ca=a,cnt=0;
        do{
            ca/=10;
            cif++;
        }while(ca);
        ca=a;
        do{
            cnt++;
            v[cif-cnt]=a%10;
            a/=10;
        }while(a > 0);
        int s=1;
        while(ok1==0 && ca>0){
            int c=ca%10;
            ca/=10;
            while(c!=9){
                c++;
                sol(ca*10+c,cif-s+1);
            }
            v[cif-s]=0;
            s++;
        }
        if(ok1==0){
            v[0]=1;
            cif++;
            sol(1,1);
        }
    }
    return 0;
}
