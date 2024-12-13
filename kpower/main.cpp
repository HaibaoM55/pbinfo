#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("kpower.in");
ofstream fout("kpower.out");
unsigned long long c, k, n;
unsigned long long v[1000005];
bool b[1000005];
unsigned long long vmax = 0;
unsigned long long a[1000];
int main()
{
    fin >> c;
    fin >> k >> n;
    unsigned long long z = 1;
    int k1 = 0;
    if(k > 1){
        for(z; z <= 1000000000000LL; z = z*k){
            k1++;
            a[k1] = z;
        }
    }else{
        k1 = 1;
        a[1] = 1;
    }
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        int p1 = 1, p2 = k1;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(a[mij] < v[i]){
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        if(v[i] == a[p1] && v[i] >= a[1]){
            b[i] = true;
        }
        if(b[i] && v[i] > vmax){
            vmax = v[i];
        }
    }
    if(c == 1){
        fout << vmax;
    }else if(c == 2){
        int nr = 0;
        vmax = 0;
        for(int i = 1; i <= n; i++){
            if(b[i] == false){
                nr = 0;
            }else{
                nr++;
                if(nr > vmax){
                    vmax = nr;
                }
            }
        }
        fout << vmax;
    }else{
        int nr = 0;
        vmax = 0;
        long long vmaxs = 0;
        long long s = 0;
        for(int i = 1; i <= n; i++){
            if(b[i] == false){
                nr = 0;
                s = 0;
            }else{
                s = s + v[i];
                nr++;
                if(nr > vmax){
                    vmax = nr;
                    vmaxs = s;
                }else if(nr == vmax && s > vmaxs){
                    vmaxs = s;
                }
            }
        }
        fout << vmaxs;
    }
    return 0;
}
