#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("proiecte.in");
ifstream fin1("proiecte.in");
ofstream fout("proiecte.out");
int n, m;
int nri, nr;
int f[1004], f1[1004];
int b[1004], b1[1004];
int fm[204], p[204];
int z = 0;
int vmax = 0;
int main()
{
    fin >> n >> m;
    fin1 >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> nri;
        fin1 >> nri;
        int corect = 0;
        for(int j = 0; j <= 1000; j++){
            f[j] = 0;
            f1[j] = 0;
        }
        for(int j = 1; j <= nri; j++){
            fin >> nr;
            f[nr%1000]++;
            if(f[nr%1000] >= nri/2){
                corect = nr%1000;
            }
        }
        int corect1 = 0;
        for(int j = 1; j <= nri; j++){
            fin1 >> nr;
            f1[nr/1000]++;
            if(f1[nr/1000] >= nri/2){
                corect1 = nr/1000;
            }
        }
        int numar = corect1*1000+corect;
        fm[i] = numar;
    }
    for(int i = 1; i <= n; i++){
        int ap=0;
        for(int j = 1; j <= m; j++){
            int vr = fm[j];
            if(vr == i){
                ap++;
                if(ap > vmax){
                    z = 1;
                    p[1] = i;
                    vmax = ap;
                }else if(ap == vmax){
                    z++;
                    p[z] = i;
                }
            }
        }
    }
    for(int i = 1; i <= z; i++){
        fout << p[i] << ' ';
    }
    return 0;
}
