#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
ifstream fin("ron.in");
ofstream fout("ron.out");
int c, n;
int pmax = 0;
bool ciur[50004];
int s[50004];
struct pereche{
    int p, l;
}v[50004];
bool compara(pereche a, pereche b){
    if(a.p < b.p){
        return true;
    }else if(a.p == b.p){
        if(a.l < b.l){
            return true;
        }
    }
    return false;
}
int main()
{
    fin >> c >> n;
    if(c == 1){
        ciur[1] = true;
        for(int i = 2; i <= 50000; i++){
            if(ciur[i] == false){
                for(unsigned int j = i; j*i <= 50000; j++){
                    ciur[j*i] = true;
                }
            }
        }
        for(int i = 1; i <= 50000; i++){
            if(ciur[i]==false){
                s[i] = 1;
            }else{
                s[i] = 0;
            }
            s[i] += s[i-1];
        }
        for(int i = 1; i <= n; i++){
            int p, l;
            fin >> p >> l;
            int x = ceil(sqrt(p));
            int y = sqrt(p+l-1);
            int p1 = s[y]-s[x-1];
            pmax = max(p1, pmax);
        }
        fout << pmax;
    }else{
        for(int i = 1; i <= n; i++){
            fin >> v[i].p >> v[i].l;
            v[i].l = v[i].p+v[i].l-1;
        }
        sort(v+1, v+n+1, compara);
        int nr = 1;
        int l1 = v[1].l;
        for(int i = 2; i <= n; i++){
            if(l1+1 < v[i].p){
                nr++;
                l1 = v[i].l;
            }else{
                l1 = max(l1, v[i].l);
            }
        }
        fout << nr;
    }
    return 0;
}
