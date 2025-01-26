#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("balba.in");
ofstream fout("balba.out");
int c, n;
int v[100004];
int f[12];
int main()
{
    fin >> c;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    if(c == 1){
        v[0] = -1;
        int nr = 0;
        for(int i = 1; i <= n; i++){
            if(v[i] != v[i-1]){
                nr++;
            }
        }
        fout << nr << '\n';
        nr = 0;
        bool ok = true;
        for(int i = 1; i <= n; i++){
            if(v[i] == v[i-1]){
                if(ok){
                    nr++;
                    ok = false;
                }
            }else{
                ok = true;
            }
        }
        fout << nr;
    }else{
        int par = 1, b = 0, minim;
        for(int i=1;i<=n;i++){
            f[v[i]]++;
        }
        for(int i=0;i<=9;i++){
            if(f[i] % 2 != 0){
                par = 0;
            }
        }
        for(int i=0;i<=9;i++){
            if(f[i]>=2)
            {
                minim=i;
                break;
            }
        }
        int k=0,mij=-1,d=-1;
        for(int cif=9;cif>=0;cif--){
            if(cif != 0 || k != 0){
                for(int i=1;i<=f[cif]/2;i++){
                    fout << cif;
                    k++;
                }
            }
            if(f[cif]%2==1)
            {
                if(b==0 && f[cif]!=1 && (cif != 0 || k!=0))
                {
                    if(cif >= mij){
                        fout<<cif;
                    }else{
                        if(cif == minim){
                            d = cif;
                        }else{
                            fout<<cif;
                        }
                    }
                    b=1;
                }
                else if(mij==-1){
                    mij=cif;
                }
            }
            if(par==1&&f[cif]>=4)
            {
                f[cif]--;
                mij=cif;
                par=0;
            }
        }
        if(mij!=-1){
            fout<<mij;
        }
        for(int cif=0;cif<=9;cif++){
            if(cif!=0 || k!=0){
                for(int i=1;i<=f[cif]/2;i++){
                    fout << cif;
                    if(cif==d){
                        fout<<d;
                        d = -1;
                    }
                }
            }
        }
    }
    return 0;
}
