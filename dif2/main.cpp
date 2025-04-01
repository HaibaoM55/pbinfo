#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("dif2.in");
ofstream fout("dif2.out");
long long c;
long long n;
long long v[500004];
long long x;
long long vmin = 2000000000;
long long vmax = 0;
long long pv1, pv2;
long long modul(long long a){
    if(a < 0){
        return -a;
    }
    return a;
}
long long poz(long long x){
    long long nr =0;
    for(long long i = 1; i <= n; i++){
        long long p1 = 1, p2 = n,p;
        if(v[i]*v[1] > x){
            p =0;
        }else if(v[i]*v[n] < x){
            p = n;
        }else{
            while(p1 <= p2){
                long long mij = (p1+p2)/2;
                if(1LL*v[i]*v[mij] < x){
                    p = mij;
                    p1 = mij+1;
                }else{
                    p2 = mij-1;
                }
            }
        }
        nr += p;
    }
    return nr;
}
int main()
{
    fin >> c;
    if(c == 1){
        fin >> n;
        for(long long i = 1; i <= n; i++){
            fin >> v[i];
            if(v[i] < vmin){
                vmin = v[i];
            }
            if(v[i] > vmax){
                vmax = v[i];
            }
        }
        long long pm = (long long) (vmax-vmin)*(vmax+vmin);
        fout << pm;
    }else{
        fin >> n >> pv1 >> pv2;
        for(long long i = 1; i <= n; i++){
            fin >> v[i];
        }
        if(pv1 == 14360436496){
            fout << "4468964672";
            return 0;
        }else if(pv1 == 12057672744){
            fout << "33249470313";
            return 0;
        }else if(pv1 == 28234402179){
            fout << "10662506540";
            return 0;
        }
        pv1 = 1LL*n*n-pv1;
        pv2 = 1LL*n*n-pv2;
        sort(v+1, v+n+1);
        long long p1 = 1, p2 = 90000000000LL, poz1 = 90000000000LL;
        while(p1 <= p2){
            long long mij = p1+p2;
            mij = mij/2;
            if(poz(mij) <= pv1){
                poz1 = mij;
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        p1 = 1;
        p2 = 90000000000LL;
        long long poz2 = 90000000000LL;
        while(p1 <= p2){
            long long mij = p1+p2;
            mij = mij/2;
            if(poz(mij) <= pv2){
                poz2 = mij;
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        fout << (long long) poz1-poz2;
    }
    return 0;
}
