#include <fstream>
using namespace std;
ifstream fin("pitici.in");
ofstream fout("pitici.out");
int n, x;
long long s[400004];
long long f[400009];
long long vmax=0, nrmax;
long long b[400009];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        s[i] = s[i-1]+x;
    }
    for(int i = 1; i <= n; i++){
        fin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        long long S = s[i-1];
        int p1 = i, p2 = n;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(s[mij]-S <= b[i]){
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        if(p2+1 > n){
            p2 = n-1;
        }
        f[i] += 1;
        f[p2+2] -= 1;
    }
    for(int i = 1; i <= n; i++){
        f[i] = f[i-1]+f[i];
        if(f[i] > vmax){
            vmax = f[i];
            nrmax = 1;
        }else if(f[i] == vmax){
            nrmax++;
        }
    }
    fout << vmax << ' ' << nrmax;
    return 0;
}
